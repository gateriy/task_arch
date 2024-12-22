
#include "Block_2.h"


std::string math_x(const long long int& x, const int& y) {

	long long int count{ x }, end_x{ 0 };
	std::string res{ "" },  var{""};

	if (y > 1 && y <= 36) {
	
		while (count > 0) {
			end_x = count % y;

			if (end_x < 10) {
				res += (end_x + '0');
			}
			else {
				res += (end_x - 10 + 'A');
			}
			count /= y;
		}
	}
	else { "Некоректная система счистления!"; }

	std::reverse(res.begin(), res.end());

	return res;
}

void block_2() {
	long long int var_x{ 0 }, var_y{ 0 };
	char end_x{ ' ' };
	

	do {

		std::cout << "Ввведите число: ";
		std::cin >> var_x;
		std::cout << "Ввведите число системы счислени (от 2 до 36): ";
		std::cin >> var_y;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Система счисления: " << var_y << std::endl;
		std::cout << "Значение: " << math_x(var_x,var_y) << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::cout << "Выйти из программы да - 0, нет - любой символ!: ";
		std::cin >> end_x;
		if (end_x == '0') { break; }
	} while (true);


}