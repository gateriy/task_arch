// Find7.cpp : IDF-TF (end sprin 1).
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>



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

struct Document {
    int id;
    double relevance;
};

class SearchServer {
public:
 
    void D_C(const int& document_count) {
    document_count_  = document_count;
    }

    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }
    
    void AddDocument(const int& document_id, const string& document) {
      
        double summ_n_word = 0;//РєРѕР»РёС‡РµСЃС‚РІРѕ СЃР»РѕРІ РІ РґРѕРєСѓРјРµРЅС‚Рµ
        double n_word = 0;//РєРѕР»РёС‡РµСЃС‚РІРѕ РїРѕРІС‚РѕСЂРµРЅРёР№ РєР°Р¶РґРѕРіРѕ СЃР»РѕРІР° РІ РґРѕРєСѓРјРµРЅС‚Рµ
        double tf = .0;//tf РєР°Р¶РґРѕРіРѕ СЃР»РѕРІР° РІ РґРѕРєСѓРјРµРЅС‚Рµ
        const vector<string> words = SplitIntoWordsNoStop(document, stop_words_);
       //РѕРїСЂРµРґРµР»РёР»Рё 1/(РѕР±С‰РµРµ РєРѕР»РёС‡РµСЃС‚РІРѕ СЃР»РѕРІ РІ РґРѕРєСѓРјРµРЅС‚Рµ) 
        summ_n_word = 1/static_cast<double> (words.size());
      
        for (const auto& w : words) {
           // n_word = static_cast<double>(count(words.begin(), words.end(), w));
           // tf = n_word / summ_n_word;  
            // РґР»СЏ РєР°Р¶РґРѕРіРѕ СЃР»РѕРІР° РґРѕРєСѓРјРµРЅС‚Р° Р·Р°РїРёСЃР°Р»Рё РІ map {СЃР»РѕРІРѕ - РєР»СЋС‡,{id,tf}}
            word_to_document_freqs_[w].insert({ document_id,+summ_n_word });

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

   map<string, map<int, double>> word_to_document_freqs_;

   int document_count_=0;

private:  
    set<string> stop_words_;
    
    struct Query {
        map<string,double> query_words_;
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
                    query.query_words_[query_word.data];
                }
            }
        }
        return query;
    }

    double Math_Idf(const int& doc_count,const int& docum_quantity) const {
        double idf=log(static_cast<double>(doc_count) / static_cast<double>(docum_quantity));
        return  idf;
    }

    //РїРѕРёСЃРє РґРѕРєСѓРјРµРЅС‚РѕРІ
    vector<Document> FindAllDocuments(const Query& query_words) const {
        vector<Document> matched_documents;
        map<int, double> document_to_relevance;
        set<int> minus_id;
        double idf = 0;
        
        for (const auto& word_id : word_to_document_freqs_) //РїРµСЂРµР±РёСЂР°СЋ СЃР»РѕРІР° РґРѕРєСѓРјРµРЅС‚Р°
        {
             for (const auto& minus_document : query_words.minus_query_words_) //РїРµСЂРµР±РёСЂР°СЋ -СЃР»РѕРІР° Р·Р°РїСЂРѕСЃР°
            {
                if (word_id.first == minus_document) //С„РѕСЂРјРёСЂСѓСЋ РёРЅРґРµРєСЃС‹ РґРѕРєСѓРјРµРЅС‚РѕРІ СЃ -СЃР»РѕРІР°РјРё
                {
                    for (const auto& id_set : word_id.second) {                    
                        minus_id.insert(id_set.first);
                    }
                }
            }
            for (const auto& document : query_words.query_words_) //РїРµСЂРµР±РёСЂР°СЋ +СЃР»РѕРІР° Р·Р°РїСЂРѕСЃР°
            {              
                if (word_id.first == document.first)
                {   
                   // idf =log(static_cast<double>(document_count_)/static_cast<double>(word_id.second.size()));
                    idf = Math_Idf(document_count_, word_id.second.size());
                    for (const auto& id_set : word_id.second) {
                        
                     document_to_relevance[id_set.first] = document_to_relevance[id_set.first]+idf * id_set.second;                     

                    }
                }
            }
        }

        for (auto& set_minus : minus_id) {
            document_to_relevance.erase(set_minus);
        }

        for (auto& matched_docum : document_to_relevance) {
            matched_documents.push_back({ matched_docum.first, matched_docum.second });
        }
        return matched_documents;
    }
};

SearchServer CreateSearchServer() {
    SearchServer  search_server;
    search_server.SetStopWords(ReadLine());
   search_server.D_C(ReadLineWithNumber());
    for (int i = 0; i < search_server.document_count_; ++i) {
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

  /*  for (auto i : search_server1.word_to_document_freqs_) {
        cout << "{\t"s << i.first << " ----- "s;
        for (auto x : i.second) {
            cout << "("s<<x.first<<"-"s << x.second << ") }"s;
        }
        cout << endl;
    }*/

}
