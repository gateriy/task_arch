п»ї// Sort_numeric.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cctype> // СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ tolower.

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
//-----СЂР°Р·Р±РёРµРЅРёРµ СЃС‚СЂРѕРєРё РЅР° СЃР»РѕРІР° РїРѕ РїСЂРѕР±РµР»Р°Рј Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РІРµРєС‚РѕСЂР° СЃР»РѕРІ---------------------------
vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
//СЃС‡РёС‚РєР° СЂСЏРґР° РІ РІРёРґРµ string Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ РІ РІРµРєС‚РѕСЂ int
vector<int>GetLineStringToInt() {
    vector<int> n = {};
    string str = ReadLine();
    vector<string> words = SplitIntoWords(str);
        for (const string& i : words) {
        n.push_back(stoi(i));
    }
    return n;
}
//С„СѓРЅРєС†РёСЏ РІС‹РІРѕРґР°
void PrintNumbers(const vector<int>& numbers) {
    for (auto number : numbers) {
        cout << number << " "s;
    }
}

int main() {
    //СЃС‡РёС‚Р°Р»Рё РїРµСЂРІСѓСЋ С†РёС„СЂСѓ СЃС‚СЂРѕРєРё
    int Nn = 0;
    cin >> Nn;
    //СЃС‡РёС‚Р°Р»Рё РѕСЃС‚Р°Р»СЊРЅС‹Рµ С†РёС„СЂС‹ СЃС‚СЂРѕРєРё Рё СЃРѕР±СЂР°Р»Рё РІ РІРµРєС‚РѕСЂ
   vector<int> numeric = GetLineStringToInt();

   sort(numeric.begin(), numeric.end(), [](int n1, int n2) {
       /* РќР°РїРёС€РёС‚Рµ С‚РµР»Рѕ Р»СЏРјР±РґР°-С„СѓРЅРєС†РёРё СЃР°РјРѕСЃС‚РѕСЏС‚РµР»СЊРЅРѕ.
          РЎРЅР°С‡Р°Р»Р° РґРѕР»Р¶РЅС‹ СЂР°СЃРїРѕР»Р°РіР°С‚СЊСЃСЏ С‡С‘С‚РЅС‹Рµ С‡РёСЃР»Р° РІ РїРѕСЂСЏРґРєРµ РІРѕР·СЂР°СЃС‚Р°РЅРёСЏ,
          Р° СЃР»РµРґРѕРј Р·Р° РЅРёРјРё вЂ” РЅРµС‡С‘С‚РЅС‹Рµ С‡РёСЃР»Р° РІ РїРѕСЂСЏРґРєРµ СѓР±С‹РІР°РЅРёСЏ*/
       if (n1 % 2 == 0 && n2 % 2 == 0) { return n1 < n2; }
       if (n1 % 2 == 0 && n2 % 2 != 0) { return true; }
       if (n1 % 2 != 0 && n2 % 2 == 0) { return false; }
       if (n1 % 2 != 0 && n2 % 2 != 0) { return n1 > n2; }
       else return true;
/*x Рё y вЂ” С‡С‘С‚РЅС‹Рµ.Р’РµСЂРЅРёС‚Рµ СЂРµР·СѓР»СЊС‚Р°С‚ СЃСЂР°РІРЅРµРЅРёСЏ x < y
x С‡С‘С‚РЅРѕРµ, y РЅРµС‡С‘С‚РЅРѕРµ. Р§РёСЃР»Р° СѓРїРѕСЂСЏРґРѕС‡РµРЅС‹, РІРµСЂРЅРёС‚Рµ true
x РЅРµС‡С‘С‚РЅРѕРµ, y С‡С‘С‚РЅРѕРµ. Р§РёСЃР»Р° РЅРµСѓРїРѕСЂСЏРґРѕС‡РµРЅС‹, РІРµСЂРЅРёС‚Рµ false
x Рё y вЂ” РЅРµС‡С‘С‚РЅС‹Рµ. Р’РµСЂРЅРёС‚Рµ СЂРµР·СѓР»СЊС‚Р°С‚ СЃСЂР°РІРЅРµРЅРёСЏ x > y  */
       });
   //С‚РµСЃС‚РѕРІС‹Р№ РІС‹РІРѕРґ
 /*  cout << Nn << " -- "s;
    for (const int & i : numeric) {
        cout << i * i << " "s;   }
    cout << endl;*/
    // РІС‹РІРѕРґ
    PrintNumbers(numeric);
}   
