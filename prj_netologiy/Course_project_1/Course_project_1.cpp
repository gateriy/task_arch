// Course priject 1

#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
//#include <unistd.h>

/*
3 2
4 3
5 4
6 5
7 6
8 7
9 8
5 4
4 3
3 2
6 5
7 6
8 7
2 1
5 4
8 7
9 8
3 2
4 3
6 5
*/

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

class Area {
public:

    //вывод массива в консоль
    void PrintArr() {
        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {

                std::cout << _arr_x[i][j];
            }
            std::cout << std::endl;;
        }
    }

    //создание и первичное заполнение массива
    void InputDataArr() {

        InputFistData(); //ввод первичных данных массива

        _arr_x = CreateArr(); // генерация массива

        InputArr(); //заполненеие поля массива

        VariablArr(); // ввод координат живых точек и внесение в массив

        std::cout << std::endl;
    }

    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки
     void CheckTransformPoint() {

         //приоритет жизнь
         if(_priority == 1) {
             CheckTransformPoint_Live();
             CheckTransformPoint_Death();
         }
         //приоритет смерть
         if (_priority == 2) {
             CheckTransformPoint_Death();
             CheckTransformPoint_Live();
         }
         //приоритет Жизнь+Смерть одновременно
         if (_priority == 0) {
             CheckTransformPoint_Live_Death();
         }

    }

    //даление массива (освобождение памяти)
    void DeletArr() {

        for (int j = 0; j < _y; ++j) {

            delete[] _arr_x[j];
        }
        delete[] _arr_x;
    }
    //данные массива
    void DataMemoreArr() {
        size_t size_1, size_2, size_3;

        size_1 = sizeof(*_arr_x) * _y; //размер массива указателей на строки
        size_2 = sizeof(**_arr_x) * _x; //размер массива одной строки
        size_3 = sizeof(**_arr_x) * _y * _x; //размер массива из "y" строк без массива указателей на строки

        for (int i = 0; i < 30; ++i) {
            std::cout << "-";
        }
        std::cout << std::endl;
        std::cout << "Тип элементов массива : " << typeid(**_arr_x).name() << std::endl;
        std::cout << std::endl;

        std::cout << size_1 << " bytes" << "\t<-- Размер массива указателей на строки массива" << std::endl;
        std::cout << size_2 << " bytes" << "\t<-- Размер строки массива" << std::endl;
        std::cout << size_3 << " bytes" << "\t<-- Размер элементов массива" << std::endl;
        std::cout << size_3 + size_1 << " bytes" << "\t<-- Общий размер двумерного массива" << std::endl;
        std::cout << std::endl;

    }

    int _cycle_live{ 0 };//количество циклов 
    
private:
    int             _x{ 0 };            //количество столбцов
    int             _y{ 0 };            //количество строк
    int             _live_v{ 0 };       //количество первичных живых точек
    std::string**   _arr_x;             //ссылка на массив
    std::string     _simvol_area{ "" }; //символ поля
    std::string     _simvol_live{ "" }; //символ жизни
    int             _priority{ 0 };// определение приоритета жизнь или смерть при проходе массива (0 - одновременно)

    //генерация двумерного массива
    std::string** CreateArr() {

        std::string** arr = new std::string* [_y]; 

        for (int i = 0; i < _y; ++i) {
            arr[i] = new std::string[_x]; // arr[строка - y][столбец - x]
        }
        return arr;
    }
    //заполнение массиа символами пространства
    void InputArr() {
      
        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {

                _arr_x[i][j] = _simvol_area; // arr[строка][столбец]
            }
        }
    }
    //ввод первичных данных пространства
    void InputFistData() {

        /*
        y/x 1 2 3
        1
        2
        3
        */

        std::cout << "Введите количество стобцов: ";
        std::cin >> _x;
       
        std::cout << "Введите количество строк: ";
        std::cin >> _y;
      
       // std::cout << std::endl;
        std::cout << "Введите символ отображение заполненеия поля: ";
        std::cin >> _simvol_area;
        std::cout << "Введите количество живых точек: ";
        std::cin >> _live_v;
        std::cout << "Введите символ отображение живых точек: ";
        std::cin >> _simvol_live;
        std::cout << "Введите количество циклов: ";
        std::cin >> _cycle_live;
        std::cout << "Введите приоритет игры (жизнь+смерть 0, жизнь 1, смерть 2): ";
        std::cin >> _priority;
        std::cout << "Введите координаты живых точек (y,x) парами через пробел: " << std::endl;
    }
    //ввод первичных координат живых точек
    void VariablArr() {
        int z{ 0 };
        bool asd{ false };
        std::string var[2]{ "0","0" };
        int live_x{ 0 }, live_y{ 0 }; //координаты первичных живых точек
        std::string text_x_y{ "" }, text_v{ "" };

        for (int g = 0; g <= _live_v; ++g) {
            live_x = 0;
            live_y = 0;
            z = 0;
        
            std::getline(std::cin, text_x_y);

            if (text_x_y != "") {
                for (const auto& ch : text_x_y) {
                    if (ch != ' ') {
                        if (ch == '0' || 
                            ch == '1' ||
                            ch == '2' ||
                            ch == '3' ||
                            ch == '4' ||
                            ch == '5' ||
                            ch == '6' ||
                            ch == '7' ||
                            ch == '8' ||
                            ch == '9' ) {
                            text_v = text_v + ch;
                        }
                        asd = true;
                    }
                    else { 
                        if (text_v != "") {
                            if (z < 2 && text_v != "") {
                                var[z] = text_v;
                            }
                            ++z;
                        }
                        asd = false;
                        text_v = "";
                    };
                 }
                if (asd == true) {
                    if (z < 2 && text_v != "") {
                        var[z] = text_v;
                    }
                     asd = false;
                     text_v = "";
                }
                live_x = stoi(var[1]);
                live_y = stoi(var[0]);

                _arr_x[live_y][live_x] = _simvol_live;
            }
        }
    } 
    //проверка состояния точки и подсчет ЖИВЫХ точек её окружения
    std::pair <std::string /*сост. точки*/, int/*колич. живых*/> CheckBlockPoint(const int& var_y, const int& var_x) {

        int res{ 0 };
        std::string chek_point = _simvol_area;



        for (int a = (var_y - 1); a <= (var_y + 1); ++a) {
            for (int b = (var_x - 1); b <= (var_x + 1); ++b) {

                if (a >= 0 && b >= 0 && a < _y && b < _x) {

                    if (_arr_x[a][b] == _simvol_live) {
                        ++res;
                    }
                }
            }
        }

        if (_arr_x[var_y][var_x] == _simvol_live) {
            chek_point = _simvol_live;
            res = res - 1;
        }
        return { chek_point, res };
    }
    //трансформация точки по условию зарождения
    void TransformPointArr_Live(const int& var_y, const int& var_x, const std::pair <std::string, int>& pnt) {

        //live 
        if (pnt.second == 3 && pnt.first == _simvol_area) {

            _arr_x[var_y][var_x] = _simvol_live;
        }
    }
    //трансформация точки по условию смерти
    void TransformPointArr_Death(const int& var_y, const int& var_x, const std::pair <std::string, int>& pnt) {

        //died
        if (pnt.second > 3 || pnt.second < 2) {

            _arr_x[var_y][var_x] = _simvol_area;
        }
    }
    //трансформация точки по условию одновременно проходящих процессов жизни/смерти
    void TransformPointArr_Live_Death(const int& var_y, const int& var_x, const std::pair <std::string, int>& pnt) {

        //live 
        if (pnt.second == 3 && pnt.first == _simvol_area) {

            _arr_x[var_y][var_x] = _simvol_live;
        }
        //died
        if (pnt.second > 3 || pnt.second < 2) {

            _arr_x[var_y][var_x] = _simvol_area;
        }
    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки по условию Жизнь
    void CheckTransformPoint_Live() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                //CheckBlockPoint(j, i);//подсчет живых клеток в блоке из 8 клеток вокруг исследуемой
                TransformPointArr_Live(i, j, CheckBlockPoint(i, j)); //трансформация точки по условию зарождения                
            }
        }
    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки по условию Смерть
    void CheckTransformPoint_Death() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                //CheckBlockPoint(j, i);//подсчет живых клеток в блоке из 8 клеток вокруг исследуемой
                TransformPointArr_Death(i, j, CheckBlockPoint(i, j)); //трансформация точки по условиям смерти
            }
        }
    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки для одновременно проходящих процессов жизни/смерти
    void CheckTransformPoint_Live_Death() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                //CheckBlockPoint(j, i);//подсчет живых клеток в блоке из 8 клеток вокруг исследуемой
                TransformPointArr_Live_Death(i, j, CheckBlockPoint(i, j)); //трансформация точки по условиям Жизнь+ смерть
            }
        }
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Area LiveArea;//инициация класса

    do {
        system("CLS");

        std::cout << "Course project 1";
        std::cout << "(Проект игра Жизнь)\n";
       // std::cout << "\n" << std::endl;

        LiveArea.InputDataArr();
        LiveArea.PrintArr();

        std::cout << "Продолжить? (введите любой символ и нажмите ввод)";  
        char pausa;
        std::cin >> pausa;

     //   int y, x;
       // std::cin >> y;
      //  std::cin >> x;


      //  std::cout << LiveArea.CheckBlockPoint(y, x).first << "   " << LiveArea.CheckBlockPoint(y, x).second << std::endl;
       // std::cout << "Продолжить? (введите любой символ и нажмите ввод)";
       // std::cin >> pausa;
      
        for (int i = 0; i < LiveArea._cycle_live; ++i) {
            Sleep(100);      
           // system("CLS");
           
            LiveArea.CheckTransformPoint();
            LiveArea.PrintArr();
            std::cout << "\n" << std::endl;
        }

        //sleep(1);
        //system("clear");   
         
        LiveArea.DeletArr();

        std::cout << std::endl;
    } while (UserWantExitProgram());
}

