#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

//--------------
using namespace std;
//-----С‡С‚РµРЅРёРµ Рё РІРѕР·РІСЂР°С‚ СЃС‚СЂРѕРєРё---------------------------------------------------------------------
string ReadLine() 	{
    string s;
    getline(cin, s);
    return s;		}
//-----С‡С‚РµРЅРёРµ Рё РІРѕР·РІСЂР°С‚ РєРѕР»РёС‡РµСЃС‚РІР° СЃС‚СЂРѕРє РІ С‚РµРєСЃС‚Рµ Рё СЃР°РјРѕР№ СЃС‚СЂРѕРєРё-----------------------------------
int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;       }
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
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
//-----СЃРѕР·РґР°РЅРёРµ РєРѕРЅС‚РµР№РЅРµСЂР° РЎС‚РѕРї СЃР»РѕРІ---------------------------------------------------------------
set<string> ParseStopWords(const string& text) 			{
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);					}
    return stop_words;									}
//-----СЃРѕР·РґР°РЅРёРµ РІРµРєС‚РѕСЂР° СЃР»РѕРІ РёСЃС…РѕРґРЅРѕРіРѕ С‚РµРєСЃС‚Р° Р·Р° РІС‹С‡РµС‚РѕРј СЃС‚РѕРї СЃР»РѕРІ---------------------------------
vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);       }		
													}
    return words;																		}
//-----СЃРѕР·РґР°РЅРёРµ Рё РґРѕР±Р°РІР»РµРЅРёРµ Рє РІРµРєС‚РѕСЂСѓ РёР· РїР°СЂ {id Рё РІРµРєС‚РѕСЂ СЃС‚СЂРѕРєРё} РЅРѕРІРѕР№ РїР°СЂС‹ РІ РєРѕРЅРµС† РІРµРєС‚РѕСЂР°------ 
void AddDocument(vector<pair<int, vector<string> > >& documents,
                 const set<string>& 				stop_words,
                 int 								document_id, 
                 const string& 						document)    			  {
					 
					 
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
	pair<int, vector<string> > ddd;
	ddd.first = document_id;
	ddd.second = words;
    documents.push_back(ddd);
  //documents.push_back(pair<int, vector<string> > (document_id,words));
																				}
//-----СЃРѕР·РґР°РЅРёРµ РєРѕРЅС‚РµР№РЅРµСЂР° СЃР»РѕРІ РїРѕРёСЃРєРѕРІРѕРіРѕ Р·Р°РїСЂРѕСЃР° Р·Р° РІС‹С‡РµС‚РѕРј СЃС‚РѕРї СЃР»РѕРІ----------------------------
set<string> ParseQuery(const string& text, const set<string>& stop_words) 	{
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) 	{
        query_words.insert(word);
																		}
    return query_words;														}
//-----РІРѕР·РІСЂР°С‚ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё РІ РїР°СЂРµ {id Рё РІРµРєС‚РѕСЂ СЃС‚СЂРѕРєРё} РїРѕ Р·Р°РїСЂРѕСЃСѓ РІ РІРёРґРµ С‡РёСЃР»Р°-------------------
int MatchDocument(const pair<int, vector<string> >& content, const set<string>& query_words) {
	int res =0;
    for (const string& word : content.second) 					{
        if (query_words.count(word) != 0)	{
            ++res;
													}
														}
    return res; 																			}
//-----РґР»СЏ РєР°Р¶РґРѕРіРѕ РЅР°Р№РґРµРЅРЅРѕРіРѕ РґРѕРєСѓРјРµРЅС‚Р° РІРѕР·РІСЂР°С‰Р°РµС‚ РµРіРѕ id Рё СЂРµР»РµРІР°С‚РЅРѕСЃС‚СЊ {СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ, id}-------
vector<pair<int, int> > FindAllDocuments(	const vector<pair<int, vector<string> > >&	documents,
									    	const set<string>& 							stop_words, 
									    	const string& 								query) 		
{	                                            
/*
// Р”Р»СЏ РєР°Р¶РґРѕРіРѕ РґРѕРєСѓРјРµРЅС‚Р° РІРѕР·РІСЂР°С‰Р°РµС‚ РµРіРѕ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ Рё id
vector<pair<int, int>> FindAllDocuments(const vector<pair<int, vector<string>>>&    documents,
                                        const set<string>&                          query_words)
{
    // РџСЂРµРІСЂР°С‚РёС‚Рµ С„СѓРЅРєС†РёСЋ FindDocuments РІ FindAllDocuments
    // РџРµСЂРІС‹Рј СЌР»РµРјРµРЅС‚РѕРј РІРѕР·РІСЂР°С‰Р°РµРјС‹С… РїР°СЂ РёРґС‘С‚ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ РґРѕРєСѓРјРµРЅС‚Р°, Р° РІС‚РѕСЂС‹Рј - РµРіРѕ id
} */
	const set<string> query_words = ParseQuery(query, stop_words);	
    vector<pair<int,int> > matched_documents;	
    int document_rel = 0;
    for (const auto& document : documents) {
		document_rel=MatchDocument(document, query_words);
        if (document_rel>0) {
            matched_documents.push_back(pair<int,int> (document_rel,document.first));
        }
    }
    return matched_documents;
}
// Р’РѕР·РІСЂР°С‰Р°РµС‚ С‚РѕРї-5 СЃР°РјС‹С… СЂРµР»РµРІР°РЅС‚РЅС‹С… РґРѕРєСѓРјРµРЅС‚РѕРІ РІ РІРёРґРµ РїР°СЂ: {id, СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ}
vector<pair<int, int>> FindTopDocuments(const vector<pair<int, vector<string>>>&    documents,
                                        const set<string>&                          stop_words, 
                                        const string&                               query) 
{
int  MAX_RESULT_DOCUMENT_COUNT=5;//РєРѕРЅСЃС‚Р°РЅС‚РЅР°СЏ РїРµСЂРµРјРµРЅРЅР°СЏ РѕРїСЂРµРґРµР»СЏРµС‚ РєРѕР»РёС‡РµСЃС‚РІРѕ С‚РѕРїРѕРІ
int nn=0;
vector<pair<int, int>> fad;
vector<pair<int, int>> res;
fad=FindAllDocuments(documents,stop_words,query);
sort(fad.begin(),fad.end());//СЃРѕСЂС‚РёСЂРѕРІРєР° РїРѕ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё {СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ, id}
reverse(fad.begin(),fad.end());//РїРµСЂРµСЃРѕСЂС‚РёСЂРѕРІРєР° РїРѕ СѓР±С‹РІР°РЅРёСЋ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё {СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ, id}
//РѕРїСЂРµРґРµР»РµРЅРёРµ РєРѕР»РёС‡РµСЃС‚РІР° С‚РѕРїРѕРІ СЃ СѓС‡РµС‚РѕРј СЂР°Р·РјРµСЂР° РІРµРєС‚РѕСЂР°
if (MAX_RESULT_DOCUMENT_COUNT>fad.size()) {MAX_RESULT_DOCUMENT_COUNT=fad.size();} 

for (const auto& aaa : fad) {
		
        if (nn<MAX_RESULT_DOCUMENT_COUNT) {
            res.push_back(pair<int,int> (aaa.second, aaa.first)); //{id,СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚СЊ}  
        }
        else {break;}
        ++nn;
    }
return res;
    // РќР°РїРёС€РёС‚Рµ С„СѓРЅРєС†РёСЋ, РёСЃРїРѕР»СЊР·СѓСЏ FindAllDocuments
}

//-------------------------------
int main() {
   const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector<pair<int, vector<string> > > documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
       // AddDocument(documents, stop_words, ReadLine());
	 AddDocument(documents,stop_words,document_id,ReadLine());  
    }

    const string query = ReadLine();
    for (const auto& document_id : FindTopDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id.first <<", relevance = "s << document_id.second << " }"s << endl;
    }
}