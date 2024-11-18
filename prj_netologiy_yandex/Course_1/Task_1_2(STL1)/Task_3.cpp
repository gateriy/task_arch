#include"Task_3.h"

/*
Задача 3*. Аналог std::vector
Описание
Для лучшего понимания работы std::vector в этом задании вам нужно
написать собственную шаблонную упрощённую реализацию std::vector.

У вашего контейнера должны работать функции:

at(int index) — доступ к элементу контейнера по индексу;
push_back(T value) — размер контейнера неизвестен заранее, вам нужно
правильно увеличивать выделенную память;
size () — количество элементов в контейнере;
capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.
*/

void Task_3() {
	{

		smart_array <double> arr;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Количество действительных элементов массива: " << arr.size() << std::endl;
		std::cout << "Размер массива до нового выделения памяти: " << arr.capacity() << std::endl;
		std::cout << std::endl;


		arr.push_back(4.3);
		arr.push_back(155.3);
		arr.push_back(14.3);
		arr.push_back(15.5);
		arr.push_back(1500.3);
		arr.push_back(1600.3);
		arr.push_back(1700.3);

		std::cout << "Введеные програмно данные в массив:" << std::endl;
		for (int i = 0; i < arr.size(); ++i) {
			std::cout << "Значение (" << i << ") элемента массива: " << arr.at(i) << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Количество действительных элементов массива: " << arr.size() << std::endl;
		std::cout << "Размер массива до нового выделения памяти: " << arr.capacity() << std::endl;
	}

	{

		smart_array <std::string> arr;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Количество действительных элементов массива: " << arr.size() << std::endl;
		std::cout << "Размер массива до нового выделения памяти: " << arr.capacity() << std::endl;
		std::cout << std::endl;


		arr.push_back("один");
		arr.push_back("два");
		arr.push_back("три");
		arr.push_back("четыре");
		arr.push_back("пять");
		arr.push_back("шесть");
		arr.push_back("семь");

		std::cout << "Введеные програмно данные в массив:" << std::endl;
		for (int i = 0; i < arr.size(); ++i) {
			std::cout << "Значение (" << i << ") элемента массива: " << arr.at(i) << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Количество действительных элементов массива: " << arr.size() << std::endl;
		std::cout << "Размер массива до нового выделения памяти: " << arr.capacity() << std::endl;
	}

	{

		smart_array <int> arr;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Количество действительных элементов массива: " << arr.size() << std::endl;
		std::cout << "Размер массива до нового выделения памяти: " << arr.capacity() << std::endl;
		std::cout << std::endl;

		for (int y = 0; y < 50000000; ++y) {
			arr.push_back(y);
			if (y % 1000000 == 0) {
				std::cout << "#";
			}
		}
		std::cout << std::endl;
		std::cout << "Введеные програмно данные в массив:" << std::endl;
		for (int i = 0; i < arr.size(); ++i) {
			if (i % 10000000 == 0) {
				std::cout << "Значение (" << i << ") каждого 10000000-го элемента массива: " << arr.at(i) << std::endl;
			}
		}

		std::cout << std::endl;
		std::cout << "Количество действительных элементов массива: " << arr.size() << std::endl;
		std::cout << "Размер массива до нового выделения памяти: " << arr.capacity() << std::endl;
	}
};