// Sort_numeric.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cctype> // содержит функцию tolower.

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
//считка ряда в виде string и преобразование в вектор int
vector<int>GetLineStringToInt() {
    vector<int> n = {};
    string str = ReadLine();
    vector<string> words = SplitIntoWords(str);
        for (const string& i : words) {
        n.push_back(stoi(i));
    }
    return n;
}
//функция вывода
void PrintNumbers(const vector<int>& numbers) {
    for (auto number : numbers) {
        cout << number << " "s;
    }
}

int main() {
    //считали первую цифру строки
    int Nn = 0;
    cin >> Nn;
    //считали остальные цифры строки и собрали в вектор
   vector<int> numeric = GetLineStringToInt();

   sort(numeric.begin(), numeric.end(), [](int n1, int n2) {
       /* Напишите тело лямбда-функции самостоятельно.
          Сначала должны располагаться чётные числа в порядке возрастания,
          а следом за ними — нечётные числа в порядке убывания*/
       if (n1 % 2 == 0 && n2 % 2 == 0) { return n1 < n2; }
       if (n1 % 2 == 0 && n2 % 2 != 0) { return true; }
       if (n1 % 2 != 0 && n2 % 2 == 0) { return false; }
       if (n1 % 2 != 0 && n2 % 2 != 0) { return n1 > n2; }
       else return true;
/*x и y — чётные.Верните результат сравнения x < y
x чётное, y нечётное. Числа упорядочены, верните true
x нечётное, y чётное. Числа неупорядочены, верните false
x и y — нечётные. Верните результат сравнения x > y  */
       });
   //тестовый вывод
 /*  cout << Nn << " -- "s;
    for (const int & i : numeric) {
        cout << i * i << " "s;   }
    cout << endl;*/
    // вывод
    PrintNumbers(numeric);
}   
