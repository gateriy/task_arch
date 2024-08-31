#include "Task_1.h"

/*
В этом задании вы вынесете математические функции в отдельный файл.
Даны следующие математически функции: сложение, вычитание, умножение, деление, возведение в степень.
Вам нужно разместить их в отдельном файле исходного кода и воспользоваться ими из функции main.
Попросите пользователя ввести два числа и выбрать операцию. Выведите результат ему на консоль.

Пример работы программы
Консоль
Введите первое число: 20
Введите второе число: 2
Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): 5
20 в степени 2 = 400
*/


	double InputVar(std::string text) {
		double var{ 0 };
		std::cout << text;
		std::cin >> var;
		std::cout << std::endl;
		return var;
	}

	int InputOperat(std::string text) {
		double var{ 0 };
		std::cout << text;
		std::cin >> var;
		std::cout << std::endl;
		return var;
	}

	void Mathem_x() {

		double x{ 0 }, y{ 0 }, res{ 0 };
		int oper_var{ 0 };
		bool next{ true };
		std::vector <std::string> text_out{
			"сложить с", "вычесть с", "умножить на", "разделить на", "в степени" };

		x = InputVar("Введите первое число: ");
		y = InputVar("Введите второе число: ");

		do {
		oper_var = InputOperat("Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ");

			switch (oper_var)
			{
			case (1):
				res = x + y;
				next = false;
				break;
			case (2):
				res = x - y;
				next = false;
				break;
			case (3):
				res = x * y;
				next = false;
				break;
			case (4):
				res = x / y;
				next = false;
				break;
			case (5):
				res = pow(x, y);
				next = false;
				break;

			default:
				std::cout << "Не корректные данны. Повторите ввод" << std::endl;
				std::cout <<  std::endl;
				next = true;
				break;
			}
		} while (next);
		std::cout << x <<" "<< text_out[oper_var - 1] <<" " << y << " = " << res << std::endl;
		std::cout << std::endl;

	}

void Task_1() {
	
	Mathem_x();

};
