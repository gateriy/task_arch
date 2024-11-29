#include "Read_file.h"


//чтение файла ini по строчно и формирование первичного вектора строк
//чтение файла и формирование первичного вектора
bool ReadFileInVector::OupenFileWriteVector() {

		_in_data_file.clear();
		bool good = false;

		try {
			do {
				_x_line = 0;
				
				std::ifstream  f_in(InputTransformWay()); // открыли файл по заданному пути на чтение
				
				if (f_in.is_open()) {

					do {				
						getline(f_in >> std::ws, _x_text);
						++_x_line; //проход по файлу в режиме считывания и подсчет строк
					} while (!f_in.eof());

					f_in.clear(); //очистка потока ввода из файла
					f_in.seekg(0, std::ios::beg);//возврат курсора в начало файла

					for (int i = 0; i < _x_line; ++i) {					
						getline(f_in >> std::ws, _x_text);
						_in_data_file.push_back(_x_text);
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
		bool good = false;
		try {
			do {
				std::ofstream  f_oupen(InputTransformWay()); // открыли файл по заданному пути на запись
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
std::string ReadFileInVector::InputTransformWay() {
		std::string way{ "" };
		std::string way_file{ "" };

		std::cout << "Введите путь к файлу (если файл не в корневом каталоге программы): ";
		getline(std::cin >> std::ws, way_file);

		for (auto& ch : way_file) {

			if (ch == '\\' || ch == '/') {

				way = way + '\\' + '\\';
			}
			else {
				way = way + ch;
			}
		}
		return way;
	}


//----------------------------------------------------------------------------------------------
// D:\С++\Project\VSC\prj_netologiy_yandex\Course_1\Cours_parsing_ini\data_x.ini

void block_1() {

	Input_Output_Var<std::string, int> i_o_var;
	Input_Output_Var<std::string, std::string> i_o_str;
	ReadFileInVector read_file;

	read_file.OupenFileWriteVector();

	for (const auto& text : read_file.GetVector_1()) {
		i_o_str.Output(0, "", "<< ", text, " >>" , 1, 4);
	}





	/*
	i_o_var.Output(1,"проверка ", 1, " output ", 777, 1, 1);
	i_o_var.Output(1, "проверка ", 2, " output ", 777, 1, 2);
	i_o_var.Output(1, "проверка ", 3, " output ", 777, 1, 3);
	i_o_var.Output(1, "проверка ", 4, " output ", 777, 1, 4);
	i_o_var.Output(1, "проверка ", 5, " output ", 777, 1, 5);
	i_o_var.Output(1, "проверка ", 6, " output ", 777, 1, 6);
	i_o_var.Output(1, "проверка ", 7, " output ", 777, 1, 7);
	i_o_var.Output(1, "проверка ", 8, " output ", 777, 1, 8);
	i_o_var.Output(1, "проверка ", 9, " output ", 777, 1, 9);
	i_o_var.Output(1, "проверка ", 10, " output ", 777, 1, 10);
	*/
};