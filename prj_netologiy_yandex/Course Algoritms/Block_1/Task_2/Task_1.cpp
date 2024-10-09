#include "Task_1.h"  // Task_1 Оценка алгосложности программы

    /*
    Дан код на языке C++. Ваша задача понять и описать, что он делает,
    определить его асимптотику, то есть время и дополнительную память,
    и привести аргументы, почему она именно такая.

    Правила приёма домашней работы
    Задание нужно сдавать, указывая сложность алгоритма по скорости и по памяти.
    Результатом выполнения задания должен быть текстовый ответ, написание кода не требуется.
    */

#include <iostream>
#include <chrono>
//#include <Windows.h>
#include <iomanip>

int COUNT{ 0 };

int calc(int* arr, int size)
{
    COUNT = 1;
    int ans = 0;

    for (int i = 1; i < size; i++)
    {
        ans += arr[i] - arr[i - 1];
        ++COUNT;
    }
    return ans;
}

void Task_1() {

        int arr_1[3]{ 1,2,3 };
        int arr_2[10]{ 1,2,3,4,5,6,7,8,9,10 };
        int arr_3[20]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

        auto start_x = std::chrono::high_resolution_clock::now();
        auto end_x = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds> (end_x - start_x);

       // std::cout << std::fixed;
       // std::cout << std::setprecision(10);

        std::cout << "ОТВЕТ:" << std::endl;
        std::cout << "Функция вычисляет сумму разностей между членами массива" << std::endl;
        std::cout << "последовательно перебирая массив начиная со второго элемента." << std::endl;
        std::cout << "Время выполннеия функци напрямую зависит от количества данных в массиве О(n)." << std::endl;
        std::cout << "Для понимания приведён прямой подсчет времени - чтобы показать, что этот способ не совсем корректен" << std::endl;
        std::cout << "для определения времени работы программы!" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;

        for (int i = 0; i < 5; ++i) {
            std::cout << "Прогон: " << i + 1 << std::endl;

            start_x = std::chrono::high_resolution_clock::now();
            std::cout << "Результат функции: " << calc(arr_1, 3) << "\tCчет циклов: " << COUNT << "\t";
            end_x = std::chrono::high_resolution_clock::now();
            dur = std::chrono::duration_cast<std::chrono::microseconds> (end_x - start_x);
            std::cout << "Время выполнения, млсек.:  " << dur.count() << std::endl;

            start_x = std::chrono::high_resolution_clock::now();
            std::cout << "Результат функции: " << calc(arr_2, 10) << "\tCчет циклов: " << COUNT << "\t";
            end_x = std::chrono::high_resolution_clock::now();
            dur = std::chrono::duration_cast<std::chrono::microseconds> (end_x - start_x);
            std::cout << "Время выполнения, млсек.:  " << dur.count() << std::endl;

            start_x = std::chrono::high_resolution_clock::now();
            std::cout << "Результат функции: " << calc(arr_3, 20) << "\tCчет циклов: " << COUNT << "\t";
            end_x = std::chrono::high_resolution_clock::now();
            dur = std::chrono::duration_cast<std::chrono::microseconds> (end_x - start_x);
            std::cout << "Время выполнения, млсек.:  " << dur.count() << std::endl;

            std::cout << "----------------------------------" << std::endl;
       
    }
};