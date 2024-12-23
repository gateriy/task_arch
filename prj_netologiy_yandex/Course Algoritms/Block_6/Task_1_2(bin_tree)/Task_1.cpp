#include "Task_1.h"

/*
Задача 1. Вывод пирамиды на массиве
Вам нужно реализовать на консоль функцию вывода целочисленной пирамиды, 
реализованной на массиве. Функция будет называться print_pyramid.

Ваша пирамида будет храниться на массиве целых чисел, поэтому для вывода 
вам потребуется знать размер массива, в котором хранится пирамида.

Вывод пирамиды будет выглядеть следующим образом: каждый элемент пирамиды 
выводится на своей строчке. Перед значением элемента выводится информация, 
на каком уровне находится элемент, и является элемент левым или правым ребёнком. 
Корневой элемент находится на уровне 0, его дети — на уровне 1 и так далее. 
Левый элемент обозначим left, правый — right ребёнком. Для корневого элемента 
будет специальное значение root. В скобках после указания левого или правого 
ребёнка нужно вывести значение того элемента, чьим ребёнком является выводимый элемент.

Порядок вывода: уровни пирамиды выводятся слева направо, начиная с самого маленького.

После написания функции её нужно протестировать. 
Для этого используйте массивы из примеров работы программы. 
Можете сделать их автоматическими.

На консоль необходимо вывести исходный массив, затем должен идти вывод вашей функции.


Примеры работы программы
Исходный массив: 1 3 6 5 9 8
Пирамида:
0 root 1
1 left(1) 3
1 right(1) 6
2 left(3) 5
2 right(3) 9
2 left(6) 8

Исходный массив: 94 67 18 44 55 12 6 42
Пирамида:
0 root 94
1 left(94) 67
1 right(94) 18
2 left(67) 44
2 right(67) 55
2 left(18) 12
2 right(18) 6
3 left(44) 42

Исходный массив: 16 11 9 10 5 6 8 1 2 4
Пирамида:
0 root 16
1 left(16) 11
1 right(16) 9
2 left(11) 10
2 right(11) 5
2 left(9) 6
2 right(9) 8
3 left(10) 1
3 right(10) 2
3 left(5) 4

Для любого узла пирамиды, хранящегося в ячейке под индексом i,
будем считать, что его левый ребёнок хранится в 2i+1, а правый
в 2i+2.

*/

int Level_Piramid(int i) {
	int x{ 0 }, y{ 0 }, z{ 0 };

	while (true) {
		++x;

		if (i == 0) {
			return x;
		}

		y = y + static_cast<int>(pow(2, x));
		z = z + static_cast<int>(pow(2, (x - 1)));
	
		if (i >= z && i <= y) {
			return x+1;
		}	
	}
}

void print_pyramid(const std::vector<int>& array) {
	int count{ 0 };
	bool end_x = false;

	std::cout << 0 << " root\t\t" << array[0] << std::endl;

		for (int i = 0; i < array.size(); ++i) {
	
			count = Level_Piramid(i);

			if ((2 * i + 1) < array.size()) {
				std::cout << count << " left(" << array[i] << ")\t" << array[2 * i + 1] << std::endl;
			}
			else {
				end_x = true;
				break;
			}
			if ((2 * i + 2) < array.size() ) {
				std::cout << count << " right(" << array[i] << ")\t" << array[2 * i + 2] << std::endl;
			}
			else {
				end_x = true;
				break;
			}

		if (end_x) { break; }
	}
	std::cout << "---------------" << std::endl;
}

void print_array(const std::vector<int>& array) {
	std::cout << "Исходный массив:";
	for (const int& var : array) {
		std::cout << " " << var;
	}
	std::cout << std::endl;
	std::cout << "Пирамида:" << std::endl;
}



void Task_1() {
	
	std::vector < int> arr_1{ 1, 3, 6, 5, 9, 8 };
	std::vector < int> arr_2{ 94, 67, 18, 44, 55, 12, 6, 42 };
	std::vector < int> arr_3{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };


	print_array(arr_1);
	print_pyramid(arr_1);

	print_array(arr_2);
	print_pyramid(arr_2);

	print_array(arr_3);
	print_pyramid(arr_3);


};