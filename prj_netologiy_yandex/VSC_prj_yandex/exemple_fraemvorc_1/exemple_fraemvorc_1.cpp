// exemple_fraemvorc_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>

using namespace std;

void PrintDiagnosticInformation() {
    cout << "Function name: "s << __FUNCTION__ << endl;
    cout << "File name: "s << __FILE__ << endl;
    cout << "Line number: "s << __LINE__ << endl;
    cout << "Line number: "s << __LINE__ << endl;
}
// Директивой #define объявляем макрос GREETING параметрами s1 и s2
#define GREETING(s1, s2) cout << "Hello, "s << (s1) << " and "s << (s2) << endl


int main() {
    setlocale(LC_ALL, "Russian");

    PrintDiagnosticInformation();

    // Будет заменено на:
    // cout << "Hello, "s << ("Ivan"s) << " and "s << ("Maria"s) << endl;
    GREETING("Ivan"s, "Maria"s);

    // Будет заменено на:
    // cout << "Hello, "s << (5 + 5) << " and "s << (42) << endl;
    GREETING(5 + 5, 42);
}