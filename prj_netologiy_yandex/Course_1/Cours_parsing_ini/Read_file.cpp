#include "Read_file.h"


//чтение файла ini по строчно и формирование первичного вектора строк
//чтение файла и формирование первичного вектора
bool ReadFileInVector::OupenFileWriteVector() {

		_in_data_file.clear();
		bool good = false;

		try {
			do {
				_x_line = 0;
				
				std::ifstream  f_in(_way); // открыли файл по заданному пути на чтение
				
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
						}
					};

					f_in.close();
					good = true;
					break;
				}
				else {
					std::cout << "Файл не найден или не доступен! Повторите ввод пути к файлу." << std::endl;
				}
			} while (true);

		} catch (...) {
			std::cout << "Не известная ошибка!" << std::endl;
			good = false;
		}
		return good;
	}

//заполнение вторичного вектора
std::vector<std::string> ReadFileInVector::SetVector_2(const std::vector < std::string>& a) {

		if (!a.empty()) {
			_out_data_file.clear();

			for (const auto& i : a) {
				_out_data_file.push_back(i);
			}
		}
		return _out_data_file;
	}

//вывод первичного вектора
std::vector<std::string> ReadFileInVector::GetVector_1() { return _in_data_file; }

//вывод вторичного вектора
std::vector<std::string> ReadFileInVector::GetVector_2() { return _out_data_file;	}

//запись данных вторичного вектора в файл
bool ReadFileInVector::InFileWriteVetor() {
		InputTransformWay();
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

//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
void ReadFileInVector::InputTransformWay() {
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

//второй вариан счиывания пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
void ReadFileInVector::InputTransformWay_2(const std::string& way_text) {
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

//преобразование переменных секции и перееменной 
void ParsingIni::_ReadVar(const std::string& a) {
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
std::pair <std::string, std::string> ParsingIni::_Read_String(const std::string& var_str) {
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
std::string ParsingIni::_Var_Type(const std::string& var) {
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
std::pair<std::string, std::string> ParsingIni::Str_Value_Type(const std::string& text_var) {

	_ReadVar(text_var);
	std::string res{}, type_x{};;
	bool begin_section = false;
	bool first = false;

	if (!_in_data_file.empty()) {

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

						if (_section_var.second == _Read_String(str_var).first) {
							res = _Read_String(str_var).second;
							type_x = _Var_Type(_Read_String(str_var).second);
							first = true;
						}
						//if (first ==false) {
							//std::cout << "Переменная не найдена! Список всех переменных секции:" << std::endl;
							//std::cout <<"????? ["<< _Read_String(str_var).first << "] = ["
							//<< _Read_String(str_var).second <<"]"
							//<< " <- " << _Var_Type(_Read_String(str_var).second) << std::endl;
						//}
					}
				}
			}
		}
		if (first == false) {
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

							std::cout << "????? [" << _Read_String(str_var).first << "] = ["
								<< _Read_String(str_var).second << "]"
								<< " <- " << _Var_Type(_Read_String(str_var).second) << std::endl;

						}
					}
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


//----------------------------------------------------------------------------------------------
// D:\С++\Project\VSC\prj_netologiy_yandex\Course_1\Cours_parsing_ini\data_x.ini

void block_1() {

	//Input_Output_Var<std::string, int> i_o_var;
	Input_Output_Var<std::string, std::string> i_o_str;

	//ParsingIni parser;
	ParsingIni parser("D:/С++/Project/VSC/prj_netologiy_yandex/Course_1/Cours_parsing_ini/data_x.ini");

/*
	if (res.second == "string") {
		auto s = res.first;
		std::cout << "[" << s << "]" << typeid(s).name() << "[" << res.second << "]" << std::endl;
	}
	else
		if (res.second == "int") {
			auto s = std::stoll(res.first);
			std::cout << "[" << s << "]" << typeid(s).name() << "[" << res.second << "]" << std::endl;
		}
		else
			if (res.second == "double") {
				auto s = std::stold(res.first);	
				std::cout << "[" << s << "]" << typeid(s).name() << "[" << res.second << "]" << std::endl;
			}*/
//	auto s = parser.Get_Value<std::string>("Section1.var4");
	//std::cout << "[" << s << "][" << res.second << "]" << std::endl;	

	std::cout <<"--------------------------" << std::endl;
	auto res = parser.Str_Value_Type("Section2.var1");
	std::cout << "["<<res.first<<"]-["<< res.second<<"]" << std::endl;

	std::cout <<"---------------------------" << std::endl;
	res = parser.Str_Value_Type("Section3.var2");
	std::cout << "[" << res.first << "]-[" << res.second << "]" << std::endl;

	std::cout <<"---------------------------" << std::endl;
	res = parser.Str_Value_Type("Section1.var2");
	std::cout << "[" << res.first << "]-[" << res.second << "]" << std::endl;

	std::cout << "---------------------------" << std::endl;
	res = parser.Str_Value_Type("Section1.var4");
	std::cout << "[" << res.first << "]-[" << res.second << "]" << std::endl;

	std::cout << "---------------------------" << std::endl;
	res = parser.Str_Value_Type("Section1.var6");
	std::cout << "[" << res.first << "]-[" << res.second << "]" << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout  << std::endl;

	/*
	std::cout << "--------------------------"<<std::endl;
	std::cout << std::endl;
	std::cout << parser._section_var.first << "<<->>" << parser._section_var.second << std::endl;
	std::cout << std::endl;
	for (const auto& text : parser.GetVector_1()) {
		i_o_str.Output(0, "", "<< ", text, " >>" , 1, 4);
	}
	*/
};