// find_exemp2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Document {
    int id;
    double relevance;
    int rating;
};

void SortDocuments(vector<Document>& matched_documents) {

    //первый вариант сортировки

  /*  sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {        
            return lhs.rating > rhs.rating || 
                (lhs.rating==rhs.rating && lhs.relevance>rhs.relevance);
        });*/
    //второй вариант сортировки с парами

    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {
            return pair(lhs.rating, lhs.relevance) >
                   pair(rhs.rating, rhs.relevance);
        });

    /*
Ожидаемый вывод:
102 0.3 5
101 1.2 4
100 0.5 4
*/

    /*Вы сортировали найденные поисковой системой документы по убыванию релевантности. 
    Не меняя данной функции, исправьте компаратор так,
    чтобы он сортировал по убыванию рейтинга. 
    А при одинаковом рейтинге — по убыванию релевантности.*/

}

int main() {
    vector<Document> documents = { {100, 0.5, 4}, {101, 1.2, 4}, {102, 0.3, 5} };
    SortDocuments(documents);
    for (const Document& document : documents) {
        cout << document.id << ' ' << document.relevance << ' ' << document.rating << endl;
    }

    return 0;
}