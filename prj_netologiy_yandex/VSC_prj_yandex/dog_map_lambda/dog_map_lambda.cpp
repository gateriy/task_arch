п»ї// dog_map_lambda.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs, const map<string, int>& max_amount,
    map<string, int>& shelter) {
    int result=count_if(new_dogs.begin(), new_dogs.end(), [&shelter, &max_amount](const string& name) {
        // РІ map РІ [] РёР»Рё at() СЌС‚Рѕ РѕР±СЂР°С‰РµРЅРёРµ Рє РєР»СЋС‡Сѓ!!!! РёРјРµРЅРЅРѕ Рє РєР»СЋС‡Сѓ!
        if (shelter[name] < max_amount.at(name)) {
         ++shelter[name];// РїСЂРё РЅР°Р»РёС‡РёРё РєР»СЋС‡Р° name СѓРІРµР»РёС‡РёРІР°РµС‚ Р·РЅР°С‡РµРЅРёРµ РїСЂРё РѕС‚СЃСѓС‚СЃС‚РІСѓРёРё СЃРѕР·РґР°РµС‚ РЅРѕРІС‹Р№ РєР»СЋС‡ (!!!) name СЃ 0 Р·РЅР°С‡РµРЅРёРµРј
            return true;
        }
        else { return false; }

        });

    /* return count_if(new_dogs.begin(), new_dogs.end(),
        [&max_amount, &shelter](const string& name) {
            int& current_amount = shelter[name];
            if (current_amount < max_amount.at(name)) {
                ++current_amount;
                return true;
            } else {
                return false;
            }
        });*/


    return result;

} 

int main() {

    map<string, int> shelter{{"shepherd"s, 1},{"corgi"s, 3},};
    map<string, int> max_amount{{"shepherd"s, 2},{"corgi"s, 3},{"shiba inu"s, 1},};

    cout << CountAndAddNewDogs({ "shepherd"s, "shiba inu"s, "shiba inu"s, "corgi"s }, max_amount, shelter) << endl;
}