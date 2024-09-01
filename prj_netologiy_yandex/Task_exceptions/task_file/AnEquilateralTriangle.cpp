#include "AnEquilateralTriangle.h"
#include "My_exception.h"

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
bool AnEquilateralTriangle::check() {

	if (!((A == 60) && (B == 60) && (C == 60))) {
		throw My_Exeception(shablon_text+"углы не равны 60 град.");
	}
	if (!((a == b) && (a == c) && (b == c))) {
		throw My_Exeception(shablon_text+"длины сторон не равны.");
	}

	return ((A == 60) && (B == 60) && (C == 60) && (a == b) && (a == c) && (b == c));
}