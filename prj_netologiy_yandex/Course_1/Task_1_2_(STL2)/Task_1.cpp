#include "Task_1.h"



/*
Задача 1. Уникальный вектор
Описание
Нужно реализовать функцию, которая удаляет все дубликаты, 
а не только подряд идущие, из std::vector.

Пример правильной работы программы
[IN]: 1 1 2 5 6 1 2 4
[OUT]: 1 2 4 5 6
*/

template <typename T, typename F>
void print_container_1(const T& var_x, const F& text) {
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

template<typename T>
std::vector <T> unique_vector(std::vector<T>& vec_x) {

	auto it_begin_x = vec_x.begin();
	auto it_end_x = vec_x.end();

	sort(it_begin_x, it_end_x);
	vec_x.erase(unique(it_begin_x, it_end_x), it_end_x);
	
	return vec_x;
}

void Task_1() {

	std::vector<int> vector_x = { 1, 1, 2, 5, 6, 1, 2, 4 };
	print_container_1(vector_x, "[IN]: ");
	print_container_1(unique_vector(vector_x), "[OUT]: ");

};