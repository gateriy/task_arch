// Find8_1.cpp IDF-TF (end sprin 1)
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
    int rating;
};

class SearchServer {
public:
    //заданное количество документов
   /*void D_C(const int& document_count) {
        document_count_ = document_count;
    }*/

    const vector<int> RatingStringToInt(const string& ratings) {
        vector<int> rating_int = {};
        vector<string>rating_str = SplitIntoWords(ratings);
        if (rating_str.empty() == 0) {
            for (string r_s : rating_str) {
                rating_int.push_back(stoi(r_s));//вектор рейтинга промежуточный
            }
        }
        else rating_int.push_back(0);
        rating_int.erase(rating_int.begin());
        return rating_int;
    }

    void AddDocument(const int& document_id, const string& document, const vector<int>& ratings) {
        ++document_count_;
        double summ_n_word = 0;//количество слов в документе
       
        vector<string> words = SplitIntoWordsNoStop(document);//вектор слов промежуточный

        if (words.empty() == 0) {
            summ_n_word = 1 / static_cast<double> (words.size()); //определили 1/(общее количество слов в документе) 

            for (const auto& w : words) {
                word_to_document_freqs_[w][document_id] += summ_n_word;// для каждого слова документа записали в map {слово - ключ,{id,tf}}                    
            }
        } 
        
        document_ratings_[document_id] = ComputeAverageRating(ratings);
    }

    vector<Document> FindTopDocuments(const string& raw_query) const {
        const Query query = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query);

        sort(matched_documents.begin(), matched_documents.end(),
            [](const Document& lhs, const Document& rhs) {
                return lhs.relevance > rhs.relevance;
            });
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }

    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }

private:
    int document_count_ = 0;
    map<string, map<int, double>> word_to_document_freqs_;
    set<string> stop_words_;
    map<int, int> document_ratings_;//Ключом в этом словаре id документа, значение — его рейтинг.

    struct QueryWord {
        string data;
        bool is_minus;
        bool is_stop;
    };
    //функция вычисления среднего рейтига
    int ComputeAverageRating(const vector<int>& ratings) {

        int summ_rat = 0;
        int rat_size = ratings.size();
        if (ratings.empty() == 0) {
            for (const int& rating : ratings) {
                summ_rat = summ_rat + rating;
            }
            return summ_rat / rat_size;
        }
        else return 0;

    }

  /*  vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) const {
        vector<string> words;
        for (const string& word : SplitIntoWords(text)) {
            if (stop_words.count(word) == 0) {
                words.push_back(word);
            }
        }
        return words;
    }*/

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

     QueryWord ParseQueryWord(string text) const {
        bool is_minus = false;
        // Word shouldn't be empty
        if (text[0] == '-') {
            is_minus = true;
            text = text.substr(1);
        }
        return { text, is_minus, IsStopWord(text) };
    }

 /*   struct Query {
        map<string, double> query_words_;
        set<string> minus_query_words_;
    };
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
    }*/

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

   /* double Math_Idf(const int& doc_count, const int& docum_quantity) const {
        double idf = log(static_cast<double>(doc_count) / static_cast<double>(docum_quantity));
        return  idf;
    }*/

    // Existence required
    double ComputeWordInverseDocumentFreq(const string& word) const {
        return log(document_count_ * 1.0 / word_to_document_freqs_.at(word).size());
    }
    //поиск документов
    vector<Document> FindAllDocuments(const Query& query_words) const {
        vector<Document> matched_documents;
        map<int, pair <double, int>> document_to_relevance;
        set<int> minus_id;
        double idf = 0;

        for (const auto& word_id : word_to_document_freqs_) //перебираю слова документа
        {
            for (const auto& minus_document : query_words.minus_words) //перебираю -слова запроса
            {
                if (word_id.first == minus_document) //формирую индексы документов с -словами
                {
                    for (const auto& id_set : word_id.second) {
                        minus_id.insert(id_set.first);
                    }
                }
            }
            for (const auto& document : query_words.plus_words) //перебираю +слова запроса
            {
                if (word_id.first == document)
                {
                   idf = ComputeWordInverseDocumentFreq(word_id.first);
                    int rating = 0;

                    for (const auto& [document_id, tf] : word_id.second) {

                        if (document_ratings_.empty() == 0) {
                            rating = document_ratings_.at(document_id);
                        }

                        document_to_relevance[document_id].first += tf * idf;
                        document_to_relevance[document_id].second = rating;
                    }
                }
            }
        }

        for (auto& set_minus : minus_id) {
            document_to_relevance.erase(set_minus);
        }

        for (auto& [i, rel_rat] : document_to_relevance) {
            matched_documents.push_back({ i, rel_rat.first, rel_rat.second });
        }
        return matched_documents;
    }
};

SearchServer CreateSearchServer() {
    SearchServer  search_server;
    search_server.SetStopWords(ReadLine());
    const int document_count = ReadLineWithNumber();

    for (int i = 0; i < document_count; ++i) {
        string doc = ReadLine();
        vector <int> rat=search_server.RatingStringToInt(ReadLine());
        search_server.AddDocument(i,doc, rat);
    }
    return search_server;
}

int main() {
    const SearchServer  search_server1 = CreateSearchServer();
    string query = ReadLine();

    for (auto [document_id, relevance, rating] : search_server1.FindTopDocuments(query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << ", rating = "s << rating << " }"s
            << endl;
    }

    /*for (auto i : search_server1.word_to_document_freqs_) {
          cout << "{\t"s << i.first << " ----- "s;
          for (auto x : i.second) {
              cout << "("s<<x.first<<"-"s << x.second << ") }"s;
          }
          cout << endl;
      }

    for (auto i : search_server1.document_ratings_) {
        cout << "{\t"s << i.first << " ----- "s << i.second << " }"s << endl;;
        }*/


}
