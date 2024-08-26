// tf_idf_exemple 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
        {"белый"s, "кот"s, "и"s, "модный"s, "ошейник"s},
        {"пушистый"s, "кот"s, "пушистый"s, "хвост"s},
        {"ухоженный"s, "пёс"s, "выразительные"s, "глаза"s},
    };
    const auto& tf_idfs = ComputeTfIdfs(documents, "кот");
    for (const double tf_idf : tf_idfs) {
        cout << tf_idf << " "s;
    }
    cout << endl;
    return 0;
}