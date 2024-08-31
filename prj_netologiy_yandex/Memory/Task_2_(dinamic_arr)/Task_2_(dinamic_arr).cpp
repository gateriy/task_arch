// Task_2_(dinamic_arr).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <iomanip>
#include <Windows.h>

// функция выхода из программы
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
//создание массива
template< typename T>
T* CreateArr(const long long& x, const T& type_x) {

    T* arr = new T[x];

    return arr;
} 
//наполненеие массива нулями
template< typename T>
void InputArr(T* arr, const long long& x) {

    T input_x{ 0 };
    for (long long i = 0; i < x; ++i) {
       arr[i] = input_x;
    }
}
//вывод массива в консоль
template< typename T>
void PrintArr(T* arr, const long long& x) {

    std::cout << "Массив: ";

    for (long long i = 0; i < x; ++i) {
        
            std::cout << arr[i];
    }
    std::cout << std::endl;
}
//удаление массива и освобождение памяти
template< typename T>
void DeletArr(T* arr) {

    delete[] arr;
}
//вывод дополнительных данных о массивн
template< typename T>
void DataMemoreArr(T* arr, const long long& x) {
    size_t size_1, size_2, size_3;

    size_1 = sizeof(arr); //размер массива указателей на строки
    size_2 = sizeof(*arr) * x; //размер массива одной строки
  
    for (long long i = 0; i < 30; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << "Тип элементов массива : " << typeid(*arr).name() << std::endl;
    std::cout << size_2 << " bytes" << " <- Размер массива" << std::endl;
    std::cout << std::endl;
}
//комплексная шаблонная функция создание/наполнение/вывод/удаление массива
template< typename T>
void CreatInputOutputDeleteVarArr(const long long& x, const T& type_x) {

    T* d_arr_1 = CreateArr(x, type_x);    //создание массива
    InputArr(d_arr_1, x);                 //наполненеие массива (таблица умножения)
    PrintArr(d_arr_1, x);                 //вывод на консоль массива
    DataMemoreArr(d_arr_1, x);            //вывод данных о памяти массива и типе его данных   
    DeletArr(d_arr_1);                    //очистка памяти массива 
}
//выбор типа данных массива и запуск комплексной функции CreatInputOutputDeleteVarArr с определенным типом данных
void VariablTypeArrOut(const long long& x, const int& type_x) {

    enum myType {
        INT = 1,
        DOUBLE,
        FLOAT,
        LONG,
        LONG_LONG,
        SIZE_T
    };

    switch (type_x)
    {
    case (myType::INT): {
        CreatInputOutputDeleteVarArr(x, static_cast<int>(type_x));
        break;
    }
    case (myType::DOUBLE): {
        CreatInputOutputDeleteVarArr(x, static_cast<double>(type_x));
        break;
    }
    case (myType::FLOAT): {
        CreatInputOutputDeleteVarArr(x, static_cast<float>(type_x));
        break;
    }
    case (myType::LONG): {
        CreatInputOutputDeleteVarArr(x, static_cast<long>(type_x));
        break;
    }
    case (myType::LONG_LONG): {
        CreatInputOutputDeleteVarArr(x, static_cast<long long>(type_x));
        break;
    }
    case (myType::SIZE_T): {
        CreatInputOutputDeleteVarArr(x, static_cast<size_t>(type_x));
        break;
    }
    default: {
        std::cout << std::endl;
        std::cout << "Incorrect data!" << std::endl;
        std::cout << std::endl;
        break;
    }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        long long size_x{ 0 };
          int  type_arr_x{ 1 };
        std::cout << "Task 2 (arr**)";
        std::cout << "\n" << std::endl;
        std::cout << "(создание одномерного динамического массива разных типов по выбору)\n";
        std::cout << "(заполненеие нулями)";
        std::cout << "\n" << std::endl;
        std::cout << "Введите тип элементов массива (Int(1), Double(2), Float(3), Long(4), Long_Long(5), Size_t(6)) цифру в скобках: ";
        std::cin >> type_arr_x;
        std::cout << std::endl;
        std::cout << "Введите размер массива: ";
        std::cin >> size_x;
       // std::cout << std::endl;

        VariablTypeArrOut(size_x, type_arr_x);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}

