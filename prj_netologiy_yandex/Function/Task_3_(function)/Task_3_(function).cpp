п»ї//Task_3_(function)

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

/*РќР°РїРёС€РёС‚Рµ С„СѓРЅРєС†РёСЋ, РєРѕС‚РѕСЂР°СЏ РїСЂРёРЅРёРјР°РµС‚ РЅР° РІС…РѕРґ С†РµР»РѕРµ С‡РёСЃР»Рѕ вЂ” РЅРѕРјРµСЂ СЌР»РµРјРµРЅС‚Р° РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚Рё Р¤РёР±РѕРЅР°С‡С‡Рё 
вЂ” Рё РІРѕР·РІСЂР°С‰Р°РµС‚ С‡РёСЃР»Рѕ Р¤РёР±РѕРЅР°С‡С‡Рё, РёРјРµСЋС‰РµРµ СЌС‚РѕС‚ РЅРѕРјРµСЂ РІ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚Рё. Р¤СѓРЅРєС†РёСЏ РґРѕР»Р¶РЅР° Р±С‹С‚СЊ СЂРµРєСѓСЂСЃРёРІРЅРѕР№.*/

int inRowPosition() {
    std::cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ: ";
    int position_x{ 0 };
    std::cin >> position_x;
    std::cout << std::endl;
    return position_x;
}
//РїРѕСЃСЂРµРґСЃС‚РІРѕРј СЂРµРєСѓСЂСЃРёРё
    void inResultRecurs(  int& position_x, long long& res_1, long long res_2) {
        std::cout << res_1 <<" ";             
        --position_x;
        if (position_x == 0) {
              return;
          }      
        inResultRecurs(position_x, res_2, (res_1 + res_2));
    }
//РїРѕСЃСЂРµРґСЃС‚РІРѕРј С†РёРєР»Р°
    void inResultFor(const int& position_x) {

        long long arr[2]{ 0,1 };
        long long res{ 0 };
        bool first = true;

        for (int i = 0; i < position_x; ++i) {

            if (first == false) {
                res = arr[1] + arr[0];
            }
            first = false;
            std::cout << res << " ";
            arr[0] = arr[1];
            arr[1] = res;
        }
    }

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    do {
        std::cout << "Task 3 (function)";
        std::cout << "\n" << std::endl;

        int data_x = inRowPosition();
        long long fist_data{ 0 };

        std::cout << "Р§РёСЃР»Р° Р¤РёР±РѕРЅР°С‡С‡Рё (С†РёРєР»):\t\t";
        inResultFor(data_x);
        std::cout << "\n" << std::endl;

        std::cout << "Р§РёСЃР»Р° Р¤РёР±РѕРЅР°С‡С‡Рё (СЂРµРєСѓСЂСЃРёСЏ):\t";
        inResultRecurs(data_x, fist_data, fist_data+1);
        std::cout << "\n"<<std::endl;

        std::cout << std::endl;
    } while (UserWantExitProgram());
}
