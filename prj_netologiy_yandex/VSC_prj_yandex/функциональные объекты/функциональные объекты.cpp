п»ї// С„СѓРЅРєС†РёРѕРЅР°Р»СЊРЅС‹Рµ РѕР±СЉРµРєС‚С‹.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Animal {
    string name;
    int age;
    double weight;
};

template <typename Container, typename KeyMapper>
void SortBy(Container& container, KeyMapper key_mapper, bool reverse=false) {
    if (reverse) {
        sort(container.begin(), container.end(), [key_mapper](const auto& lhs, const auto& rhs) {
            return key_mapper(lhs) > key_mapper(rhs);
            });
    } else {
        sort(container.begin(), container.end(), [key_mapper](const auto& lhs, const auto& rhs) {
            return key_mapper(lhs) < key_mapper(rhs);
            });
    }
}

void PrintNames(const vector<Animal>& animals) {
    for (const Animal& animal : animals) {
        cout << animal.name << ' ';
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Animal> animals = {
        {"РњСѓСЂРєР°"s, 10, 5},
        {"Р‘РµР»РєР°"s, 5, 1.5},
        {"Р“РµРѕСЂРіРёР№"s, 2, 4.5},
        {"Р СЋСЂРёРє"s, 12, 3.1},
    };

    PrintNames(animals);
    SortBy(animals, [](const Animal& animal) { return animal.name; }, true);
    PrintNames(animals);
    SortBy(animals, [](const Animal& animal) { return animal.weight; });
    PrintNames(animals);
    return 0;

    return 0;
}