#include "Rhomb.h"

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

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "Правильная" << std::endl; }
	else { std::cout << "Не правильная" << std::endl; }
	get_var_task_3(4);
};
//функция проверки правильности используется по условиям для 3 задания
bool Rhomb::check() {

	return (a == c && b == d && c == b && A == C && B == D && (A + C) == (B + D));
}