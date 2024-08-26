// Find4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// find4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
//#include <numeric>

using namespace std;

const int  MAX_RESULT_DOCUMENT_COUNT = 5;//константная переменная определяет количество топов
struct DocumentContent { int id; vector<string> words; }; //переменная struct - -  структура
//-----чтение и возврат строки---------------------------------------------------------------------
string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
//-----чтение и возврат количества строк в тексте и самой строки-----------------------------------
int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
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
//-----создание контейнера Стоп слов---------------------------------------------------------------
set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}
//-----создание вектора слов исходного текста за вычетом стоп слов---------------------------------
vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}
//-----создание и добавление к вектору из пар {id и вектор строки} новой пары в конец вектора------ 
void AddDocument(vector<DocumentContent>& documents,
    const set<string>& stop_words,
    int 				      document_id,
    const string& document) {

    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back({ document_id,words });
    //documents.words = words;
}
//-----создание контейнера слов поискового запроса за вычетом стоп слов----------------------------
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}
//-----возврат релевантности в паре {id и вектор строки} по запросу с проверкой пустого запроса и повторов слов в в тексте---
int MatchDocument(const DocumentContent& content, const set<string>& query_words) {
    if (query_words.empty()) {
        return 0;
    }
    set<string> matched_words;
    for (const string& word : content.words) {
        if (matched_words.count(word) != 0) {
            continue;
        }
        if (query_words.count(word) != 0) {
            matched_words.insert(word);
        }
    }
    // Преобразовываем беззнаковое число типа size_t в int используя static_cast<int>
    return static_cast<int>(matched_words.size());
}
//-----для каждого найденного документа возвращает его id и релеватность {релевантность, id}-------
vector<pair<int, int> > FindAllDocuments(const vector<DocumentContent>& documents,
    const set<string>& query_words)
{
    vector<pair<int, int> > matched_documents;
    // vector<pair<int,string>> docum;
    // docum = documents;
      //  docum = { documents.id, documents.words };
    int document_rel = 0;
    for (const auto& asd : documents) {
        document_rel = MatchDocument(asd, query_words);
        if (document_rel > 0) {
            matched_documents.push_back(pair<int, int>(document_rel, asd.id));
        }
    }
    return matched_documents;
}
// Возвращает топ-5 самых релевантных документов в виде пар: {id, релевантность}
vector<pair<int, int>> FindTopDocuments(const vector<DocumentContent>& documents,
    const set<string>& stop_words,
    const string& raw_query)
{
    vector<pair<int, int>> fad;
    fad = FindAllDocuments(documents, stop_words);
    sort(fad.begin(), fad.end());//сортировка по релевантности {релевантность, id}
    reverse(fad.begin(), fad.end());//пересортировка по убыванию релевантности {релевантность, id}

    if (MAX_RESULT_DOCUMENT_COUNT < fad.size()) { fad.resize(MAX_RESULT_DOCUMENT_COUNT); }

    return fad;
    // Напишите функцию, используя FindAllDocuments
}

//-------------------------------
int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector< DocumentContent> documents;
    const int document_count = ReadLineWithNumber();

    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, document_id, ReadLine());
    }

    const string query = ReadLine();

    for (const auto& doc_id : FindTopDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << doc_id.second << ", relevance = "s << doc_id.first << " }"s << endl;
    }

    //  for (const auto& [document_id, relevance] : FindTopDocuments(documents, stop_words, query)) {
      //    cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s  << endl;
      //}



}