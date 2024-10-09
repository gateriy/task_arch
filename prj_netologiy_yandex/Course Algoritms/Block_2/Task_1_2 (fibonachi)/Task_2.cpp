#include"Task_2.h"

int COUNT_f_2{ 0 };

std::vector<int> mem{ };

int inRowPosition_2() {
    std::cout << "Введите число: ";
    int position_x{ 0 };
    std::cin >> position_x;
    std::cout << std::endl;
    return position_x;
}

//посредством рекурсии + массив 
void inResultRecurs_2(int& position_x, unsigned int& res_1, unsigned int  res_2) {

    unsigned long long a = res_1;
    unsigned long long b = res_2;

    if ((a + b) <= UINT_MAX) {

        ++COUNT_f_2;
        mem.push_back(res_1);
  
        std::cout << res_1 << " ";

        --position_x;
        if (position_x == 0) {
            return;
        }

        inResultRecurs_2(position_x, res_2, (res_1 + res_2));
    }
    else {
        std::cout << res_1 << " ";
        std::cout << res_2 << " ";
        std::cout << "\n" << std::endl;
        std::cout << "Превышение предельного значения переменной (" << UINT_MAX << ") на следующей итерации!!! Задайте меньшее значение.\t";
        return;
    }
}

void Task_2() {
   
    std::cout << "Числа Фибоначчи (рекурсия)" << std::endl;
    unsigned int fist_data{ 0 };
    unsigned int fist_data_2{ 0 };
    char exit_x{ ' ' };

    do {
        int data_x = inRowPosition_2();
        COUNT_f_2 = 0;

        if (!mem.empty()) {

            for (int i : mem) {
                std::cout <<"(" << i << ") ";
            }

            if ((mem.size() < data_x)) {

                data_x = data_x - mem.size();
                fist_data = mem.at(mem.size() - 1) + mem.at(mem.size() - 2);
                fist_data_2 = mem.at(mem.size() - 1) + fist_data;
                inResultRecurs_2(data_x, fist_data, fist_data_2);
                std::cout << "\nКоличетсво запуска функции (рекурсий): " << COUNT_f_2 << std::endl;
            }
        }
        else {
            fist_data = 0;
            inResultRecurs_2(data_x, fist_data, fist_data + 1);
            std::cout << "\nКоличетсво запуска функции (рекурсий): " << COUNT_f_2 << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Ввести другое число? (y - да, нет - любой символ): ";
        std::cin >> exit_x;

        if (exit_x != 'y') { 
            break;
        }   

    } while (true); 

    mem.clear();
};