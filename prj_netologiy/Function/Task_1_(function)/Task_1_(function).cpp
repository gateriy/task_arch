//Task_1_(function)
#include <iostream>
#include <string>

//функция выхода из программы
bool UserWantExitProgram()
{

   std:: string exit_Y_N{};

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


/*дана программа 
В ней используются функции sum, diff, multiplication, division. 
Ваша задача — написать эти функции

int main(int argc, char** argv)
{
    int a = 5, b = 10;

    int s = sum(a, b);
    int dif = diff(a, b);
    int mult = multiplication(a, b);
    double div = division(a, b);

    std::cout << a << " + " << b << " = " << s << std::endl;
    std::cout << a << " - " << b << " = " << dif << std::endl;
    std::cout << a << " * " << b << " = " << mult << std::endl;
    std::cout << a << " / " << b << " = " << div << std::endl;

    return 0;
}  */

enum operator_x {
    SUMM,
    DIFF,
    MULY,
    DIV
};

template < typename A,typename B>
double inExecuteAlgorithm(const A& variable_a, const B& variable_b, const int & operat_x) {
    double result{ 0 };

    switch (operat_x) {
    case (SUMM): {
        result = variable_a + variable_b;
        break;
    }
    case (DIFF): {
        result = variable_a - variable_b;
        break;
    }
    case (MULY): {
        result = variable_a * variable_b;
        break;
    }
    case (DIV): {
        result = variable_a / variable_b;
        break;
    }
        default:{
            result = 0;
            break;
    }
    }
return result;
};

int main() {
  bool incorrect_data = true;
  double a{ 0 }, b{ 0 };
      //div{0};
  //int mult{ 0 }, dif{ 0 }, sum_x{ 0 };

    do {      

        std::cout << "Task 1 (function)";
        std::cout << "\n" << std::endl;
        std::cout << "Input variable A: ";
        std::cin >> a;
        std::cout << "Input variable B: ";
        std::cin >> b;
        std::cout << std::endl;

       std::string inp_operator_x{"D"};
       std::cout << "Input operator (+, -, *, /) or by default, as in the task (D): ";
       std::cin >> inp_operator_x;
       std::cout << std::endl;


       if (inp_operator_x == "+" || inp_operator_x == "D") {
        std::cout << a << " + " << b << " = " << inExecuteAlgorithm(a, b, operator_x::SUMM) << std::endl;
        incorrect_data = false;
       }
       if (inp_operator_x == "-" || inp_operator_x == "D") {
        std::cout << a << " - " << b << " = " << inExecuteAlgorithm(a, b, operator_x::DIFF) << std::endl;
        incorrect_data = false;
       }
       if (inp_operator_x == "*" || inp_operator_x == "D") {
        std::cout << a << " * " << b << " = " << inExecuteAlgorithm(a, b, operator_x::MULY) << std::endl;
        incorrect_data = false;
       }
       if (inp_operator_x == "/" || inp_operator_x == "D") {
        std::cout << a << " / " << b << " = " << inExecuteAlgorithm(a, b, operator_x::DIV) << std::endl;
        incorrect_data = false;
       }
       if (incorrect_data == true) {
           std::cout << "Incorrect data"  << std::endl;
           continue;
       }

        std::cout << std::endl;
        incorrect_data = false;
    } while (UserWantExitProgram());
}