#include "Parallelogram.h"

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

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(4);
};
//функция проверки правильности используется по условиям для 3 задания
bool Parallelogram::check() {

	return (a == c && b == d && (a + c) == (b + d) && A == C && B == D && (A + C) == (B + D));
}