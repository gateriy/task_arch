#include "Read_file.h"

//чтение файла ini по строчно и формирование первичного вектора строк
//чтение файла и формирование первичного вектора строк
bool ReadFileInVector::_OupenFileWriteVector() {

		_in_data_file.clear();
		bool good = false;
				
		//	do {
				
				_x_line = 0;
				
				std::ifstream  f_in(_way); // открыли файл по заданному пути на чтение

				if (!f_in) {
					throw std::ios_base::failure("The file was not found or is not available!");
				}
				
				if (f_in.is_open()) {

					do {				
						getline(f_in >> std::ws, _x_text);
						++_x_line; //проход по файлу в режиме считывания и подсчет строк
					} while (!f_in.eof());

					f_in.clear(); //очистка потока ввода из файла
					f_in.seekg(0, std::ios::beg);//возврат курсора в начало файла

					for (int i = 0; i < _x_line; ++i) {	
						_x_text.clear();
						getline(f_in >> std::ws, _x_text);
						if (!_x_text.empty()) {
							_in_data_file.push_back(_x_text);

							if (sizeof(_in_data_file) > _MAX_SISE_V) {
								throw std::bad_alloc();
							}
						}
					};

					f_in.close();
					good = true;
					//break;
				}
				/*else {
					std::cout << "Файл не найден или не доступен! Повторите ввод пути к файлу." << std::endl;
					_InputTransformWay();
				}*/
			//} while (true);

		return good;
	}

//заполнение вторичного вектора
/*
std::vector<std::string> ReadFileInVector::SetVector_2(const std::vector < std::string>& a) {

		if (!a.empty()) {
			_out_data_file.clear();

			for (const auto& i : a) {
				_out_data_file.push_back(i);
			}
		}
		return _out_data_file;
	}
	*/

//вывод первичного вектора
//std::vector<std::string> ReadFileInVector::GetVector_1() { return _in_data_file; }

//вывод вторичного вектора
//std::vector<std::string> ReadFileInVector::GetVector_2() { return _out_data_file;	}

//запись данных вторичного вектора в файл
/*
bool ReadFileInVector::InFileWriteVetor() {
		_InputTransformWay();
		bool good = false;
		try {
			do {
				std::ofstream  f_oupen(_way); // открыли файл по заданному пути на запись
				if (f_oupen.is_open()) {

					for (const auto& i : _out_data_file) {
						f_oupen << i << std::endl;
					};

					f_oupen.close();
					good = true;
					break;
				}
				else {
					std::cout << "Файл не найден или нет доступа! Повторите ввод пути к файлу." << std::endl;
				}
			} while (true);
		}
		catch(...) {
			std::cout << "Не известная ошибка!" << std::endl;
				good = false;
		}
		return good;
	}
	*/

//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
//noexcept
void ReadFileInVector::_InputTransformWay() noexcept {
	_way.clear();
	std::string way_file{ "" };

		std::cout << "Введите путь к файлу (если файл не в корневом каталоге программы): ";
		getline(std::cin >> std::ws, way_file);

		for (auto& ch : way_file) {

			if (ch == '\\' || ch == '/') {

				_way = _way + '\\' + '\\';
			}
			else {
				_way = _way + ch;
			}
		}
	}

//второй вариан преобразование пути к файлу / или \ в "\\" по переданной переменной
//noexcept
void ReadFileInVector::_InputTransformWay_2(const std::string& way_text) noexcept {
	_way.clear();
	
	for (auto& ch : way_text) {

		if (ch == '\\' || ch == '/') {

			_way = _way + '\\' + '\\';
		}
		else {
			_way = _way + ch;
		}
	}	 
}

//преобразование переменных секции и перееменной из переданной строки
//noexcept
void ParsingIni::_ReadVar(const std::string& a) noexcept {
	bool first = true;
	_section_var.first.clear();
	_section_var.second.clear();

	for (const auto& text_v : a) {

		if (text_v == '.') {
			first = false;
		}

		if (text_v != '.' && first == true) {
			_section_var.first = _section_var.first + text_v;
		}
		if (text_v != '.' && first == false) {
			_section_var.second = _section_var.second + text_v;
		}
	}
}

//формирует название и значение переменной в строковом формате
//noexcept
std::pair <std::string, std::string> ParsingIni::_Read_String(const std::string& var_str) noexcept{
	std::string name{}, var{};
	bool first = true;

	for (const auto& i : var_str) {
		if (i != ';') {

			if (first == false) { var = var + i; }

			if (i != '=' && first == true) {
				name = name + i;
			}
			else { first = false; }
		}
		else break;
	}

	for (auto& i : name) {
		if (name.back() == ' ') { name.pop_back(); }
		else break;
	}
	for (auto& i : var) {
		if (var.back() == ' ') { var.pop_back(); }
		else break;
	}
	return { {name},{var} };
}

//определяет возможный тип переменной на основе анализа данных по строке (string, int, double)
//noexcept
std::string ParsingIni::_Var_Type(const std::string& var) noexcept{
	int count_point{ 0 }, count_min{ 0 };
	bool str = false;

	if (!var.empty()) {
		for (const auto& i : var) {
			str = true;
			for (const char& f : { '-','0','1','2','3','4','5','6','7','8','9','0','.' }) {

				if (i == f) {
					str = false;
					break;
				}
			}
			if (i == '.') { ++count_point; }
			if (i == '-') { ++count_min; }

			if (str == true) { return "string"; }
		}

		if (str == false) {

			if (count_min == 0 || (count_min == 1 && var.at(0) == '-')) {

				if (count_point == 1) { return "double"; }
				else if (count_point == 0) { return "int"; }
				else { return "string"; }
			}
			else { return "string"; }
		}
	}
	else { return "no data available!"; }
}

//находит переменную по запросу и выдает ее значение и тип на основе анализа структуры переменной в виде string
//noexcept
std::pair<std::string, std::string> ParsingIni::Str_Value_Type(const std::string& text_var) noexcept {

	_ReadVar(text_var);
	std::string res{}, type_x{};;
	bool begin_section = false;
	bool find_section = false;
	bool first = false;

	if (!_in_data_file.empty()) {

		_Transform_Section();

		for (const auto& str_var : _in_data_file) {

			if (str_var == ('[' + _section_var.first + ']')) {
				//std::cout << "<<< Секция найдена! >>>" << std::endl;
				begin_section = true;
				find_section = true;
			}
			else {
				if (begin_section == true) {
					if ((str_var.at(0) == '[') && (str_var != ('[' + _section_var.first + ']'))) {
						begin_section = false;
						//std::cout << "<<< Секция завершена! >>>" << std::endl;
					}
					else {

						if (_section_var.second == _Read_String(str_var).first) {
							res = _Read_String(str_var).second;
							type_x = _Var_Type(_Read_String(str_var).second);
							first = true;
						}
					}
				}
			}
		}
		if (first == false && find_section==true) {
			std::cout << "Переменная не найдена! Список всех переменных секции:" << std::endl;
			for (const auto& str_var : _in_data_file) {

				if (str_var == ('[' + _section_var.first + ']')) {
					//std::cout << "<<< Секция найдена! >>>" << std::endl;
					begin_section = true;
				}
				else {
					if (begin_section == true) {
						if ((str_var.at(0) == '[') && (str_var != ('[' + _section_var.first + ']'))) {
							begin_section = false;
							//std::cout << "<<< Секция завершена! >>>" << std::endl;
						}
						else {
							if (_Read_String(str_var).first != "") {
								std::cout << "? >>> [" << _Read_String(str_var).first << "] = ["
									<< _Read_String(str_var).second << "]" << std::endl;									
							}
						}
					}
				}
			}
		}
		if ( find_section == false) {
			std::cout << "Секция не найдена! Список всех переменных и секций:" << std::endl;
			for (const auto& str_var : _in_data_file) {
				
				if (!_Read_String(str_var).first.empty()) {
					std::cout << "? >>> " << _Read_String(str_var).first;
					if (!_Read_String(str_var).second.empty()) {
						std::cout << " = [" << _Read_String(str_var).second << "]";
					}
					std::cout << std::endl;
				}
										
			}
		}
	}

	if (res == "" && first==true)
	{
		_valu_type = { {res},{"no data available!"} };
	}
	else
	{
		_valu_type = { {res},{type_x} };
	}
	return _valu_type;
}

//удаление пробелов в названии секций
//noexcept
void ParsingIni::_Transform_Section() noexcept {
	std::string text{ "" };
	bool begin_x = false;

	if (!_in_data_file.empty()) {
		for (auto& i : _in_data_file) {
			begin_x = false;
			text.clear();

			for (auto& x : i) {

				if (x == '[') { begin_x = true; }

				if (begin_x == true) {

					text = text + x;

				}
				if (x == ']') { break; }
			}
			if (begin_x == true) { i = text; }
		}
	}
}


//----------------------------------------------------------------------------------------------
// D:\С++\Project\VSC\prj_netologiy_yandex\Course_1\Cours_parsing_ini\data_x.ini

void block_1() {
	try {
		ParsingIni parser("data_x.ini");

		do {
			std::string text_var;
			std::cout << "Ведите переменную в формате SectionX.varY: ";
			std::cin >> text_var;
			std::string res = parser.Str_Value_Type(text_var).second;


			if (res == "int") {
				auto s = parser.Get_Value<long long int>(text_var); //формат как в задании!!!!
				std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
			}
			else if (res == "double") {
				auto s = parser.Get_Value<long double>(text_var);//формат как в задании!!!!
				std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
			}
			else if (res == "string") {
				auto s = parser.Get_Value<std::string>(text_var);//формат как в задании!!!!
				std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
			}
			else {
				std::cout << "Данные в заданной переменной отсутствуют! Задайте иное имя переменной или секции!" << std::endl;
			}
			std::cout << "Вести данные заново? (0 - да): ";
			char var_y{ '1' };
			std::cin >> var_y;
			if (var_y != '0') { break; }
		} while (true);

	}
	catch (const std::ios_base::failure& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Произошла ошибка! Обработка приостановлена! " << std::endl;
	}
	catch (const std::bad_alloc& a) {
		std::cerr << "Error: " << a.what() << std::endl;
		std::cerr << "Превышение объема выделенной памяти при чтении файла! Обработка приостановлена! " << std::endl;
	}
	catch (const My_Exception1& b) {
		std::cerr << "Error: " << b.what() << std::endl;
		std::cerr << "Ошибка конвертации! Обработка приостановлена! " << b.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Error: " << "???" << std::endl;
		std::cerr << "Не известная ошибка! " << std::endl;
	};

};

void block_2() {

	try {
		ParsingIni parser;

		do {
			std::string text_var;
			std::cout << "Ведите переменную в формате SectionX.varY: ";
			std::cin >> text_var;
			std::string res = parser.Str_Value_Type(text_var).second;


			if (res == "int") {
				auto s = parser.Get_Value<long long int>(text_var);//формат как в задании!!!!
				std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
			}
			else if (res == "double") {
				auto s = parser.Get_Value<long double>(text_var);//формат как в задании!!!!
				std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
			}
			else if (res == "string") {
				auto s = parser.Get_Value<std::string>(text_var);//формат как в задании!!!!
				std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
			}
			else {
				std::cout << "Данные в заданной переменной отсутствуют! Задайте иное имя переменной или секции!" << std::endl;
			}
			std::cout << "Вести данные заново? (0 - да): ";
			char var_y{ '1' };
			std::cin >> var_y;
			if (var_y != '0') { break; }
		} while (true);

	}
	catch (const std::ios_base::failure& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Произошла ошибка! Обработка приостановлена! " << std::endl;
	}
	catch (const std::bad_alloc& a) {
		std::cerr << "Error: " << a.what() << std::endl;
		std::cerr << "Превышение объема выделенной памяти при чтении файла! Обработка приостановлена! " << std::endl;
	}
	catch (const My_Exception1& b) {
		std::cerr << "Error: " << b.what() << std::endl;
		std::cerr << "Ошибка конвертации! Обработка приостановлена! " << b.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Error: " << "???" << std::endl;
		std::cerr << "Не известная ошибка! " << std::endl;
	};

};