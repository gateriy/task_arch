// Task_2_(string).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

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
        std::cout << "\n" << std::endl;
        //Напишите программу, которая просит пользователя угадать слово, записанное 
        //в коде — то есть вводить слова до тех пор, пока одно из них не совпадёт с загаданным словом.

        std::string text_var, text_x;

        text_x = "малина";

        do
        {

        std::cout << "Угадайте слово: ";
        std::cin >> text_var;

        if (!text_var.compare(text_x)) {
        std::cout << "Правильно! Вы победили! Загаданное слово — " + text_x << std::endl;
        }
        else {
            std::cout << "Неправильно" << std::endl;
        }
            
        } while (text_var.compare(text_x));



        
        std::cout << std::endl;
    } while (UserWantExitProgram());
}