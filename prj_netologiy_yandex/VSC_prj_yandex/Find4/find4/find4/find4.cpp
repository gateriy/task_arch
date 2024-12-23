п»ї// find4.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
//#include <numeric>

using namespace std;

const int  MAX_RESULT_DOCUMENT_COUNT = 5;//РєРѕРЅСЃС‚Р°РЅС‚РЅР°СЏ РїРµСЂРµРјРµРЅРЅР°СЏ РѕРїСЂРµРґРµР»СЏРµС‚ РєРѕР»РёС‡РµСЃС‚РІРѕ С‚РѕРїРѕРІ
struct DocumentContent { int id; vector<string> words; }; //РїРµСЂРµРјРµРЅРЅР°СЏ struct - -  СЃС‚СЂСѓРєС‚СѓСЂР°
//-----С‡С‚РµРЅРёРµ Рё РІРѕР·РІСЂР°С‚ СЃС‚СЂРѕРєРё---------------------------------------------------------------------
string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
//-----С‡С‚РµРЅРёРµ Рё РІРѕР·РІСЂР°С‚ РєРѕР»РёС‡РµСЃС‚РІР° СЃС‚СЂРѕРє РІ С‚РµРєСЃС‚Рµ Рё СЃР°РјРѕР№ СЃС‚СЂРѕРєРё-----------------------------------
int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}
//-----СЂР°Р·Р±РёРµРЅРёРµ СЃС‚СЂРѕРєРё РЅР° СЃР»РѕРІР° РїРѕ РїСЂРѕР±РµР»Р°Рј Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РІРµРєС‚РѕСЂР° СЃР»РѕРІ---------------------------
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
//-----СЃРѕР·РґР°РЅРёРµ РєРѕРЅС‚РµР№РЅРµСЂР° РЎС‚РѕРї СЃР»РѕРІ---------------------------------------------------------------
set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}
//-----СЃРѕР·РґР°РЅРёРµ РІРµРєС‚РѕСЂР° СЃР»РѕРІ РёСЃС…РѕРґРЅРѕРіРѕ С‚РµРєСЃС‚Р° Р·Р° РІС‹С‡РµС‚РѕРј СЃС‚РѕРї СЃР»РѕРІ---------------------------------
vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}
//-----СЃРѕР·РґР°РЅРёРµ Рё РґРѕР±Р°РІР»РµРЅРёРµ Рє РІРµРєС‚РѕСЂСѓ РёР· РїР°СЂ {id Рё РІРµРєС‚РѕСЂ СЃС‚СЂРѕРєРё} РЅРѕРІРѕР№ РїР°СЂС‹ РІ РєРѕРЅРµС† РІРµРєС‚РѕСЂР°------ 
void AddDocument(vector<DocumentContent>& documents,
    const set<string>& stop_words,
    int 				      document_id,
    const string& document) {

    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back({ document_id,words });
    //documents.words = words;
}
//-----СЃРѕР·РґР°РЅРёРµ РєРѕРЅС‚РµР№РЅРµСЂР° СЃР»РѕРІ РїРѕРёСЃРєРѕРІРѕРіРѕ Р·Р°РїСЂРѕСЃР° Р·Р° РІС‹С‡РµС‚РѕРј СЃС‚РѕРї СЃР»РѕРІ----------------------------
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}
//-----РІРѕР·РІСЂР°С‚ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё РІ РїР°СЂРµ {id Рё РІРµРєС‚РѕСЂ СЃС‚СЂРѕРєРё} РїРѕ Р·Р°РїСЂРѕСЃСѓ СЃ РїСЂРѕРІРµСЂРєРѕР№ РїСѓСЃС‚РѕРіРѕ Р·Р°РїСЂРѕСЃР° Рё РїРѕРІС‚РѕСЂРѕРІ СЃР»РѕРІ РІ РІ С‚РµРєСЃС‚Рµ---
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
   // РџСЂРµРѕР±СЂР°Р·РѕРІС‹РІР°РµРј Р±РµР·Р·РЅР°РєРѕРІРѕРµ С‡РёСЃР»Рѕ С‚РёРїР° size_t РІ int РёСЃРїРѕР»СЊР·СѓСЏ static_cast<int>
    return static_cast<int>(matched_words.size());
}
//-----РґР»СЏ РєР°Р¶РґРѕРіРѕ РЅР°Р№РґРµРЅРЅРѕРіРѕ РґРѕРєСѓРјРµРЅС‚Р° РІРѕР·РІСЂР°С‰Р°РµС‚ РµРіРѕ id Рё СЂРµР»РµРІР°С‚РЅРѕСЃС‚СЊ {СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ, id}-------
vector<pair<int, int> > FindAllDocuments(const vector<DocumentContent>&     documents,
                                         const set<string>&                 query_words)
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
// Р’РѕР·РІСЂР°С‰Р°РµС‚ С‚РѕРї-5 СЃР°РјС‹С… СЂРµР»РµРІР°РЅС‚РЅС‹С… РґРѕРєСѓРјРµРЅС‚РѕРІ РІ РІРёРґРµ РїР°СЂ: {id, СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ}
vector<pair<int, int>> FindTopDocuments(const vector<DocumentContent>&  documents,
                                        const set<string>&              stop_words,
                                        const string&               raw_query)
{
    vector<pair<int, int>> fad;
    fad = FindAllDocuments(documents, stop_words);
    sort(fad.begin(), fad.end());//СЃРѕСЂС‚РёСЂРѕРІРєР° РїРѕ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё {СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ, id}
    reverse(fad.begin(), fad.end());//РїРµСЂРµСЃРѕСЂС‚РёСЂРѕРІРєР° РїРѕ СѓР±С‹РІР°РЅРёСЋ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё {СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ, id}

    if (MAX_RESULT_DOCUMENT_COUNT < fad.size()) { fad.resize(MAX_RESULT_DOCUMENT_COUNT); }

    return fad;
    // РќР°РїРёС€РёС‚Рµ С„СѓРЅРєС†РёСЋ, РёСЃРїРѕР»СЊР·СѓСЏ FindAllDocuments
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