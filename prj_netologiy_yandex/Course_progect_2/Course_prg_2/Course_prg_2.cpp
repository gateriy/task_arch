// Course_prg_2.cpp


#include <iostream>
#include <Windows.h>

#include "Config.h"
//#include "dll_1.h"
//#include "dll_2.h"
//#include "dll_3.h"

int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

     int var_menu{ 0 };

    Config_class config_game;



    do {

        var_menu = config_game.menu_var();

        if (var_menu == 4) {

            config_game.get_var_type();
            
            bool norm = config_game.get_var_game();

            if (norm == false) {
                system("COLOR 5");
                std::cout << std::endl;
                std::cout << "ТС меньше 2 на гонке или не задана длина, тип гонки!!! Уточните данне!" << std::endl;
                system("pause");
            }
            else {
                system("COLOR 7");
                std::cout << std::endl;
                std::cout << "Играем снова!!! (1 ДА, 0 НЕТ): ";
                var_menu = config_game.input_char_to_int({ 0,1 });
            }          
        }
        if (var_menu == 0) {
            system("cls");
            std::cout << "До встречи в новой игре!!!" << std::endl;
            break;
        }

    } while (true);



   
    system("pause");
}
