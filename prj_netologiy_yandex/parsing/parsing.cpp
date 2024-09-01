п»ї// C++ Program to illustrate how to Parse Command Line 
// Arguments 
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

enum I_O_File {
    Task_1 = 1,
    Task_2,
    Task_3,
    Task_4
};

class InOutFileArr {

public:

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

    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёРµ РїРµС‡Р°С‚Рё РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР° РІ РєРѕРЅСЃРѕР»СЊ
    template< typename T>
    void PrintArr(T* arr, const int& cells) {

        for (int i = 0; i < cells; ++i) {

            std::cout << arr[i];
        }
        std::cout << std::endl;
    }

    template<typename T>
    void InputFile(const std::string& way, const T& type_arr) {

        InputTransformWay(way);
        CellsVarFile();

        do {        
            std::ifstream  f_in(_way); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ
            if (f_in.is_open()) {

        
                _arr_x = CreateOneArr(_cells, type_arr);//СЃРѕР·РґР°РЅРёРµ РѕРґРЅРѕРјРµСЂРЅРѕРіРѕ РґРёРЅР°РјРёС‡РµСЃРєРѕРіРѕ РјР°СЃСЃРёРІР° РїРѕ РєРѕР»РёС‡РµСЃС‚РІСѓ СЌР»РµРјРµРЅС‚РѕРІ СЃС‡РёС‚С‹РІР°РЅРёСЏ
               
                f_in.clear(); //РѕС‡РёСЃС‚РєР° РїРѕС‚РѕРєР° РІРІРѕРґР° РёР· С„Р°Р№Р»Р°
                f_in.seekg(0, std::ios::beg);//РІРѕР·РІСЂР°С‚ РєСѓСЂСЃРѕСЂР° РІ РЅР°С‡Р°Р»Рѕ С„Р°Р№Р»Р°
                for (int i = 0; i < _cells; ++i) {
                    f_in >> _arr_x[i];
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
    
    }


    std::string*    _arr_x;
    int             _cells{ 0 };
    std::string     _way{ "" };

    private:

      void CellsVarFile() {
            
            std::string x_text{ "" }; //СЃС‡РёС‚С‹РІР°РЅРёРµ СЃР»РѕРІ РёР»Рё СЃС‚СЂРѕРє РёР· С„Р°Р№Р»Р°

            do {
                _cells = 0;
                std::ifstream  f_in(_way); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ

                if (f_in.is_open()) {

                    do {
                        f_in >> x_text;
                        ++_cells; //РїСЂРѕС…РѕРґ РїРѕ С„Р°Р№Р»Сѓ РІ СЂРµР¶РёРјРµ СЃС‡РёС‚С‹РІР°РЅРёСЏ Рё РїРѕРґСЃС‡РµС‚ СЌР»РµРјРµРЅС‚РѕРІ
                    } while (!f_in.eof());

                    f_in.close();
                    std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ РїСЂРѕС‡РёС‚Р°РЅ! Р’СЃРµРіРѕ СЌР»РµРјРµРЅС‚РѕРІ РІ С„Р°Р№Р»Рµ: " << _cells << std::endl;
                    break;
                }
                else {
                    std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
                }
            } while (true);
        }

       //СЃС‡РёС‹РІР°РЅРёРµ РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
      void InputTransformWay(std::string way_file) {
            //std::string way{ "" };
            // std::string way_file{ "" };

             //std::cout << "Р’РІРµРґРёС‚Рµ РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ (РµСЃР»Рё С„Р°Р№Р» РЅРµ РІ РєРѕСЂРЅРµРІРѕРј РєР°С‚Р°Р»РѕРіРµ РїСЂРѕРіСЂР°РјРјС‹): ";
            // getline(std::cin >> std::ws, way_file);

            for (auto& ch : way_file) {

                if (ch == '\\' || ch == '/') {

                    _way = _way + '\\' + '\\';
                }
                else {
                    _way = _way + ch;
                }
            }
      }

};



int main(int argc, char* argv[])
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    InOutFileArr ProgrammArr;

   // int size_x{ 0 };
   // int cel{ 0 };   //СЃС‚РѕР»Р±С†С‹ РјР°СЃСЃРёРІР°
  //  int row{ 0 };   //СЃС‚СЂРѕРєРё РјР°СЃСЃРёРІР°
    int task{ 0 };  //

    std::string typ_ar{ "" }; //РїРµСЂРµРјРµРЅРЅР°СЏ Р·Р°РґР°СЋС‰Р°СЏ С‚РёРї РїРµСЂРµРјРµРЅРЅС‹С… РјР°СЃСЃРёРІР°

   // std::string* arr;
  //  std::string way_1{ "" }; //РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ 1
  //  std::string way_2{ "" }; //РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ 2
    bool error = false;


    do {
       // std::cout << "\033c";//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё
       // std::cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ Р·Р°РґР°РЅРёСЏ (1-4): ";
      
        std::cout << "Р’РІРµРґРµРЅС‹ СЃР»РµРґСѓСЋС‰РёРµ РїР°СЂР°РјРµС‚СЂС‹ РєРѕРјР°РЅРґРЅРѕР№ СЃС‚СЂРѕРєРё " << argc << " Р°СЂРіСѓРјРµРЅС‚:" << std::endl;
        // С‡С‚РµРЅРёРµ Р°СЂРіСѓРјРµРЅС‚РѕРІ РєРѕРјР°РЅРґРЅРѕР№ СЃС‚СЂРѕРєРё 
        int i = 0;
        while (i < argc) {
            std::cout << "Argument " << i  << ": " << argv[i] << std::endl;
            i++;
        }

        if ((std::string)argv[1] == "--Help") {
            std::cout << "РђСЂРіСѓРјРµРЅС‚ 1 - РќРѕРјРµСЂ Р·Р°РґР°РЅРёСЏ: -1, -2" <<std::endl;
            std::cout << "РђСЂРіСѓРјРµРЅС‚ 2 - РџРѕР»РЅС‹Р№ РїСѓС‚СЊ Рє С‡РёС‚Р°РµРјРѕРјСѓ С„Р°Р№Р»Сѓ" << std::endl;
            std::cout << "РђСЂРіСѓРјРµРЅС‚ 3 - Р’С‹Р±РѕСЂ РІС‹РІРѕРґР°: -СЃ <РєРѕРЅСЃРѕР»СЊ>, -f <С„Р°Р№Р»>" << std::endl;
            std::cout << "РђСЂРіСѓРјРµРЅС‚ 4 - РџРѕР»РЅС‹Р№ РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ Р·Р°РїРёСЃРё" << std::endl;
        }

        /*
        parsing -1 D:\РЎ++\Project\VSC_prj_netologiy\prj_netologiy\parsing\x64\Debug\in.txt -c D:\РЎ++\Project\VSC_prj_netologiy\prj_netologiy\parsing\x64\Debug\out.txt
        */
      
        error = false;
        
        if ((std::string)argv[1] == "-1") {
            task = 1;
        } else
        if ((std::string)argv[1] == "-2") {
            task = 2;
        }
        else {
            error = true;
        }

        //ProgrammArr.InputTransformWay(argv[2]);

        if ((std::string)argv[3] == "-c") {
            //task = 1;
        }
        else
            if ((std::string)argv[3] == "-f") {
               // task = 2;
            }
            else {
                error = true;
            }

        //ProgrammArr.InputTransformWay(argv[4]);

        if (error == true){
            std::cout << "РќРµРєРѕСЂСЂРµРєС‚РЅС‹Рµ Р°СЂРіСѓРјРµРЅС‚С‹ Р·Р°РїСѓСЃРєР° РїСЂРѕРіСЂР°РјРјС‹!" << std::endl;
            system("pause");
            abort;
        } 






        //-------------------------------------------
        if (task == I_O_File::Task_1) {
            std::cout << "Task 1 (file)";
            std::cout << "\n" << std::endl;

            ProgrammArr.InputFile((std::string)argv[2], typ_ar);


            for (int i = 0; i < ProgrammArr._cells; ++i) {
                std::cout << ProgrammArr._arr_x[i] << std::endl;
            }
            std::cout << std::endl;
                   


            do {
                std::ofstream  f_oupen((std::string)argv[4]); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° Р·Р°РїРёСЃСЊ
                if (f_oupen.is_open()) {

                   // f_oupen << ProgrammArr._cells << std::endl;

                    for (int i = 0; i < ProgrammArr._cells; ++i) {
                        if (i == 0) {
                            f_oupen << ProgrammArr._arr_x[i];
                        }
                        else {
                            f_oupen << " " << ProgrammArr._arr_x[i];
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


            ProgrammArr.DeleteeOneArr(ProgrammArr._arr_x); //СѓРґР°Р»РµРЅРёРµ РјР°СЃСЃРёРІР° РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё
        }

        std::cout << std::endl;
    } while (UserWantExitProgram());



return 0;
}