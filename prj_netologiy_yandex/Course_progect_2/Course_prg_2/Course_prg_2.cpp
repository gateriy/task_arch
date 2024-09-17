п»ї// Course_prg_2.cpp


#include <iostream>
#include <Windows.h>

#include "dll_1.h"
#include "dll_2.h"
#include "dll_3.h"

int main()
{
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

     int var_menu{ 0 };

    dll_lib_1::Leaver lev_1;
    dll_lib_2::Math_Game_0 lev_2;
    dll_lib_3::Leaver lev_3;

    std::cout << "Hello World!\n";
   

    var_menu = lev_1.menu_var();
    lev_1.get_var_type();
    lev_1.get_var_game();

    


   


    system("pause");
}
