п»ї// Task_(string).cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <Windows.h>
#include <string>

// С„СѓРЅРєС†РёСЏ РІС‹С…РѕРґР° РёР· РїСЂРѕРіСЂР°РјРјС‹
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        std::cout << "Task 1 string";
        //std::cout << "()\n";
        std::cout << "\n" << std::endl;
        //РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ СЃРїСЂР°С€РёРІР°РµС‚ Сѓ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ 
        //РѕС‚РґРµР»СЊРЅРѕ РµРіРѕ РёРјСЏ Рё С„Р°РјРёР»РёСЋ, Р° Р·Р°С‚РµРј РїСЂРёРІРµС‚СЃС‚РІСѓРµС‚ РµРіРѕ.Р Р°Р±РѕС‚Сѓ РЅРµРѕР±С…РѕРґРёРјРѕ РІС‹РїРѕР»РЅРёС‚СЊ, РёСЃРїРѕР»СЊР·СѓСЏ РѕРїРµСЂР°С†РёРё РЅР°Рґ СЃС‚СЂРѕРєР°РјРё.

        std::string name, surname;


        std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ: ";
        std::cin >> name;
        std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ: ";
        std::cin >> surname;
        std::cout << "Р—РґСЂР°РІСЃС‚РІСѓР№С‚Рµ, " + name + " " + surname + "!" << std::endl;

        std::cout << std::endl;
    } while (UserWantExitProgram());
}