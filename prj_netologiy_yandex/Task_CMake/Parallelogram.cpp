#include "Parallelogram.h"
#include "My_exception.h"

//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
Parallelogram::Parallelogram(double a, double b, double A, double B) :
	Quadrangle(a, b, c, d, A, B, C, D)
{
	c = a;
	d = b;
	C = A;
	D = B;
	text_var = "Параллелограмм: ";
	count = 8;
}
//функция вывода в консоль используется по условиям для 3 задания
void Parallelogram::print_info() {

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
bool Parallelogram::check() {

	if (!(a == c && b == d)) {
		throw My_Exeception(shablon_text + "cтороны a,c и b,d попарно не равны.");
	}
	if (!((a + c) == (b + d))) {
		throw My_Exeception(shablon_text + "суммы длин сторон a,c и b,d не равны.");
	}
	if (!(A == C && B == D)) {
		throw My_Exeception(shablon_text + "углы A,C и B,D попарно не равны.");
	}
	if (!((A + C) == (B + D))) {
		throw My_Exeception(shablon_text + "суммы углов A,C и B,D  не равны.");
	}


	return (a == c && b == d && (a + c) == (b + d) && A == C && B == D && (A + C) == (B + D));
}