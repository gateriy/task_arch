#include"Task_2.h"

template <typename text, typename data>
void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
	//std::cout << std::endl;
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

	Counter::Counter(const int& _count)
	{
		this->_count = _count;
	};

	Counter::Counter() {
		_count = 1;
	};

	int Counter::LookCount() {
		return _count;
	}

	int Counter::AddCount() {
		return ++_count;
	}

	int Counter::SubtractCount() {
		return --_count;
	}

int FestCounter() {
	int counter_x{ 0 };

	do
	{
		std::string Y_N{};
		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> Y_N;
		std::cout << std::endl;

		if (Y_N == "Д" || Y_N == "д" || Y_N == "да") {
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
		else {
			std::cout << "Не корректные данные! Введите параметр повторно." << std::endl;
			std::cout << std::endl;
		}

	} while (true);

}

















