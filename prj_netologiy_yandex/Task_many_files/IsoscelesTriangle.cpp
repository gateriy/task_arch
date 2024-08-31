#include "IsoscelesTriangle.h"

//равнобедренный треугольник(стороны a и c равны, углы A и C равны);
IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) :
	Triangle(a, b, c, A, B, C)
{
	d = 0;
	D = 0;
	c = a;
	C = A;
	text_var = "Равнобедренный треугольник: ";
	count = 3;
}
//функция вывода в консоль используется по условиям для 3 задания
void IsoscelesTriangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(3);
};
//функция проверки правильности используется по условиям для 3 задания
bool IsoscelesTriangle::check() {

	return ((C == A) && ((A + B + C) == 180) && (a == c));
}