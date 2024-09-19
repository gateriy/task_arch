// Course_prg_2.cpp


#include <iostream>
#include <Windows.h>

#include "Config.h"

int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

     int var_menu{ 0 };

    Config_class config_game;

    do {

        var_menu = config_game.menu_var({ 6 }, { 0 });

        if (var_menu == 4) {

            config_game.get_var_type({ 3 });
            
            bool norm = config_game.get_var_game({ 5 });

            if (norm == false) {
                std::cout << std::endl;
                config_game.time_cout_char("ТС меньше 2 на гонке или не задана длина, тип гонки!!! Уточните данне!", "", "", "", "", true, 5, 4);
                system("pause");
            }
            else {
                std::cout << std::endl;
                config_game.time_cout_char("Играем снова!!! (1 да, 0 нет): ", "", "", "", "", false, 5, 5);
                var_menu = config_game.input_char_to_int({ 0,1 });
            }          
        }
        if (var_menu == 0) {
            system("cls");
            config_game.time_cout_char("До встречи в новой игре!!!", "", "", "", "", true, 5, 4);
            break;
        }

    } while (true);
       
    system("pause");
}
