п»ї// Task_2_(string).cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.

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
        std::cout << "\n" << std::endl;
        //РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ РїСЂРѕСЃРёС‚ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ СѓРіР°РґР°С‚СЊ СЃР»РѕРІРѕ, Р·Р°РїРёСЃР°РЅРЅРѕРµ 
        //РІ РєРѕРґРµ вЂ” С‚Рѕ РµСЃС‚СЊ РІРІРѕРґРёС‚СЊ СЃР»РѕРІР° РґРѕ С‚РµС… РїРѕСЂ, РїРѕРєР° РѕРґРЅРѕ РёР· РЅРёС… РЅРµ СЃРѕРІРїР°РґС‘С‚ СЃ Р·Р°РіР°РґР°РЅРЅС‹Рј СЃР»РѕРІРѕРј.

        std::string text_var, text_x;

        text_x = "РјР°Р»РёРЅР°";

        do
        {

        std::cout << "РЈРіР°РґР°Р№С‚Рµ СЃР»РѕРІРѕ: ";
        std::cin >> text_var;

        if (!text_var.compare(text_x)) {
        std::cout << "РџСЂР°РІРёР»СЊРЅРѕ! Р’С‹ РїРѕР±РµРґРёР»Рё! Р—Р°РіР°РґР°РЅРЅРѕРµ СЃР»РѕРІРѕ вЂ” " + text_x << std::endl;
        }
        else {
            std::cout << "РќРµРїСЂР°РІРёР»СЊРЅРѕ" << std::endl;
        }
            
        } while (text_var.compare(text_x));



        
        std::cout << std::endl;
    } while (UserWantExitProgram());
}