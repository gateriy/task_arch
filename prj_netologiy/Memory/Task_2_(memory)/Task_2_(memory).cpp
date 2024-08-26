// Task_2_(memory).

#include <iostream>
#include <tuple>

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

/*В этом задании вам нужно написать функцию swap, которая будет обменивать значения между двумя переменными. 
Посмотрите на эту часть программы:*/

template<typename T, typename S>
void swap(T& volume_x, S& volume_y) {

    std::tie(volume_x, volume_y) = std::make_tuple(volume_y, volume_x);
 
  /*
    volume_x = volume_x + volume_y;
    volume_y = volume_x - volume_y;
    volume_x = volume_x - volume_y;
    */
}

int main() {


    do {
        std::cout << "Task 2 (memory)";
        std::cout << "\n" << std::endl;

        int a{ 5 }, b{ 8 };

        std::cout << "a = " << a << ", b = " << b << std::endl;

        swap(a, b);

        std::cout << "a = " << a << ", b = " << b << std::endl;

      std::cout << std::endl;
    } while (UserWantExitProgram());
}