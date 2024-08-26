//задача 2 тема циклы.

#include <iostream>

//понимйаю что для такой задачи избыточно template, но стараюсь уже вырабатыывать привычку везде где можно выходить на шаблоны....
template <typename data>
void Output(const  data& A) {
	std::cout << "Result :" << A << std::endl;
	std::cout << std::endl;
}

bool ExitProgram()
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

//Напишите программу, которая запрашивает у пользователя целое число и выводит на экран сумму всех его цифр
//реализовал как рекомендованно в уловии к задаче 

int SummNumeric() {
	
	int res{ 0 }, num{0}, num_x{0};

	std::cout << "Input numeric: ";
	std::cin >> num;
	std::cout << std::endl;

	while (true) {
		
		num_x = num % 10;
		num = num / 10;
	
	if (num_x == 0) { break; }	

	res = res + num_x;
	}
	return res;
}

int main() {

	do {

		Output(SummNumeric());

	} while (ExitProgram());
}

