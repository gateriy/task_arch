#ifndef READ_FILE_H
#define READ_FILE_H

#include "Config.h"

/*
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
*/

class My_Exception1 : public std::exception {
public:
	My_Exception1(const char* message) : message_(message) {}

	const char* what() const noexcept { return message_; }
private:
	const char* message_;
};

//чтение файла ini по строчно и формирование первичного вектора строк
class ReadFileInVector {

public:

	ReadFileInVector() {
		_InputTransformWay();
		_OupenFileWriteVector();
	}

	ReadFileInVector(const std::string& way_file) {
		this->_way_file = way_file;
		_InputTransformWay_2(_way_file);
		_OupenFileWriteVector();
	}

	~ReadFileInVector() {};

	//заполнение вторичного вектора
	//std::vector<std::string> SetVector_2(const std::vector < std::string>& a);

	//вывод первичного вектора
	//std::vector<std::string> GetVector_1();

	//вывод вторичного вектора
	//std::vector<std::string> GetVector_2();

	//запись данных вторичного вектора в файл
	//bool InFileWriteVetor();

protected:
	//524288000
	const int _MAX_SISE_V { 524288000 };        //заданный максимальны размер первичного вектора в байт
	int _x_line{};								//подсчет строк в файле
	std::string _x_text{}, _way_file{}, _way{};	//переменная строки, путь к файлу
	std::vector <std::string> _in_data_file{};	//вектор строк из файла
	std::vector <std::string> _out_data_file{};	//вектор строк после обработки (вторичный)

	//чтение файла и формирование первичного вектора
	bool _OupenFileWriteVector();

	//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	void _InputTransformWay() noexcept;

	//второй вариан преобразование пути к файлу / или \ в "\\" по переданной переменной
	void _InputTransformWay_2(const std::string& way_text) noexcept;
};

class ParsingIni : public ReadFileInVector {
public:
	
	ParsingIni() {};

	ParsingIni(const std::string& way_file) : ReadFileInVector ( way_file){	};

	~ParsingIni() {};
	
	//находит переменную по запросу и выдает ее значение и тип на основе анализа структуры переменной в виде string
	std::pair<std::string, std::string> Str_Value_Type(const std::string& text_var) noexcept;

	template<typename Y>
	const Y Get_Value(const std::string& var) {

		Str_Value_Type(var);
		if (_valu_type.second == "int") {
			auto res = std::stoll(_valu_type.first);
			return res;
		}
		else
			if (_valu_type.second == "double") {
				auto res = std::stold(_valu_type.first);
				return res;
			}
			else throw My_Exception1("An attempt to convert an unknown variable type!");

	}

	template<>
	const std::string Get_Value(const std::string& var) {
		
		Str_Value_Type(var);

		if (_valu_type.second == "string") {
			auto res = std::move(_valu_type.first);
			return res;
		}
		else throw My_Exception1("An attempt to convert an unknown variable type!");
	}
		
private:

	std::pair<std::string, std::string> _section_var;
	std::pair<std::string, std::string> _valu_type{};

	//преобразование переменных секции и перееменной из переданной строки
	void _ReadVar(const std::string& a) noexcept;
	
	//формирует название и значение переменной в строковом формате
	std::pair <std::string, std::string> _Read_String(const std::string& var_str) noexcept;

	//определяет возможный тип переменной на основе анализа данных по строке (string, int, double)
	std::string _Var_Type(const std::string& var) noexcept;

	//удаление пробелов в названии секций
	void _Transform_Section() noexcept;
};

void block_1();

void block_2();

#endif;