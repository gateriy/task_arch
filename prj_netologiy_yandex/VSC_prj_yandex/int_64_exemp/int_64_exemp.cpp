п»ї// int_64_exemp.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <cstdint>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    const auto min = numeric_limits<int64_t>::min();     // РјРёРЅРёРјР°Р»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ С‚РёРїР° int64_t
    const auto max = numeric_limits<uint64_t>::max();    // РјР°РєСЃРёРјР°Р»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ С‚РёРїР° uint64_t

    cout << min << endl;
    cout << max << endl;
    cout << min+max << endl; //РїСЂРµРІС‹С€РµРЅРёСЏ РЅРµС‚ РѕС‚РІРµС‚ -1 (РјРёРЅ Р±РѕР»СЊС€Рµ РЅР° 1)
    cout << min*2 << endl; //РїСЂРµРІС‹С€РµРЅРёРµ Р»РёРјРёС‚Р° РїРµСЂРµРјРµРЅРЅРѕР№ int
    cout << max*2 << endl; //РїСЂРµРІС‹С€РµРЅРёРµ Р»РёРјРёС‚Р° РїРµСЂРµРјРµРЅРЅРѕР№ int
    


}