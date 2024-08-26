// assert_exemp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

#define NDEBUG // Объявляем макрос NDEBUG

/*Запустим программу и увидим, что макрос assert не сработал. 
Дело в том, что мы объявили макрос NDEBUG перед подключением файла cassert. 
Определение макроса assert зависит от макроса NDEBUG, который по умолчанию не 
объявлен в стандартной библиотеке. Если объявить NDEBUG перед подключением файла <cassert>,  
assert не будет делать ничего. 
Это позволяет ограничить использование макроса assert отладочными версиями 
программы и отключить проверки в финальной сборке программы.

Тесты для C++ пишут, используя не только макрос assert. 
Существуют целые фреймворки, такие как Google Test, Boost.Test, Catch2. 
На практике для разработки тестов применяют фрейморк, а макрос assert оставляют, 
чтобы проверить инварианты в отладочных версиях программы. Мы покажем, как это работает, 
разобрав устройство нашего тестового фреймворка.*/

#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

// При помощи директивы #define объявляется макрос GREETING
//#define GREETING cout << "Hello, friend"s << endl

/*В C++ перед компиляцией происходит препроцессинг — обработка исходного кода. 
На этом этапе макросы заменяются на соответствующие им значения. Некоторые макросы, 
например assert, объявлены в стандартной библиотеке, другие встроены напрямую в компилятор. 
Сейчас нас интересуют встроенные:
__FILE__ — вместо него препроцессор вставляет в текст программы имя текущего файла исходного кода;
__LINE__ — вместо него препроцессор вставляет номер текущей строки;
__FUNCTION__ — препроцессор заменяет его на имя текущей функции.
Эти макросы и использует фреймворк. Вот как они работают:*/

void PrintDiagnosticInformation() {
    cout << "Function name: "s << __FUNCTION__ << endl;
    cout << "File name: "s << __FILE__ << endl;
    cout << "Line number: "s << __LINE__ << endl;
    cout << "Line number: "s << __LINE__ << endl;
}

template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        // Включаем режим вывода значений типа bool в виде true и false
        cout << boolalpha;
        cout << "Assertion failed: "s << t << " != "s << u << "."s;  
        cout << " Hint: "s << hint;

        cout << endl;
        abort();
    }
}

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const string& t_str, const string& u_str, const string& file,
    const string& func, unsigned line, const string& hint) {
    if (t != u) {
        cout << boolalpha;
        cout << file << "("s << line << "): "s << func << ": "s;
        cout << "ASSERT_EQUAL("s << t_str << ", "s << u_str << ") failed: "s;
        cout << t << " != "s << u << "."s;
        if (!hint.empty()) {
            cout << " Hint: "s << hint;
        }
        cout << endl;
        abort();
    }
}

#define ASSERT_EQUAL(a, b) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_EQUAL_HINT(a, b, hint) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, (hint))


int Add(int x, int y) {
    return x * y;
}

//AssertEqual(Add(2, 3), 5);
//AssertEqual(Sort(vector<int>{1, 4, 2}), vector<int>{1, 2, 4});
  



int main()
{
    const string greeting = "Hello"s;
    const string hello = "hello"s;


    AssertEqual(hello.length(), (double)5, "123123123"s);

    // Эта проверка не сработает
    AssertEqual(2 + 2, 7, "Add() must add its arguments"s);

    // Ошибка в условии допущена намеренно, чтобы продемонстрировать работу AssertEqual
    AssertEqual(greeting.empty(), true, "Greeting must be non-empty"s);
}