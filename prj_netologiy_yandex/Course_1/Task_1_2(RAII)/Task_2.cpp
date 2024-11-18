#include"Task_2.h"

/*
Задача 2. Копирование умных массивов
Описание
В этом задании вам нужно поработать с классом умных массивов, 
который вы реализовали в предыдущем задании. 
Сначала попробуйте создать два экземпляра вашего класса с 
различными элементами и присвоить один другому.

smart_array arr(5);
arr.add_element(1);
arr.add_element(4);
arr.add_element(155);

smart_array new_array(2);
new_array.add_element(44);
new_array.add_element(34);

arr = new_array


В программе возникает исключение, потому что компилятор самостоятельно 
сгенерировал оператор присваивания, который просто копирует все поля одного 
объекта другому. В частности, проблема возникает из-за копирования указателя: 
оба объекта класса имеют одинаковый указатель на область памяти и в своих 
деструкторах пытаются освободить его. Происходит двойное освобождение памяти.

*/

void Task_2() {

	{
		int yyy{ 0 };
		std::cout << "Введите размер первичного массива 1: ";
		std::cin >> yyy;

		smart_array arr_1(yyy);

		std::cout << "Введите размер первичного массива 2: ";
		std::cin >> yyy;

		smart_array arr_2(yyy);

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Размер первично инициированного массива 1: " << arr_1.get_size_array() << std::endl;
		std::cout << std::endl;

		arr_1.add_element(1);
		arr_1.add_element(4);
		arr_1.add_element(155);
		arr_1.add_element(14);
		arr_1.add_element(15);
		arr_1.add_element(1500);
		arr_1.add_element(1600);
		arr_1.add_element(1700);

		std::cout << "Введеные програмно данные в массив 1:" << std::endl;
		for (int i = 0; i < arr_1.get_size_added_array(); ++i) {
			std::cout << "Значение (" << i << ") элемента массива 1: " << arr_1.get_element(i) << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Размер массива 1 после добавление всех элементов: " << arr_1.get_size_array() << std::endl;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Размер первично инициированного массива 2: " << arr_2.get_size_array() << std::endl;
		std::cout << std::endl;

		arr_2.add_element(2);
		arr_2.add_element(44);
		arr_2.add_element(34);

		std::cout << "Введеные програмно данные в массив 2:" << std::endl;
		for (int i = 0; i < arr_2.get_size_added_array(); ++i) {
			std::cout << "Значение (" << i << ") элемента массива 2: " << arr_2.get_element(i) << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Размер массива 2 после добавление всех элементов: " << arr_2.get_size_array() << std::endl;

		arr_1 = arr_2;

		std::cout <<"-----------------------------------------------------" << std::endl;
		std::cout << "Размер массива 1 после его присвоения к массиву 2: " << arr_1.get_size_array() << std::endl;
		std::cout << "Mассив 1 после его присвоения к массиву 2:" << std::endl;
		for (int i = 0; i < arr_1.get_size_added_array(); ++i) {
			std::cout << "Значение (" << i << ") элемента массива 1: " << arr_1.get_element(i) << std::endl;
		}
	}
	std::cout << "Блок закрыт!" << std::endl;

};