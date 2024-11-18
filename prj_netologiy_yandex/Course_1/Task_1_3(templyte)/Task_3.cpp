#include"Task_3.h"


/*
Задача 3. Счётчик чисел
Описание
В этом задании вам нужно реализовать функтор, 
который подсчитывает сумму и количество чисел, делящихся на 3.

Должны быть реализованы 2 функции:

get_sum()
get_count()

Пример правильной работы программы
[IN]: 4 1 3 6 25 54
[OUT]: get_sum() = 63
[OUT]: get_count() = 3

Можете использовать функцию std::foreach.
*/


void Task_3() {

	bool first{ false };
	{
		my_class <int> arr_x;

		std::vector<int> vect_x{ 4, 1, 3, 6, 25, 54 };
		arr_x(vect_x);


		first = false;
		std::cout << "[IN]: ";
		for (const auto& i : arr_x.get_vector()) {

			if (first == false) {
				std::cout << i;
				first = true;
			}
			else {
				std::cout << ", " << i;
			}
		}
		std::cout << std::endl;
		std::cout << "[OUT]: get_sum() = " << arr_x.get_sum() << std::endl;
		std::cout << "[OUT]: get_count() = " << arr_x.get_count() << std::endl;
		std::cout << "----------------------------------" << std::endl;
	}

	{
		my_class <long int> arr_x;
		std::vector<long int> vect_x{ 40000, 10000, 3000000, 600000000, 250, 540, };
		arr_x(vect_x);


		first = false;
		std::cout << "[IN]: ";
		for (const auto& i : arr_x.get_vector()) {

			if (first == false) {
				std::cout << i;
				first = true;
			}
			else {
				std::cout << ", " << i;
			}
		}
		std::cout << std::endl;
		std::cout << "[OUT]: get_sum() = " << arr_x.get_sum() << std::endl;
		std::cout << "[OUT]: get_count() = " << arr_x.get_count() << std::endl;
		std::cout << "----------------------------------" << std::endl;
	}
	std::cout <<  std::endl;

};