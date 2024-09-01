п»ї// find6.cpp 
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

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

vector<string> SplitIntoWords(const string& text)  {
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

struct Document {
    int id;
    int relevance;
};

class SearchServer {
public:
   
    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }

    void AddDocument(const int & document_id,const string &document) {
        const vector<string> words = SplitIntoWordsNoStop(document, stop_words_);       
        for (const string& w : words) {
           word_to_documents_[w].insert( document_id);
        }    
    } 

    vector<Document> FindTopDocuments(const string& raw_query) const {
        const Query query_words = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query_words);
        sort(matched_documents.begin(), matched_documents.end(), [](const Document& lhs, const Document& rhs) {
            return lhs.relevance > rhs.relevance;
            });        
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }
 map<string, set<int>> word_to_documents_;
private:

    set<string> stop_words_;    
   
    struct Query {
        set<string> query_words_;
        set<string> minus_query_words_;
    };
    struct QueryWord {
        string data;
        bool is_minus;
        bool is_stop;
    };

    vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) const {
        vector<string> words;
        for (const string& word : SplitIntoWords(text)) {
            if (stop_words.count(word) == 0) {
                words.push_back(word);
            }
        }
        return words;
    }

    bool IsStopWord(const string& word) const {
        return stop_words_.count(word) > 0;
    }

    QueryWord ParseQueryWord(string text) const {
        bool is_minus = false;
        // Word shouldn't be empty
        if (text[0] == '-') {
            is_minus = true;
            text = text.substr(1);
        }
        return { text, is_minus, IsStopWord(text) };
    }

    Query ParseQuery(const string& text) const {
        Query query;
        for (const string& word : SplitIntoWords(text)) {
            const QueryWord query_word = ParseQueryWord(word);
            if (!query_word.is_stop) {
                if (query_word.is_minus) {
                    query.minus_query_words_.insert(query_word.data);
                }
                else {
                    query.query_words_.insert(query_word.data);
                }
            }
        }
        return query;
    }

    vector<Document> FindAllDocuments(const Query& query_words) const {
        vector<Document> matched_documents;
        map<int, int> document_to_relevance;
        set<int> minus_id;    

    for (const auto& word_id : word_to_documents_) //РїРµСЂРµР±РёСЂР°СЋ СЃР»РѕРІР° РґРѕРєСѓРјРµРЅС‚Р°
    {
        for (const auto& minus_document : query_words.minus_query_words_) //РїРµСЂРµР±РёСЂР°СЋ -СЃР»РѕРІР° Р·Р°РїСЂРѕСЃР°
        {
            if (word_id.first == minus_document) //С„РѕСЂРјРёСЂСѓСЋ РёРЅРґРµРєСЃС‹ РґРѕРєСѓРјРµРЅС‚РѕРІ СЃ -СЃР»РѕРІР°РјРё
            {  
                for (const int& id_set : word_id.second) {
                    //document_to_relevance.erase(id_set);
                    minus_id.insert(id_set);                 
                }
            }
        }
        for (const auto& document : query_words.query_words_) //РїРµСЂРµР±РёСЂР°СЋ +СЃР»РѕРІР° Р·Р°РїСЂРѕСЃР°
        {
            if (word_id.first == document) 
            {
                for (const auto& id_set : word_id.second) {                  
                        document_to_relevance[id_set] = document_to_relevance[id_set] + 1;                   
                }
            }
        }
    }

   for ( auto& i : minus_id) {        
      document_to_relevance.erase(i);
    }

         for ( auto &i : document_to_relevance) {
                 matched_documents.push_back({ i.first, i.second });
           }
        return matched_documents;       
    }
};

    SearchServer CreateSearchServer() {
        SearchServer  search_server;
        search_server.SetStopWords(ReadLine());
        const int document_count = ReadLineWithNumber();
        for (int i = 0; i < document_count; ++i) {
            search_server.AddDocument(i, ReadLine());
        }
        return search_server;
    }

int main() {
    const SearchServer  search_server1 = CreateSearchServer();
    string query = ReadLine();
    
   for (auto [document_id, relevance] : search_server1.FindTopDocuments(query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
            << endl;
    }
 
    for (auto [word, id] : search_server1.word_to_documents_) {
        cout << "{\t" << word << "\t - \t";
        for (int i : id) {
            cout << i << " }";
        } 
        cout << endl;  
     }
   
}