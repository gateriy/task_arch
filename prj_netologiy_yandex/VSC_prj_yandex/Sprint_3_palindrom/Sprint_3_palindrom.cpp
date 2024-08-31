// Sprint_3_palindrom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Определяет, будет ли слово палиндромом
// text может быть строкой, содержащей строчные буквы английского алфавита и пробелы
// Пустые строки и строки, состоящие только из пробелов, - это не палиндромы
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

    // Напишите недостающий код
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