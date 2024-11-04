#include "Task_1.h"

/*
В этом задании нужно реализовать обход графа в глубину.

Граф представлен матрицей смежности размерностью N x N — это двумерный массив, 
содержащий N строчек и N столбцов.

N — это количество вершин графа. Все вершины графа пронумерованы, 
то есть имеют уникальный индекс от 1 до N включительно.

Значение, находящееся в ячейке матрицы смежности, говорит о 
наличии или отсутствии связи между вершинами, индексы которых соответствуют 
номеру строчки и номеру столбца этой ячейки. Если значение в ячейке равно 1, 
то связь между вершинами есть. Если значение равно 0, то связи между вершинами нет. 
В ячейках с одинаковыми номерами столбца и строки всегда находится 0.

Ваша задача — имея предоставленную матрицу смежности, произвести обход графа, 
представленного этой матрицей, в глубину. При посещении каждой следующей ячейки 
ваша программа должна вывести на консоль индекс посещаемой ячейки.

Матрица смежности будет задаваться в текстовом файле в формате: 
первым числом в файле идёт количество вершин графа (N). Далее располагаются 
N строчек, каждая из которых содержит N чисел — 1 или 0.

Обход графа начинается с первой вершины с индексом 1.

Пример работы программы
Входящий файл input.txt:
7
0 0 1 0 0 1 1
0 0 1 1 0 0 1
1 1 0 0 0 0 1
0 1 0 0 1 0 0
0 0 0 1 0 0 1
1 0 0 0 0 0 1
1 1 1 0 1 1 0
*/

	//чтение файла и формирование первичного вектора
	void InOutFileVector::OupenFileWriteVector() {
		in_data_file.clear();
		do {
			x_line = 0;
			std::cout << "Чтение данных из файла *.txt" << std::endl;
			std::ifstream  f_in(InputTransformWay()); // открыли файл по заданному пути на чтение
			if (f_in.is_open()) {

				do {
					//f_in >> x_text;
					getline(f_in >> std::ws, x_text);
					++x_line; //проход по файлу в режиме считывания и подсчет строк
				} while (!f_in.eof());

				f_in.clear(); //очистка потока ввода из файла
				f_in.seekg(0, std::ios::beg);//возврат курсора в начало файла

				for (int i = 0; i < x_line; ++i) {
					//f_in >> x_text;
					getline(f_in >> std::ws, x_text);
					in_data_file.push_back(x_text);
				};

				f_in.close();
				std::cout << "Файл успешно прочитан!" << std::endl;
				std::cout << std::endl;
				break;
			}
			else {
				std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
			}
		} while (true);
	}

	//вывод первичного вектора
	std::vector<std::string> InOutFileVector::GetVector_1() {

		return in_data_file;
	}

	//ввод вторичного вектора
	std::vector<std::string> InOutFileVector::SetVector_2(const std::vector < std::string>& a) {

		if (!a.empty()) {
			out_data_file.clear();

			for (const auto& i : a) {
				out_data_file.push_back(i);
			}
		}
		return out_data_file;
	}

	//вывод вторичного вектора
	std::vector<std::string> InOutFileVector::GetVector_2() {

		return out_data_file;
	}

	//запись в файл
	void InOutFileVector::InFileWriteVetor() {

		do {
			std::cout << "Запись данных в файл *.txt" << std::endl;
			std::ofstream  f_oupen(InputTransformWay()); // открыли файл по заданному пути на запись
			if (f_oupen.is_open()) {

				//f_oupen << cel << std::endl;

				for (const auto& i : out_data_file) {

					f_oupen << i << std::endl;

				};

				f_oupen.close();
				std::cout << "Файл успешно записан!" << std::endl;
				// std::cout << std::endl;
				break;
			}
			else {
				std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
			}
		} while (true);

	}

	//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	std::string InOutFileVector::InputTransformWay() {
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

	//создание массива (на основе вектора векторов)
	std::vector <std::vector<int>> InOutFileVector::CreateArrayVector(const std::vector < std::string>& a) {
		int var_x{ 0 };
		std::string var_char{ "" };
		std::vector <std::vector<int>> res_2{};
		std::vector <int> res_1{};

		for (std::string string_x : a) {
			
			for (char& var : string_x) {

				if (var != ' ') {
					var_char = var_char + var;
				}
				else {
					res_1.push_back(stoi(var_char));
					var_char = "";
				}
			}
			if (var_char != "") {
				res_1.push_back(stoi(var_char));
				var_char = "";
			}
			res_2.push_back(res_1);
			res_1.clear();
		}
		return res_2;
	};
	
	//нумерация с 0
	std::vector<int> connection_point(const std::vector <std::vector<int>>& array, int point_x) {
		
		std::vector<int>res{};
		int count{ 0 };

			for (auto i : array[point_x]) {

				if (i == 1) {
					res.push_back(count);					
				}
				++count;
			}
			return res;
	}

	std::vector <std::vector <std::pair<bool, int>> > Array_Pair(const std::vector <std::vector<int>>& array) {
		std::vector <std::pair<bool, int>>  array_way_1;
		std::vector <std::vector <std::pair<bool, int>> >  array_way_2;

		for (auto i : array) {
			for (auto x : i) {
				array_way_1.push_back({ false,x });
			}
			array_way_2.push_back(array_way_1);
			array_way_1.clear();
		}
		return array_way_2;
	}

	std::vector <std::pair<bool, int>> Array_Pair_statuse(const std::vector <std::vector<int>>& array) {
		std::vector <std::pair<bool, int>>  array_way_1;
	
		for (int x = 0; x < array.at(0).size(); ++x) {
				array_way_1.push_back({ false,x });
			}
					
		return array_way_1;
	}

	void input_matrix_graf(const std::vector <std::vector<int>>& array) {
		bool fist = false;
		for (const auto& var_y : array) {
			fist = false;
			for (auto i : var_y) {

				if (fist == false) {
					std::cout << i;
					fist = true;
				}
				else { std::cout << "\t" << i; }
			}
			std::cout << std::endl;
		}
		std::cout << "-----------------" << std::endl;
	}

	void input_matrix_graf_pair(const std::vector <std::vector <std::pair<bool, int>>>& array) {

		bool fist = false;

		for (auto i : array) {
			fist = false;
			for (auto x : i) {

				if (fist == false) {
					std::cout << x.second << "(" << x.first << ")";
					fist = true;
				}
				else { std::cout << "\t" << x.second << "(" << x.first << ")"; }
			}
			std::cout << std::endl;
		}
		std::cout << "-----------------" << std::endl;
	}

	void input_connection_point(const std::vector <std::vector<int>>& array, int var) {
		bool fist = false;

		std::cout << "Узел графа " << var+1 << " связан c узлами: ";
		fist = false;
		for (auto i : connection_point(array, var)) {

			if (fist == false) {
				std::cout << i+1;
				fist = true;
			}
			else { std::cout << "  " << i+1; }

		}
		std::cout << std::endl;
		std::cout << "-----------------" << std::endl;
	}

	void input_statuse_point(const std::vector <std::pair<bool, int>>& array) {
		bool fist = false;
		for (auto& x : array) {
			if (fist == false) {
				std::cout << x.second+1 << "(" << x.first << ")";
				fist = true;
			}
			else { std::cout << "\t" << x.second +1 << "(" << x.first << ")"; }
		}
		std::cout << std::endl;
		std::cout << "-----------------" << std::endl;

	}

	void input_go_res(const std::vector <int>& array) {
		bool fist = false;
		for (auto& x : array) {
			if (fist == false) {
				std::cout << x+1;
				fist = true;
			}
			else { std::cout << " " << x+1 ; }
		}
		std::cout << std::endl;
		std::cout << "-----------------" << std::endl;

	}

	std::vector <int> go_array(const std::vector <std::vector<int>>& array, 
		 std::vector <std::pair<bool, int>>& array_statuse, int& point) {

		int count{ 0 };
		std::vector <int> res{};
		bool back_point = false;
		bool end_point;

		array_statuse.at(point).first = true;
		res.push_back(point);

		do {
			end_point = false;
			count = 0;

			for (auto& x : array.at(point)) {

				if ((x == 1 || back_point == true) && (array_statuse.at(count).first == false)) {
					point = count;
					array_statuse.at(point).first = true;
					res.push_back(point);
					end_point = true;
					back_point = false;
					break;
				}
				++count;
			}

			if (end_point == false) {
				for (auto z : array_statuse) {
					if (z.first == false) {
						point = z.second;
						end_point = true;
						back_point = true;
						break;
					}
				}
			}

		} while (end_point);
		return res;
	}

void Task_1() {

	// D:\С++\Project\VSC\prj_netologiy_yandex\Course Algoritms\Block_7\Task 1 (graf)\input.txt

	/* матрицу чуть усложнил по сравнению с ДЗ - внес отдельные две точки (второй уровень связанности 10 и 11 узлы) для проверки
	и доболнительный хвост из двуух узлов от 5 узла (8 и 9 узлы). см ниже!

0 0 1 0 0 1 1 0 0 0 0
0 0 1 1 0 0 1 0 0 0 0
1 1 0 0 0 0 1 0 0 0 0
0 1 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 1 1 0 0 0
1 0 0 0 0 0 1 0 0 0 0
1 1 1 0 1 1 0 0 0 0 0
0 0 0 0 1 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1 0

	*/

	std::vector <std::vector<int>> data_array;
	std::vector <std::pair<bool, int>> data_array_statuse;
	int var{ 0 },var_point{ 0 };
	
	InOutFileVector read_file;
	read_file.OupenFileWriteVector();
	data_array = read_file.CreateArrayVector(read_file.GetVector_1());
	data_array_statuse = Array_Pair_statuse(data_array);

	std::cout << "Структура матрицы связей графа:" << std::endl;
	input_matrix_graf(data_array);

	std::cout << "Статус обхода графа (0 - не обойден, 1 - пройден) графа на старте:" << std::endl;
	input_statuse_point(data_array_statuse);

		std::cout << "Введите узел графа: ";
		std::cin >> var;
		var_point = var - 1;
		data_array_statuse.at(var_point).first = true;	

	std::cout << "Структура связей первой точки обхода графа:" << std::endl;;
	input_connection_point(data_array, var_point);
	
	std::cout << "Порядок обхода графа: ";
	input_go_res(go_array(data_array, data_array_statuse, var_point));

	std::cout << "Статус обхода графа (0 - не обойден, 1 - пройден) графа на финише:" << std::endl;
	input_statuse_point(data_array_statuse);

};