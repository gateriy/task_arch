п»ї// find11.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
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
    int rating;
};

enum class DocumentStatus {
    ACTUAL,
    IRRELEVANT,
    BANNED,
    REMOVED,
};

class SearchServer {
public:
    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }

    void AddDocument(int document_id, const string& document, DocumentStatus status,
        const vector<int>& ratings) {
        ++document_count_;
        const vector<string> words = SplitIntoWordsNoStop(document);
        const double inv_word_count = 1.0 / words.size();
        for (const string& word : words) {
            word_to_document_freqs_[word][document_id] += inv_word_count;
        }
        documents_.emplace(document_id, DocumentData{ ComputeAverageRating(ratings), status });
    }
    //РєРѕР»РёС‡РµСЃС‚РІРѕ РґРѕРєСѓРјРµРЅС‚РѕРІ РІ СЃРёСЃС‚РµРјРµ
    int GetDocumentCount() const {
        return  document_count_;
    }

    vector<Document> FindTopDocuments(const string& raw_query,
        DocumentStatus status = DocumentStatus::ACTUAL) const {

        const Query query = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query, status);

        sort(matched_documents.begin(), matched_documents.end(),
            [](const Document& lhs, const Document& rhs) {
                return lhs.relevance > rhs.relevance;
            });
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }


    tuple<vector<string>, DocumentStatus> MatchDocument(const string& raw_query, int document_id) const {
        Query word_query = ParseQuery(raw_query);
        vector<string> plus_words = {};
        set<int> minus_yes = {};

        for (const auto& [words, id_tf] : word_to_document_freqs_) {

            for (const auto& w_q : word_query.minus_words)
                if (words == w_q) {
                    for (auto i : id_tf) {
                        minus_yes.insert(i.first);
                    }
                }
        }

        for (const auto& [words, id_tf] : word_to_document_freqs_) {
            for (const auto& w_q : word_query.plus_words) {
                if (words == w_q ) {
                    for (auto i : id_tf) {
                        if (i.first == document_id && count(minus_yes.begin(), minus_yes.end(), document_id)==0) {
                            
                            plus_words.push_back(w_q);
                        }
                    }
                }
            }
        }
        sort(plus_words.begin(), plus_words.end());

        return { plus_words, documents_.at(document_id).status };

        // return { word.plus_words, }
         /*Р’ РїРµСЂРІРѕРј СЌР»РµРјРµРЅС‚Рµ РєРѕСЂС‚РµР¶Р° РІРµСЂРЅРёС‚Рµ РІСЃРµ РїР»СЋСЃ-СЃР»РѕРІР° Р·Р°РїСЂРѕСЃР°, СЃРѕРґРµСЂР¶Р°С‰РёРµСЃСЏ РІ РґРѕРєСѓРјРµРЅС‚Рµ.
         РЎР»РѕРІР° РЅРµ РґРѕР»Р¶РЅС‹ РґСѓР±Р»РёСЂРѕРІР°С‚СЊСЃСЏ. РџСѓСЃС‚СЊ РѕРЅРё Р±СѓРґСѓС‚ РѕС‚СЃРѕСЂС‚РёСЂРѕРІР°РЅС‹ РїРѕ РІРѕР·СЂР°СЃС‚Р°РЅРёСЋ.
         Р•СЃР»Рё РґРѕРєСѓРјРµРЅС‚ РЅРµ СЃРѕРѕС‚РІРµС‚СЃС‚РІСѓРµС‚ Р·Р°РїСЂРѕСЃСѓ (РЅРµС‚ РїРµСЂРµСЃРµС‡РµРЅРёР№ РїРѕ РїР»СЋСЃ-СЃР»РѕРІР°Рј РёР»Рё РµСЃС‚СЊ РјРёРЅСѓСЃ-СЃР»РѕРІРѕ),
         РІРµРєС‚РѕСЂ СЃР»РѕРІ РЅСѓР¶РЅРѕ РІРµСЂРЅСѓС‚СЊ РїСѓСЃС‚С‹Рј.*/


    };

private:
    struct DocumentData {
        int rating;
        DocumentStatus status;
    };

    struct Query {
        set<string> plus_words;
        set<string> minus_words;
    };

    set<string> stop_words_;
    map<string, map<int, double>> word_to_document_freqs_;
    map<int, DocumentData> documents_;
    int document_count_ = 0;

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

    static int ComputeAverageRating(const vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        int rating_sum = 0;
        for (const int rating : ratings) {
            rating_sum += rating;
        }
        return rating_sum / static_cast<int>(ratings.size());
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
        return { text, is_minus, IsStopWord(text) };
    }

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
        return log(documents_.size() * 1.0 / word_to_document_freqs_.at(word).size());
    }

    vector<Document> FindAllDocuments(const Query& query, DocumentStatus status) const {
        map<int, double> document_to_relevance;
        for (const string& word : query.plus_words) {
            if (word_to_document_freqs_.count(word) == 0) {
                continue;
            }
            const double inverse_document_freq = ComputeWordInverseDocumentFreq(word);
            for (const auto& [document_id, term_freq] : word_to_document_freqs_.at(word)) {
                if (documents_.at(document_id).status == status) {
                    document_to_relevance[document_id] += term_freq * inverse_document_freq;
                }
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
            matched_documents.push_back(
                { document_id, relevance, documents_.at(document_id).rating });
        }
        return matched_documents;
    }

};


//----------------------------------------------
void PrintMatchDocumentResult(int document_id, const vector<string>& words, DocumentStatus status) {
    cout << "{ "s
        << "document_id = "s << document_id << ", "s
        << "status = "s << static_cast<int>(status) << ", "s
        << "words ="s;
    for (const string& word : words) {
        cout << ' ' << word;
    }
    cout << "}"s << endl;
}
int main() {

    setlocale(LC_ALL, "Russian");//РїРµСЂРµРІРѕРґ РєРѕРЅСЃРѕР»Рё РЅР° Р СѓСЃСЃРєРёР№ СЏР·С‹Рє

    SearchServer search_server;
    search_server.SetStopWords("Рё РІ РЅР°"s);
    search_server.AddDocument(0, "Р±РµР»С‹Р№ РєРѕС‚ Рё РјРѕРґРЅС‹Р№ РѕС€РµР№РЅРёРє"s, DocumentStatus::ACTUAL, { 8, -3 });
    search_server.AddDocument(1, "РїСѓС€РёСЃС‚С‹Р№ РєРѕС‚ РїСѓС€РёСЃС‚С‹Р№ С…РІРѕСЃС‚"s, DocumentStatus::ACTUAL, { 7, 2, 7 });
    search_server.AddDocument(2, "СѓС…РѕР¶РµРЅРЅС‹Р№ РїС‘СЃ РІС‹СЂР°Р·РёС‚РµР»СЊРЅС‹Рµ РіР»Р°Р·Р°"s, DocumentStatus::ACTUAL, { 5, -12, 2, 1 });
    search_server.AddDocument(3, "СѓС…РѕР¶РµРЅРЅС‹Р№ СЃРєРІРѕСЂРµС† РµРІРіРµРЅРёР№"s, DocumentStatus::BANNED, { 9 });
    const int document_count = search_server.GetDocumentCount();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        const auto [words, status] = search_server.MatchDocument("РїСѓС€РёСЃС‚С‹Р№ -РєРѕС‚"s, document_id);
        PrintMatchDocumentResult(document_id, words, status);
    }
}