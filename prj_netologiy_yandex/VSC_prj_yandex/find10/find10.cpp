п»ї// find10.cpp : Р­С‚РѕС‚ С„Р°Р№Р» РЅР° РѕСЃРЅРѕРІРµ Р°РІС‚РѕСЂСЃРєРѕРіРѕ СЂРµС€РµРЅРёСЏ.
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
    int result;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}


enum class DocumentStatus {
    ACTUAL, 
    IRRELEVANT, 
    BANNED, 
    REMOVED
};

struct Document {
    int id;
    double relevance;
    int rating;
    DocumentStatus status;
};



class SearchServer {
public:
    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }

    void AddDocument(int document_id, const string& document, DocumentStatus status, const vector<int>& ratings) {
        const vector<string> words = SplitIntoWordsNoStop(document);
        const double inv_word_count = 1.0 / words.size();
        for (const string& word : words) {
            word_to_document_freqs_[word][document_id] += inv_word_count;//word-id-tf
        }
            document_ratings_.emplace(document_id, ComputeAverageRating(ratings));//СЃСЂРµРґРЅРёР№ СЂРµР№С‚РёРЅРі id-tf
            document_status_.emplace(document_id, status);//СЃС‚Р°С‚СѓСЃ id-status
    }
     
    //vector<Document> FindTopDocuments(const string& raw_query, DocumentStatus status) const {
    vector<Document> FindTopDocuments(const string & raw_query, DocumentStatus status = DocumentStatus::ACTUAL) const {
        const Query query = ParseQuery(raw_query);
        vector<Document> matched_documents = {};

        for (const auto& vect_status : FindAllDocuments(query)) {
            if (status != vect_status.status) {
                continue;
            }
                matched_documents.push_back({
                    vect_status.id,
                    vect_status.relevance,
                    vect_status.rating,
                    vect_status.status
                    });         
        }
       
        sort(matched_documents.begin(), matched_documents.end(),
            [](const Document& lhs, const Document& rhs) {
               return lhs.relevance > rhs.relevance;
               //return lhs.relevance > rhs.relevance;
            });


        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }

private:
    set<string> stop_words_;
    map<string, map<int, double>> word_to_document_freqs_;
    map<int, int> document_ratings_;
    map<int, DocumentStatus> document_status_;

    bool IsStopWord(const string& word) const {
        return stop_words_.count(word) > 0;
    }

    vector<string> SplitIntoWordsNoStop(const string& text) const {
        vector<string> words;
        for (const string& word : SplitIntoWords(text)) {
            if (!IsStopWord(word)) {
                words.push_back(word);
            }
        }
        return words;
    }



    struct QueryWord {
        string data;
        bool is_minus;
        bool is_stop;
    };

    QueryWord ParseQueryWord(string text) const {
        bool is_minus = false;
        // Word shouldn't be empty
        if (text[0] == '-') {
            is_minus = true;
            text = text.substr(1);
        }
        return {
            text,
            is_minus,
            IsStopWord(text)
        };
    }

    struct Query {
        set<string> plus_words;
        set<string> minus_words;
    };

    Query ParseQuery(const string& text) const {
        Query query;
        for (const string& word : SplitIntoWords(text)) {
            const QueryWord query_word = ParseQueryWord(word);
            if (!query_word.is_stop) {
                if (query_word.is_minus) {
                    query.minus_words.insert(query_word.data);
                }
                else {
                    query.plus_words.insert(query_word.data);
                }
            }
        }
        return query;
    }

    // Existence required
    double ComputeWordInverseDocumentFreq(const string& word) const {
        return log(document_ratings_.size() * 1.0 / word_to_document_freqs_.at(word).size());
    }

    vector<Document> FindAllDocuments(const Query& query) const {
        map<int, double> document_to_relevance;
        for (const string& word : query.plus_words) {
            if (word_to_document_freqs_.count(word) == 0) {
                continue;
            }
            const double inverse_document_freq = ComputeWordInverseDocumentFreq(word);
            for (const auto& [document_id, term_freq] : word_to_document_freqs_.at(word)) {
                document_to_relevance[document_id] += term_freq * inverse_document_freq;
            }
        }

        for (const string& word : query.minus_words) {
            if (word_to_document_freqs_.count(word) == 0) {
                continue;
            }
            for (const auto& [document_id, _] : word_to_document_freqs_.at(word)) {
                document_to_relevance.erase(document_id);
            }
        }

        vector<Document> matched_documents;
        for (const auto& [document_id, relevance] : document_to_relevance) {
            matched_documents.push_back({
                document_id,
                relevance,
                document_ratings_.at(document_id),
                document_status_.at(document_id)
                });
        }
        return matched_documents;
    }

    static int ComputeAverageRating(const vector<int>& ratings) {
        int rating_sum = 0;
        for (const int rating : ratings) {
            rating_sum += rating;
        }
        return rating_sum / static_cast<int>(ratings.size());
    }
};
//С„СѓРЅРєС†РёСЏ РІС‹РІРѕРґРґР°
void PrintDocument(const Document& document) {  
        cout << "{ "
            << "document_id = " << document.id << ", "
            << "relevance = " << document.relevance << ", "
            << "rating = " << document.rating
            << " }" << endl;    
}

int main() {

    const vector<int> ratings = { 9, -2, 6, 1, 18 };
    cout << SearchServer::ComputeAverageRating(ratings) << endl;

    SearchServer search_server;
    search_server.SetStopWords("Рё РІ РЅР°"s);
    search_server.AddDocument(0, "Р±РµР»С‹Р№ РєРѕС‚ Рё РјРѕРґРЅС‹Р№ РѕС€РµР№РЅРёРє"s, DocumentStatus::ACTUAL, { 8, -3 });
    search_server.AddDocument(1, "РїСѓС€РёСЃС‚С‹Р№ РєРѕС‚ РїСѓС€РёСЃС‚С‹Р№ С…РІРѕСЃС‚"s, DocumentStatus::ACTUAL, { 7, 2, 7 });
    search_server.AddDocument(2, "СѓС…РѕР¶РµРЅРЅС‹Р№ РїС‘СЃ РІС‹СЂР°Р·РёС‚РµР»СЊРЅС‹Рµ РіР»Р°Р·Р°"s, DocumentStatus::ACTUAL, { 5, -12, 2, 1 });
    search_server.AddDocument(3, "СѓС…РѕР¶РµРЅРЅС‹Р№ СЃРєРІРѕСЂРµС† РµРІРіРµРЅРёР№"s, DocumentStatus::BANNED, { 9 });
    
    cout << "ACTUAL:"s << endl;//РІС‹РІРѕРґ 
    for (const Document& document : search_server.FindTopDocuments("РїСѓС€РёСЃС‚С‹Р№ СѓС…РѕР¶РµРЅРЅС‹Р№ РєРѕС‚"s, DocumentStatus::ACTUAL)) {
       PrintDocument(document);


    }
    cout << "BANNED:"s << endl;//РІС‹РІРѕРІРґ
    for (const Document& document : search_server.FindTopDocuments("РїСѓС€РёСЃС‚С‹Р№ СѓС…РѕР¶РµРЅРЅС‹Р№ РєРѕС‚"s, DocumentStatus::BANNED)) {
       PrintDocument(document);
    }

    /*const SearchServer search_server = CreateSearchServer();

    const string query = ReadLine();
    for (const Document& document : search_server.FindTopDocuments(query)) {
        cout << "{ "
            << "document_id = " << document.id << ", "
            << "relevance = " << document.relevance << ", "
            << "rating = " << document.rating
            << " }" << endl;
    }*/

    /* 
 a s d
3
f g h
1 2 3
c v b
1 2 3
z x c
1 2 3
f c x

{ document_id = 2, relevance = 0.501359, rating = 2 }
{ document_id = 0, relevance = 0.366204, rating = 2 }
{ document_id = 1, relevance = 0.135155, rating = 2 }
    */
}