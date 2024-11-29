#ifndef READ_FILE_H
#define READ_FILE_H

#include "Config.h"

template <typename text, typename data>
class Input_Output_Var
{
public:

	data InputVar(const text& A, const  data& B) {
		auto var = B;
		std::cout << text;
		std::cin >> var;
		return var;
	}

	void Output(const int& _first, const text& A, const  data& B, const text& C, const  data& D, const int& _end, const int& color) {

		for (int i = 0; i < _first; ++i) {
			std::cout << std::endl;
		}
			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		std::cout << A << B << C << D;

		for (int i = 0; i < _end; ++i) {
			std::cout << std::endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
private:

};


//чтение файла ini по строчно и формирование первичного вектора строк
class ReadFileInVector {

public:

	//чтение файла и формирование первичного вектора
	bool OupenFileWriteVector();

	//заполнение вторичного вектора
	std::vector<std::string> SetVector_2(const std::vector < std::string>& a);

	//вывод первичного вектора
	std::vector<std::string> GetVector_1();

	//вывод вторичного вектора
	std::vector<std::string> GetVector_2();

	//запись данных вторичного вектора в файл
	bool InFileWriteVetor();

private:
	int _x_line{};								//подсчет строк в файле
	std::string _x_text{};						//переменная строки
	std::vector <std::string> _in_data_file{};	//вектор строк из файла
	std::vector <std::string> _out_data_file{};	//вектор строк после обработки (вторичный)

	//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	std::string InputTransformWay();
};




void block_1();

#endif;