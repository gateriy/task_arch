п»ї// tf_idf_exemple 2.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename Documents, typename Term>

vector<double> ComputeTfIdfs(const Documents& documents, const Term& term_x ) {

    double tf = 0;
    int document_freq = 0;
    vector<double> res = {};
    double idf = 0;
    //string term = ""s + term_x;

  
    for (const auto& doc : documents) {    
        if (count(doc.begin(), doc.end(), (term_x)) > 0) {
            ++document_freq;
        }
    }

    for (const auto& docums : documents) {
        if (count(docums.begin(), docums.end(), (term_x)) > 0) {
            tf = static_cast<double>(count(docums.begin(), docums.end(), (term_x))) / static_cast<double>(docums.size());
            if (document_freq > 0) {
                idf = log(static_cast<double>(documents.size()) / static_cast<double>(document_freq));
            }
            else { idf = 0; }
            res.push_back(tf * idf);
        }
        else { res.push_back(0.0); }
    }
    return res;
}


int main() {
    const vector<vector<string>> documents = {
        {"Р±РµР»С‹Р№"s, "РєРѕС‚"s, "Рё"s, "РјРѕРґРЅС‹Р№"s, "РѕС€РµР№РЅРёРє"s},
        {"РїСѓС€РёСЃС‚С‹Р№"s, "РєРѕС‚"s, "РїСѓС€РёСЃС‚С‹Р№"s, "С…РІРѕСЃС‚"s},
        {"СѓС…РѕР¶РµРЅРЅС‹Р№"s, "РїС‘СЃ"s, "РІС‹СЂР°Р·РёС‚РµР»СЊРЅС‹Рµ"s, "РіР»Р°Р·Р°"s},
    };
    const auto& tf_idfs = ComputeTfIdfs(documents, "РєРѕС‚");
    for (const double tf_idf : tf_idfs) {
        cout << tf_idf << " "s;
    }
    cout << endl;
    return 0;
}