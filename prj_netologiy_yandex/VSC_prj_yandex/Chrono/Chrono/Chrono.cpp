п»ї// Chrono.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <chrono>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int SAMPLE_COUNT = 5;

/**
 * РћРїСЂРµРґРµР»СЏРµС‚, РєР°РєРёРµ РёРјРµРЅР° РёР· РІРµРєС‚РѕСЂР° candidates СЃРѕРґРµСЂР¶Р°С‚СЃСЏ РІРЅСѓС‚СЂРё РјРЅРѕР¶РµСЃС‚РІР° storage.
 * Р’РѕР·РІСЂР°С‰Р°РµС‚ РІРµРєС‚РѕСЂ, РіРґРµ РєР°Р¶РґРѕРјСѓ СЌР»РµРјРµРЅС‚Сѓ РёР· candidates СЃРѕРѕС‚РІРµС‚СЃС‚РІСѓРµС‚ РѕРґРЅРѕ РёР· С‡РёСЃРµР»:
 *  0 - СЌР»РµРјРµРЅС‚ РёР· candidates РѕС‚СЃСѓС‚СЃС‚РІСѓРµС‚ РІ storage
 *  1 - СЌР»РµРјРµРЅС‚ РёР· candidates РїСЂРёСЃСѓС‚СЃС‚РІСѓРµС‚ РІРЅСѓС‚СЂРё storage
 */
vector<int> CountNamesLong(const set<string>& storage, const vector<string>& candidates) {
    // Р­С‚Р° С„СѓРЅРєС†РёСЏ СЂР°Р±РѕС‚Р°РµС‚ РїСЂР°РІРёР»СЊРЅРѕ, РЅРѕ РЅРµРґРѕСЃС‚Р°С‚РѕС‡РЅРѕ Р±С‹СЃС‚СЂРѕ.
    // РќРµ СѓРґР°Р»СЏР№С‚Рµ Рё РЅРµ РёР·РјРµРЅСЏР№С‚Рµ РєРѕРґ СЌС‚РѕР№ С„СѓРЅРєС†РёРё.

    vector<int> output;
    for (auto& name : candidates) {
        // РџРѕРґСЃС‡РёС‚С‹РІР°РµРј РєРѕР»РёС‡РµСЃС‚РІРѕ РІС…РѕР¶РґРµРЅРёР№ name РІ storage СЃС‚Р°РЅРґР°СЂС‚РЅС‹Рј Р°Р»РіРѕСЂРёС‚РјРѕРј count
        output.push_back(count(storage.begin(), storage.end(), name));
    }
    return output;
}

// РќР°РїРёС€РёС‚Рµ С‚РµР»Рѕ С„СѓРЅРєС†РёРё CountNames, РєРѕС‚РѕСЂР°СЏ РІС‹РґР°С‘С‚ СЂРµР·СѓР»СЊС‚Р°С‚, Р°РЅР°Р»РѕРіРёС‡РЅС‹Р№ CountNamesLong,
// РЅРѕ РІС‹РїРѕР»РЅСЏРµС‚СЃСЏ Р±С‹СЃС‚СЂРµРµ Р·Р° СЃС‡С‘С‚ РёСЃРїРѕР»СЊР·РѕРІР°РЅРёСЏ РІСЃС‚СЂРѕРµРЅРЅРѕРіРѕ Р°Р»РіРѕСЂРёС‚РјР° count РІРјРµСЃС‚Рѕ РѕР±С‰РµРіРѕ
vector<int> CountNames(const set<string>& storage, const vector<string>& candidates) {
    vector<int> output;
    for (auto& name : candidates) {
        // РџРѕРґСЃС‡РёС‚С‹РІР°РµРј РєРѕР»РёС‡РµСЃС‚РІРѕ РІС…РѕР¶РґРµРЅРёР№ name РІ storage СЃС‚Р°РЅРґР°СЂС‚РЅС‹Рј Р°Р»РіРѕСЂРёС‚РјРѕРј count
        output.push_back(storage.count(name));

       // output.push_back(count(storage.begin(), storage.end(), name));
    }
    return output;
}

int main() {
    set<string> s;
    vector<string> v;
    string stra;
    string strb;

    for (int j = 0; j < 10000; ++j) {
        s.insert(stra);
        stra += "a"s;
        if (j % 2 == 0) {
            v.push_back(strb);
            strb += "b"s;
        }
        else {
            v.push_back(stra);
        }
    }

    cout << "Testing slow version" << endl;
    // Р—Р°РјРµСЂСЏРµРј РІСЂРµРјСЏ СЂР°Р±РѕС‚С‹ РЅРµСЃРєРѕР»СЊРєРѕ СЂР°Р·, С‚Р°Рє РєР°Рє РѕРЅРѕ РјРѕР¶РµС‚ РѕС‚Р»РёС‡Р°С‚СЊСЃСЏ РѕС‚ Р·Р°РїСѓСЃРєР° Рє Р·Р°РїСѓСЃРєСѓ
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        // Р—Р°СЃРµРєР°РµРј РІСЂРµРјСЏ Р·Р°РїСѓСЃРєР° С„СѓРЅРєС†РёРё
        auto begin = chrono::steady_clock::now();
        CountNamesLong(s, v);
        // Р—Р°СЃРµРєР°РµРј РІСЂРµРјСЏ Р·Р°РІРµСЂС€РµРЅРёСЏ С„СѓРЅРєС†РёРё
        auto end = chrono::steady_clock::now();

        // Р’С‹РІРѕРґРёРј РІСЂРµРјСЏ СЂР°Р±РѕС‚С‹ РІ РјРёРєСЂРѕСЃРµРєСѓРЅРґР°С…
        cout << "Time difference Long = "s
            << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[Вµs]"s << endl;
    }


    cout << "Testing fast version" << endl;
    // Р—Р°РјРµСЂСЏРµРј РІСЂРµРјСЏ СЂР°Р±РѕС‚С‹ РЅРµСЃРєРѕР»СЊРєРѕ СЂР°Р·, С‚Р°Рє РєР°Рє РѕРЅРѕ РјРѕР¶РµС‚ РѕС‚Р»РёС‡Р°С‚СЊСЃСЏ РѕС‚ Р·Р°РїСѓСЃРєР° Рє Р·Р°РїСѓСЃРєСѓ
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        // Р—Р°СЃРµРєР°РµРј РІСЂРµРјСЏ Р·Р°РїСѓСЃРєР° С„СѓРЅРєС†РёРё
        auto begin = chrono::steady_clock::now();
        CountNames(s, v);
        // Р—Р°СЃРµРєР°РµРј РІСЂРµРјСЏ Р·Р°РІРµСЂС€РµРЅРёСЏ С„СѓРЅРєС†РёРё
        auto end = chrono::steady_clock::now();

        // Р’С‹РІРѕРґРёРј РІСЂРµРјСЏ СЂР°Р±РѕС‚С‹ РІ РјРёРєСЂРѕСЃРµРєСѓРЅРґР°С…
        cout << "Time difference Long = "s
            << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[Вµs]"s << endl;
    }

    // Р’С‹ РјРѕР¶РµС‚Рµ Р·Р°РјРµСЂРёС‚СЊ РІСЂРµРјСЏ СЂР°Р±РѕС‚С‹ С„СѓРЅРєС†РёРё CountNames Рё СЃСЂР°РІРЅРёС‚СЊ РµС‘ СЃ РІСЂРµРјРµРЅРµРј
    // СЂР°Р±РѕС‚С‹ CountNamesLong
}