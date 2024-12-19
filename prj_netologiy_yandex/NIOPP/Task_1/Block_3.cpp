
#include "Block_3.h"

std::string math_x_2(const int& x, const int& y) {

	int count{ x }, end_x{ 0 };
	std::string res{ "" }, var{ "" };

	if (y > 1 && y <= 16) {
		do {
			var = std::to_string(count % y);
			res.push_back(var.at(0));
			count = count / y;
		} while (count > y);

		var = std::to_string(count % y);
		res.push_back(var.at(0));
	}
	
	std::reverse(res.begin(), res.end());
	return res;
}

std::string form_text(const std::string& text, const std::string& format) {
	std::string res{ "" };
	int count = (text.size()-1) ;

	for (int i = (format.size()-1); i >=0; --i) {
		
		if (format.at(i) == ' ') {
			res.push_back(' ');
		}
		if (format.at(i) == 'X') {

			if (count >= 0 && count < text.size()) {
				res.push_back(text.at(count));
			}
			else {
				res.push_back('0');
			}
			--count;
		}
	}
	std::reverse(res.begin(), res.end());
	return res;
}


void block_3() {
	int var_x{ 0 };
	std::string var_y{ "" };
	char end_x{ ' ' };

	do {

		std::cout << "Ввведите число: ";
		std::cin >> var_x;
		std::cout << "Ввведите формат представления в виде Х (латиница) и пробел (например, Х ХХ ХХХ): ";
		std::getline(std::cin >> std::ws, var_y);

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Представление: " << form_text(math_x_2(var_x, 2), var_y )<< std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::cout << "Выйти из программы да - 0, нет - любой символ!: ";
		std::cin >> end_x;
		if (end_x == '0') { break; }
	} while (true);

}