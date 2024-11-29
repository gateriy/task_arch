#include "Task_1.h"


/*
Задача 1. Перемещение объектов
Описание
Вам нужно реализовать шаблонную функцию, 
которая перемещает содержимое одного std::vector в другой.

std::vector <std::string> one = { "test_string1", "test_string2" };
std::vector <std::string> two;
move_vectors(...)
*/


template<class T>
T move_vectors(T& var) { return std::move(var); }


void Task_1() {
	
	std::vector <std::string> one = { "test_string1", "test_string2" };
	
	std::cout << "Исходный вектор до перемещения" << std::endl;
	for (const auto& i : one) {
		std::cout << i << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;


	std::vector <std::string> two = move_vectors(one);


	std::cout << "Исходный вектор после перемещения" << std::endl;
	if (one.empty()) {
		std::cout << "Вектор пуст!!!" << std::endl;
	}
	else {
		for (const auto& i : one) {
			std::cout << i << std::endl;
		}
	}
	std::cout << "-------------------------------" << std::endl;

	std::cout << "Перемещенный новый вектор" << std::endl;
	for (const auto& i : two) {
		std::cout << i << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
};