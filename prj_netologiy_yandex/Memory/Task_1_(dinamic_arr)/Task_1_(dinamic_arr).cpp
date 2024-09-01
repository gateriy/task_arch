п»ї// Task_1_(dinamic_arr).cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
// Task_3_(dinanic_arr).cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
//

#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <Windows.h>

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

template< typename T>
T* CreateArr(const int& x, const T& type_x) {

    T* arr = new T [x];

    return arr;
}

template< typename T>
void InputdublArr(T* arr, const int& x) {

    std::cout << "Р’РІРµРґРёС‚Рµ РґР°РЅРЅС‹Рµ РІ РјР°СЃСЃРёРІ: " << std::endl;

    T input_x{ 0 };
    for (int i = 0; i < x; ++i) {

        std::cout << "arr[" << i << "] = ";
        std::cin >> input_x;
      
            arr[i] = input_x;
        }
}

template< typename T>
void PrintArr(T* arr, const int& x) {

    std::cout << std::endl;
    std::cout << "Р’РІРµРґС‘РЅРЅС‹Р№ РјР°СЃСЃРёРІ: "<< std::endl;

    for (int i = 0; i < x; ++i) {
       {
            std::cout << std::setprecision(2) << "arr[" << i <<"] = " << arr[i] << "\t";
        }
        std::cout << std::endl;
    }

}

template< typename T>
void DeletArr(T* arr) {

    delete[] arr;
}

template< typename T>
void DataMemoreArr(T*arr, const int& x) {
    size_t size_1, size_2, size_3;

    size_1 = sizeof(arr) ; //СЂР°Р·РјРµСЂ РјР°СЃСЃРёРІР° СѓРєР°Р·Р°С‚РµР»РµР№ РЅР° СЃС‚СЂРѕРєРё
    size_2 = sizeof(*arr) * x; //СЂР°Р·РјРµСЂ РјР°СЃСЃРёРІР° РѕРґРЅРѕР№ СЃС‚СЂРѕРєРё
 
    for (int i = 0; i < 30; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << "РўРёРї СЌР»РµРјРµРЅС‚РѕРІ РјР°СЃСЃРёРІР° : " << typeid(*arr).name() << std::endl;
    std::cout << std::endl;

    std::cout << size_2 << " bytes" << " <- Р Р°Р·РјРµСЂ РјР°СЃСЃРёРІР°" << std::endl;
    std::cout << std::endl;
}

template< typename T>
void CreatInputOutputDeleteVarArr(const int& x, const T& type_x) {

    T* d_arr_1 = CreateArr(x, type_x);  //СЃРѕР·РґР°РЅРёРµ РјР°СЃСЃРёРІР°
    DataMemoreArr(d_arr_1, x);                   //РІС‹РІРѕРґ РґР°РЅРЅС‹С… Рѕ РїР°РјСЏС‚Рё РјР°СЃСЃРёРІР° Рё С‚РёРїРµ РµРіРѕ РґР°РЅРЅС‹С…
    InputdublArr(d_arr_1, x);                //РЅР°РїРѕР»РЅРµРЅРµРёРµ РјР°СЃСЃРёРІР° (С‚Р°Р±Р»РёС†Р° СѓРјРЅРѕР¶РµРЅРёСЏ)
    PrintArr(d_arr_1, x);                    //РІС‹РІРѕРґ РЅР° РєРѕРЅСЃРѕР»СЊ РјР°СЃСЃРёРІР°
    DeletArr(d_arr_1);                       //РѕС‡РёСЃС‚РєР° РїР°РјСЏС‚Рё РјР°СЃСЃРёРІР° 
}

void VariablTypeArrOut(const int& x, const int& type_x) {
    // int type_x{ 0 };

    enum myType {
        INT = 1,
        DOUBLE,
        FLOAT,
        LONG,
        LONG_LONG,
        SIZE_T
    };

    switch (type_x)
    {
    case (myType::INT): {
        CreatInputOutputDeleteVarArr(x, static_cast<int>(type_x));
        break;
    }
    case (myType::DOUBLE): {
        CreatInputOutputDeleteVarArr(x, static_cast<double>(type_x));
        break;
    }
    case (myType::FLOAT): {
        CreatInputOutputDeleteVarArr(x, static_cast<float>(type_x));
        break;
    }
    case (myType::LONG): {
        CreatInputOutputDeleteVarArr(x, static_cast<long>(type_x));
        break;
    }
    case (myType::LONG_LONG): {
        CreatInputOutputDeleteVarArr(x, static_cast<long long>(type_x));
        break;
    }
    case (myType::SIZE_T): {
        CreatInputOutputDeleteVarArr(x, static_cast<size_t>(type_x));
        break;
    }
    default: {
        std::cout << std::endl;
        std::cout << "Incorrect data!" << std::endl;
        std::cout << std::endl;
        break;
    }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        int size_x{ 0 }, size_y{ 0 }, type_arr_x{ 1 };
        std::cout << "Task 1 (arr**)";
        std::cout << "\n" << std::endl;
        std::cout << "(СЃС‰Р·РґР°РЅРёРµ РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РґРёРЅР°РјРёС‡РµСЃРєРѕРіРѕ РјР°СЃСЃРёРІР° СЂР°Р·РЅС‹С… С‚РёРїРѕРІ РїРѕ РІС‹Р±РѕСЂСѓ)\n";
        std::cout << "(Р·Р°РїРѕР»РЅРµРЅРёРµ СЃ РєРѕРЅСЃРѕР»Рё)";
        std::cout << "\n" << std::endl;
        std::cout << "Р’РІРµРґРёС‚Рµ СЂР°Р·РјРµСЂ РјР°СЃСЃРёРІР°: ";
        std::cin >> size_x;
       // std::cout << "Р’РІРµРґРёС‚Рµ РєРѕР»РёС‡РµСЃС‚РІРѕ СЃС‚СЂРѕРє: ";
       // std::cin >> size_y;
        std::cout << std::endl;
        std::cout << "Р’РІРµРґРёС‚Рµ С‚РёРї СЌР»РµРјРµРЅС‚РѕРІ РјР°СЃСЃРёРІР° (Int(1), Double(2), Float(3), Long(4), Long_Long(5), Size_t(6)) С†РёС„СЂСѓ РІ СЃРєРѕР±РєР°С…: ";
        std::cin >> type_arr_x;
        std::cout << std::endl;

        VariablTypeArrOut(size_x, type_arr_x);

        std::cout << std::endl;
    } while (UserWantExitProgram());
}

