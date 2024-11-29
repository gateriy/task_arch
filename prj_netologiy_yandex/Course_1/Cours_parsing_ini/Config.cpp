#include "Config.h"

void Config::InteractiveVarTask(const std::string& v_text) {

	ConsolLang1251();

	do {
		std::cout << "\033c";//очистка консоли
		text = v_text;

		VarTaskNumber();

	} while (ExitProgram());
}

enum class Config::Task {
	exit_0,
	block_1,
	block_2,
	block_3
};

void Config::VarTaskNumber() {

	std::cout << text;

	do {


		std::cin >> number_task;
		std::cout << std::endl;

		if (number_task == "1" || number_task == "2" || number_task == "3" || number_task == "0") {

			std::cout << "\033c";//очистка консоли

			std::cout << "Блок " << number_task << ":" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;

			switch (stoi(number_task))
			{
			case(static_cast<int>(Task::block_1)):
				block_1();
				exit = false;
				break;
			case(static_cast<int>(Task::block_2)):
				//Task_2();
				exit = false;
				break;
			case(static_cast<int>(Task::block_3)):
				//Task_3();
				exit = false;
				break;
			case(static_cast<int>(Task::exit_0)):
				std::cout << "\033c";//очистка консоли
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
}

bool Config::ExitProgram()
{
	char exit_Y_N{};
	do
	{
		std::cout << "Exit programm (Y/N): ";
		std::cin >> exit_Y_N;
		std::cout << std::endl;

		if (exit_Y_N == 'Y' || exit_Y_N == 'y') {
			return false;
		}
		else if (exit_Y_N == 'N' || exit_Y_N == 'n') {
			return true;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}
	} while (true);
}

void Config::ConsolLang1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
