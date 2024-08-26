// Find5
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

struct Document {
    int id;
    int relevance;
};

//bool HasDocumentGreaterRelevance

class SearchServer {
   
public:
    vector<string> SplitIntoWords(const string& text) const  {
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
    void AddDocument(int document_id, const string& document) {
        const vector<string> words = SplitIntoWordsNoStop(document, stop_words_);
        documents_.push_back({ document_id, words });
    }
    void SetStopWords(const string& text)  {
        // set<string> stop_words;
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }  
    set<string> ParseQuery(const string& text, const set<string>& stop_words)   const {
        set<string> query_words;
        for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
            query_words.insert(word);
        }
        return query_words;
    }
    vector<Document> FindTopDocuments(const string& raw_query) const {
        const set<string> query_words = ParseQuery(raw_query, stop_words_);
        auto matched_documents = FindAllDocuments(query_words);
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }  
        sort(matched_documents.begin(), matched_documents.end(), [](const Document& lhs, const Document& rhs) {
            return lhs.relevance > rhs.relevance;
            });
        return matched_documents;
    }

    vector<Document> FindAllDocuments(const set<string>& query_words) const {
        vector<Document> matched_documents;
        for (const auto& document : documents_) {
            const int relevance = MatchDocument(document, query_words);
            if (relevance > 0) {
                matched_documents.push_back({ document.id, relevance });
            }
        }
        return matched_documents;
    }

    vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) const {
        vector<string> words;
        for (const string& word : SplitIntoWords(text)) {
            if (stop_words.count(word) == 0) {
                words.push_back(word);
            }
        }
        return words;
    }

  private:   
    struct DocumentContent {
        int id = 0;
        vector<string> words;
    };
    vector<DocumentContent> documents_;
    set<string> stop_words_;

    
    static int MatchDocument(const DocumentContent& content, const set<string>& query_words) {
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
    
};

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

/*/set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}*/

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
 
  const SearchServer  search_server1= CreateSearchServer();

   

  string query = ReadLine();

    for (auto [document_id, relevance] : search_server1.FindTopDocuments(query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
            << endl;
    }
}