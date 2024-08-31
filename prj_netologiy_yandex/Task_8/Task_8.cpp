//задачи 8,9,10

#include <iostream>
#include <vector>
#include <string>

enum Task {
	summ=1,
	summ_numeric,
	composition_numeric
	

};

template <typename data>
void Output(const  data& A ) {
	//std::cout << std::endl;
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
		}else  {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}			

	} while (true);		
}

//Напишите программу, которая запрашивает у пользователя целые числа до тех пор, пока пользователь не введёт число 0.
//После того, как пользователь ввёл число 0, программа выводит сумму введённых пользователем чисел и завершает работу.
double SummN() {

	std::vector<double> numeric{};
	int i{ 0 }, input{ 0 }, summ{ 0 };

	do
	{
		//std::cout << std::endl;
		std::cout << "Input numeric <" << ++i << "> (ignor 0): ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == 0) {
			break;
		}
		else {
			numeric.push_back(input);
		}

	} while (true);

	for (const auto& a : numeric) {
		summ = summ+a;
	}
	return summ;
}

//Напишите программу, которая запрашивает у пользователя целое число и выводит на экран сумму всех его цифр
//реализовал через конвертацию string и vector (по предложенному варианту не пошел)
int SummNumeric() {
	std::string num{}, num_x{};
	std::vector<int>numeric{};
	int res{0};

	std::cout << "Input numeric: ";
	std::cin >> num;
	std::cout << std::endl;
	
	for  (const auto& i : num) {
		num_x = i;
		numeric.push_back(stoi(num_x));
	}
	if (!numeric.empty()) {
		for (const auto& n : numeric) {
			res = res + n;
			//std::cout << n << std::endl;

		}
	}
	else res = 0;

	return res;
}

//Напишите программу, которая запрашивает у пользователя целое число и выводит на экран таблицу умножения для этого числа.
void CompositionNumeric() {
	long int num_x{0}, range{ 0 };
//	std::vector<int>numeric{ 0 };

	std::cout << "Input numeric: ";
	std::cin >> num_x;
	std::cout << std::endl;

	std::cout << "Input range: ";
	std::cin >> range;
	std::cout << std::endl;
	std::cout << num_x << std::endl;

	for (int i=1; i <= range; ++i) {		
		std::cout << num_x << "\tx\t" << i << "\t=\t" << num_x *i << std::endl;
	}

}

int main(){

	do {
			bool exit{ true };

		do {

			std::string number_programm{ };
			std::cout << "Input numder task (1, 2, 3): ";
			std::cin >> number_programm;
			std::cout << std::endl;

			if (number_programm == "1" || number_programm == "2" || number_programm == "3") {

				switch (stoi(number_programm))
				{
				case(Task::summ):
					Output(SummN());				
					exit = false;
					break;
				case(Task::summ_numeric):
					Output(SummNumeric());
					exit = false;
					break;
				case(Task::composition_numeric):
					CompositionNumeric();
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

