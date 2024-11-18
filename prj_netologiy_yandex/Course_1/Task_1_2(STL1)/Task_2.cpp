#include"Task_2.h"

/*
Задача 2. Удаление дубликатов
Описание
Вам поступают числа из стандартного потока ввода. 
Первым числом вводится количество элементов, далее сами значения.

Нужно вывести все эти числа без дубликатов в порядке убывания.

Пример правильной работы программы
[IN]:
6
1
5
1
3
4
4
[OUT]:
5
4
3
1

*/

void Task_2() {
	int count{ 0 };
	int var{ 0 };
	bool first{ false };
	std::vector <double> vector_x{};


	std::cout << "Введите количество данных: ";
	std::cin >> count;

	for (int i = 0; i < count; ++i) {
		std::cout << "Значение [" << i + 1 << "]: ";
		std::cin >> var;
		vector_x.push_back(var);
	}
	std::cout << std::endl;

	first =true;
	std::cout << "Первичные данные: ";
	for (const auto& y : vector_x) {
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

	sort(vector_x.begin(), vector_x.end());
	vector_x.erase(unique(vector_x.begin(), vector_x.end()), vector_x.end());
	sort(vector_x.begin(), vector_x.end(), [](const auto& a, const auto& b) {return a > b; });

	first = true;
	std::cout << "Преобразованные данные: ";
	for (const auto& y : vector_x) {
		if (first == true) {
			std::cout << y;
			first = false;
		}
		else {
			std::cout <<", " << y;
		}
	}
	std::cout << std::endl;
	std::cout <<"---------------------------" << std::endl;
	std::cout << std::endl;
	
};