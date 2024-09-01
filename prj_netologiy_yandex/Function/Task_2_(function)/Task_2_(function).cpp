п»ї//Task_2_(function)

#include <iostream>
#include <windows.h>

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

/*РћРїСЂРµРґРµР»РёС‚Рµ, С‡С‚Рѕ РѕРЅР° РґРµР»Р°РµС‚, Рё РЅР°Р№РґРёС‚Рµ РґСѓР±Р»РёСЂСѓСЋС‰РёР№СЃСЏ РєРѕРґ. 
РЎРѕР·РґР°Р№С‚Рµ С„СѓРЅРєС†РёСЋ, РєРѕС‚РѕСЂР°СЏ Р±СѓРґРµС‚ СѓСЃС‚СЂР°РЅСЏС‚СЊ РґСѓР±Р»РёСЂРѕРІР°РЅРёРµ, Рё РІРјРµСЃС‚Рѕ РїРѕРІС‚РѕСЂСЏСЋС‰РµРіРѕСЃСЏ РєРѕРґР° РІС‹Р·С‹РІР°Р№С‚Рµ РµС‘. 
Р РµР·СѓР»СЊС‚Р°С‚ СЂР°Р±РѕС‚С‹ РїСЂРѕРіСЂР°РјРјС‹ РЅРµ РґРѕР»Р¶РµРЅ РёР·РјРµРЅРёС‚СЊСЃСЏ.*/

class myClass {
public:
    void inOut() {
        for (int i = 0; i < _size_value; ++i) {
            inResult(_value[i], _power[i]);
        }
    }
private:
    const  int _value[3]{ 5,3,4 };
    const  int _power[3]{ 2,3,4 };
    const  int _size_value{ sizeof(_value) / sizeof(_value[0]) };

    void inResult(const double& value, const int& power) {
        auto result{ 1. };
        for (int i = 0; i < power; ++i) {
            result *= value;
        }
        std::cout << value << " РІ СЃС‚РµРїРµРЅРё " << power << " = " << result << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    myClass inOutData;

    do {
        std::cout << "Task 2 (function)";
        std::cout << "\n" << std::endl;

        inOutData.inOut();

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
