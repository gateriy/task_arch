#include "Rhomb.h"
#include "My_exception.h"

//ромб(все стороны равны, углы A, C и B, D попарно равны).
Rhomb::Rhomb(double a, double A, double B) :
	Parallelogram(a, b, A, B)
{
	b = a;
	d = b;
	text_var = "Ромб: ";
	count = 9;
}
//функция вывода в консоль используется по условиям для 3 задания
void Rhomb::print_info() {
try{	
	get_var_task_3(count);
	check();
	std::cout << std::endl;
}
catch (const My_Exeception& exp) {
	std::cout << exp.what() << std::endl;
}
catch (...) {
	std::cout << "Не известная ошибка" << std::endl;
}
};
//функция проверки правильности используется по условиям для 3 задания
bool Rhomb::check() {

	if (!(a == c && b == d && c == b)) {
		throw My_Exeception(shablon_text + "cтороны не равны.");
	}
	if (!(A == C && B == D)) {
		throw My_Exeception(shablon_text + "углы A, C и B, D попарно не равны.");
	}
	if (!((A + C) == (B + D))) {
		throw My_Exeception(shablon_text + "суммы углов A, C и B, D попарно не равны.");
	}

	return (a == c && b == d && c == b && A == C && B == D && (A + C) == (B + D));
}