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
	double x =  static_cast<double>(numerator_) / static_cast<double>(denominator_) ;
	double y = static_cast<double>(new_var.numerator_) / static_cast<double>(new_var.denominator_) ;
	return ((abs(x - y)) <= std::numeric_limits<double>::epsilon());
}
bool Fraction::operator != (Fraction& new_var) {
	return !(*this == new_var);
}
bool Fraction::operator > (Fraction& new_var) {
	double x = static_cast<double>(numerator_) / static_cast<double>(denominator_);
	double y = static_cast<double>(new_var.numerator_) / static_cast<double>(new_var.denominator_);
	return ((abs(x - y) > std::numeric_limits<double>::epsilon()) && (x > y));
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

std::pair<int, int> Fraction::GetVarFraction() {
	return { numerator_,denominator_ };
}



//Верно, что * - оператор разыменования, неверно, что this - ссылка.
//this - указатель на текущий объект.Таким образом,
//* this - ссылка на текущий объект.

void Task_1() {
	
	Fraction f1(4, 3);
	Fraction f2(8, 6);

	std::cout << "Значение дроби 1 = " << f1.GetVarFraction().first << "/" << f1.GetVarFraction().second << std::endl;
	std::cout << "Значение дроби 2 = " << f2.GetVarFraction().first << "/" << f2.GetVarFraction().second << std::endl;

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

};