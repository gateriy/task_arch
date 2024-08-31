// lamda_x.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
//-----разбиение строки на слова по пробелам и формирование вектора слов---
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
//считали все строки из наборов слов и преобразовали в сквозной вектор слов
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
        // Реализуйте эту лямбда-функцию
        // Верните true, если query содержит слово buzzword
      if (buzzword == query) { return true; }
      else return false;
      }); 
}