#include "Triangle.h"

//треугольник(стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
Triangle::Triangle(double a, double b, double c, double A, double B, double C) :
	Figure(a, b, c, 0, A, B, C, 0)
{
	//d = 0;
	//D = 0;
	text_var = "Треугольник: ";
	count = 1;
}
//функция вывода в консоль используется по условиям для 3 задания
void Triangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(3);
};
//функция проверки правильности используется по условиям для 3 задания
bool Triangle::check() {

	return ((A + B + C) == 180);
}