п»ї// Task_2_(scope_of_variables).cpp 

#include<iostream>
#include<Windows.h>
//#include<string>

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

/*Р°С€Р° Р·Р°РґР°С‡Р° вЂ” СЃРѕР·РґР°С‚СЊ РЅРµСЃРєРѕР»СЊРєРѕ С„СѓРЅРєС†РёР№ СЃ РѕРґРёРЅР°РєРѕРІРѕР№ СЃРёРіРЅР°С‚СѓСЂРѕР№, С‚Рѕ РµСЃС‚СЊ СЃ РѕРґРёРЅР°РєРѕРІС‹Рј РёРјРµРЅРµРј, 
РѕРґРёРЅР°РєРѕРІС‹РјРё РїР°СЂР°РјРµС‚СЂР°РјРё Рё РѕРґРёРЅР°РєРѕРІС‹Рј С‚РёРїРѕРј РІРѕР·РІСЂР°С‰Р°РµРјРѕРіРѕ Р·РЅР°С‡РµРЅРёСЏ, РЅРѕ СЃ СЂР°Р·РЅРѕР№ СЂРµР°Р»РёР·Р°С†РёРµР№.

РЎРѕР·РґР°Р№С‚Рµ С‡РµС‚С‹СЂРµ С„СѓРЅРєС†РёРё int calc(int x, int y), РєР°Р¶РґР°СЏ РёР· РєРѕС‚РѕСЂС‹С… Р±СѓРґРµС‚ СЂРµР°Р»РёР·РѕРІС‹РІР°С‚СЊ РѕРґРЅРѕ 
РёР· С‡РµС‚С‹СЂС‘С… РїСЂРѕСЃС‚С‹С… Р°СЂРёС„РјРµС‚РёС‡РµСЃРєРёС… РґРµР№СЃС‚РІРёР№: СЃР»РѕР¶РµРЅРёРµ, РІС‹С‡РёС‚Р°РЅРёРµ, СѓРјРЅРѕР¶РµРЅРёРµ, РґРµР»РµРЅРёРµ.

x = 6, y = 9
РЎР»РѕР¶РµРЅРёРµ: 15
Р’С‹С‡РёС‚Р°РЅРёРµ: -3
РЈРјРЅРѕР¶РµРЅРёРµ: 54
Р”РµР»РµРЅРёРµ: 0

*/

namespace calc_summ {

    int calc(const int& x, const int& y) {

        return x + y;
    }
};
namespace calc_subtraction {

    int calc(const int& x, const int& y) {

        return x - y;
    }
};
namespace calc_division {

    int calc(const int& x, const int& y) {

        return x / y;
    }
};
namespace calc_multiplication {

    int calc(const int& x, const int& y) {

        return x * y;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        double x{ 0.0 }, y{ 0.0 };

        std::cout << "Task 2 (scope of variables)";
        std::cout << "\n" << std::endl;
        std::cout << "Р’РІРµРґРёС‚Рµ РїРµСЂРµРјРµРЅРЅСѓСЋ РҐ:";
        std::cin >> x;
        std::cout << "Р’РІРµРґРёС‚Рµ РїРµСЂРµРјРµРЅРЅСѓСЋ Y:";
        std::cin >> y;
        std::cout << "\n" << "x = " << x << "y = " << y << "\n";


        std::cout << "РЎР»РѕР¶РµРЅРёРµ: " << calc_summ::calc(x,y);
        std::cout << "Р’С‹С‡РёС‚Р°РЅРёРµ: " << calc_subtraction::calc(x, y);
        std::cout << "РЈРјРЅРѕР¶РµРЅРёРµ: " << calc_multiplication::calc(x, y);
        std::cout << "Р”РµР»РµРЅРёРµ: " << calc_division::calc(x, y);
        }

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
