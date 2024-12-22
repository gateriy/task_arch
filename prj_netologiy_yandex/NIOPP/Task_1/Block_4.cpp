
#include "Block_4.h"

int graf_x(const std::pair<double, double>& A, const std::pair<double, double>& B, const std::pair<double, double>& C) {

	double X1 = A.first;
	double Y1 = A.second;

	double X2 = B.first;
	double Y2 = B.second;

	double Xx = C.first;
	double Yy = C.second;

	double Y{ 0 }, X{ 0 };

	if ((X1 != X2) && (Y1!=Y2)) {

		Y = (Y2 - Y1) / (X2 - X1) * Xx + Y1 - (Y2 - Y1) / (X2 - X1) * X1;
		X = (Yy - Y1 + (Y2 - Y1) / (X2 - X1) * X1) / ((Y2 - Y1) / (X2 - X1));

		if (Yy == Y) { return 0; }

		if (Y2 > Y1) //восходящая
		{
			if (X < Xx) { return 1; }
			if (X > Xx) { return -1; }
		}
		if (Y2 < Y1) //нисходящая
		{
			if (X > Xx) { return 1; }
			if (X < Xx) { return -1; } 
		}
	}
	if (Y1 == Y2) //горизонтальная линия
	{
		if (X1 < X2) //правое направление
		{
			if (Y1 > Yy) { return 1;  }
			if (Y1 < Yy) { return -1; }
		}
		if (X1 > X2) //левое направление
		{
			if (Y1 > Yy) { return -1; }
			if (Y1 < Yy) { return 1;  }
		}
	}
	if (X1 == X2) {
		if (Y1 < Y2) // направление в верх
		{
			if (X1 > Xx) { return -1; }
			if (X1 < Xx) { return 1; }
		}
		if (Y1 > Y2) // направление в низ
		{
			if (X1 > Xx) { return 1; }
			if (X1 < Xx) { return -1; }
		}
	}   
}


void block_4() {

	std:: pair <int, int> var_a{ 0,0 }, var_b{ 0,0 }, var_c{ 0,0 };
	int var_x{ 0 }, var_y{ 0 }, res{ 0 };
	char end_x{ ' ' };

	do {
		std::cout << "Ввведите координаты точки А: " << std::endl;
		std::cout << "Ввведите X: ";
		std::cin >> var_x;
		std::cout << "Ввведите Y: ";
		std::cin >> var_y;
		var_a = { var_x,var_y };

		std::cout << "Ввведите координаты точки B: " << std::endl;
		std::cout << "Ввведите X: ";
		std::cin >> var_x;
		std::cout << "Ввведите Y: ";
		std::cin >> var_y;
		var_b = { var_x,var_y };

		std::cout << "Ввведите координаты точки C: " << std::endl;
		std::cout << "Ввведите X: ";
		std::cin >> var_x;
		std::cout << "Ввведите Y: ";
		std::cin >> var_y;
		var_c = { var_x,var_y };

		res = graf_x(var_a, var_b, var_c);

		std::cout << "-----------------------------------------" << std::endl;

		if (res == 0) {
			std::cout << "Точка С лежит на заданной прямой: " << "[" << res << "]" << std::endl;
		}
		if (res == -1) {
			std::cout << "Точка С лежит слева от заданной прямой: " << "[" << res << "]" << std::endl;
		}
		if (res == 1) {
			std::cout << "Точка С лежит справа от заданной прямой: " << "[" << res << "]" << std::endl;
		}
	
		std::cout << "-----------------------------------------" << std::endl;

		std::cout << "Выйти из программы да - 0, нет - любой символ!: ";
		std::cin >> end_x;
		if (end_x == '0') { break; }
	} while (true);


}