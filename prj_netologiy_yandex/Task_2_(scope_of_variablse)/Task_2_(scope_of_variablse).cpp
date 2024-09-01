п»ї// Task_2_(scope_of_variables).cpp 

#include<iostream>
#include<Windows.h>

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

/*Р°С€Р° Р·Р°РґР°С‡Р° вЂ” СЃРѕР·РґР°С‚СЊ РЅРµСЃРєРѕР»СЊРєРѕ С„СѓРЅРєС†РёР№ СЃ РѕРґРёРЅР°РєРѕРІРѕР№ СЃРёРіРЅР°С‚СѓСЂРѕР№, С‚Рѕ РµСЃС‚СЊ СЃ РѕРґРёРЅР°РєРѕРІС‹Рј РёРјРµРЅРµРј,
РѕРґРёРЅР°РєРѕРІС‹РјРё РїР°СЂР°РјРµС‚СЂР°РјРё Рё РѕРґРёРЅР°РєРѕРІС‹Рј С‚РёРїРѕРј РІРѕР·РІСЂР°С‰Р°РµРјРѕРіРѕ Р·РЅР°С‡РµРЅРёСЏ, РЅРѕ СЃ СЂР°Р·РЅРѕР№ СЂРµР°Р»РёР·Р°С†РёРµР№.

РЎРѕР·РґР°Р№С‚Рµ С‡РµС‚С‹СЂРµ С„СѓРЅРєС†РёРё int calc(int x, int y), РєР°Р¶РґР°СЏ РёР· РєРѕС‚РѕСЂС‹С… Р±СѓРґРµС‚ СЂРµР°Р»РёР·РѕРІС‹РІР°С‚СЊ РѕРґРЅРѕ
РёР· С‡РµС‚С‹СЂС‘С… РїСЂРѕСЃС‚С‹С… Р°СЂРёС„РјРµС‚РёС‡РµСЃРєРёС… РґРµР№СЃС‚РІРёР№: СЃР»РѕР¶РµРЅРёРµ, РІС‹С‡РёС‚Р°РЅРёРµ, СѓРјРЅРѕР¶РµРЅРёРµ, РґРµР»РµРЅРёРµ.

x = 6, y = 9
РЎР»РѕР¶РµРЅРёРµ: 15
Р’С‹С‡РёС‚Р°РЅРёРµ: -3
РЈРјРЅРѕР¶РµРЅРёРµ: 54
Р”РµР»РµРЅРёРµ: 0

*/

namespace calc_summ {
    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёСЏ СЃР»РѕР¶РµРЅРёРµ
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x + y;
    }
};
namespace calc_subtraction {
    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёСЏ РІС‹С‡РёС‚Р°РЅРёРµ
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x - y;
    }
};
namespace calc_division {
    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёСЏ РґРµР»РµРЅРёРµ
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x / y;
    }
};
namespace calc_multiplication {
    //С€Р°Р±Р»РѕРЅРЅР°СЏ С„СѓРЅРєС†РёСЏ СѓРјРЅРѕР¶РµРЅРёРµ
    template<typename T, typename S>
    auto calc(const T& x, const S& y) {

        return x * y;
    }
};

// РїСЂРѕСЃС‚Р°СЂРЅСЃС‚РІРѕ РёРјРµРЅ РІРІРѕРґР° РґР°РЅРЅС‹С…
namespace calc_input {
    // С„СѓРЅРєС†РёСЏ РІРІРѕРґР°  
    std::pair <double,double> calc(const std::string& text_1, const std::string& text_2 ) {
        auto x{ 0 }, y{ 0 };
        std::cout << text_1;
        std::cin >> x;
        std::cout << text_2;
        std::cin >> y;
        std::cout << "\n";
        std::cout << "x = " << x << ", " << "y = " << y << "\n";

        return { x, y };
    }
};

// РїСЂРѕСЃС‚Р°СЂРЅСЃС‚РІРѕ РёРјРµРЅ РІС‹Р±РѕСЂР° РґРµР№СЃС‚РІРёСЏ
namespace calc_var {
    static enum Var_action {
        SUUM = 1,
        SUBSTR,
        MULTIPL,
        DEVIS,
        ALL
    };
 // С„СѓРЅРєС†РёСЏ РІС‹Р±РѕСЂР° РґРµР№СЃС‚РІРёСЏ
        int calc(const std::string& text_1) {
            int x_var{ 0 };
            std::string text_var{};

            do
            {
                std::cout << std::endl;
                std::cout << text_1;
                std::cin >> text_var;
                std::cout << std::endl;

                if (text_var == "+") {
                    x_var = 1;
                    break;
                }
                else if (text_var == "-") {
                    x_var = 2;
                    break;
                }
                else if (text_var == "*") {
                    x_var = 3;
                    break;
                }
                else if (text_var == "/") {
                    x_var = 4;
                    break;
                }
                else if (text_var == "A") {
                    x_var = 5;
                    break;
                } else {
                    std::cout << "IncorСЃect data!";
                    std::cout << std::endl;
                    continue;
                }
            } while (true);
            return x_var;
        } 
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
            
        std::pair<double, double> x_y{};

        std::cout << "Task 2 (scope of variables)";
        std::cout << "\n" << std::endl;

        x_y = calc_input::calc("Р’РІРµРґРёС‚Рµ РїРµСЂРµРјРµРЅРЅСѓСЋ РҐ: ", "Р’РІРµРґРёС‚Рµ РїРµСЂРµРјРµРЅРЅСѓСЋ Y: ");
    
            switch (calc_var::calc("Р’РІРµРґРёС‚Рµ РґРµР№СЃС‚РІРёРµ (+, -, *, /) РёР»Рё РІС‹Р±РµСЂРёС‚Рµ РІСЃРµ СЃСЂР°Р·Сѓ (Рђ): "))
            {
            case (calc_var::SUUM): {
                std::cout << "РЎР»РѕР¶РµРЅРёРµ: " << "\t" << calc_summ::calc(x_y.first, x_y.second) << "\n";
                    break;
                }
            case (calc_var::SUBSTR): {
                std::cout << "Р’С‹С‡РёС‚Р°РЅРёРµ: " << "\t" << calc_subtraction::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            case (calc_var::MULTIPL): {
                std::cout << "РЈРјРЅРѕР¶РµРЅРёРµ: " << "\t" << calc_multiplication::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            case (calc_var::DEVIS): {
                std::cout << "Р”РµР»РµРЅРёРµ: " << "\t" << calc_division::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            case (calc_var::ALL): {
                std::cout << "РЎР»РѕР¶РµРЅРёРµ: " << "\t" << calc_summ::calc(x_y.first, x_y.second) << "\n";
                std::cout << "Р’С‹С‡РёС‚Р°РЅРёРµ: " << "\t" << calc_subtraction::calc(x_y.first, x_y.second) << "\n";
                std::cout << "РЈРјРЅРѕР¶РµРЅРёРµ: " << "\t" << calc_multiplication::calc(x_y.first, x_y.second) << "\n";
                std::cout << "Р”РµР»РµРЅРёРµ: " << "\t" << calc_division::calc(x_y.first, x_y.second) << "\n";
                break;
            }
            default:
                break;
            }
        std::cout << std::endl;
    } 
    while (UserWantExitProgram());
}

