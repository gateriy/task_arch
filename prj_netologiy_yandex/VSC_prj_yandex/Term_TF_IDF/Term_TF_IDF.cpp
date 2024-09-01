п»ї// Term_TF_IDF.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <typename Term>

vector<double> ComputeTfIdfs(const vector<vector<Term>>& documents, const Term& term ) {

map<Term, double> tf = {};
int document_freq=0;
vector<double> res;

    for (const auto& docums : documents) {
        if (count(docums.begin(), docums.end(), term) != 0) {
            ++document_freq;
        }       
    }

    for (const auto& docums : documents) {
        const double inv_word_count = 1.0 / docums.size();
        tf={};

        for (const auto& word : docums) {
            tf[word] += inv_word_count;
        }
      res.push_back(tf[term] * log(documents.size() * 1.0 / document_freq));
    }
    return res;
}


int main() {
    const vector<vector<string>> documents = {
        {"Р±РµР»С‹Р№"s, "РєРѕС‚"s, "Рё"s, "РјРѕРґРЅС‹Р№"s, "РѕС€РµР№РЅРёРє"s},
        {"РїСѓС€РёСЃС‚С‹Р№"s, "РєРѕС‚"s, "РїСѓС€РёСЃС‚С‹Р№"s, "С…РІРѕСЃС‚"s},
        {"СѓС…РѕР¶РµРЅРЅС‹Р№"s, "РїС‘СЃ"s, "РІС‹СЂР°Р·РёС‚РµР»СЊРЅС‹Рµ"s, "РіР»Р°Р·Р°"s},
    };
    const auto& tf_idfs = ComputeTfIdfs(documents, "РєРѕС‚"s);
    for (const double tf_idf : tf_idfs) {
        cout << tf_idf << " "s;
    }
    cout << endl;
    return 0;
}