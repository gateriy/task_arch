//Task 4 array

#include <iostream>

//функция выхода из программы
bool UserWantExitProgram()
{

	char exit_Y_N{};

	do
	{
		//std::cout << std::endl;
		std::cout << "Exit programm (Y/N): ";
		std::cin >> exit_Y_N;
		std::cout << std::endl;

		if (exit_Y_N == 'Y') {
			return false;
			break;
		}
		else if (exit_Y_N == 'N') {
			return true;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}

	} while (true);
}

//Напишите программу, которая создаёт и инициализирует неупорядоченный массив целых чисел на 10 
//элементов и сортирует его пузырьком в обратную сторону.

const int size{ 10 }; //global const array

//create two duplicate array random
std::pair <int*, int*> InArrRand() {
	
	static int arr_1[size]; //статическая переменная хранения массива
	static int arr_2[size]; //статическая переменная хранения дублирующего массива

	for (int i = 0; i < size; ++i) {
		arr_1[i] = rand() % 100;
		arr_2[i] = arr_1[i];
	}
	return { arr_1, arr_2 };
}

//исходный и отсортированные массивы функция
std::pair <int*, int*>  SortArr (bool max_min) {

	std::pair <int*, int*> arr = InArrRand();
	int* arr_1 = arr.first;
	int* arr_2 = arr.second;
	int arr_n{ 0 };

	bool var_x = false;
	do {
		 var_x = false;
			for (int n = 0; n < (size-1); ++n) {

				if (arr_2[n] < arr_2[n + 1] && !max_min) {

					arr_n = arr_2[n + 1];
					arr_2[n + 1] = arr_2[n];
					arr_2[n] = arr_n;
					var_x = true;					
				}
				if (arr_2[n] > arr_2[n + 1] && max_min) {

					arr_n = arr_2[n + 1];
					arr_2[n + 1] = arr_2[n];
					arr_2[n] = arr_n;
					var_x = true;
				}
			}	
	} while (var_x);
	return { arr_1, arr_2 };
}

int main() {
	char tp = 'D';
	bool type_x = true;
	do {
		std::cout << "Task 4 (arr)";
		std::cout << "\n" << std::endl;
				
		do {
			std::cout << "Type of sorting (direct/revers) D/R: ";
			std::cin >> tp;
			std::cout << std::endl;

			if (tp == 'D') {
				type_x = true;
				break;
			}
			else if (tp == 'R') {
				type_x = false;
				break;
			}
			else {
				std::cout << "Incorrect data!" << std::endl;
				continue;
			}
		} while (true);

		std::pair <int*, int*> arr = SortArr(type_x);

		bool fist_cycle = false;

		std::cout << "Array before sorting:\t";
		for (int i = 0; i < size; ++i ) {

			if (fist_cycle) {
				std::cout << ", ";
			}
			fist_cycle = true;
			std::cout << arr.first[i];
		}
		std::cout << std::endl;

		fist_cycle = false;
		std::cout << "Array after sorting:\t";
		for (int i = 0; i < size; ++i) {

			if (fist_cycle) {
				std::cout << ", ";
			}
			fist_cycle = true;
			std::cout << arr.second[i];
		}
		std::cout << "\n" << std::endl;

	} while (UserWantExitProgram());
}


