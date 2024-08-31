// Task_3_(arr_*_&).cpp 

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

/*  Напишите функцию reverse, которая принимает на вход массив произвольного размера и «разворачивает» 
его в обратную сторону — то есть первый элемент становится последним и наоборот. 
Выведите на консоль массив до вызова функции и после вызова функции.

Обратите внимание, что функция reverse должна изменять передаваемый ей массив. 
Элементы в нём должны изменить свой порядок.  */

int* GeneratArr(int* arr, const int& size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    return arr;
}

//input array random
void PrintArr(int* arr, const int& size) {

    std::cout << "Массив размером [" << size << "]:\t";
    bool fist = true;

    for (int i = 0; i < size; ++i) {
        if (fist == false) {
            std::cout << ", ";
        }
        std::cout << arr[i];
        fist = false;
    }
    std::cout << std::endl;
}

int* Revers(int* arr_1, const int& size) {

    int sise_x{ size - 1 }, y{ 0 };
    
    for (int i = sise_x ; i > sise_x/2; --i) {       
        y = arr_1[i];
        arr_1[i]= arr_1[sise_x - i];
        arr_1[sise_x - i] = y;
    }
    return arr_1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   const int size{ 15 };
   int arr_1[size];

    do {
        std::string text_v;
        std::cout << "Task 3 (arr * &)";
        std::cout << "\n" << std::endl;
        std::cout << "(заполнение статических массивов посредством rand(), реализация в отдельной функции)\n";
        std::cout << "(ввод и вывод из функции через указатели)";
        std::cout << "\n" << std::endl;

        std::cout << "Прямой массив:\n";
        PrintArr(GeneratArr(arr_1, size), size);
        std::cout <<  std::endl;
        std::cout << "Реверсивный массив:\n";
        PrintArr(Revers(arr_1, size), size);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
