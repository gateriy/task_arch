// Task_1_(file).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <Windows.h>
#include <fstream> //для работы с файлами
#include <string>

// функция выхода из программы
bool UserWantExitProgram()
{
    std::string exit_Y_N{};

    do
    {
        //std::cout << std::endl;
        std::cout << "Exit programm (Y/N): ";
        std::cin >> exit_Y_N;
        //std::cout << std::endl;

        if (exit_Y_N == "Y"|| exit_Y_N == "y") {
            return false;
            break;
        }
        else if (exit_Y_N == "N"|| exit_Y_N == "n") {
            return true;
            break;
        }
        else {
            std::cout << "Incorrect data!" << std::endl;
            continue;
        }

    } while (true);
}

    enum I_O_File {
        Task_1=1,
        Task_2,
        Task_3,
        Task_4
    };

class InOutFileArr {

public:

    //счиывание преобразование / или \ в "\\" пути к файлу с консоли
    std::string InputTransformWay() {
        std::string way{ "" };
        std::string way_file{ "" };

        std::cout << "Введите путь к файлу (если файл не в корневом каталоге программы): ";
        getline(std::cin >> std::ws, way_file);
      
        for (auto& ch : way_file) {
        
                if (ch == '\\' || ch == '/') {

                    way = way + '\\' + '\\';
                }
                else {
                    way = way + ch;
                }
        }
        return way;
    }
 
    //шаблонная функцие создания одномерного массива
    template<typename T>
    T* CreateOneArr(const int& cells, const T& type_arr) {

        T* arr = new T[cells];
        return arr;
    }     

    //шаблонная функцие удаления одномерного массива
    template<typename T>
    void DeleteeOneArr(T* arr) {

          delete[] arr;
    }

    //шаблонная функцие создания двумерного массива
    template<typename T>
    T** CreateDoublArr(const int& rows, const int& cells, const T& type_arr) {

        T** arr = new T * [rows];

        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cells];
        }
        return arr;
    }  

    //шаблонная функцие удаления двумерного массива
    template<typename T>
    void DeleteDoubleArr(T** arr, const int& rows ){
   
            for (int j = 0; j < rows; ++j) {

                delete[] arr[j];
            }
            delete[] arr;       
    }

    //шаблонная функцие печати одномерного массива в консоль
    template< typename T>
    void PrintArr(T* arr, const int& cells) {

        for (int i = 0; i < cells; ++i) {

            std::cout  << arr[i];
        }
        std::cout << std::endl;
    }

    //шаблонная функцие печати двумерного массива в консоль
    template< typename T>
    void PrintDoubleArr(T** arr, const int& rows, const int& cells) {

        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cells; ++i) {

                std::cout << arr[j][i] ;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

//private:
};

int main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
       // setlocale(LC_ALL, "Russian");

        InOutFileArr ProgrammArr;

        int size_x{ 0 }, type_arr_x{ 1 };
        int cel{ 0 };   //столбцы массива
        int row{ 0 };   //строки массива
        int task{ 0 };  //
        int x_line{ 0 }; //счетчик количества строк или слов в файле
        std::string typ_ar{ "" }; //переменная задающая тип переменных массива
        std::string x_text { "" }; //считывание слов или строк из файла
        std::string* arr;
        std::string** arr_doubl;

        do {
            std::cout << "\033c";//очистка консоли
            std::cout << "Введите номер задания (1-4): ";
            std::cin >> task;

//-------------------------------------------
            if (task == I_O_File::Task_1) {
                std::cout << "Task 1 (file)";
                std::cout << "\n" << std::endl;

                do {
                    x_line = 0;
                    std::ifstream  f_in(ProgrammArr.InputTransformWay()); // открыли файл по заданному пути на чтение
                    if (f_in.is_open()) {

                        do {
                            f_in >> x_text;
                            ++x_line; //проход по файлу в режиме считывания и подсчет элементов
                        } while (!f_in.eof());

                        cel = x_line;
                        arr = ProgrammArr.CreateOneArr(cel, typ_ar);//создание одномерного динамического массива по количеству элементов считывания
                        f_in.clear(); //очистка потока ввода из файла
                        f_in.seekg(0, std::ios::beg);//возврат курсора в начало файла

                        for (int i = 0; i < cel; ++i) {
                            f_in >> arr[i];
                        };

                        f_in.close();
                        std::cout << "Файл успешно прочитан!" << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
                    }
                } while (true);

                for (int i = 0; i < cel; ++i) {
                    std::cout << arr[i] << std::endl;
                }
                std::cout << std::endl;
                ProgrammArr.DeleteeOneArr(arr); //удаление массива освобождение памяти
            }

 //---------------------------------------------
            if (task == I_O_File::Task_2) {

                std::cout << "Task 2 (file)";
                std::cout << "\n" << std::endl;

                do
                {
                    x_line = 0;
                    std::ifstream  f_in(ProgrammArr.InputTransformWay()); // открыли файл по заданному пути на чтение
                    if (f_in.is_open()) {
                        
                        f_in >> cel;   

                        arr = ProgrammArr.CreateOneArr(cel, typ_ar);
                   
                        for (int i = 0; i < cel; ++i) {
                            f_in >> arr[i];
                        };

                        f_in.close();
                        std::cout << "Файл успешно прочитан!" << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
                    }
                } while (true);


                std::string* arr_2;
                int j = (cel - 1);
                arr_2 = ProgrammArr.CreateOneArr(cel, typ_ar);

                for (int i = 0; i < cel; ++i) {
                    arr_2[j] = arr[i];
                    --j;
                }
                for (int i = 0; i < cel; ++i) {
                    arr[i] = arr_2[i];
                }
                ProgrammArr.DeleteeOneArr(arr_2); //удаление массива освобождение памяти


                for (int i = 0; i < cel; ++i) {

                    if (i == 0) {
                    std::cout << arr[i];
                    }
                    else {
                        std::cout << " " << arr[i];
                    }
                }
                std::cout << std::endl;
                ProgrammArr.DeleteeOneArr(arr); //удаление массива освобождение памяти

            }                    
        
//---------------------------------------------------
            if (task == I_O_File::Task_3) {
                std::cout << "Task 3 (file)";
                std::cout << "\n" << std::endl;

                std::cout << "Введите размер массива: ";
                std::cin >> cel;
                std::cout << std::endl;
                arr = ProgrammArr.CreateOneArr(cel, typ_ar);

                for (int i = 0; i < cel; ++i) {

                    std::cout << "arr[0] = ";
                    std::cin >> arr[i];                   
               }
                std::cout << std::endl;

                std::string* arr_2;
                int j = (cel - 1);
                arr_2 = ProgrammArr.CreateOneArr(cel, typ_ar);

                for (int i = 0; i < cel; ++i) {
                    arr_2[j] = arr[i];
                    --j;
                }
                for (int i = 0; i < cel; ++i) {
                    arr[i] = arr_2[i];
                }
                ProgrammArr.DeleteeOneArr(arr_2); //удаление массива освобождение памяти

                do {
                    std::ofstream  f_oupen(ProgrammArr.InputTransformWay()); // открыли файл по заданному пути на запись
                    if (f_oupen.is_open()) {

                        f_oupen << cel << std::endl;

                        for (int i = 0; i < cel; ++i) {
                            if (i == 0) {
                                f_oupen << arr[i];
                            }
                            else {
                                f_oupen << " " << arr[i];
                            }
                        };
                        f_oupen << std::endl;

                        f_oupen.close();
                        std::cout << "Файл успешно записан!" << std::endl;
                       // std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
                    }
                } while (true);
            }

 // -------------------------------------------------- -
                if (task == I_O_File::Task_4) {
                    std::cout << "Task 4 (file)";
                    std::cout << "\n" << std::endl;


                    do {
                        x_line = 0;
                        std::ifstream  f_in(ProgrammArr.InputTransformWay()); // открыли файл по заданному пути на чтение
                        if (f_in.is_open()) {

                            f_in >> row;
                            f_in >> cel;

                            arr_doubl = ProgrammArr.CreateDoublArr(row,cel, typ_ar);

                            for (int j = 0; j < row; ++j) {

                                for (int i = 0; i < cel; ++i) {
                                    f_in >> arr_doubl[j][i];
                                }
                            }

                            f_in.close();
                            std::cout << "Файл успешно прочитан!" << std::endl;
                            std::cout << std::endl;
                            break;
                        }
                        else {
                            std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
                        }
                    } while (true);

                    std::string** arr_2;
                    int j{ 0 };
                    arr_2 = ProgrammArr.CreateDoublArr(row, cel, typ_ar);

                    for (int a = 0; a < row; ++a) {
                        j = (cel);
                        for (int i = 0; i < cel; ++i) {
                            --j;
                            arr_2[a][j] = arr_doubl[a][i];                            
                        }
                        for (int i = 0; i < cel; ++i) {
                            arr_doubl[a][i] = arr_2[a][i];
                        }
                    }
                    ProgrammArr.DeleteDoubleArr(arr_2,row); //удаление массива освобождение памяти

                    for (int j = 0; j < row; ++j) {
                        for (int i = 0; i < cel; ++i) {

                            if (i == 0) {
                                std::cout << arr_doubl[j][i];
                            }else
                            { 
                                std::cout << " " << arr_doubl[j][i];
                            }                         
                        }  
                        std::cout << std::endl;
                    }
                    ProgrammArr.DeleteDoubleArr(arr_doubl, row); //удаление массива освобождение памяти
         
                }

            std::cout << std::endl;
        } while (UserWantExitProgram());

}

