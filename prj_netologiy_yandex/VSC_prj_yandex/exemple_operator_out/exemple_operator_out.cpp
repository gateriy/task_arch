п»ї// exemple_operator_out.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.



#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

template < typename Key, typename Value>
ostream& operator<<(ostream& out_map, const map<Key, Value>& container);

template < typename Element>
ostream& operator<<(ostream& out, const vector<Element>& container);

template < typename Element>
ostream& operator<<(ostream& out, const set<Element>& container);

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << ", "s << p.second << ')';
}

template < typename Docums>
void Print(ostream& out, const Docums& container) {

    bool i = 1;
    for (const auto& element : container) {
        if (!i) {
            out << ", "s;
        }
        i = 0;
        out << element;
    }
}

/*template < typename Key, typename Value>
void Print_map(ostream& out, const map<Key, Value>& container) {

    bool i = 1;
    for (const auto& [a,b] : container) {
        if (!i) {
            out << ", "s;
        }
        i = 0;
        out << '(';
        out << a ;
        out << ", "s;
        out << b;
        out << ')';
    }
}*/

template < typename Element>
ostream& operator<<(ostream& out, const vector<Element>& container) { 
    out << "["s;
    Print(out, container);
    out << "]"s;
    return out;
}

template < typename Element>
ostream& operator<<(ostream& out, const set<Element>& container) {
    out << "{"s;
    Print(out, container);
    out << "}"s;
    return out;
}

template < typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& container) {
    out << "<"s;
    Print(out, container);
    out << ">"s;
    return out ;
}


int main() {
    setlocale(LC_ALL, "Russian");


    const set<string> cats = { "РњСѓСЂРєР°"s, "Р‘РµР»РєР°"s, "Р“РµРѕСЂРіРёР№"s, "Р СЋСЂРёРє"s };
    cout << cats << endl;
    const vector<int> ages = { 10, 5, 2, 12 };
    cout << ages << endl;
    const map<string, int> cat_ages = {
        {"РњСѓСЂРєР°"s, 10},
        {"Р‘РµР»РєР°"s, 5},
        {"Р“РµРѕСЂРіРёР№"s, 2},
        {"Р СЋСЂРёРє"s, 12}
    };
    cout << cat_ages << endl;

    /*const set<string> cats = {"РњСѓСЂРєР°"s, "Р‘РµР»РєР°"s, "Р“РµРѕСЂРіРёР№"s, "Р СЋСЂРёРє"s};
    cout << cats << endl;

 const vector<double> ages_0 = { 10, 4, 2, 20 };
    cout << ages_0 << endl;

    const map<double> ages_0 = { 10, 4, 2, 20 };
    cout << ages_0 << endl;*/

 /*const vector<string> ages_1 = {"10"s, "5"s, "2"s, "12"s};
 cout << ages_1 << endl;

 const vector<string> ages_2 = { "10", "5", "2", "12" };
 cout << ages_2 << endl;

 const vector<char> ages_3 = { '1', '5', '3', '2'};
 cout << ages_3 << endl;

   const vector<int> ages = { 10, 4, 2, 20 };
    cout << ages << endl;*/

 
    return 0;
}