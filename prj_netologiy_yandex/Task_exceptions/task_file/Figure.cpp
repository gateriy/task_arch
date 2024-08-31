#include "Figure.h"

Figure::Figure() {};
Figure::Figure(double a, double b, double c, double d, double A, double B, double C, double D) :
	a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
{}
//функция вывода в консоль используется по условиям для 2 задания
void Figure::print_info() {

	std::cout << text_var << std::endl;

	if (check() == true) {
		std::cout << "Правильная" << std::endl;
	}
	else {
		std::cout << "Не правильная" << std::endl;
	}
	std::cout << "Количество сторон: 0" << std::endl;
	std::cout << std::endl;
};
//функция проверки правильности используется по условиям для 2 задания
bool Figure::check() { return true; };
void Figure::get_var_task_3(int number_of_sides) {

	std::cout << "Количество сторон: " << number_of_sides << std::endl;

	if (count >= 1 && count < 5) {
		std::cout << "Стороны: а = " << a << " b = " << b << " c = " << c << std::endl;
		std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << std::endl;
	}
	if (count >= 5 && count <= 9) {
		std::cout << "Стороны: а = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
		std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << " D = " << D << std::endl;
	}
	std::cout << std::endl;
}