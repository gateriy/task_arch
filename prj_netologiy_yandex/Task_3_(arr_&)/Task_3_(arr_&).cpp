п»ї// Task_3_(arr_*_&).cpp 

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

/*  РќР°РїРёС€РёС‚Рµ С„СѓРЅРєС†РёСЋ reverse, РєРѕС‚РѕСЂР°СЏ РїСЂРёРЅРёРјР°РµС‚ РЅР° РІС…РѕРґ РјР°СЃСЃРёРІ РїСЂРѕРёР·РІРѕР»СЊРЅРѕРіРѕ СЂР°Р·РјРµСЂР° Рё В«СЂР°Р·РІРѕСЂР°С‡РёРІР°РµС‚В» 
РµРіРѕ РІ РѕР±СЂР°С‚РЅСѓСЋ СЃС‚РѕСЂРѕРЅСѓ вЂ” С‚Рѕ РµСЃС‚СЊ РїРµСЂРІС‹Р№ СЌР»РµРјРµРЅС‚ СЃС‚Р°РЅРѕРІРёС‚СЃСЏ РїРѕСЃР»РµРґРЅРёРј Рё РЅР°РѕР±РѕСЂРѕС‚. 
Р’С‹РІРµРґРёС‚Рµ РЅР° РєРѕРЅСЃРѕР»СЊ РјР°СЃСЃРёРІ РґРѕ РІС‹Р·РѕРІР° С„СѓРЅРєС†РёРё Рё РїРѕСЃР»Рµ РІС‹Р·РѕРІР° С„СѓРЅРєС†РёРё.

РћР±СЂР°С‚РёС‚Рµ РІРЅРёРјР°РЅРёРµ, С‡С‚Рѕ С„СѓРЅРєС†РёСЏ reverse РґРѕР»Р¶РЅР° РёР·РјРµРЅСЏС‚СЊ РїРµСЂРµРґР°РІР°РµРјС‹Р№ РµР№ РјР°СЃСЃРёРІ. 
Р­Р»РµРјРµРЅС‚С‹ РІ РЅС‘Рј РґРѕР»Р¶РЅС‹ РёР·РјРµРЅРёС‚СЊ СЃРІРѕР№ РїРѕСЂСЏРґРѕРє.  */

int* GeneratArr(int* arr, const int& size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    return arr;
}

//input array random
void PrintArr(int* arr, const int& size) {

    std::cout << "РњР°СЃСЃРёРІ СЂР°Р·РјРµСЂРѕРј [" << size << "]:\t";
    bool fist = true;

    for (int i = 0; i < size; ++i) {
        if (fist == false) {
            std::cout << ", ";
        }
        std::cout << arr[i];
        fist = false;
    }
    std::cout << std::endl;
}

int* Revers(int* arr_1, const int& size) {

    int sise_x{ size - 1 }, y{ 0 };
    
    for (int i = sise_x ; i > sise_x/2; --i) {       
        y = arr_1[i];
        arr_1[i]= arr_1[sise_x - i];
        arr_1[sise_x - i] = y;
    }
    return arr_1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   const int size{ 15 };
   int arr_1[size];

    do {
        std::string text_v;
        std::cout << "Task 3 (arr * &)";
        std::cout << "\n" << std::endl;
        std::cout << "(Р·Р°РїРѕР»РЅРµРЅРёРµ СЃС‚Р°С‚РёС‡РµСЃРєРёС… РјР°СЃСЃРёРІРѕРІ РїРѕСЃСЂРµРґСЃС‚РІРѕРј rand(), СЂРµР°Р»РёР·Р°С†РёСЏ РІ РѕС‚РґРµР»СЊРЅРѕР№ С„СѓРЅРєС†РёРё)\n";
        std::cout << "(РІРІРѕРґ Рё РІС‹РІРѕРґ РёР· С„СѓРЅРєС†РёРё С‡РµСЂРµР· СѓРєР°Р·Р°С‚РµР»Рё)";
        std::cout << "\n" << std::endl;

        std::cout << "РџСЂСЏРјРѕР№ РјР°СЃСЃРёРІ:\n";
        PrintArr(GeneratArr(arr_1, size), size);
        std::cout <<  std::endl;
        std::cout << "Р РµРІРµСЂСЃРёРІРЅС‹Р№ РјР°СЃСЃРёРІ:\n";
        PrintArr(Revers(arr_1, size), size);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
