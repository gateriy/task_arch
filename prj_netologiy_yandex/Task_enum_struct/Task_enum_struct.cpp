// Task_enum_struct.cpp 
// задачи 1,2,3

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <Windows.h>

enum class Task {
	task_1=1,
	task_2,
	task_3
};

template <typename data>
void Output(const  data& A) {
	//std::cout << std::endl;
	std::cout << A << std::endl;
	//std::cout << std::endl;
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

		if (exit_Y_N == 'Y'|| exit_Y_N == 'y') {
			return false;
			break;
		}
		else if (exit_Y_N == 'N'|| exit_Y_N == 'n') {
			return true;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}

	} while (true);
}

//Напишите программу, которая спрашивает у пользователя номер месяца и выводит на 
//экран название месяца, введённого пользователем.
//Если пользователь ввёл некорректный номер месяца, сообщите ему об этом.
//Спрашивайте пользователя до тех пор, пока он не введёт 0.
//Для решения задачи воспользуйтесь перечислением.
void Task_1() {

	enum class Months {

		january=1,
		february,
		march,
		april,
		may,
		june,
		july,
		august,
		september,
		october,
		november,
		december
	};

	std::vector<std::string> momths_rus{
			"Январь",
			"Февраль",
			"Март",
			"Апрель",
			"Май",
			"Июнь",
			"Июль",
			"Август",
			"Сентябрь",
			"Октябрь",
			"Ноябрь",
			"Декабрь"
	};

			do {
			int number_month{ 0 };
			std::cout << "Введите номер месяца : ";
			std::cin >> number_month;

			if (number_month != 0) {

				switch (static_cast<Months>(number_month))
				{
				case(Months::january):
					Output(momths_rus.at(0));
					break;
				case(Months::february):
					Output(momths_rus.at(1));
					break;
				case(Months::march):
					Output(momths_rus.at(2));
					break;
				case(Months::april):
					Output(momths_rus.at(3));
					break;
				case(Months::may):
					Output(momths_rus.at(4));
					break;
				case(Months::june):
					Output(momths_rus.at(5));
					break;
				case(Months::july):
					Output(momths_rus.at(6));
					break;
				case(Months::august):
					Output(momths_rus.at(7));
					break;
				case(Months::september):
					Output(momths_rus.at(8));
					break;
				case(Months::october):
					Output(momths_rus.at(9));
					break;
				case(Months::november):
					Output(momths_rus.at(10));
					break;
				case(Months::december):
					Output(momths_rus.at(11));
					break;
				default:
					std::cout << "Неправильный номер!" << std::endl;
					break;
				}
			}
			else {
				std::cout << "До свидания" << std::endl;
				std::cout <<  std::endl;
				break;
			}
		} while (true);
}


//Создайте структуру для хранения информации о банковском счёте. 
//Она должна хранить номер счёта (целое число), имя владельца (строка) 
//и количество денег на счету (дробное число).
//Создайте функцию для изменения баланса счёта.Функция должна принимать 
//экземпляр структуры банковского счёта и новую сумму.
//Попросите пользователя заполнить поля экземпляра структуры, 
//сообщить новый баланс счёта и выведите обновлённый экземпляр структуры на консоль.
struct DataBank
{
	int number{};
	std::string name{};
	double cash;
};
void ChangeCash( DataBank& databank_1, const double& ch_x) {

	databank_1.cash = ch_x;
};
void Task_2() {

	DataBank databank;

	std::cout << "Введите номер счёта : ";
	std::cin >> databank.number;

	std::cout << "Введите имя владельца : ";
	std::cin >> databank.name;

	std::cout << "Введите баланс : ";
	std::cin >> databank.cash;

	double cash_x;
	std::cout << "Введите новый баланс : ";
	std::cin >> cash_x;

	ChangeCash(databank, cash_x);

	std::cout << "Ваш счёт : "<<databank.name<< ", "<< databank.number <<", "<<databank.cash<<std::endl;
	std::cout << std::endl;
}


//Создайте структуру для хранения адреса. 
//Структура должна содержать название города, улицы, номер дома, номер квартиры и индекс.
//Создайте функцию для вывода структуры на консоль.
//Протестируйте созданную функцию.
//Создайте в коде экземпляры структуры, передайте их в функцию и 
//выведите на консоль получившиеся экземпляры структуры.
struct DataAddress
{
	std::string city{};
	std::string street{};
	int home{};
	int room{};
	int index{};
};
void ChangeCash(const DataAddress& dataaddress_x) {

		std::cout << "Город : " << dataaddress_x.city << std::endl;
		std::cout << "Улица : " << dataaddress_x.street << std::endl;
		std::cout << "Номер дома : " << dataaddress_x.home << std::endl;
		std::cout << "Номер квартиры : " << dataaddress_x.room << std::endl;
		std::cout << "Индекс : " << dataaddress_x.index << std::endl;
};
void Task_3() {

	DataAddress ddd_x;
	DataAddress ddd_x_2;
		
	ddd_x = { "Москва","Арбат",12,8,123456 };
	ddd_x_2 = { "Ижевск","Пушкина",59,143,953769 };

	ChangeCash(ddd_x);
	std::cout << std::endl;
	ChangeCash(ddd_x_2);
	std::cout << std::endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		//system("CLS"); //очистка консоли
		std::cout << "\033c";//очистка консоли
		bool exit{ true };	

		do {

			std::string number_task{ };
			std::cout << "Input numder task (1, 2, 3): ";
			std::cin >> number_task;
			std::cout << std::endl;

			if (number_task == "1" || number_task == "2" || number_task == "3") {

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
				case(static_cast<int>(Task::task_3)):
					Task_3();
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

