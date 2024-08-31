// Cource_prj_v2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
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

class Area {
public:

    //вывод массива в консоль
    void PrintArr() {
        
       // char pausa;
         _live_v = 0;
       
        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {

                std::cout << _arr_x[i][j];

                if (_arr_x[i][j] == _simvol_live) {
                    ++_live_v;
                }
            }
            std::cout  << std::endl;
        }
        std::cout << "Цикл: " << _score_cycle  << " Количество живых точек: " << _live_v << std::endl;
        //-----------------------------------------------------------
        if(_balance == true && _fist_print == false) {          
                std::cout << "Игра окончена! Достигнуто равновестное состояние!" << std::endl;
                _game_over = true;
        }
        //------------------------------------------------------------
        if (_live_v == 0 && _fist_print == false) {
            if (++_score_2 == 1) {
                std::cout << "Игра окончена! Отсутствуют живые клетки!" << std::endl;
                _game_over = true;
            }
        }

     

        if (_fist_print == true) {
            std::cout << std::endl;
            std::cout << "Начать игру!? ";
            std::system("pause");
            //std::cin >> pausa;
            _fist_print = false;
        }      
    }
    //ввод первичных данных по выбору консоль или файл
    void InputData() {
        std::string type_input{ "f" };
        bool correct_var_input{ true };

        do {
            correct_var_input = false;
            std::cout << "Выберите тип загрузки первичных данных (F - файл, С - консоль): ";
            std::cin >> type_input;
            std::cout << std::endl;

            if (type_input == "F" || type_input == "f") {
                InputDataArrFile();    //ввод первичных данных игры через файл
                correct_var_input = true;
               // std::cout << std::endl;
            }
            else
                if (type_input == "C" || type_input == "c") {
                    InputDataArr();        //ввод первичных данных игры через консоль
                    correct_var_input = true;
                  //  std::cout << std::endl;
                }
                else {
                    std::cout << "Не корректные данные! Повторите выбор." << std::endl;
                    std::cout << std::endl;
                }
        } while (!correct_var_input);
        std::cout << std::endl;
    }

    //основной блок игры
    void GameArea() {

        for (int i = 0; i < _cycle_live; ++i) {
           Sleep(300);
            //sleep(1);

            _score_cycle++;

            CheckTransformPoint();

            if (_game_over && _fist_print == false) {
                break;
            }
            else {               
                std::cout << "\033c";//очистка консоли
                //  system("CLS");
                PrintArr();          
            }

        }  
    }

    //удаление массива 1 (освобождение памяти)
    void DeletArr_x() {

        for (int j = 0; j < _y; ++j) {

            delete[] _arr_x[j];
        }
        delete[] _arr_x;

        _fist_print = true;
        _game_over = false;
        _score_cycle = 0;
       // _score_1 = 0;
        _score_2 = 0;
    }
    //удаление массива 2 (освобождение памяти)
    void DeletArr_x_2() {

        for (int j = 0; j < _y; ++j) {

            delete[] _arr_x_2[j];
        }
        delete[] _arr_x_2;
    }
    //данные массива 1
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
 
private:

    int             _x{ 0 };            //количество столбцов
    int             _y{ 0 };            //количество строк
    int             _live_v{ 0 };       //количество живых точек
  //  int             _live_v_old{ 0 };   //количество живых точек предыдущей итерации
    int             _priority{ 0 };     //определение приоритета жизнь или смерть при проходе массива (0 - одновременно)
    int             _cycle_live{ 0 };   //количество заданных циклов 
    int             _score_cycle{ 1 };  //счетчик циклов 
   // int             _score_1{ 0 };      //счетчик равновестных состояний 
    int             _score_2{ 0 };      //счетчик нулевых состояний 
    std::string**   _arr_x;             //указатель на массив 1
    std::string**   _arr_x_2;           //указатель на массив 2
    std::string     _simvol_area{ "" }; //символ поля
    std::string     _simvol_live{ "" }; //символ жизни
    bool            _fist_print{ true };//переменная первого запуска функции PrintArr()
    bool            _game_over{ false };
    bool            _balance{ false };  //флаг равновесия (true)
 
    //генерация двумерного массива
    std::string** CreateArr() {

        std::string** arr = new std::string * [_y];

        for (int i = 0; i < _y; ++i) {
            arr[i] = new std::string[_x]; // arr[строка - y][столбец - x]
        }
        return arr;
    }

    //ввод первичных данных пространства с консоли
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
        std::cout << "Введите приоритет игры (жизнь+смерть 0, жизнь 1, смерть 2, по поколениям 3): ";
        std::cin >> _priority;
        std::cout << "Введите координаты живых точек (y,x) парами через пробел: " << std::endl;
    }
    //ввод первичных данных пространства из файла
    void InputFistDataFile() {

        std::ifstream file("input_x.txt");

        if (!file.is_open()) {
            std::cout << "File \"input.txt\" has not been found!" << std::endl;
        }
        else {

            file >> _y >> _x; //считывание количества строк и столбцов
            file >> _cycle_live; //считывание количества циклов
            file >> _priority; //считывание приоритета
            file >> _simvol_area >> _simvol_live; // считывания символов пространства и жизни
        }
        file.close();

        std::cout << "Заданное количество стобцов: " << _x << std::endl;
        std::cout << "Заданное количество строк: " << _y << std::endl;
        std::cout << "Заданное символ отображение заполненеия поля: " << _simvol_area << std::endl;
        std::cout << "Заданное символ отображение живых точек: " << _simvol_live << std::endl;
        std::cout << "Заданное количество циклов: " << _cycle_live << std::endl;
        std::cout << "Заданное приоритет игры (жизнь+смерть 0, жизнь 1, смерть 2, по поколениям 3): " << _priority << std::endl;
    }

    //заполнение массива 1 и 2 символами пространства
    void InputArr() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {

                _arr_x[i][j] = _simvol_area; // arr[строка][столбец] заполненеие пространства массив 1
                _arr_x_2[i][j] = _simvol_area; // arr[строка][столбец] заполненеие пространства массив 2
            }
        }
    }

    //ввод первичных координат живых точек с консоли
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
                            ch == '9') {
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

                if (live_x >= 0 && live_y >= 0 && live_y < _y && live_x < _x) {
                    _arr_x[live_y][live_x] = _simvol_live;
                }
            }
        }
    }
    //ввод первичных координат живых точек из файла
    void VariablArrFile() {

        std::ifstream file("input_x.txt");
        std::string tmp{};

        if (!file.is_open()) {
            std::cout << "File \"input.txt\" has not been found!" << std::endl;
        }
        else {
            file >> tmp >> tmp;//проход не нужных строк в файле
            file >> tmp;//проход не нужных строк в файле
            file >> tmp;//проход не нужных строк в файле
            file >> tmp >> tmp;//проход не нужных строк в файле     
         
              // идет считывание из файла и преобразование в живые клетки
            int var_y = -1, var_x = -1;
             
           do{

                file >> var_y >> var_x; //считывание живых точек

                if (var_x >= 0 && var_y >= 0 && var_y < _y && var_x < _x) {
                    _arr_x[var_y][var_x] = _simvol_live; //заполнение точек в массив
                   
                  //  std::cout << var_y <<"  " << var_x << std::endl;

                }
               // var_x = 0;
                //var_y = 0;

                ++_live_v;//подсчет количества живых точек
            } 
            while (!file.eof());
        }
        file.close();

        std::cout << "Заданное количество живых точек: " << _live_v << std::endl;

    }

    //создание и первичное заполнение массива с консоли
    void InputDataArr() {

        InputFistData(); //ввод первичных данных массива с консоли

        _arr_x = CreateArr(); // генерация массива 1
        _arr_x_2 = CreateArr(); // генерация массива 2

        InputArr(); //заполненеие поля массива символами пространства

        VariablArr(); // ввод координат живых точек и внесение в массив с консоли
    }
    //создание и первичное заполнение массива из файла
    void InputDataArrFile() {

        InputFistDataFile(); //ввод первичных данных массива из файла

        _arr_x = CreateArr(); // генерация массива 1
        _arr_x_2 = CreateArr(); // генерация массива 2

        InputArr(); //заполненеие поля массива символами пространства

        VariablArrFile(); // ввод координат живых точек и внесение в массив из файла
    }

    //проверка состояния точки и подсчет ЖИВЫХ точек её окружения
    std::pair <std::string /*сост. точки*/, int/*колич. живых*/> CheckBlockPoint(std::string** arr, const int& var_y, const int& var_x) {

        int res{ 0 };
        std::string chek_point = _simvol_area;

        for (int a = (var_y - 1); a <= (var_y + 1); ++a) {
            for (int b = (var_x - 1); b <= (var_x + 1); ++b) {

                if (a >= 0 && b >= 0 && a < _y && b < _x) {

                    if (arr[a][b] == _simvol_live) {
                        ++res;
                    }
                }
            }
        }

        if (arr[var_y][var_x] == _simvol_live) {
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
    //трансформация точки по условию преобразования поколения и на основе двух массивов
    void TransformPointArr_x_To_Arr_x_2(const int& var_y, const int& var_x, const std::pair <std::string, int>& pnt) {

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
                TransformPointArr_Live(i, j, CheckBlockPoint(_arr_x, i, j)); //трансформация точки по условию зарождения                
            }
        }
    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки по условию Смерть
    void CheckTransformPoint_Death() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                //CheckBlockPoint(j, i);//подсчет живых клеток в блоке из 8 клеток вокруг исследуемой
                TransformPointArr_Death(i, j, CheckBlockPoint(_arr_x,i, j)); //трансформация точки по условиям смерти
            }
        }
    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки для одновременно проходящих процессов жизни/смерти
    void CheckTransformPoint_Live_Death() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                //CheckBlockPoint(j, i);//подсчет живых клеток в блоке из 8 клеток вокруг исследуемой
                TransformPointArr_Live_Death(i, j, CheckBlockPoint(_arr_x, i, j)); //трансформация точки по условиям Жизнь+ смерть
            }
        }
    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки на основе двух массивов
    void CheckTransformPoint_Arr_x_To_Arr_x_2() {

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                //CheckBlockPoint(j, i);//подсчет живых клеток в блоке из 8 клеток вокруг исследуемой
                TransformPointArr_x_To_Arr_x_2(i, j, CheckBlockPoint(_arr_x_2, i, j)); //трансформация первого массива по данным второго
            }
        }
    }
    //копирование массивов
    void CopyArr_x_To_Arr_x_2() {
        //копирование массива 1 в мвассив 2
        if (_balance == false) {
            for (int i = 0; i < _y; ++i) {
                for (int j = 0; j < _x; ++j) {
                    _arr_x_2[i][j] = _arr_x[i][j];
                }
            }
        }
    }
    //проверка массивов на равенство
    void CheckArr_x_To_Arr_x_2() {

        if (_fist_print == false) {
        _balance = true;

            for (int i = 0; i < _y; ++i) {
                for (int j = 0; j < _x; ++j) {

                    if (_arr_x_2[i][j] != _arr_x[i][j]) {
                        _balance = false;
                        break;
                    }
                }
            }
       }

    }
    //проверка точек массива, оределение окружения (живых) каждой точки, трансформация точки
    void CheckTransformPoint() {

        CopyArr_x_To_Arr_x_2();

        if (_balance == false) {

            //приоритет Жизнь+Смерть одновременно
            if (_priority == 0) {
                CheckTransformPoint_Live_Death();
            }
            //приоритет жизнь
            if (_priority == 1) {
                CheckTransformPoint_Live();
                CheckTransformPoint_Death();
            }
            //приоритет смерть
            if (_priority == 2) {
                CheckTransformPoint_Death();
                CheckTransformPoint_Live();
            }
            //обработка через второй массив
            if (_priority == 3) {
                CheckTransformPoint_Arr_x_To_Arr_x_2();
            }
        }
        CheckArr_x_To_Arr_x_2();      
    }
};


int main() { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Area LiveArea;//инициация класса

    do {
        //system("CLS"); //очистка консоли
        std::cout << "\033c";//очистка консоли

        std::cout << "Course project 1 ";
        std::cout << "(Проект игра Жизнь)\n";
        std::cout << std::endl;
 
        LiveArea.InputData();   //ввод первичных данных по выбору консоль или файл
        LiveArea.PrintArr();    //вывод в консоль первичных загруженных данных и массива           
        LiveArea.GameArea();    //основной блок игры  
        LiveArea.DeletArr_x();  //удаление массива 1
        LiveArea.DeletArr_x_2();//удаление массива 2

        std::cout << std::endl;
    } while (UserWantExitProgram());
}

