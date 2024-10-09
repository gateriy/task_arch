#include"Task_2.h"

/*
Задача 2.
Вам нужно написать функцию, которая принимает на вход отсортированный
массив целых чисел и целое число. Назовём его точкой отсчёта.
Функция должна посчитать количество элементов в массиве, которые больше,
чем переданное в функцию целое число — то есть больше, чем точка отсчёта.
Требуемая алгоритмическая сложность: время O(log2n), дополнительная память O(1).

Затем нужно протестировать написанную функцию.
Точку отсчёта спрашивайте в начале работы программы у пользователя,
а отсортированный массив сделайте автоматическим,
например [14, 16, 19, 32, 32, 32, 56, 69, 72].

Примеры работы программы с массивом [14, 16, 19, 32, 32, 32, 56, 69, 72]

Введите точку отсчёта: 32
Количество элементов в массиве больших, чем 32: 3

Введите точку отсчёта: 15
Количество элементов в массиве больших, чем 15: 8

*/

int If_Count_Arr(int* arr, int size, int var_x) {

	int left = 0;
	int right = size - 1;
	int middle{ 0 };
	//int i{ 0 };

	while (true) {

		middle = (left + right) / 2;

		if (arr[middle] == var_x && arr[middle + 1] > var_x) {
			return (size - 1) - middle;
		}
		
		if (arr[middle] > var_x) {
			right = middle; //ищем слева

			if (right == 0) {
				return  (size);
			}
		}

		if (arr[middle] <= var_x) {
			left = middle; //ищем справа
									
			if (arr[left] <= var_x && arr[left + 1] > var_x) {
				return (size - 1) - left;
			}

			if ((left + 1) == (size - 1)) {
				return 0;
			}
		}
		//std::cout << left<< "<< " << middle << " >>" << right <<" --- " <<++i << std::endl;
	}	
}



void Task_2() {

	int arr_x[] { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int var{ 0 };

	std::cout <<"Введите точку отсчёта: ";
	std::cin >> var;
	std::cout << std::endl;

	std::cout << "Количество элементов в массиве больших, чем " << var << ": "
		<< If_Count_Arr(arr_x, sizeof(arr_x) / sizeof(arr_x[0]),var) << std::endl;

	std::cout <<   std::endl;


};