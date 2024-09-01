п»ї// Task_1_(file).cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.

#include <iostream>
#include <Windows.h>
#include <fstream> //РґР»СЏ СЂР°Р±РѕС‚С‹ СЃ С„Р°Р№Р»Р°РјРё
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
        //std::cout << std::endl;

        if (exit_Y_N == "Y"|| exit_Y_N == "y") {
            return false;
            break;
        }
        else if (exit_Y_N == "N"|| exit_Y_N == "n") {
            return true;
            break;
        }
        else {
            std::cout << "Incorrect data!" << std::endl;
            continue;
        }

    } while (true);
}

    enum I_O_File {
        Task_1=1,
        Task_2,
        Task_3,
        Task_4
    };

class InOutFileArr {

public:

    //СЃС‡РёС‹РІР°РЅРёРµ РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
    std::string InputTransformWay() {
        std::string way{ "" };
        std::string way_file{ "" };

        std::cout << "Р’РІРµРґРёС‚Рµ РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ (РµСЃР»Рё С„Р°Р№Р» РЅРµ РІ РєРѕСЂРЅРµРІРѕРј РєР°С‚Р°Р»РѕРіРµ РїСЂРѕРіСЂР°РјРјС‹): ";
        getline(std::cin >> std::ws, way_file);
      
        for (auto& ch : way_file) {
        
                if (ch == '\\' || ch == '/') {

                    way = way + '\\' + '\\';
                }
                else {
                    way = way + ch;
                }
        }
        return way;
    }
 
    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ СЃРѕР·РґР°РЅРёСЏ РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР°
    template<typename T>
    T* CreateOneArr(const int& cells, const T& type_arr) {

        T* arr = new T[cells];
        return arr;
    }     

    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ СѓРґР°Р»РµРЅРёСЏ РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР°
    template<typename T>
    void DeleteeOneArr(T* arr) {

          delete[] arr;
    }

    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ СЃРѕР·РґР°РЅРёСЏ РґРІСѓРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР°
    template<typename T>
    T** CreateDoublArr(const int& rows, const int& cells, const T& type_arr) {

        T** arr = new T * [rows];

        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cells];
        }
        return arr;
    }  

    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ СѓРґР°Р»РµРЅРёСЏ РґРІСѓРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР°
    template<typename T>
    void DeleteDoubleArr(T** arr, const int& rows ){
   
            for (int j = 0; j < rows; ++j) {

                delete[] arr[j];
            }
            delete[] arr;       
    }

    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ РїРµС‡Р°С‚Рё РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР° РІ РєРѕРЅСЃРѕР»СЊ
    template< typename T>
    void PrintArr(T* arr, const int& cells) {

        for (int i = 0; i < cells; ++i) {

            std::cout  << arr[i];
        }
        std::cout << std::endl;
    }

    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ РїРµС‡Р°С‚Рё РґРІСѓРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР° РІ РєРѕРЅСЃРѕР»СЊ
    template< typename T>
    void PrintDoubleArr(T** arr, const int& rows, const int& cells) {

        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cells; ++i) {

                std::cout << arr[j][i] ;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

//private:
};

int main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
       // setlocale(LC_ALL, "Russian");

        InOutFileArr ProgrammArr;

        int size_x{ 0 }, type_arr_x{ 1 };
        int cel{ 0 };   //СЃС‚РѕР»Р±С†С‹ РјР°СЃСЃРёРІР°
        int row{ 0 };   //СЃС‚СЂРѕРєРё РјР°СЃСЃРёРІР°
        int task{ 0 };  //
        int x_line{ 0 }; //СЃС‡РµС‚С‡РёРє РєРѕР»РёС‡РµСЃС‚РІР° СЃС‚СЂРѕРє РёР»Рё СЃР»РѕРІ РІ С„Р°Р№Р»Рµ
        std::string typ_ar{ "" }; //РїРµСЂРµРјРµРЅРЅР°СЏ Р·Р°РґР°СЋС‰Р°СЏ С‚РёРї РїРµСЂРµРјРµРЅРЅС‹С… РјР°СЃСЃРёРІР°
        std::string x_text { "" }; //СЃС‡РёС‚С‹РІР°РЅРёРµ СЃР»РѕРІ РёР»Рё СЃС‚СЂРѕРє РёР· С„Р°Р№Р»Р°
        std::string* arr;
        std::string** arr_doubl;

        do {
            std::cout << "\033c";//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё
            std::cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ Р·Р°РґР°РЅРёСЏ (1-4): ";
            std::cin >> task;

//-------------------------------------------
            if (task == I_O_File::Task_1) {
                std::cout << "Task 1 (file)";
                std::cout << "\n" << std::endl;

                do {
                    x_line = 0;
                    std::ifstream  f_in(ProgrammArr.InputTransformWay()); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ
                    if (f_in.is_open()) {

                        do {
                            f_in >> x_text;
                            ++x_line; //РїСЂРѕС…РѕРґ РїРѕ С„Р°Р№Р»Сѓ РІ СЂРµР¶РёРјРµ СЃС‡РёС‚С‹РІР°РЅРёСЏ Рё РїРѕРґСЃС‡РµС‚ СЌР»РµРјРµРЅС‚РѕРІ
                        } while (!f_in.eof());

                        cel = x_line;
                        arr = ProgrammArr.CreateOneArr(cel, typ_ar);//СЃРѕР·РґР°РЅРёРµ РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РґРёРЅР°РјРёС‡РµСЃРєРѕРіРѕ РјР°СЃСЃРёРІР° РїРѕ РєРѕР»РёС‡РµСЃС‚РІСѓ СЌР»РµРјРµРЅС‚РѕРІ СЃС‡РёС‚С‹РІР°РЅРёСЏ
                        f_in.clear(); //РѕС‡РёСЃС‚РєР° РїРѕС‚РѕРєР° РІРІРѕРґР° РёР· С„Р°Р№Р»Р°
                        f_in.seekg(0, std::ios::beg);//РІРѕР·РІСЂР°С‚ РєСѓСЂСЃРѕСЂР° РІ РЅР°С‡Р°Р»Рѕ С„Р°Р№Р»Р°

                        for (int i = 0; i < cel; ++i) {
                            f_in >> arr[i];
                        };

                        f_in.close();
                        std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ РїСЂРѕС‡РёС‚Р°РЅ!" << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
                    }
                } while (true);

                for (int i = 0; i < cel; ++i) {
                    std::cout << arr[i] << std::endl;
                }
                std::cout << std::endl;
                ProgrammArr.DeleteeOneArr(arr); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё
            }

 //---------------------------------------------
            if (task == I_O_File::Task_2) {

                std::cout << "Task 2 (file)";
                std::cout << "\n" << std::endl;

                do
                {
                    x_line = 0;
                    std::ifstream  f_in(ProgrammArr.InputTransformWay()); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ
                    if (f_in.is_open()) {
                        
                        f_in >> cel;   

                        arr = ProgrammArr.CreateOneArr(cel, typ_ar);
                   
                        for (int i = 0; i < cel; ++i) {
                            f_in >> arr[i];
                        };

                        f_in.close();
                        std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ РїСЂРѕС‡РёС‚Р°РЅ!" << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
                    }
                } while (true);


                std::string* arr_2;
                int j = (cel - 1);
                arr_2 = ProgrammArr.CreateOneArr(cel, typ_ar);

                for (int i = 0; i < cel; ++i) {
                    arr_2[j] = arr[i];
                    --j;
                }
                for (int i = 0; i < cel; ++i) {
                    arr[i] = arr_2[i];
                }
                ProgrammArr.DeleteeOneArr(arr_2); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё


                for (int i = 0; i < cel; ++i) {

                    if (i == 0) {
                    std::cout << arr[i];
                    }
                    else {
                        std::cout << " " << arr[i];
                    }
                }
                std::cout << std::endl;
                ProgrammArr.DeleteeOneArr(arr); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё

            }                    
        
//---------------------------------------------------
            if (task == I_O_File::Task_3) {
                std::cout << "Task 3 (file)";
                std::cout << "\n" << std::endl;

                std::cout << "Р’РІРµРґРёС‚Рµ СЂР°Р·РјРµСЂ РјР°СЃСЃРёРІР°: ";
                std::cin >> cel;
                std::cout << std::endl;
                arr = ProgrammArr.CreateOneArr(cel, typ_ar);

                for (int i = 0; i < cel; ++i) {

                    std::cout << "arr[0] = ";
                    std::cin >> arr[i];                   
               }
                std::cout << std::endl;

                std::string* arr_2;
                int j = (cel - 1);
                arr_2 = ProgrammArr.CreateOneArr(cel, typ_ar);

                for (int i = 0; i < cel; ++i) {
                    arr_2[j] = arr[i];
                    --j;
                }
                for (int i = 0; i < cel; ++i) {
                    arr[i] = arr_2[i];
                }
                ProgrammArr.DeleteeOneArr(arr_2); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё

                do {
                    std::ofstream  f_oupen(ProgrammArr.InputTransformWay()); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° Р·Р°РїРёСЃСЊ
                    if (f_oupen.is_open()) {

                        f_oupen << cel << std::endl;

                        for (int i = 0; i < cel; ++i) {
                            if (i == 0) {
                                f_oupen << arr[i];
                            }
                            else {
                                f_oupen << " " << arr[i];
                            }
                        };
                        f_oupen << std::endl;

                        f_oupen.close();
                        std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ Р·Р°РїРёСЃР°РЅ!" << std::endl;
                       // std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
                    }
                } while (true);
            }

 // -------------------------------------------------- -
                if (task == I_O_File::Task_4) {
                    std::cout << "Task 4 (file)";
                    std::cout << "\n" << std::endl;


                    do {
                        x_line = 0;
                        std::ifstream  f_in(ProgrammArr.InputTransformWay()); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ
                        if (f_in.is_open()) {

                            f_in >> row;
                            f_in >> cel;

                            arr_doubl = ProgrammArr.CreateDoublArr(row,cel, typ_ar);

                            for (int j = 0; j < row; ++j) {

                                for (int i = 0; i < cel; ++i) {
                                    f_in >> arr_doubl[j][i];
                                }
                            }

                            f_in.close();
                            std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ РїСЂРѕС‡РёС‚Р°РЅ!" << std::endl;
                            std::cout << std::endl;
                            break;
                        }
                        else {
                            std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
                        }
                    } while (true);

                    std::string** arr_2;
                    int j{ 0 };
                    arr_2 = ProgrammArr.CreateDoublArr(row, cel, typ_ar);

                    for (int a = 0; a < row; ++a) {
                        j = (cel);
                        for (int i = 0; i < cel; ++i) {
                            --j;
                            arr_2[a][j] = arr_doubl[a][i];                            
                        }
                        for (int i = 0; i < cel; ++i) {
                            arr_doubl[a][i] = arr_2[a][i];
                        }
                    }
                    ProgrammArr.DeleteDoubleArr(arr_2,row); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё

                    for (int j = 0; j < row; ++j) {
                        for (int i = 0; i < cel; ++i) {

                            if (i == 0) {
                                std::cout << arr_doubl[j][i];
                            }else
                            { 
                                std::cout << " " << arr_doubl[j][i];
                            }                         
                        }  
                        std::cout << std::endl;
                    }
                    ProgrammArr.DeleteDoubleArr(arr_doubl, row); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё
         
                }

            std::cout << std::endl;
        } while (UserWantExitProgram());

}

