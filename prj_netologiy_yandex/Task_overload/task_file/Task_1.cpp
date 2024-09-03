#include "Task_1.h"



/*

Задача 1. Сравнения в дробях
В этом задании вы переопределите операторы сравнения для дробей.

Дан код на C++:

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
Ваша задача — дописать класс Fraction так, чтобы программа компилировалась и работала корректно.

Пример работы программы

Консоль

f1 not == f2
f1 != f2
f1 not < f2
f1 > f2
f1 not <= f2
f1 >= f2

*/

bool Fraction::operator == (Fraction& new_var) {
	return (numerator_ == new_var.numerator_ && denominator_ == new_var.denominator_);
}
bool Fraction::operator != (Fraction& new_var) {
	return !(*this == new_var);
}
bool Fraction::operator > (Fraction& new_var) {//перегрузка наоборот по условиям задачи !!!!!!
	return numerator_ < new_var.numerator_ && denominator_ < new_var.denominator_;
}
bool Fraction::operator < (Fraction& new_var) {
	return (new_var > *this);
}
bool Fraction::operator >= (Fraction& new_var) {
	return !(*this < new_var);
}
bool Fraction::operator <= (Fraction& new_var) {
	return !(*this > new_var);
}

//Верно, что * - оператор разыменования, неверно, что this - ссылка.
//this - указатель на текущий объект.Таким образом,
//* this - ссылка на текущий объект.


void Task_1() {
	
	Fraction f1(4, 3);
	Fraction f2(6, 11);
	

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	//f2.VVV();
	//f1.VVV();
};