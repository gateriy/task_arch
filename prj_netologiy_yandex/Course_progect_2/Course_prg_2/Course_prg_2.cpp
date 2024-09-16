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

    std::pair <int, int> x_y{ 0,0 };

    dll_lib_1::Leaver lev_1;
    dll_lib_2::Leaver lev_2;
    dll_lib_3::Leaver lev_3;

    std::cout << "Hello World!\n";
    lev_1.leave();
    lev_2.leave();
    lev_3.leave();

    x_y = lev_1.menu_var();
    
    std::cout << lev_1.get_var_type(x_y.first,x_y.second) << std::endl;

    system("pause");
}
