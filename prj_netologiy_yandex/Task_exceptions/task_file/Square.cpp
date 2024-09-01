#include "Square.h"
#include "My_exception.h"

//квадрат(все стороны равны, все углы равны 90);
Square::Square(double a) :
	Rectangle(a, b)
{
	b = a;
	d = a;
	text_var = "Квадрат: ";
	count = 7;
}
//функция вывода в консоль используется по условиям для 3 задания
void Square::print_info() {
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
bool Square::check() {

	if (!(a == c && b == d && c == b)) {
		throw My_Exeception(shablon_text + "cтороны не равны.");
	}
	if (!(A == 90 && B == 90 && C == 90 && D == 90)) {
		throw My_Exeception(shablon_text + "один или несколько углов не равны 90 град.");
	}

	return (a == c && b == d && c == b && A == 90 && B == 90 && C == 90 && D == 90);
}