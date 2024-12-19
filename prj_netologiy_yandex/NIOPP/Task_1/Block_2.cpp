
#include "Block_2.h"


std::string math_x(const int& x, const int& y) {

	int count{ x }, end_x{ 0 };
	std::string res{ "" },  var{""};

	if (y > 1 && y <= 16) {
		do {
			
			var = std::to_string(count % y);
			if (var == "10") { var = "A"; }
			if (var == "11") { var = "B"; }
			if (var == "12") { var = "C"; }
			if (var == "13") { var = "D"; }
			if (var == "14") { var = "E"; }
			if (var == "15") { var = "F"; }

			res.push_back(var.at(0));
			count = count / y;

		} while (count > y);

		var = std::to_string(count % y);
		res.push_back(var.at(0));
	}
	else { "Некоректная система счистления!"; }

	std::reverse(res.begin(), res.end());

	return res;
}

void block_2() {
	int var_x{ 0 }, var_y{ 0 };
	char end_x{ ' ' };
	

	do {

		std::cout << "Ввведите число: ";
		std::cin >> var_x;
		std::cout << "Ввведите число системы счислени (от 2 до 16): ";
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