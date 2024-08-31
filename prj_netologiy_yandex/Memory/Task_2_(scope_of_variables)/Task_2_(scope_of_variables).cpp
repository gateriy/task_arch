// Task_2_(scope_of_variables).cpp 

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

/*аша задача — создать несколько функций с одинаковой сигнатурой, то есть с одинаковым именем, 
одинаковыми параметрами и одинаковым типом возвращаемого значения, но с разной реализацией.

Создайте четыре функции int calc(int x, int y), каждая из которых будет реализовывать одно 
из четырёх простых арифметических действий: сложение, вычитание, умножение, деление.

x = 6, y = 9
Сложение: 15
Вычитание: -3
Умножение: 54
Деление: 0

*/

namespace calc_summ {

    int calc(const int& x, const int& y) {

        return x + y;
    }
};
namespace calc_subtraction {

    int calc(const int& x, const int& y) {

        return x - y;
    }
};
namespace calc_division {

    int calc(const int& x, const int& y) {

        return x / y;
    }
};
namespace calc_multiplication {

    int calc(const int& x, const int& y) {

        return x * y;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        double x{ 0.0 }, y{ 0.0 };

        std::cout << "Task 2 (scope of variables)";
        std::cout << "\n" << std::endl;
        std::cout << "Введите переменную Х:";
        std::cin >> x;
        std::cout << "Введите переменную Y:";
        std::cin >> y;
        std::cout << "\n" << "x = " << x << "y = " << y << "\n";


        std::cout << "Сложение: " << calc_summ::calc(x,y);
        std::cout << "Вычитание: " << calc_subtraction::calc(x, y);
        std::cout << "Умножение: " << calc_multiplication::calc(x, y);
        std::cout << "Деление: " << calc_division::calc(x, y);
        }

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
