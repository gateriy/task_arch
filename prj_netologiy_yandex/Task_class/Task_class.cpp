// Task_class.cpp 
// задачи 1,2

#include <iostream>
#include <string>
#include <Windows.h>

enum class Task {
	task_1 = 1,
	task_2,
};

template <typename text, typename data>
void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
	//std::cout << std::endl;
}

template <typename text, typename data>
data Input_X(const text& A, const data& B) {
	data cycle{ B };
	std::cout << A;
	std::cin >> cycle;
	return cycle;
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

		if (exit_Y_N == 'Y' || exit_Y_N == 'y') {
			return false;
			break;
		}
		else if (exit_Y_N == 'N' || exit_Y_N == 'n') {
			return true;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}

	} while (true);
}

/*Создайте класс Calculator. Класс должен содержать два поля num1 и num2 для хранения дробных чисел. 
Также класс должен содержать следующие методы:
double add() - метод должен возвращать результат сложения num1 и num2
double multiply() - метод должен возвращать результат перемножения num1 и num2
double subtract_1_2() - метод должен возвращать результат вычитания num2 из num1
double subtract_2_1() - метод должен возвращать результат вычитания num1 из num2
double divide_1_2() - метод должен возвращать результат деления num1 на num2
double divide_2_1() - метод должен возвращать результат деления num2 на num1
bool set_num1(double num1) - метод должен установить значение поля num1 равное значению аргумента 
num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, 
в обратном случае false
bool set_num2(double num2) - метод должен установить значение поля num2 равное значению аргумента 
num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, 
в обратном случае false
Напишите код, демонстрирующий работу класса Calculator. Попросите пользователя ввести два числа. 
После этого выведите пользователю результаты всех операций или попросите его ввести значение ещё раз, 
если предыдущий ввод был некорректен
Программа спрашивает пользователя бесконечно, пока он сам не закроет консоль*/

class Calculator {
public:

	/*Task_1(const double& num1, const double& num2) {
		this->num1 = num2;
		this->num2 = num2;
	}*/

	//Task_1(const double& _num1, const double& _num2) : num1{ _num1 }, num2{ _num2 }
	//{};
	Calculator() {};

	bool set_num1(const double& num1) {

		if (num1 != 0) {
		this->num1 = num1;
		}
		if (this->num1 == num1) {
			return true;
		}
		else { return false; }
	}
	bool set_num2(const double& num2) {

		if (num2 != 0) {
			this->num2 = num2;
		}
		if (this->num2 == num2) {
			return true;
		}
		else { return false; }
	}

	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num2 * num1;
	}
	double subtract_1_2() {
		return num2 - num1;
	}
	double subtract_2_1() {
		return num1 - num2;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}

private:
	double num1{ 0 };
	double num2{ 0 };		
};

double InputDataNum(const std::string& text) {
	double x{ 0 };
	do {
		std::cout << text;
		std::cin >> x;
		if (x == 0) {
			std::cout << "Не корректный ввод!" << std::endl;
		}
		else {
			return x;
			break;
		}
	} while (true);
}

void Task_1() {

	Calculator сalculator{};

	int a{ 0 };
	int b = Input_X("Введите количество циклов: ",0.0);

	do {
		if (сalculator.set_num1(InputDataNum("Введите num1: ")) == true &&
			 сalculator.set_num2(InputDataNum("Введите num2: ")) == true) {
				std::cout << std::endl;
				Output("\tnum1 + num2 = ", сalculator.add());
				Output("\tnum1 * num2 = ", сalculator.multiply());
				Output("\tnum2 - num1 = ", сalculator.subtract_1_2());
				Output("\tnum1 - num2 = ", сalculator.subtract_2_1());
				Output("\tnum1 / num2 = ", сalculator.divide_1_2());
				Output("\tnum2 / num1 = ", сalculator.divide_2_1());
				std::cout << std::endl;
		}
	++a;
	} while (b != a);
}

/*
Создайте класс Counter. Класс должен выполнять функцию счётчика, для этого он должен предоставлять:

возможность увеличить своё значение на 1
возможность уменьшить своё значение на 1
возможность посмотреть своё текущее значение
возможность создания экземпляра класса с начальным значением по умолчанию (1)
возможность создания экземпляра класса с инициализирующим начальным значением

Обратите внимание на то, что у внешнего кода не должно быть возможности изменить внутреннее значение 
счётчика напрямую

Напишите код, демонстрирующий работу класса Counter. Спросите у пользователя, хочет ли он указать 
начальное значение для счётчика. Если хочет, дайте ему возможность это сделать. Затем предоставьте 
пользователю возможность вводить команды:

+: увеличьте счётчик на 1
-: уменьшите счётчик на 1
=: выведите текущее значение счётчика
x: завершите работу программы
*/

class Counter {
public:
	Counter(const int& _count)
	{
		this ->_count = _count;	
	};

	Counter() {
		_count = 1;
	};	

	int LookCount() {
		return _count;
	}
	int AddCount() {
		return ++_count;
	}
	int SubtractCount() {
		return --_count;
	}
	
private:
	int _count{};
};

int FestCounter() {
	int counter_x{ 0 };

	do
	{
		std::string Y_N{};
		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> Y_N;
		std::cout << std::endl;

		if (Y_N == "Д" || Y_N == "д" || Y_N=="да") {
			std::cout << "Введите начальное значение счетчика: ";
			std::cin >> counter_x;
			break;
		}
		else if (Y_N == "Н" || Y_N == "н" || Y_N == "нет") {
			counter_x = 1;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}
	} while (true);
	return counter_x;
}

void Task_2() {
	
	Counter counter(FestCounter());
	char comm{ };
	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> comm;
		if (comm == '+') {
			counter.AddCount();
		}
		else if (comm == '-') {
			counter.SubtractCount();
		}
		else if (comm == '=') {
			Output("Текущее значение счетчика: ", counter.LookCount());			
		}
		else if (comm == 'x' || comm == 'х') {
			std::cout << "До свидания!" << std::endl;
			std::cout << std::endl;
			break;
		}
		else{ 
			std::cout << "Не корректные данные! Введите параметр повторно."  << std::endl;
			std::cout << std::endl;
		}

	} while (true);
	
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		//system("CLS"); //очистка консоли
		std::cout << "\033c";//очистка консоли
			bool exit = true;		

		do {

			std::string number_task{ };
			std::cout << "Input numder task (1, 2): ";
			std::cin >> number_task;
			std::cout << std::endl;


			if (number_task == "1" || number_task == "2") {

				switch (stoi(number_task))
				{
				case(static_cast<int>(Task::task_1)):				
					Task_1();
					exit = false;
					break;
				case(static_cast<int>(Task::task_2)):
					Task_2();
					exit = false;
					break;
				}
			}
			else {
				std::cout << "Incorrect data!" << std::endl;
				std::cout << std::endl;
				continue;
			}

		} while (exit);

	} while (ExitProgram());
}