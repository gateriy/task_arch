п»ї// Task_1_(arr_*_&).cpp 

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

 int*  GeneratArr(int* arr, const int& size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    return arr ;
}

 //input array random
 void PrintArr(int* arr, const int& size) {

     std::cout << "РњР°СЃСЃРёРІ СЂР°Р·РјРµСЂРѕРј [" << size << "]:\t";
     bool fist = true;

        for (int i = 0; i < size; ++i) {
            if (fist == false) {
                std::cout << ", ";
            }
           std::cout << arr[i] ;
           fist = false;
        }
        std::cout << std::endl;
    }

int main() {
     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);

        int size{ 0 };
        int arr_1[5];
        int arr_2[10];
        int arr_3[20];

    do {
        std::string text_v;
        std::cout << "Task 1 (arr * &)";
        std::cout << "\n" << std::endl;
        std::cout << "(Р·Р°РїРѕР»РЅРµРЅРёРµ СЃС‚Р°С‚РёС‡РµСЃРєРёС… РјР°СЃСЃРёРІРѕРІ РїРѕСЃСЂРµРґСЃС‚РІРѕРј rand(), СЂРµР°Р»РёР·Р°С†РёСЏ РІ РѕС‚РґРµР»СЊРЅРѕР№ С„СѓРЅРєС†РёРё)\n";
        std::cout << "(РІРІРѕРґ Рё РІС‹РІРѕРґ РёР· С„СѓРЅРєС†РёРё С‡РµСЂРµР· СѓРєР°Р·Р°С‚РµР»Рё)";
        std::cout << "\n" << std::endl;

        size = sizeof(arr_1) / sizeof(arr_1[0]);
        PrintArr(GeneratArr(arr_1, size), size);     

        size = sizeof(arr_2) / sizeof(arr_2[0]);
        PrintArr(GeneratArr(arr_2, size), size);

        size = sizeof(arr_3) / sizeof(arr_3[0]);
        PrintArr(GeneratArr(arr_3, size), size);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
