п»ї#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;
struct DocumentContent { int id; vector<string> words; }; //РїРµСЂРµРјРµРЅРЅР°СЏ struct - -  СЃС‚СЂСѓРєС‚СѓСЂР°

//СЃС‚СЂСѓРєС‚СѓСЂР° id - СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ
struct Document {
    int id;
    int relevance;
};
//HasDocumentGreaterRelevance РєРѕРјРїР°СЂР°С‚РѕСЂ РґР»СЏ С„СѓРЅРєС†РёРё sort РїРѕ ID Рё СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё
bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
    return lhs.relevance > rhs.relevance;
}

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}

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

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(vector<DocumentContent>& documents, const set<string>& stop_words,
    int document_id, const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);

    documents.push_back({ document_id, words });
}

set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}

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
    return static_cast<int>(matched_words.size());
}

// Р”Р»СЏ РєР°Р¶РґРѕРіРѕ РґРѕРєСѓРјРµРЅС‚Р° РІРѕР·РІСЂР°С‰Р°РµС‚ РµРіРѕ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ Рё id
vector<Document> FindAllDocuments(const vector<DocumentContent>& documents,
    const set<string>& query_words) {
    vector<Document> matched_documents;
    for (const auto& document : documents) {
        const int relevance = MatchDocument(document, query_words);
        if (relevance > 0) {
            matched_documents.push_back({ relevance, document.id });
        }
    }
    return matched_documents;
}

// Р’РѕР·РІСЂР°С‰Р°РµС‚ С‚РѕРї-5 СЃР°РјС‹С… СЂРµР»РµРІР°РЅС‚РЅС‹С… РґРѕРєСѓРјРµРЅС‚РѕРІ РІ РІРёРґРµ РїР°СЂ: {id, СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ}
vector<Document> FindTopDocuments(const vector<DocumentContent>& documents,
    const set<string>& stop_words, const string& raw_query) {
    const set<string> query_words = ParseQuery(raw_query, stop_words);
    vector <Document> matched_documents = FindAllDocuments(documents, query_words);

      //  reverse(matched_documents.begin(), matched_documents.end());
    sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
    if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
        matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    for (auto& matched_document : matched_documents) {
        swap(matched_document.id, matched_document.relevance);
    }
    return matched_documents;
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector<DocumentContent> documents;
    
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, document_id, ReadLine());
    }
    const string query = ReadLine();
    
    //sort(documents.begin(), documents.end(), HasDocumentGreaterRelevance);

    for (auto [document_id, relevance] : FindTopDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
            << endl;
    }
}