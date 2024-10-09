#include"Task_2.h"

/*
В этом задании вам нужно реализовать функцию добавления нового элемента в конец 
динамического массива целых чисел append_to_dynamic_array.

Добавление элемента будет происходить по алгоритму: если логический размер массива 
меньше фактического, то вы добавляете новый элемент в запас вашего массива и 
увеличиваете его логический размер на 1.

Если логический размер массива равен его фактическому размеру, 
тогда создаётся новый массив размером в 2 раза больше. 

В него перекладываются элементы из старого массива вместе с новым элементом в конце. 
Фактический и логический размеры массива изменяют своё значение. Логический размер 
увеличивается на единицу, фактический размер увеличивается в два раза, старый массив уничтожается. 

Далее программа должна работать уже с новым массивом.

Организуйте интерактивное взаимодействие с пользователем. Ваша программа будет работать по алгоритму:

Пользователь вводит фактический размер массива.
Пользователь вводит логический размер массива.
Пользователь вводит элементы для заполнения массива. 
Их количество будет равно логическому размеру массива.
Программа выводит введённый массив на консоль с помощью функции print_dynamic_array из прошлого задания.
Пользователь вводит новый элемент для добавления в конец. 
Ввод элементов заканчивается, если пользователь введёт специальное значение (например, 0).
Программа выводит массив с добавленным элементом.
Пункты 5 и 6 повторяются до тех пор, пока пользователь не введёт специальное значение (например, 0).
Программа прощается, выводит окончательное состояние динамического массива и завершает свою работу.
Подумайте над тем, какая сигнатура будет у вашей функции и как вы будете хранить 
фактический и логический размеры вашего массива.

Примеры работы программы

Введите фактичеcкий размер массива: 3
Введите логический размер массива: 2
Введите arr[0]: 1
Введите arr[1]: 2

Динамический массив: 1 2 _

Введите элемент для добавления: 9
Динамический массив: 1 2 9

Введите элемент для добавления: 7
Динамический массив: 1 2 9 7 _ _

Введите элемент для добавления: 4
Динамический массив: 1 2 9 7 4 _

Введите элемент для добавления: 0
Спасибо! Ваш массив: 1 2 9 7 4 _

Введите фактичеcкий размер массива: 8
Введите логический размер массива: 9
Ошибка! Логический размер массива не может
*/

/*
std::pair<int, int> input_sizes() {
	int size_a{ 0 };
	int size_l{ 0 };

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> size_a;

	do {
		std::cout << "Введите логический размер массива : ";
		std::cin >> size_l;

		if (size_l > size_a) {
			std::cout << "Ошибка! Логический размер массива не может превышать фактический! Уточните размер!" << std::endl;
		}
		else break;
	} while (true);
	std::cout << std::endl;
	return { size_l ,size_a };
}

int* create_dynamic_array(int actual_size) {

	int* arr = new int[actual_size];

	for (int i = 0; i < actual_size; ++i) {
		arr[i] = 0;
	}

	return arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

	for (int i = 0; i < (actual_size); ++i) {

		if (i <= (logical_size - 1)) {
			std::cout << arr[i] << " ";
		}
		else {
			std::cout << "_ ";
		}
	}
}

void delete_dynamic_array(int* arr) { delete[] arr; }
*/

int* append_to_dynamic_array(int* arr, int &logical_size, int &actual_size) {
	int* arr_var;
	++logical_size;
	if (logical_size > actual_size) {

		actual_size = actual_size * 2;
		arr_var = create_dynamic_array(actual_size);

		for (int i = 0; i < actual_size; ++i) {
			if (i < actual_size / 2) {
				arr_var[i] = arr[i];
			}
			else arr_var[i] = 0;
		}
		delete_dynamic_array(arr);
		arr = create_dynamic_array(actual_size);
		for (int i = 0; i < actual_size; ++i) {
			arr[i] = arr_var[i];
		}
		delete_dynamic_array(arr_var);
	}
	return arr;
};

void Task_2() {

	std::pair<int, int> sizes = input_sizes();
	int size_arr = sizes.second;
	int size_logic_arr = sizes.first;
	int* arr_x = create_dynamic_array(size_arr);
	int input_var{ 0 };

	for (int i = 0; i <= (size_logic_arr - 1); ++i) {

		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr_x[i];
	}
	std::cout << std::endl;

	std::cout << "Динамический массив: ";
	print_dynamic_array(arr_x, size_logic_arr, size_arr);
	std::cout  << std::endl;

	do {

		std::cout << "Введите элемент для добавления (0 - выход): ";

		std::cin >> input_var;
		if (input_var == 0) { 
			std::cout << "Спасибо! Ваш массив: ";
			print_dynamic_array(arr_x, size_logic_arr, size_arr);
			std::cout << "\n" << std::endl;
			break; }

		arr_x = append_to_dynamic_array(arr_x, size_logic_arr, size_arr);
		arr_x[size_logic_arr-1] = input_var;

		std::cout << "Динамический массив: ";
		print_dynamic_array(arr_x, size_logic_arr, size_arr);
		std::cout << "\n"<<std::endl;

	} while (true);

	delete_dynamic_array(arr_x);
};