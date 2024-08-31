// Task_1_(arr_*_&).cpp 

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

/*  Напишите функцию print, которая принимает на вход массив произвольного размера и выводит его на экран. 
В программе создайте несколько массивов разного размера и используйте для вызова вашей функции.  */

 int*  GeneratArr(int* arr, const int& size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    return arr ;
}

 //input array random
 void PrintArr(int* arr, const int& size) {

     std::cout << "Массив размером [" << size << "]:\t";
     bool fist = true;

        for (int i = 0; i < size; ++i) {
            if (fist == false) {
                std::cout << ", ";
            }
           std::cout << arr[i] ;
           fist = false;
        }
        std::cout << std::endl;
    }

int main() {
     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);

        int size{ 0 };
        int arr_1[5];
        int arr_2[10];
        int arr_3[20];

    do {
        std::string text_v;
        std::cout << "Task 1 (arr * &)";
        std::cout << "\n" << std::endl;
        std::cout << "(заполнение статических массивов посредством rand(), реализация в отдельной функции)\n";
        std::cout << "(ввод и вывод из функции через указатели)";
        std::cout << "\n" << std::endl;

        size = sizeof(arr_1) / sizeof(arr_1[0]);
        PrintArr(GeneratArr(arr_1, size), size);     

        size = sizeof(arr_2) / sizeof(arr_2[0]);
        PrintArr(GeneratArr(arr_2, size), size);

        size = sizeof(arr_3) / sizeof(arr_3[0]);
        PrintArr(GeneratArr(arr_3, size), size);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
