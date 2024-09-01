п»ї// exemple_Term.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
template <typename Term>

map<Term, int> ComputeTermFreqs(const vector<Term>& terms) {
    map<Term, int> term_freqs;
    for (const Term& term : terms) {
        ++term_freqs[term];
    }
    return term_freqs;
}
pair<string, int> FindMaxFreqAnimal(const vector<pair<string, int>>& animals) {
    // РІРµСЂРЅРёС‚Рµ Р¶РёРІРѕС‚РЅРѕРіРѕ СЃ РјР°РєСЃРёРјР°Р»СЊРЅРѕР№ С‡Р°СЃС‚РѕС‚РѕР№
    int x = 0;
    pair<string, int> y;
    for (auto & [i,g] : ComputeTermFreqs(animals)) {
        
        if (g > x) {
            x = i.second;
            y = {i.first,i.second};
        }
    }
    return y;
}

int main() {
    const vector<pair<string, int>> animals = {
        {"Murka"s, 5},  // 5-Р»РµС‚РЅСЏСЏ РњСѓСЂРєР°
        {"Belka"s, 6},  // 6-Р»РµС‚РЅСЏСЏ Р‘РµР»РєР°
        {"Murka"s, 7},  // 7-Р»РµС‚РЅСЏСЏ РњСѓСЂРєР° РЅРµ С‚Р° Р¶Рµ, С‡С‚Рѕ 5-Р»РµС‚РЅСЏСЏ!

        {"Belka"s, 6},  // РЎРЅРѕРІР° 6-Р»РµС‚РЅСЏСЏ Р‘РµР»РєР°
            {"Murka"s, 5},  // РЎРЅРѕРІР° 5-Р»РµС‚РЅСЏСЏ РњСѓСЂРєР°
    };
    const pair<string, int> max_freq_animal = FindMaxFreqAnimal(animals);
    cout << max_freq_animal.first << " "s << max_freq_animal.second << endl;
}  
