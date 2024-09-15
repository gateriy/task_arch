#include "Rectangle.h"
#include "My_exception.h"

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
bool Rectangle::check() {

	if (!(a == c && b == d)) {
		throw My_Exeception(shablon_text + "cтороны a,c и b,d попарно не равны.");
	}
	if (!(A == 90 && B == 90 && C == 90 && D == 90)) {
		throw My_Exeception(shablon_text + "один или несколько углов не равны 90 град.");
	}


	return (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90);
}