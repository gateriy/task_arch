п»ї// Task_1_(memory).

#include <iostream>
#include <vector>

//С„СѓРЅРєС†РёСЏ РІС‹С…РѕРґР° РёР· РїСЂРѕРіСЂР°РјРјС‹
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

/*Р”Р»СЏ РєР°Р¶РґРѕР№ РїРµСЂРµРјРµРЅРЅРѕР№ РІС‹РІРµРґРёС‚Рµ РЅР° РєРѕРЅСЃРѕР»СЊ РµС‘ Р°РґСЂРµСЃ Рё СЂР°Р·РјРµСЂ.*/

struct myStruct {
    int int_x{ 0 };
    size_t sise_t_x{ 0 };
    short short_x{ 0 };
    long long_x{ 0 };
    long long Long_long_x{ 0 };
    float float_x{ 0 };
    double double_x{ 0 };
    long double long_double_x{ 0 };
    bool bool_x{ 0 };

    std::vector <std::string> text{
    "int",
    "size_t",
    "short",
    "long",
    "long long",
    "float",
    "double",
    "long double",
    "bool" };
};

 template<typename T, typename S>
    void Result(T& volume, S& text) {
     //   std::cout   << "Adres = [ " << &volume << " ],\tsize = [ " << sizeof(volume) << " ] byte" << "\t<<< data type: " << typeid(volume).name() << "\n";
    std::cout << "Adres = [ " << &volume << " ],\tsize = [ " << sizeof(volume) << " ] byte" << "\t<<< data type: " << text << "\n";
    }

int main() {

    myStruct CreateMyStruct;

    do {
        std::cout << "Task 2 (function)";
        std::cout << "\n" << std::endl;

        Result(CreateMyStruct.int_x, CreateMyStruct.text[0]);
        Result(CreateMyStruct.sise_t_x, CreateMyStruct.text[1]);
        Result(CreateMyStruct.short_x, CreateMyStruct.text[2]);
        Result(CreateMyStruct.long_x, CreateMyStruct.text[3]);
        Result(CreateMyStruct.Long_long_x, CreateMyStruct.text[4]);
        Result(CreateMyStruct.float_x, CreateMyStruct.text[5]);
        Result(CreateMyStruct.double_x, CreateMyStruct.text[6]);
        Result(CreateMyStruct.long_double_x, CreateMyStruct.text[7]);
        Result(CreateMyStruct.bool_x, CreateMyStruct.text[8]);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}