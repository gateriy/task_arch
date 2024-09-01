п»ї// lamda_x.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//-----------------------------------
string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
//------------------------------
int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}
//-----СЂР°Р·Р±РёРµРЅРёРµ СЃС‚СЂРѕРєРё РЅР° СЃР»РѕРІР° РїРѕ РїСЂРѕР±РµР»Р°Рј Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РІРµРєС‚РѕСЂР° СЃР»РѕРІ---
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
//СЃС‡РёС‚Р°Р»Рё РІСЃРµ СЃС‚СЂРѕРєРё РёР· РЅР°Р±РѕСЂРѕРІ СЃР»РѕРІ Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°Р»Рё РІ СЃРєРІРѕР·РЅРѕР№ РІРµРєС‚РѕСЂ СЃР»РѕРІ
vector<string> SplitIntoVect(const vector<string>& queries) {
    vector<string> words;
    for (string query : queries) {
       query = ReadLine();
        for (const string& i : SplitIntoWords(query)) {
            words.push_back(i);
        }
    }
    return words;
}
//-----------------------------------------------------------------------
int main() {
    const int queryCount = ReadLineWithNumber();
    vector<string> queries(queryCount);
    vector<string> words = SplitIntoVect(queries);
    const string buzzword = ReadLine();  
  /*  for (string i : words) {
        cout << "["<<i<<"]" << "-"s ;
    }
    cout << endl;*/
  cout << count_if(words.begin(), words.end(), [buzzword](const string& query) {
        // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚Сѓ Р»СЏРјР±РґР°-С„СѓРЅРєС†РёСЋ
        // Р’РµСЂРЅРёС‚Рµ true, РµСЃР»Рё query СЃРѕРґРµСЂР¶РёС‚ СЃР»РѕРІРѕ buzzword
      if (buzzword == query) { return true; }
      else return false;
      }); 
}