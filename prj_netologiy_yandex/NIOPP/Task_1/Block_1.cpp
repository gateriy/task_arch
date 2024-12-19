
#include "Block_1.h"
#include "Config.h"


std::string name_generat(const bool workshop_a, const bool workshop_b, const bool workshop_c) {

	int count{ 0 };

	if (workshop_a == true) { ++count; }
	if (workshop_b == true) { ++count; }
	if (workshop_c == true) { ++count; }

	if (count == 1) {
		return "Генератор Y включен!";
	} else 
		if (count == 2) {
			return "Генератор X включен!";
		} else
			if (count == 3) {
				return "Генератор X и Y включен!";
			} else return "Все генераторы выключены!";	
}


void block_1() {

	char end_x{ ' ' }, workshop_in{ ' ' };
	bool work_a{ false }, work_b{ false }, work_c{ false };

	do {

		std::cout << "Ввведите запрос цеха А (0 - выкл, 1 - вкл): ";
		std::cin >> workshop_in;
		if (workshop_in == '1') {
			work_a = true;
		}
		else { work_a = false; }

		std::cout << "Ввведите запрос цеха В (0 - выкл, 1 - вкл): ";
		std::cin >> workshop_in;
		if (workshop_in == '1') {
			work_b = true;
		}
		else { work_b = false; }

		std::cout << "Ввведите запрос цеха С (0 - выкл, 1 - вкл): ";
		std::cin >> workshop_in;
		if (workshop_in == '1') {
			work_c = true;
		}
		else { work_c = false; }

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "В настоящее время в работе: " << std::endl;
		std::cout << name_generat(work_a, work_b, work_c) << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::cout << "Выйти из программы да - 0, нет - любой символ!: ";
		std::cin >> end_x;
		if (end_x == '0') { break; }
	} while (true);


}