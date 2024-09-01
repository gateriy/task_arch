п»ї// Sprint_3_palindrom.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// РћРїСЂРµРґРµР»СЏРµС‚, Р±СѓРґРµС‚ Р»Рё СЃР»РѕРІРѕ РїР°Р»РёРЅРґСЂРѕРјРѕРј
// text РјРѕР¶РµС‚ Р±С‹С‚СЊ СЃС‚СЂРѕРєРѕР№, СЃРѕРґРµСЂР¶Р°С‰РµР№ СЃС‚СЂРѕС‡РЅС‹Рµ Р±СѓРєРІС‹ Р°РЅРіР»РёР№СЃРєРѕРіРѕ Р°Р»С„Р°РІРёС‚Р° Рё РїСЂРѕР±РµР»С‹
// РџСѓСЃС‚С‹Рµ СЃС‚СЂРѕРєРё Рё СЃС‚СЂРѕРєРё, СЃРѕСЃС‚РѕСЏС‰РёРµ С‚РѕР»СЊРєРѕ РёР· РїСЂРѕР±РµР»РѕРІ, - СЌС‚Рѕ РЅРµ РїР°Р»РёРЅРґСЂРѕРјС‹
bool IsPalindrome(const string& text) {
    //vector<char> x_text;
    string x_text="";
    bool res=false;
    if (!text.empty()) {
        for (const char& x_char : text) {
            if (x_char == ' ') {
                continue;
            }
            else {
                // x_text.push_back(x_char);
                x_text = x_text + x_char;
            }
        }

        if (!x_text.empty()) {
            int b = x_text.size() - 1;
            for (int a = 0; a < x_text.size(); ++a) {

                if (x_text.at(a) == x_text.at(b)) {
                    res = true;
                    --b;
                }
                else {
                    res = false;
                    break;
                }

            }
        }



    }
    else res= false;

    // РќР°РїРёС€РёС‚Рµ РЅРµРґРѕСЃС‚Р°СЋС‰РёР№ РєРѕРґ
    return res;
   // return x_text;
}

int main() {
 
        string text;
        getline(cin, text);

        // cout << IsPalindrome(text) << endl;

        if (IsPalindrome(text)) {
            cout << "palindrome"s << endl;
        }
        else {
            cout << "not a palindrome"s << endl;
        }
       
    
}