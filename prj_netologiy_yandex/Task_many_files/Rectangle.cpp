#include "Rectangle.h"

//прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
Rectangle::Rectangle(double a, double b) :
	Quadrangle(a, b, c, d, A, B, C, D)
{
	c = a;
	d = b;
	C = 90;
	A = 90;
	B = 90;
	D = 90;
	text_var = "Прямоугольник: ";
	count = 6;
}
//функция вывода в консоль используется по условиям для 3 задания
void Rectangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(4);
};
//функция проверки правильности используется по условиям для 3 задания
bool Rectangle::check() {

	return (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90);
}