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

	ReadFileInVector() {
		InputTransformWay();
		OupenFileWriteVector();
	}

	ReadFileInVector(const std::string& way_file) {
		this->_way_file = way_file;
		InputTransformWay_2(_way_file);
		OupenFileWriteVector();
	}

	~ReadFileInVector() {};

	//заполнение вторичного вектора
	std::vector<std::string> SetVector_2(const std::vector < std::string>& a);

	//вывод первичного вектора
	std::vector<std::string> GetVector_1();

	//вывод вторичного вектора
	std::vector<std::string> GetVector_2();

	//запись данных вторичного вектора в файл
	bool InFileWriteVetor();

protected:
	int _x_line{};								//подсчет строк в файле
	std::string _x_text{}, _way_file{}, _way{};	//переменная строки, путь к файлу
	std::vector <std::string> _in_data_file{};	//вектор строк из файла
	std::vector <std::string> _out_data_file{};	//вектор строк после обработки (вторичный)

	//чтение файла и формирование первичного вектора
	bool OupenFileWriteVector();

	//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	void InputTransformWay();

	//второй вариан счиывания пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	void InputTransformWay_2(const std::string& way_text);
};


class ParsingIni : public ReadFileInVector {
public:
	
	ParsingIni() {};

	ParsingIni(const std::string& way_file) : ReadFileInVector ( way_file){	};

	~ParsingIni() {};
	
	std::pair<std::string, std::string> Str_Value_Type(const std::string& text_var);


	template<typename Y,typename X>
	Y Get_Value( const X var) {
		//std::pair<std::string, std::string> _valu_type = var;
		Str_Value_Type(var);
		//auto res{};

	
			if (_valu_type.second == "int") {
				auto res = std::stoll(_valu_type.first);
				//std::cout << "[" << res << "]" << typeid(res).name() << "[" << _valu_type.second << "]" << std::endl;
				return res;
			}
			else
				if (_valu_type.second == "double") {
					auto res = std::stold(_valu_type.first);
					//std::cout << "[" << res << "]" << typeid(res).name() << "[" << _valu_type.second << "]" << std::endl;
					return res;
				}
				else 		
					if (_valu_type.second == "string") {
					auto res = std::move( _valu_type.first);
					//std::cout << "[" << res << "]" << typeid(res).name() << "[" << _valu_type.second << "]" << std::endl;
					return res;
				} else { return 0; }
				
		//std::string res = _valu_type.first;
		//return res;

	}


/*
	 template<typename T, typename X>
	 T Convert_Data(std::string& var) {
		 T res;

		 if (_type_x == "int") {
			 res = std::stoll(var);
		 }
		 else
			 if (_type_x == "double") {
				 res = std::stold(var);
			 }
			 else res = var;

		 return res;
		 //return var;
	 }
	*/

private:

	std::pair<std::string, std::string> _section_var;
	void _ReadVar(const std::string& a);
	std::pair<std::string, std::string> _valu_type{};


	//формирует название и значение переменной в строковом формате
	std::pair <std::string, std::string> _Read_String(const std::string& var_str);

	//определяет возможный тип переменной на основе анализа данных по строке (string, int, double)
	std::string _Var_Type(const std::string& var);

	


	/*
	template<class X>
	X ConvertVar(std::string text){

		std::string name{}, var{};
		X res{};
		bool first = true;
		bool var_string = false;
		bool var_long = false;
		bool var_double = false;
		int count_point{ 0 }, count_min{ 0 };

		for (const auto& i : var_str) {
			if (i != ';') {

				if (first == false){ var = var + i; }

				if (i != '=' && first == true) {
					name = name + i;
				}
				else { first = false;}
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

			first = false;

		for (const auto& i : var) {

			for (const char& f : { '-','0','1','2','3','4','5','6','7','8','9','0','.' }) {

				if (i != f) { 
					var_string = true;
					break; 
				}
				else {
					if (i == '.') {
						++count_point;
					}
					if (i == '-') {
						++count_min;
					}
				}
			}
		}

		if (count_min == 0 || (count_min == 1 && var.at(0) == '-')) {

			if (count_point == 1) {
				var_double = true;
			}
			else if (count_point == 0) {
				var_long = true;
			}
			else {
				var_string = true;
			}
		}
		else {
			var_string = true;
		}

		if (var_string == true) {
			res = var;
		}
		else if (var_long == true) {
			res = static_cast<long int> (var);
		}
		else if (var_double = true) {
			res = static_cast<double> (var);
		}
		return { {name},{res} };
	}
	*/


};


void block_1();

#endif;