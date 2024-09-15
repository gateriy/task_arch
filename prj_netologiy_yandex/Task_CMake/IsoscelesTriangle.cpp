#include "IsoscelesTriangle.h"
#include "My_exception.h"

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
bool IsoscelesTriangle::check() {

	if (!(C == A)) {
		throw My_Exeception(shablon_text+"два угла A и C не равны.");
	}
	if (!((A + B + C) == 180)) {
		throw My_Exeception(shablon_text + "суммы углов не равны 180 град.");
	}
	if (!(a == c)) {
		throw My_Exeception(shablon_text + "две стороны a и с не равны.");
	}
	

	return ((C == A) && ((A + B + C) == 180) && (a == c));
}