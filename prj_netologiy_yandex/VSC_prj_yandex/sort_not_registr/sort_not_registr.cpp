п»ї// sort_not_registr.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype> // СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ tolower.

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

// РџСЂРёРІРѕРґРёС‚ СЃС‚СЂРѕРєСѓ Рє РЅРёР¶РЅРµРјСѓ СЂРµРіРёСЃС‚СЂСѓ РІС‚РѕСЂРѕР№ СЃРїРѕСЃРѕР± СЃРѕСЂС‚РёСЂРѕРІРєРё
/*string ToLowerCase(string s) {
    for (char& ch : s) {
        ch = tolower(static_cast<unsigned char>(ch));
    }
    return s;
}*/

int main() {
    // СЃС‡РёС‚Р°РµРј РІС…РѕРґРЅС‹Рµ РґР°РЅРЅС‹Рµ
    int Nn = 0;
    cin >> Nn;
   string str= ReadLine(); 
   vector<string> words = SplitIntoWords(str);

// РІР°СЂРёР°РЅС‚ СЃРѕСЂС‚РёСЂРѕРІРєРё С‡РµСЂРµР· ToLowerCase Рё lexicographical_compare С‚Рµ РґРІР° РІР»РѕР¶РµРЅРЅС‹С… РєРѕРјРїР°СЂР°С‚РѕСЂР°
   sort(begin(words), end(words), [](const string& left, const string& right) {
       return lexicographical_compare(
           begin(left), end(left),
           begin(right), end(right),
           [](char cl, char cr) { return tolower(cl) < tolower(cr); }
       );
       }
   );

//РґСЂСѓРіРѕР№ РІР°СЂРёР°РЅС‚ СЃРѕСЂС‚РёСЂРѕРІРєРё С‡РµСЂРµР· ToLowerCase
 /*  sort(words.begin(), words.end(), [](const string& left, const string& right) {
       return ToLowerCase(left) < ToLowerCase(right);
       });
 */

   for (string i : words) {
       cout << i << " "s; }
   cout <<endl;
}