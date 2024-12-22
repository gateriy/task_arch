
#include "Block_3.h"

std::string form_text(const long long int& var, const std::string& format) {
	std::string res{ "" }, var_text{ "" };	

	std::bitset <100> var_2(var);
	var_text = var_2.template to_string<char, std::char_traits<char>, std::allocator<char> >();
	int count = (var_text.size()-1) ;

	for (int i = (format.size()-1); i >=0; --i) {
		
		if (format.at(i) == ' ') {
			res.push_back(' ');
		}
		if (format.at(i) == 'X') {

			if (count >= 0 && count < var_text.size()) {
				res.push_back(var_text.at(count));
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
	long long int var_x{ 0 };
	std::string var_y{ "" };
	char end_x{ ' ' };

	do {

		std::cout << "Ввведите число: ";
		std::cin >> var_x;		

		std::cout << "Ввведите формат представления в виде Х (латиница) и пробел (например, Х ХХ ХХХ): ";
		std::getline(std::cin >> std::ws, var_y);

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Представление: " << form_text(var_x, var_y )<< std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::cout << "Выйти из программы да - 0, нет - любой символ!: ";
		std::cin >> end_x;
		if (end_x == '0') { break; }
	} while (true);

}