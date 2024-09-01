#include "RightAngledTriangle.h"

//прямоугольный треугольник(угол C всегда равен 90);
RightAngledTriangle::RightAngledTriangle(double a, double b, double c, double A, double B) :
	Triangle(a, b, c, A, B, 90)
{
	d = 0;
	D = 0;
	//C = 90;
	text_var = "Прямоугольный треугольник: ";
	count = 2;
}
//функция вывода в консоль используется по условиям для 3 задания
void RightAngledTriangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(3);
};
//функция проверки правильности используется по условиям для 3 задания
bool RightAngledTriangle::check() {

	return ((C == 90) && ((A + B + C) == 180));
}
