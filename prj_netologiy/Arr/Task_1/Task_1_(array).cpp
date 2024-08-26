//Task 1 array

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

//Напишите программу, которая создаёт массив целых чисел на 10 элементов
//и выводит на экран все элементы массива через запятую и пробел(, ).

//input array random
std::pair <int, int*> InArrRand() {

	const int size{ 10 }; //const array
	static int Arr_1[size]; //статическая переменная хранения массива

	for (int i = 0; i < size; ++i) {
		Arr_1[i] = rand()%100;
	}
	return { size,Arr_1 };
}

int main() {

	do {
		std::cout << "Task 1 (arr)";
		std::cout << "\n"<<std::endl;

	
		int* p = InArrRand().second;
		//int size = sizeof(p) / sizeof(p[0]);

		for (int n=0;n< InArrRand().first;++n){

			
			std::cout << n<< ":\t"<<p[n] <<"\n"<<std::endl;
		}
		//std::cout << "\n" << std::endl;
					
	} while (UserWantExitProgram());
}

