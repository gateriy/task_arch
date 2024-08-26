// Task_abstraktion.cpp : 
// // задачи 1,2

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream> //для работы с файлами
#include<algorithm>

enum class Task {
	task_1 = 1,
	task_2,
};

template <typename text, typename data>
void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
	//std::cout << std::endl;
}

template <typename text, typename data>
data Input_X(const text& A, const data& B) {
	data cycle{ B };
	std::cout << A;
	std::cin >> cycle;
	return cycle;
}

bool ExitProgram()
{

	char exit_Y_N{};

	do
	{
		//std::cout << std::endl;
		std::cout << "Exit programm (Y/N): ";
		std::cin >> exit_Y_N;
		std::cout << std::endl;

		if (exit_Y_N == 'Y' || exit_Y_N == 'y') {
			return false;
			break;
		}
		else if (exit_Y_N == 'N' || exit_Y_N == 'n') {
			return true;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}

	} while (true);
}

//чтение файла и формирование первичного вектора
class InOutFileVector {

public:

	//чтение файла и формирование первичного вектора
	void OupenFileWriteVector() {
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
	std::vector<std::string> GetVector_1() {

		return in_data_file;
	}

	//ввод вторичного вектора
	std::vector<std::string> SetVector_2(const std::vector < std::string>& a) {

		if (!a.empty()) {
		out_data_file.clear();

			for (const auto& i : a) {
				out_data_file.push_back(i);
			}
		}
		return out_data_file;
	}

	//вывод вторичного вектора
	std::vector<std::string> GetVector_2() {

		return out_data_file;
	}

	void InFileWriteVetor() {

		do {
			std::cout << "Запись данных в файл *.txt" << std::endl;
			std::ofstream  f_oupen(InputTransformWay()); // открыли файл по заданному пути на запись
			if (f_oupen.is_open()) {

				//f_oupen << cel << std::endl;

				for (const auto& i: out_data_file) {
					
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

private:
	int x_line{};
	std::string x_text{};
	std::vector <std::string> in_data_file{};
	std::vector <std::string> out_data_file{};

	//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	std::string InputTransformWay() {
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
};	

//-----------------------------------------

/*Вам дан файл in.txt, в котором находится N адресов. 
Число N идёт первым в файле. 
После числа N располагаются N блоков по 4 строки в каждом. 
Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.
Задача программы заключается в том, чтобы считать адреса из файла in.txt и 
вывести их в файл out.txt в другом формате и в обратном порядке. 
Не забудьте вывести количество адресов в начале.
Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.


3
Москва
Строителей
34
12
Омск
Пушкина
2
13
Новосибирск
Мира
85
64


3
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
Москва, Строителей, 34, 12

*/

class AdressData {

public:

	void OutputConsolVector_2() {

	std::cout << "------------------" << std::endl;
	for (const auto& i : in_out_file_vector.GetVector_2()) {
		std::cout << i << std::endl;
	}
    std::cout << "------------------" << std::endl;

}

	void OutputFileVector_2() {

	in_out_file_vector.InFileWriteVetor();

}
				
	void CreateVector_2() {
	
	_count = 0;

	for (const auto& i : in_out_file_vector.GetVector_1()) {
			
		if (_count > 0) {			

			if (_count < 4) {
				text = text + i + ", ";
			}
			else {
				text = text + i;
			}
			
			if (_count == 4) {

				vector_x.push_back(text);
				_count = 0;
				text = {};

			}
		}
		++_count;
	};
	
	if (!vector_x.empty()) {
		in_out_file_vector.SetVector_2(vector_x);
		vector_x.clear();
	}
}

	void CreateVector_1() {
	in_out_file_vector.OupenFileWriteVector();
}

	void ReversVector_2() {

		std::vector <std::string> vector_var{};

		for (const auto& i : in_out_file_vector.GetVector_2()) {
			vector_var.push_back(i);
		}
		if (!vector_var.empty()) {

			std::reverse(vector_var.begin(), vector_var.end());
			in_out_file_vector.SetVector_2(vector_var);
			vector_var.clear();
		}
	}

	void SortVector2() {

		std::vector <std::string> vector_var{};

		for (const auto& i : in_out_file_vector.GetVector_2()) {
			vector_var.push_back(i);
		}
		if (!vector_var.empty()) {
			std::sort(vector_var.begin(), vector_var.end());

			in_out_file_vector.SetVector_2(vector_var);

			vector_var.clear();
		}
	}

private:
	int _count{0};
	std::string text{};
	InOutFileVector in_out_file_vector;
	std::vector <std::string> vector_x{};
	std::map<std::string, std::string> map_x{};

};

void Task_1() {

	AdressData adressd_data;
	adressd_data.CreateVector_1();
	adressd_data.CreateVector_2();
	adressd_data.ReversVector_2();
	adressd_data.OutputConsolVector_2();
	adressd_data.OutputFileVector_2();
}

/*
Вам дан файл in.txt, в котором находится N адресов. 
Число N идёт первым в файле. 
После числа N располагаются N блоков по 4 строки в каждом. 
Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.
Задача программы заключается в том, чтобы считать адреса из файла in.txt, 
отсортировать их по названию города и вывести отсортированный список адресов 
в файл out.txt в другом формате. Не забудьте вывести количество адресов в начале.
Города должны быть отсортированы в алфавитном порядке.
Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.

5
Москва
Строителей
34
12
Новокузнецк
Науки
5
16
Омск
Пушкина
2
13
Москва
Арбат
4
1
Новосибирск
Мира
85
64

5
Москва, Строителей, 34, 12
Москва, Арбат, 4, 1
Новокузнецк, Науки, 5, 16
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
*/

void Task_2() {

	AdressData adressd_data;
	adressd_data.CreateVector_1();
	adressd_data.CreateVector_2();
	adressd_data.SortVector2();
	adressd_data.OutputConsolVector_2();
	adressd_data.OutputFileVector_2();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		//system("CLS"); //очистка консоли
		std::cout << "\033c";//очистка консоли
		bool exit = true;

		do {

			std::string number_task{ };
			std::cout << "Input numder task (1, 2): ";
			std::cin >> number_task;
			std::cout << std::endl;


			if (number_task == "1" || number_task == "2") {

				switch (stoi(number_task))
				{
				case(static_cast<int>(Task::task_1)):
					Task_1();
					exit = false;
					break;
				case(static_cast<int>(Task::task_2)):
					Task_2();
					exit = false;
					break;
				}
			}
			else {
				std::cout << "Incorrect data!" << std::endl;
				std::cout << std::endl;
				continue;
			}

		} while (exit);

	} while (ExitProgram());
}