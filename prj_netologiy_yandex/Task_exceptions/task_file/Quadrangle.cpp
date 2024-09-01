#include "Quadrangle.h"
#include "My_exception.h"

//четырёхугольник(стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) :
	Figure(a, b, c, d, A, B, C, D)
{
	text_var = "Четырехугольник: ";
	count = 5;
}
//функция вывода в консоль используется по условиям для 3 задания
void Quadrangle::print_info() {
try{

	get_var_task_3(count);
	check();
}
catch (const My_Exeception& exp) {
	std::cout << exp.what() << std::endl;
}
catch (...) {
	std::cout << "Не известная ошибка" << std::endl;
}
};
//функция проверки правильности используется по условиям для 3 задания
bool Quadrangle::check() {

	if (!((A + B + C + D) == 360)) {
		throw My_Exeception(shablon_text + "суммы углов не равны 360 град.");
	}
	
	return ((A + B + C + D) == 360);
}