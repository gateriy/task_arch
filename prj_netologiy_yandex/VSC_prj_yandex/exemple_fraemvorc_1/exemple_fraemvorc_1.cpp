п»ї// exemple_fraemvorc_1.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <string>

using namespace std;

void PrintDiagnosticInformation() {
    cout << "Function name: "s << __FUNCTION__ << endl;
    cout << "File name: "s << __FILE__ << endl;
    cout << "Line number: "s << __LINE__ << endl;
    cout << "Line number: "s << __LINE__ << endl;
}
// Р”РёСЂРµРєС‚РёРІРѕР№ #define РѕР±СЉСЏРІР»СЏРµРј РјР°РєСЂРѕСЃ GREETING РїР°СЂР°РјРµС‚СЂР°РјРё s1 Рё s2
#define GREETING(s1, s2) cout << "Hello, "s << (s1) << " and "s << (s2) << endl


int main() {
    setlocale(LC_ALL, "Russian");

    PrintDiagnosticInformation();

    // Р‘СѓРґРµС‚ Р·Р°РјРµРЅРµРЅРѕ РЅР°:
    // cout << "Hello, "s << ("Ivan"s) << " and "s << ("Maria"s) << endl;
    GREETING("Ivan"s, "Maria"s);

    // Р‘СѓРґРµС‚ Р·Р°РјРµРЅРµРЅРѕ РЅР°:
    // cout << "Hello, "s << (5 + 5) << " and "s << (42) << endl;
    GREETING(5 + 5, 42);
}