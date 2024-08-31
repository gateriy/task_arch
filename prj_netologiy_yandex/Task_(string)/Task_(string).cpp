// Task_(string).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <Windows.h>
#include <string>

// функция выхода из программы
bool UserWantExitProgram()
{
    std::string exit_Y_N{};

    do
    {
        //std::cout << std::endl;
        std::cout << "Exit programm (Y/N): ";
        std::cin >> exit_Y_N;
        std::cout << std::endl;

        if (exit_Y_N == "Y" || exit_Y_N == "y") {
            return false;
            break;
        }
        else if (exit_Y_N == "N" || exit_Y_N == "n") {
            return true;
            break;
        }
        else {
            std::cout << "Incorrect data!" << std::endl;
            continue;
        }

    } while (true);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        std::cout << "Task 1 string";
        //std::cout << "()\n";
        std::cout << "\n" << std::endl;
        //Напишите программу, которая спрашивает у пользователя 
        //отдельно его имя и фамилию, а затем приветствует его.Работу необходимо выполнить, используя операции над строками.

        std::string name, surname;


        std::cout << "Введите имя: ";
        std::cin >> name;
        std::cout << "Введите фамилию: ";
        std::cin >> surname;
        std::cout << "Здравствуйте, " + name + " " + surname + "!" << std::endl;

        std::cout << std::endl;
    } while (UserWantExitProgram());
}