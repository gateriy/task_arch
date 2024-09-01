#include "Triangle.h"
#include "My_exception.h"

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
bool Triangle::check() {

	if (!(A + B + C)) {
		throw My_Exeception(shablon_text + "углы не равны.");
	}
	
	return ((A + B + C) == 180);
}