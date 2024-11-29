#include"Task_2.h"

/*
Задача 2. Печать контейнера
Описание
Нужно реализовать шаблонную функцию, которая печатает содержимое контейнера.

Контейнер может быть любым:

std::set
std::vector
std::list

Пример правильной работы программы
std::set<std::string> test_set = { "one", "two", "three", "four" };
print_container(...); // four one three two. помните почему такой порядок? :)

std::list<std::string> test_list = { "one", "two", "three", "four" };
print_container(...); // one, two, three, four

std::vector<std::string> test_vector = { "one", "two", "three", "four" };
print_container(...); // one, two, three, four

*/

template <typename T, typename F>
void print_container(const T& var_x, const F& text) {
	bool first{ false };

	std::cout << std::endl;
	first = true;
	std::cout << text;
	for (const auto& y : var_x) {
		if (first == true) {


			std::cout << y;
			first = false;
		}
		else {
			std::cout << ", " << y;
		}
	}
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << std::endl;


};

void Task_2() {

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set, "Контейнер set: "); // four one three two. помните почему такой порядок? :)

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list, "Контейнер list: "); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector, "Контейнер vector: "); // one, two, three, four

};