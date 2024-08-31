//Task_3_(function)

#include <iostream>
#include <windows.h>

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

/*Напишите функцию, которая принимает на вход целое число — номер элемента последовательности Фибоначчи 
— и возвращает число Фибоначчи, имеющее этот номер в последовательности. Функция должна быть рекурсивной.*/

int inRowPosition() {
    std::cout << "Введите число: ";
    int position_x{ 0 };
    std::cin >> position_x;
    std::cout << std::endl;
    return position_x;
}
//посредством рекурсии
    void inResultRecurs(  int& position_x, long long& res_1, long long res_2) {
        std::cout << res_1 <<" ";             
        --position_x;
        if (position_x == 0) {
              return;
          }      
        inResultRecurs(position_x, res_2, (res_1 + res_2));
    }
//посредством цикла
    void inResultFor(const int& position_x) {

        long long arr[2]{ 0,1 };
        long long res{ 0 };
        bool first = true;

        for (int i = 0; i < position_x; ++i) {

            if (first == false) {
                res = arr[1] + arr[0];
            }
            first = false;
            std::cout << res << " ";
            arr[0] = arr[1];
            arr[1] = res;
        }
    }

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    do {
        std::cout << "Task 3 (function)";
        std::cout << "\n" << std::endl;

        int data_x = inRowPosition();
        long long fist_data{ 0 };

        std::cout << "Числа Фибоначчи (цикл):\t\t";
        inResultFor(data_x);
        std::cout << "\n" << std::endl;

        std::cout << "Числа Фибоначчи (рекурсия):\t";
        inResultRecurs(data_x, fist_data, fist_data+1);
        std::cout << "\n"<<std::endl;

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
