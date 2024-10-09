#include "AllConfigTask.h"


template <typename text, typename data> data InputVar(const text& A, const  data& B) {
	//идентификатор типа переменной
	auto var = B;
	std::cout << text;
	std::cin >> var;
	std::cout << std::endl;
	return var;
}

template <typename text, typename data> void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
	//std::cout << std::endl;
};

void AllConfigTask::InteractiveVarTask(const std::string& v_text) {

	ConsolLang1251();

	do {
		std::cout << "\033c";//очистка консоли
		text = v_text;

		VarTaskNumber();

	} while (ExitProgram());
}

enum class AllConfigTask::Task {
	exit_0,
	task_1,
	task_2,
	task_3
};

void AllConfigTask::VarTaskNumber() {

	std::cout << text;

	do {


		std::cin >> number_task;
		std::cout << std::endl;

		if (number_task == "1" || number_task == "2" || number_task == "3" || number_task == "0") {

			std::cout << "\033c";//очистка консоли

			//if(number_task != "0") {
			std::cout << "Task " << number_task << ":" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			//}
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

bool AllConfigTask::ExitProgram()
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

void AllConfigTask::ConsolLang1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
