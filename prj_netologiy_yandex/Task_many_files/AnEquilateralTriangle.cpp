#include "AnEquilateralTriangle.h"

//равносторонний треугольник(все стороны равны, все углы равны 60);
AnEquilateralTriangle::AnEquilateralTriangle(double a) :
	Triangle(a, b, c, A, B, C)
{
	c = a;
	b = a;
	C = 60;
	A = 60;
	B = 60;
	text_var = "Равносторонний треугольник: ";
	count = 4;
}
//функция вывода в консоль используется по условиям для 3 задания
void AnEquilateralTriangle::AnEquilateralTriangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(3);
};
//функция проверки правильности используется по условиям для 3 задания
bool AnEquilateralTriangle::check() {

	return ((A == 60) && (B == 60) && (C == 60) && (a == b) && (a == c) && (b == c));
}