п»ї// Task_2_(arr_*_&).cpp 

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

/*  РќР°РїРёС€РёС‚Рµ С„СѓРЅРєС†РёСЋ print, РєРѕС‚РѕСЂР°СЏ РїСЂРёРЅРёРјР°РµС‚ РЅР° РІС…РѕРґ РјР°СЃСЃРёРІ РїСЂРѕРёР·РІРѕР»СЊРЅРѕРіРѕ СЂР°Р·РјРµСЂР° Рё РІС‹РІРѕРґРёС‚ РµРіРѕ РЅР° СЌРєСЂР°РЅ.
Р’ РїСЂРѕРіСЂР°РјРјРµ СЃРѕР·РґР°Р№С‚Рµ РЅРµСЃРєРѕР»СЊРєРѕ РјР°СЃСЃРёРІРѕРІ СЂР°Р·РЅРѕРіРѕ СЂР°Р·РјРµСЂР° Рё РёСЃРїРѕР»СЊР·СѓР№С‚Рµ РґР»СЏ РІС‹Р·РѕРІР° РІР°С€РµР№ С„СѓРЅРєС†РёРё.  */

/*Р’Р°С€Р° Р·Р°РґР°С‡Р° вЂ” СЂРµР°Р»РёР·РѕРІР°С‚СЊ СѓР¶Рµ Р·РЅР°РєРѕРјСѓСЋ РІР°Рј С„СѓРЅРєС†РёСЋ swap (РІСЃРїРѕРјРЅРёС‚СЊ РјРѕР¶РЅРѕ Р·РґРµСЃСЊ), 
РЅРѕ СЃ РїРѕРјРѕС‰СЊСЋ СѓРєР°Р·Р°С‚РµР»РµР№, Р° РЅРµ СЃСЃС‹Р»РѕРє.*/


//С‚Р°РєР°СЏ СЂРµР°Р»РёР·Р°С†РёСЏ РїРѕР·РІРѕР»СЏРµС‚ РЅРµ Р·Р°РґР°РІР°С‚СЊ Р·Р°СЂР°РЅРµРµ С‚РёРї РїРµСЂРµРјРµРЅРЅРѕР№ РЅР° РєРѕС‚РѕСЂСѓСЋ СЃСЃС‹Р»Р°РµС‚СЃСЏ СѓРєР°Р·Р°С‚РµР»СЊ
template<typename T, typename S>
void swap(T* volume_x, S* volume_y) {

   /* *volume_x = *volume_x + *volume_y;
    *volume_y = *volume_x - *volume_y;
    *volume_x = *volume_x - *volume_y;*/

    T var{ 0 };

    var = *volume_x;
    *volume_x = *volume_y;
    *volume_y = var;
}

/*
//С„РёРєСЃРёСЂРѕРІР°РЅР°СЏ СЂРµР°Р»РёР·Р°С†РёСЏ РЅР° С‚РёРї РїРµСЂРµРјРµРЅРЅРѕР№ РЅР° РєРѕС‚РѕСЂСѓСЋ СЃСЃС‹Р»Р°РµС‚СЃСЏ СѓРєР°Р·Р°С‚РµР»СЊ
void swap(int* volume_x, int* volume_y) {

    *volume_x = *volume_x + *volume_y;
    *volume_y = *volume_x - *volume_y;
    *volume_x = *volume_x - *volume_y;
}
*/

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        std::string text_v;
        std::cout << "Task 2 (arr * &)";
        std::cout << "\n" << std::endl;
        std::cout << "(РїСЂРёРјРµРЅРёР» РѕРїСЂРµРґРµР»РµРЅРёРµ С„СѓРЅРєС†РёРё swap РєР°Рє template<typename T>, С‡С‚Рѕ РїРѕР·РІРѕР»СЏРµС‚ РЅРµ Р·Р°РґР°РІР°С‚СЊ С‚РёРї РїРµСЂРµРјРµРЅРЅС‹С…,\n";
        std::cout << "РЅР° РєРѕС‚РѕСЂС‹Рµ СЃСЃС‹Р»Р°РµС‚СЃСЏ СѓРєР°Р·Р°С‚РµР»СЊ Р·Р°СЂР°РЅРµРµ Рё РїРµСЂРµРѕРїСЂРµРґРµР»СЏС‚СЊ РїСЂРё РІС‹С‹Р·РѕРІРµ С„СѓРЅРєС†РёРё)";
        std::cout << "\n" << std::endl;

        int a{ 5 }, b{ 8 };
        std::cout << "РўРёРї РїРµСЂРµРјРµРЅРЅРѕР№ A: " << typeid(a).name() << std::endl;
        std::cout << "РўРёРї РїРµСЂРµРјРµРЅРЅРѕР№ B: " << typeid(b).name() << std::endl;
        std::cout <<  std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap(&a, &b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << std::endl;

      
        double  da{ 5.5 },  db{ 8.8 };
        std::cout << "РўРёРї РїРµСЂРµРјРµРЅРЅРѕР№ A: " << typeid(da).name() << std::endl;
        std::cout << "РўРёРї РїРµСЂРµРјРµРЅРЅРѕР№ B: " << typeid(db).name() << std::endl;
        std::cout << std::endl;
        std::cout << "a = " << da << ", b = " << db << std::endl;
        swap(&da, &db);
        std::cout << "a = " << da << ", b = " << db << std::endl;
        std::cout << std::endl;

        size_t  sa{ 5 };
        b = 8;
        std::cout << "РўРёРї РїРµСЂРµРјРµРЅРЅРѕР№ A: " << typeid(sa).name() << std::endl;
        std::cout << "РўРёРї РїРµСЂРµРјРµРЅРЅРѕР№ B: " << typeid(b).name() << std::endl;
        std::cout << std::endl;
        std::cout << "a = " << sa << ", b = " << b << std::endl;
        swap(&sa, &b);
        std::cout << "a = " << sa << ", b = " << b << std::endl;
        std::cout << std::endl;

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
