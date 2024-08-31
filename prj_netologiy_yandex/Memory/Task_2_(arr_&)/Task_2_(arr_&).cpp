// Task_2_(arr_*_&).cpp 

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

/*Ваша задача — реализовать уже знакомую вам функцию swap (вспомнить можно здесь), 
но с помощью указателей, а не ссылок.*/


//такая реализация позволяет не задавать заранее тип переменной на которую ссылается указатель
template<typename T, typename S>
void swap(T* volume_x, S* volume_y) {

   /* *volume_x = *volume_x + *volume_y;
    *volume_y = *volume_x - *volume_y;
    *volume_x = *volume_x - *volume_y;*/

    T var{ 0 };

    var = *volume_x;
    *volume_x = *volume_y;
    *volume_y = var;
}

/*
//фиксированая реализация на тип переменной на которую ссылается указатель
void swap(int* volume_x, int* volume_y) {

    *volume_x = *volume_x + *volume_y;
    *volume_y = *volume_x - *volume_y;
    *volume_x = *volume_x - *volume_y;
}
*/

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        std::string text_v;
        std::cout << "Task 2 (arr * &)";
        std::cout << "\n" << std::endl;
        std::cout << "(применил определение функции swap как template<typename T>, что позволяет не задавать тип переменных,\n";
        std::cout << "на которые ссылается указатель заранее и переопределять при выызове функции)";
        std::cout << "\n" << std::endl;

        int a{ 5 }, b{ 8 };
        std::cout << "Тип переменной A: " << typeid(a).name() << std::endl;
        std::cout << "Тип переменной B: " << typeid(b).name() << std::endl;
        std::cout <<  std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap(&a, &b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << std::endl;

      
        double  da{ 5.5 },  db{ 8.8 };
        std::cout << "Тип переменной A: " << typeid(da).name() << std::endl;
        std::cout << "Тип переменной B: " << typeid(db).name() << std::endl;
        std::cout << std::endl;
        std::cout << "a = " << da << ", b = " << db << std::endl;
        swap(&da, &db);
        std::cout << "a = " << da << ", b = " << db << std::endl;
        std::cout << std::endl;

        size_t  sa{ 5 };
        b = 8;
        std::cout << "Тип переменной A: " << typeid(sa).name() << std::endl;
        std::cout << "Тип переменной B: " << typeid(b).name() << std::endl;
        std::cout << std::endl;
        std::cout << "a = " << sa << ", b = " << b << std::endl;
        swap(&sa, &b);
        std::cout << "a = " << sa << ", b = " << b << std::endl;
        std::cout << std::endl;

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
