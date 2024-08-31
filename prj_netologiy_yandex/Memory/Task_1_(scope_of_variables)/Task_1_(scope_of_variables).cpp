// Task_1_(scope_of_variables).cpp 

#include<iostream>
#include<Windows.h>
//#include<string>


//функция выхода из программы
bool UserWantExitProgram()
{

    std::string exit_Y_N{};

    do
    {
        //std::cout << std::endl;
        std::cout << "Exit programm (Y/N): ";
        std::cin >> exit_Y_N;
        std::cout << std::endl;

        if (exit_Y_N == "Y") {
            return false;
            break;
        }
        else if (exit_Y_N == "N") {
            return true;
            break;
        }
        else {
            std::cout << "Incorrect data!" << std::endl;
            continue;
        }

    } while (true);
}

/*Нужно написать функцию, которая отслеживает, сколько раз она была вызвана за время работы программы.*/


void counting_function_static() {

    static int counter{ 0 };
    std::cout << "Количество вызовов функции counting_function_static(): " << ++counter << "\n";
}

int counter_2{ 0 };
void counting_function_global() {

    std::cout << "Количество вызовов функции counting_function_global(): " << ++counter_2 << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
    std::string text_v;
        std::cout << "Task 1 (scope of variables)";
        std::cout << "\n" << std::endl;
        std::cout << "Введите вариант объявление переменной (global/static) G/S: ";
        std::cin >> text_v;
        std::cout << std::endl;

        if (text_v == "S") {
            for (int i = 0; i < 15; i++)
            {
                counting_function_static();
            }
        }
        else if (text_v == "G") {
            for (int i = 0; i < 15; i++)
            {
                counting_function_global();
            }
        }
        else {
            std::cout << "Incorrect data!"<< "\n";
            std::cout << std::endl;
            continue;
        }

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
