// exemple3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum class Status { ACTUAL, EXPIRED, DELETED };

struct Document {
    int id;
    Status status;
    double relevance;
    int rating;
    auto MakeKey() const {
        return tuple(status, rating * -1, relevance * -1);
    }
};
//первый способ сортировки
/*void SortDocuments(vector<Document>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {
     return  tuple(lhs.status,lhs.rating*-1, lhs.relevance*-1) < tuple(rhs.status,rhs.rating*-1, rhs.relevance*-1);
        });
}*/
//второй способ сортировки с использованием метода из структутры MakeKey
void SortDocuments(vector<Document>& matched_documents) {

    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {
            return  lhs.MakeKey() < rhs.MakeKey();
        });
}

int main() {
    vector<Document> documents = {
        {100, Status::ACTUAL, 0.5, 4}, {101, Status::EXPIRED, 0.5, 4},
        {102, Status::ACTUAL, 1.2, 4}, {103, Status::DELETED, 1.2, 4},
        {104, Status::ACTUAL, 0.3, 5},
    };
    SortDocuments(documents);
    for (const Document& document : documents) {
        cout << document.id << ' ' << static_cast<int>(document.status) << ' ' << document.relevance
            << ' ' << document.rating << endl;
    }

    return 0;
}