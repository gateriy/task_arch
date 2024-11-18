#include "Task_1.h"

/*
Задача 1. Умный массив
Описание
Вам нужно реализовать умный массив для данных типа int в духе идиомы RAII, 
который сам управляет своей памятью: самостоятельно выделяет её при создании и очищает, 
когда объект данного класса не используется.

Должны быть реализованы следующие функции:

Конструктор, принмающий количество элементов, которое будет хранить массив.
Функция добавления нового элемента в массив. Не забудьте обработать случай, 
когда количество элементов больше количества элементов, на которую выделена память.
Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
Деструктор.
Пример правильной работы программы
Работа с вашим классом должна происходить так:

try {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	arr.add_element(14);
	arr.add_element(15);
	std::cout << arr.get_element(1) << std::endl;
}
catch (const std::exception& ex) {
	std::cout << ex.what() << std::endl;
}
*/

void smart_array::add_element(int x) {
	
	if (count < size_x) {
		array[count] = x;
	}
	else {
		int size_old = size_x;
		size_x = size_x * 2; //использую согласно алгоритмеке и для снижения асимтотики - удвоение массива 
							 //при достижении его размера (!!!)
		int* array_2 = new int[size_x];

		for (int i = 0; i < size_x; ++i) {
			if (i < size_old) {
				array_2[i] = array[i];
			}
			else {
				array_2[i] = 0;
			}
		}

		array_2[count] = x;
		delete[] array;
		array = new int[size_x];

		for (int i = 0; i < size_x; ++i) {			
				array[i] = array_2[i];		
		}
		delete[] array_2;
	}
	++count;
};

int smart_array::get_element(int index) {
	if (index < size_x) {
		return array[index];
	}
	else {
		std::cout << "Overflow index array" << std::endl;
		return -1;
	}
};

int smart_array::get_size_array()  {
	return size_x;
}

int smart_array::get_size_added_array() {
	return count;
}


void Task_1() {
	{
		int yyy{ 0 };
		std::cout << "Введите размер первичного массива: ";
		std::cin >> yyy;

		smart_array arr(yyy);

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Размер первично инициированного массива: " << arr.get_size_array() << std::endl;
		std::cout << std::endl;

		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(1500);
		arr.add_element(1600);
		arr.add_element(1700);

		std::cout << "Введеные програмно данные в массив:"  << std::endl;
		for (int i = 0; i < arr.get_size_added_array(); ++i) {
			std::cout << "Значение (" << i << ") элемента массива: " << arr.get_element(i) << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Размер массива после добавление всех элементов: " << arr.get_size_array() << std::endl;
	}
	std::cout << "Блок закрыт!" << std::endl;
};