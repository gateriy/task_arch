#include "Quadrangle.h"

//четырёхугольник(стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) :
	Figure(a, b, c, d, A, B, C, D)
{
	text_var = "Четырехугольник";
	count = 5;
}
//функция вывода в консоль используется по условиям для 3 задания
void Quadrangle::print_info() {
	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(4);
};
//функция проверки правильности используется по условиям для 3 задания
bool Quadrangle::check() {

	return ((A + B + C + D) == 360);
}