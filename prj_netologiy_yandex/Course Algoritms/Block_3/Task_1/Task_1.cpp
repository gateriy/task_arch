#include "Task_1.h"

/*
Нужно написать функцию с сигнатурой void quick_sort(int* arr, int size), 
которая принимает на вход массив целых чисел и его размер. 
Функция должна отсортировать полученный массив методом «быстрая сортировка».

Затем нужно протестировать написанную функцию. Для проверки используйте массивы:

3 43 38 29 18 72 57 61 2 33;
88 91 87 59 53 49 29 16 4 27 28 89 2 25 74;
24 66 20 79 30 16 19 62 94 59 0 7 59 90 84 60 95 62.

Выведите на экран массив до и после сортировки.
*/


int quick_sort(int* arr, int size) {

	int left{ 0 };
	int right{ 0 };
	int pivot{ 0 };
	int count{ 0 };
	int count_2{ 0 };
	int count_3{ 0 };
	int exit_x{ 1 };
	std::string str{ "" };
	
	while (exit_x != 0 ) {
		++count_3;
		left = 0;
		right = size - 1;

		if (count <= (size - 2)) {
			++count;
		}
		else {
			count = 1;
			exit_x = 0;
			++count_2;
		}

		str = "Отсортированный массив (опорных циклов " + std::to_string(count_3) +"):     ";
		for (int i = 0; i < size; ++i) {
			str = str + std::to_string(arr[i]) + " ";
		}
		std::cout << str;
		std::cout << std::string(str.length(), '\b');
		Sleep(300);
		
		pivot = arr[count];

		while (true) {

			while (arr[left] < pivot) {
				++left;
			}
			while (arr[right] > pivot) {
				--right;
			}

			if (left >= right) { 
				break;
			} else {
				std::swap(arr[right], arr[left]);
				++left;
				--right;	
				++exit_x;
			}
		}
	}
	return count_2;
}

void Task_1() {
	int cikl{ 0 };

	int arr_1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr_2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr_3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	int size_1 = sizeof(arr_1) / sizeof(*arr_1);
	int size_2 = sizeof(arr_2) / sizeof(*arr_2);
	int size_3 = sizeof(arr_3) / sizeof(*arr_3);


	std::cout << "Исходный массив 1:\t\t\t\t";
	for (int i : arr_1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	cikl = quick_sort(arr_1, size_1);	
	std::cout << "\nКоличество проходов по массиву: " <<cikl<< std::endl;
	std::cout << "Размер массива: " << size_1 << std::endl;
	std::cout <<"\n"<< std::endl;
	//-------------------------------
	std::cout << "Исходный массив 2:\t\t\t\t";
	for (int i : arr_2) {
		std::cout << i << " ";
	}
	std::cout  << std::endl;
	cikl = quick_sort(arr_2, size_2);
	std::cout << "\nКоличество проходов по массиву: " << cikl << std::endl;
	std::cout << "Размер массива: " << size_2 << std::endl;
	std::cout <<"\n"<< std::endl;
	//---------------------------------
	std::cout << "Исходный массив 3:\t\t\t\t";
	for (int i : arr_3) {
		std::cout << i << " ";
	}
	std::cout  << std::endl;
	cikl = quick_sort(arr_3, size_3);
	std::cout << "\nКоличество проходов по массиву: " << cikl << std::endl;
	std::cout << "Размер массива: " << size_3 << std::endl;
	std::cout <<"\n"<< std::endl;	
};