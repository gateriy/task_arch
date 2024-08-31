// C++ Program to illustrate how to Parse Command Line 
// Arguments 
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

        if (exit_Y_N == "Y" || exit_Y_N == "y") {
            return false;
            break;
        }
        else if (exit_Y_N == "N" || exit_Y_N == "n") {
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
    Task_1 = 1,
    Task_2,
    Task_3,
    Task_4
};

class InOutFileArr {

public:

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

    //шаблонная функцие печати одномерного массива в консоль
    template< typename T>
    void PrintArr(T* arr, const int& cells) {

        for (int i = 0; i < cells; ++i) {

            std::cout << arr[i];
        }
        std::cout << std::endl;
    }

    template<typename T>
    void InputFile(const std::string& way, const T& type_arr) {

        InputTransformWay(way);
        CellsVarFile();

        do {        
            std::ifstream  f_in(_way); // открыли файл по заданному пути на чтение
            if (f_in.is_open()) {

        
                _arr_x = CreateOneArr(_cells, type_arr);//создание одномерного динамического массива по количеству элементов считывания
               
                f_in.clear(); //очистка потока ввода из файла
                f_in.seekg(0, std::ios::beg);//возврат курсора в начало файла
                for (int i = 0; i < _cells; ++i) {
                    f_in >> _arr_x[i];
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
    
    }


    std::string*    _arr_x;
    int             _cells{ 0 };
    std::string     _way{ "" };

    private:

      void CellsVarFile() {
            
            std::string x_text{ "" }; //считывание слов или строк из файла

            do {
                _cells = 0;
                std::ifstream  f_in(_way); // открыли файл по заданному пути на чтение

                if (f_in.is_open()) {

                    do {
                        f_in >> x_text;
                        ++_cells; //проход по файлу в режиме считывания и подсчет элементов
                    } while (!f_in.eof());

                    f_in.close();
                    std::cout << "Файл успешно прочитан! Всего элементов в файле: " << _cells << std::endl;
                    break;
                }
                else {
                    std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
                }
            } while (true);
        }

       //счиывание преобразование / или \ в "\\" пути к файлу с консоли
      void InputTransformWay(std::string way_file) {
            //std::string way{ "" };
            // std::string way_file{ "" };

             //std::cout << "Введите путь к файлу (если файл не в корневом каталоге программы): ";
            // getline(std::cin >> std::ws, way_file);

            for (auto& ch : way_file) {

                if (ch == '\\' || ch == '/') {

                    _way = _way + '\\' + '\\';
                }
                else {
                    _way = _way + ch;
                }
            }
      }

};



int main(int argc, char* argv[])
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    InOutFileArr ProgrammArr;

   // int size_x{ 0 };
   // int cel{ 0 };   //столбцы массива
  //  int row{ 0 };   //строки массива
    int task{ 0 };  //

    std::string typ_ar{ "" }; //переменная задающая тип переменных массива

   // std::string* arr;
  //  std::string way_1{ "" }; //путь к файлу 1
  //  std::string way_2{ "" }; //путь к файлу 2
    bool error = false;


    do {
       // std::cout << "\033c";//очистка консоли
       // std::cout << "Введите номер задания (1-4): ";
      
        std::cout << "Введены следующие параметры командной строки " << argc << " аргумент:" << std::endl;
        // чтение аргументов командной строки 
        int i = 0;
        while (i < argc) {
            std::cout << "Argument " << i  << ": " << argv[i] << std::endl;
            i++;
        }

        if ((std::string)argv[1] == "--Help") {
            std::cout << "Аргумент 1 - Номер задания: -1, -2" <<std::endl;
            std::cout << "Аргумент 2 - Полный путь к читаемому файлу" << std::endl;
            std::cout << "Аргумент 3 - Выбор вывода: -с <консоль>, -f <файл>" << std::endl;
            std::cout << "Аргумент 4 - Полный путь к файлу записи" << std::endl;
        }

        /*
        parsing -1 D:\С++\Project\VSC_prj_netologiy\prj_netologiy\parsing\x64\Debug\in.txt -c D:\С++\Project\VSC_prj_netologiy\prj_netologiy\parsing\x64\Debug\out.txt
        */
      
        error = false;
        
        if ((std::string)argv[1] == "-1") {
            task = 1;
        } else
        if ((std::string)argv[1] == "-2") {
            task = 2;
        }
        else {
            error = true;
        }

        //ProgrammArr.InputTransformWay(argv[2]);

        if ((std::string)argv[3] == "-c") {
            //task = 1;
        }
        else
            if ((std::string)argv[3] == "-f") {
               // task = 2;
            }
            else {
                error = true;
            }

        //ProgrammArr.InputTransformWay(argv[4]);

        if (error == true){
            std::cout << "Некорректные аргументы запуска программы!" << std::endl;
            system("pause");
            abort;
        } 






        //-------------------------------------------
        if (task == I_O_File::Task_1) {
            std::cout << "Task 1 (file)";
            std::cout << "\n" << std::endl;

            ProgrammArr.InputFile((std::string)argv[2], typ_ar);


            for (int i = 0; i < ProgrammArr._cells; ++i) {
                std::cout << ProgrammArr._arr_x[i] << std::endl;
            }
            std::cout << std::endl;
                   


            do {
                std::ofstream  f_oupen((std::string)argv[4]); // открыли файл по заданному пути на запись
                if (f_oupen.is_open()) {

                   // f_oupen << ProgrammArr._cells << std::endl;

                    for (int i = 0; i < ProgrammArr._cells; ++i) {
                        if (i == 0) {
                            f_oupen << ProgrammArr._arr_x[i];
                        }
                        else {
                            f_oupen << " " << ProgrammArr._arr_x[i];
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


            ProgrammArr.DeleteeOneArr(ProgrammArr._arr_x); //удаление массива освобождение памяти
        }

        std::cout << std::endl;
    } while (UserWantExitProgram());



return 0;
}