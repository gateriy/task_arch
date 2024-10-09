#include "Task_1.h"

/*
Задача 1. Снова числа Фибоначчи
Напишите ещё раз программу, которая реализует рекурсивный подсчёт чисел Фибоначчи. 
Не заглядывайте в ваше предыдущее решение, постарайтесь написать его заново.

Кроме написания кода нужно оценить сложность вашего алгоритма вычисления 
n-го числа Фибоначчи по скорости и по памяти.

принимает на вход целое число — номер элемента последовательности Фибоначчи
— и возвращает число Фибоначчи, имеющее этот номер в последовательности. Функция должна быть рекурсивной.
*/

int COUNT_f{ 0 };

int inRowPosition() {
    std::cout << "Введите число: ";
    int position_x{ 0 };
    std::cin >> position_x;
    std::cout << std::endl;
    return position_x;
}

//посредством рекурсии
void inResultRecurs(int& position_x, unsigned int & res_1, unsigned int  res_2) {

    unsigned long long a = res_1;
    unsigned long long b = res_2;

    if ((a + b) <= UINT_MAX) {

        ++COUNT_f;
        std::cout << res_1 << " ";

        --position_x;
        if (position_x == 0) {
            return;
        }

        inResultRecurs(position_x, res_2, (res_1 + res_2));
    }
    else {
        std::cout << res_1 << " ";
        std::cout << res_2 << " ";
        std::cout <<"\n"<< std::endl;
        std::cout << "Превышение предельного значения переменной (" << UINT_MAX <<") на следующей итерации!!! Задайте меньшее значение.\t";
        return;
    }

}

void Task_1() {
	
    std::cout << "Рекурсия";
    std::cout << "\n" << std::endl;

    int data_x = inRowPosition();
    unsigned int fist_data{ 0 };
    COUNT_f = 0;
    std::cout << "Числа Фибоначчи (рекурсия):\t";
    inResultRecurs(data_x, fist_data, fist_data + 1);
    std::cout << "\n" << std::endl;
    std::cout << "Количетсво запуска функции (рекурсий): " << COUNT_f  << std::endl;
    
};







