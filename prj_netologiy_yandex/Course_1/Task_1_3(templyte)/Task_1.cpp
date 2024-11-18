#include "Task_1.h"



/*
Задача 1. Возведение в квадрат
Описание
Нужно реализовать шаблонную функцию возведения в квадрат, 
которая работает не только с простыми числами, но и с векторами. 
Для этого создайте две реализации шаблонной функции.

Пример правильной работы программы
[IN]: 4
[OUT]: 16
[IN]: -1, 4, 8
[OUT]: 1, 16, 64
*/

template < typename var >
var square(var var_x) {
	return var_x * var_x;

};

template <typename var>
std::vector<var> square(std::vector<var> var_x) {

	std::vector<var> res;

	for (const auto& i : var_x) {
		res.push_back(i * i);
	}
	return res;
}

template <typename var_T, typename vector_T>
void output_res(const var_T& var_y, const std::vector<vector_T>& vector_x) {
	bool first{ true };

	std::cout << "[IN]:\t" << var_y << std::endl;
	std::cout << "[OUT]:\t" << square(var_y) << std::endl;

	first = true;
	std::cout << "[IN]:\t";
	for (const auto& i : vector_x) {
		if (first) {
			std::cout << i;
		}
		else {
			std::cout << ", " << i;
		}
		first = false;
	}
	std::cout << std::endl;

	first = true;
	std::cout << "[OUT]:\t";
	for (const auto& i : square(vector_x)) {
		if (first) {
			std::cout << i;
		}
		else {
			std::cout << ", " << i;
		}
		first = false;
	}
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;

}

void Task_1() {

	std::cout << "type - int:" << std::endl;
	int var_y1{ 0 };
	std::vector <int> vector_x1{};

	var_y1 = 5;
	vector_x1 = { 1, 2, 3, 4, 5 };
	output_res(var_y1, vector_x1);


	std::cout << "type - double:" << std::endl;
	double var_y2{ 0 };
	std::vector <double> vector_x2{};

	var_y2 = 5.5;
	vector_x2 = { 1.1, 2.2, 3.3, 4.3, 5.5 };
	output_res(var_y2, vector_x2);


	std::cout << "type - long int:" << std::endl;
	long int var_y3{ 0 };
	std::vector <long int> vector_x3{};

	var_y3 = 5500;
	vector_x3 = { 1, 2, 3, 40000, 5000 };
	output_res(var_y3, vector_x3);

};