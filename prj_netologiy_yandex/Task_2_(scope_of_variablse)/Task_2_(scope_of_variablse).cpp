// Task_2_(scope_of_variables).cpp 

#include<iostream>
#include<Windows.h>

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
    //шаблонная функция сложение
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x + y;
    }
};
namespace calc_subtraction {
    //шаблонная функция вычитание
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x - y;
    }
};
namespace calc_division {
    //шаблонная функция деление
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x / y;
    }
};
namespace calc_multiplication {
    //шаблонная функция умножение
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x * y;
    }
};

// простарнство имен ввода данных
namespace calc_input {
    // функция ввода  
    std::pair <double,double> calc(const std::string& text_1, const std::string& text_2 ) {
        auto x{ 0 }, y{ 0 };
        std::cout << text_1;
        std::cin >> x;
        std::cout << text_2;
        std::cin >> y;
        std::cout << "\n";
        std::cout << "x = " << x << ", " << "y = " << y << "\n";

        return { x, y };
    }
};

// простарнство имен выбора действия
namespace calc_var {
    static enum Var_action {
        SUUM = 1,
        SUBSTR,
        MULTIPL,
        DEVIS,
        ALL
    };
 // функция выбора действия
        int calc(const std::string& text_1) {
            int x_var{ 0 };
            std::string text_var{};

            do
            {
                std::cout << std::endl;
                std::cout << text_1;
                std::cin >> text_var;
                std::cout << std::endl;

                if (text_var == "+") {
                    x_var = 1;
                    break;
                }
                else if (text_var == "-") {
                    x_var = 2;
                    break;
                }
                else if (text_var == "*") {
                    x_var = 3;
                    break;
                }
                else if (text_var == "/") {
                    x_var = 4;
                    break;
                }
                else if (text_var == "A") {
                    x_var = 5;
                    break;
                } else {
                    std::cout << "Incorсect data!";
                    std::cout << std::endl;
                    continue;
                }
            } while (true);
            return x_var;
        } 
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
            
        std::pair<double, double> x_y{};

        std::cout << "Task 2 (scope of variables)";
        std::cout << "\n" << std::endl;

        x_y = calc_input::calc("Введите переменную Х: ", "Введите переменную Y: ");
    
            switch (calc_var::calc("Введите действие (+, -, *, /) или выберите все сразу (А): "))
            {
            case (calc_var::SUUM): {
                std::cout << "Сложение: " << "\t" << calc_summ::calc(x_y.first, x_y.second) << "\n";
                    break;
                }
            case (calc_var::SUBSTR): {
                std::cout << "Вычитание: " << "\t" << calc_subtraction::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            case (calc_var::MULTIPL): {
                std::cout << "Умножение: " << "\t" << calc_multiplication::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            case (calc_var::DEVIS): {
                std::cout << "Деление: " << "\t" << calc_division::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            case (calc_var::ALL): {
                std::cout << "Сложение: " << "\t" << calc_summ::calc(x_y.first, x_y.second) << "\n";
                std::cout << "Вычитание: " << "\t" << calc_subtraction::calc(x_y.first, x_y.second) << "\n";
                std::cout << "Умножение: " << "\t" << calc_multiplication::calc(x_y.first, x_y.second) << "\n";
                std::cout << "Деление: " << "\t" << calc_division::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            default:
                break;
            }
        std::cout << std::endl;
    } 
    while (UserWantExitProgram());
}

