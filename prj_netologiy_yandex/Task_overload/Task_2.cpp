#include "Task_2.h"
#include "AllConfigTask.h"

/*

Задача 2. Остальные операции с дробями
В этом задании вы переопределите остальные операторы для класса дроби.

Необходимо переопределить операторы для класса Fraction из предыдущего задания:

сложение;
вычитание;
умножение;
деление;
унарный минус;
инкремент постфиксный и префиксный;
декремент постфиксный и префиксный.
Продемонстрируйте работу ваших операторов. Попросите пользователя ввести две дроби и покажите результат каждой операции. Операции декремента и инкремента отнимают и прибавляют к дроби 1 соответственно.

Составьте выражения, содержащие постфиксный и префиксный инкремент и декремент, чтобы продемонстрировать разницу между постфиксной и префиксной версиями.

Пример работы программы
Консоль

Введите числитель дроби 1: 3
Введите знаменатель дроби 1: 4
Введите числитель дроби 2: 4
Введите знаменатель дроби 2: 5

3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
Значение дроби 1 = 7/4
7/4-- * 4/5 = 7/5
Значени дроби 1 = 3/4

*/

std::pair<int, int> Fraction2::VarNod(int& x, int& y) {
	int nod{ std::gcd(abs(x), abs(y)) };
	x = x / nod;
	y = y / nod;
	return { x,y };
}

std::pair<int, int> Fraction2:: GetVarFraction() {
	return { numerator_,denominator_ };
}

int InputVar(const std::string& text) {
	int B{ 0 };
	std::cout << text;
	std::cin >> B;
	return B;
}

std::string Output(const std::string& A_1, const  int& B_1, const std::string& A_2, const  int& B_2) {
	
	std::string text{};
	text = A_1+ std::to_string(B_1) + A_2 + std::to_string(B_2);
	return text;
};

void Task_2() {
	
	int num_1{ InputVar("Введите числитель дроби 1: ")   };
	int den_1{ InputVar("Введите знаменатель дроби 1: ") };
	int num_2{ InputVar("Введите числитель дроби 2: ")   };
	int den_2{ InputVar("Введите знаменатель дроби 2: ") };
std::cout << std::endl;	

	Fraction2 f1(num_1, den_1);
	Fraction2 f2(num_2, den_2);

std::cout << Output("Значение дроби 1 = ", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) << std::endl;
std::cout << Output("Значение дроби 2 = ", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) << std::endl;
std::cout << std::endl;

	Fraction2 f3 = f1 + f2;
	Fraction2 f4 = f1 - f2;
	Fraction2 f5 = f1 * f2;
	Fraction2 f6 = f1 / f2;

std::cout << Output("", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) <<
" + " << Output("", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) <<
" = " << Output("", f3.GetVarFraction().first, "/", f3.GetVarFraction().second) << std::endl;

std::cout << Output("", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) <<
" - " << Output("", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) <<
" = " << Output("", f4.GetVarFraction().first, "/", f4.GetVarFraction().second) << std::endl;

std::cout << Output("", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) <<
" * " << Output("", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) <<
" = " << Output("", f5.GetVarFraction().first, "/", f5.GetVarFraction().second) << std::endl;

std::cout << Output("", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) <<
" / " << Output("", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) <<
" = " << Output("", f6.GetVarFraction().first, "/", f6.GetVarFraction().second) << std::endl;
std::cout << std::endl;

std::cout << Output("++", f1.GetVarFraction().first, "/", f1.GetVarFraction().second);

	Fraction2 f8 = ++f1 * f2;

std::cout << " * " << Output("", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) <<
" = " << Output("", f8.GetVarFraction().first, "/", f8.GetVarFraction().second) << std::endl;
std::cout << Output("Значение дроби 1 = ", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) << std::endl;

std::cout << Output("", f1.GetVarFraction().first, "/", f1.GetVarFraction().second);

	Fraction2 f9 = f1-- * f2;

std::cout << "-- * " << Output("", f2.GetVarFraction().first, "/", f2.GetVarFraction().second) <<
" = " << Output("", f9.GetVarFraction().first, "/", f9.GetVarFraction().second) << std::endl;
std::cout << Output("Значение дроби 1 = ", f1.GetVarFraction().first, "/", f1.GetVarFraction().second) << std::endl;
std::cout << std::endl;

};