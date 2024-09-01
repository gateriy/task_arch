#include "Task_1.h"


/*
Задача 1. Простое исключение
В этом задании вы попробуете выбросить и обработать исключение.
Создайте функцию int function(std::string str, int forbidden_length). 
Эта функция должна возвращать длину переданной строки, если эта длина 
не равна значению переданного параметра forbidden_length. 
В противном случае она должна выбрасывать исключение bad_length.

Для проверки функции организуйте работу с пользователем. 
В начале задайте запретную длину, а затем считывайте пользовательские 
строки и выводите их длину до тех пор, пока пользователь не введёт строку запретной длины. 
После этого сообщите ему, что он ввёл строку запретной длины, и завершите программу.

Пример работы программы Консоль

Введите запретную длину: 5
Введите слово: Привет
Длина слова "Привет" равна 6
Введите слово: мир
Длина слова "мир" равна 3
Введите слово: пирог
Вы ввели слово запретной длины! До свидания

---Что использовать для решения.---
Для вычисления длины строки используйте метод класса std::string — length.
Для создания исключения используйте ключевое слово throw.
Для ожидания исключения используйте ключевое слово try.
Для обработки исключения используйте ключевое слово catch.
*/



int function(const std::string& str, const int& forbidden_length) {
		
	if (forbidden_length != (str.length())) {
		return static_cast<int>(str.length());
	}
	else {
		throw My_Exeception("Вы ввели слово запретной длины! До свидания");
	};
}

int StringToInt(const std::string& text_var) {
	
	std::string simbol{ "0123456789 "};
	std::string var_t{""};
	bool err{ false };

	for (const char& i : text_var) {
		err = false;		 
		for (const char& simvol_x : simbol) {

			if (i == simvol_x) { 
				var_t = var_t + i;
				err = true;
			}
		}
			if (err == false) {
				throw My_Exeception("Вы ввели не целочисленный символ! До свидания");
			}
	}
	return std::stoi(var_t);
}

void Task_1() {
		std::string size_text{};
		std::string text{};	
		int s_text{ 0 }, x_var{ 0 };
	try
	{			
		std::cout << "Введите запретную длину: ";
		std::cin >> size_text;
		s_text = StringToInt(size_text);
		std::cout << std::endl;


		do {
			std::cout << "Введите слово: ";
			std::cin >> text;
			x_var = function(text, s_text);
			std::cout << "Длина слова " << text << " равна " << x_var << std::endl;
		} while (true);
		
	}
	catch (const My_Exeception& exp) {	
		std::cout << std::endl;
		std::cout << exp.what() << std::endl; }

	catch (...) { 
		std::cout << std::endl;
		std::cout << "Не известная ошибка" << std::endl; }

};