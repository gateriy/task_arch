#include "Square.h"

//квадрат(все стороны равны, все углы равны 90);
Square::Square(double a) :
	Rectangle(a, b)
{
	b = a;
	d = a;
	text_var = "Квадрат: ";
	count = 7;
}
//функция вывода в консоль используется по условиям для 3 задания
void Square::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(4);
};
//функция проверки правильности используется по условиям для 3 задания
bool Square::check() {

	return (a == c && b == d && c == b && A == 90 && B == 90 && C == 90 && D == 90);
}