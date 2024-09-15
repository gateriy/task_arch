#include "Figure.h"
#include "My_exception.h"

Figure::Figure() {};
Figure::Figure(double a, double b, double c, double d, double A, double B, double C, double D) :
	a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
{}
//функция вывода в консоль используется по условиям для 2 задания
void Figure::print_info() {

	std::cout << text_var << " (Стороны: 0 Углы: 0) " << "Создан!" << std::endl;;

};
//функция проверки правильности используется по условиям для 2 задания
bool Figure::check() { return true; };
void Figure::get_var_task_3(int number_of_sides) {

	//std::cout << "Количество сторон: " << number_of_sides << std::endl;
	std::cout << std::endl;


	if (number_of_sides >= 1 && number_of_sides < 5) {
		std::cout << text_var << "(Стороны: а = " << a << " b = " << b << " c = " << c <<
			" Углы: A = " << A << " B = " << B << " C = " << C << ") Создан!" << std::endl;;
	}
	if (number_of_sides >= 5 && number_of_sides <= 9) {
		std::cout << text_var << "(Стороны: а = " << a << " b = " << b << " c = " << c << " d = " << d <<
			" Углы: A = " << A << " B = " << B << " C = " << C << " D = " << D << ") Создан!" << std::endl;;
	}
	//std::cout << std::endl;
}