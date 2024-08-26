// sort_not_registr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype> // содержит функцию tolower.

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
//-----разбиение строки на слова по пробелам и формирование вектора слов---------------------------
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

// Приводит строку к нижнему регистру второй способ сортировки
/*string ToLowerCase(string s) {
    for (char& ch : s) {
        ch = tolower(static_cast<unsigned char>(ch));
    }
    return s;
}*/

int main() {
    // считаем входные данные
    int Nn = 0;
    cin >> Nn;
   string str= ReadLine(); 
   vector<string> words = SplitIntoWords(str);

// вариант сортировки через ToLowerCase и lexicographical_compare те два вложенных компаратора
   sort(begin(words), end(words), [](const string& left, const string& right) {
       return lexicographical_compare(
           begin(left), end(left),
           begin(right), end(right),
           [](char cl, char cr) { return tolower(cl) < tolower(cr); }
       );
       }
   );

//другой вариант сортировки через ToLowerCase
 /*  sort(words.begin(), words.end(), [](const string& left, const string& right) {
       return ToLowerCase(left) < ToLowerCase(right);
       });
 */

   for (string i : words) {
       cout << i << " "s; }
   cout <<endl;
}