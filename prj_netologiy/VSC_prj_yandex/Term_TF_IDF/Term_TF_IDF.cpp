// Term_TF_IDF.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
        {"белый"s, "кот"s, "и"s, "модный"s, "ошейник"s},
        {"пушистый"s, "кот"s, "пушистый"s, "хвост"s},
        {"ухоженный"s, "пёс"s, "выразительные"s, "глаза"s},
    };
    const auto& tf_idfs = ComputeTfIdfs(documents, "кот"s);
    for (const double tf_idf : tf_idfs) {
        cout << tf_idf << " "s;
    }
    cout << endl;
    return 0;
}