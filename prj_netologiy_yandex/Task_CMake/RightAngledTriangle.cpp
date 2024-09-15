#include "RightAngledTriangle.h"
#include "My_exception.h"

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
bool RightAngledTriangle::check() {

	if (!(C == 90)) {
		throw My_Exeception(shablon_text + "угол С не равен 90 град.");
	}
	if (!((A + B + C) == 180)) {
		throw My_Exeception(shablon_text + "сумма углов не равна 180 град.");
	}
	

	return ((C == 90) && ((A + B + C) == 180));
}
