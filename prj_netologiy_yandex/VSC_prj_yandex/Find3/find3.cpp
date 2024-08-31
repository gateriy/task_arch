#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

//--------------
using namespace std;
//-----чтение и возврат строки---------------------------------------------------------------------
string ReadLine() 	{
    string s;
    getline(cin, s);
    return s;		}
//-----чтение и возврат количества строк в тексте и самой строки-----------------------------------
int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;       }
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
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
//-----создание контейнера Стоп слов---------------------------------------------------------------
set<string> ParseStopWords(const string& text) 			{
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);					}
    return stop_words;									}
//-----создание вектора слов исходного текста за вычетом стоп слов---------------------------------
vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);       }		
													}
    return words;																		}
//-----создание и добавление к вектору из пар {id и вектор строки} новой пары в конец вектора------ 
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
//-----создание контейнера слов поискового запроса за вычетом стоп слов----------------------------
set<string> ParseQuery(const string& text, const set<string>& stop_words) 	{
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) 	{
        query_words.insert(word);
																		}
    return query_words;														}
//-----возврат релевантности в паре {id и вектор строки} по запросу в виде числа-------------------
int MatchDocument(const pair<int, vector<string> >& content, const set<string>& query_words) {
	int res =0;
    for (const string& word : content.second) 					{
        if (query_words.count(word) != 0)	{
            ++res;
													}
														}
    return res; 																			}
//-----для каждого найденного документа возвращает его id и релеватность {релевантность, id}-------
vector<pair<int, int> > FindAllDocuments(	const vector<pair<int, vector<string> > >&	documents,
									    	const set<string>& 							stop_words, 
									    	const string& 								query) 		
{	                                            
/*
// Для каждого документа возвращает его релевантность и id
vector<pair<int, int>> FindAllDocuments(const vector<pair<int, vector<string>>>&    documents,
                                        const set<string>&                          query_words)
{
    // Превратите функцию FindDocuments в FindAllDocuments
    // Первым элементом возвращаемых пар идёт релевантность документа, а вторым - его id
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
// Возвращает топ-5 самых релевантных документов в виде пар: {id, релевантность}
vector<pair<int, int>> FindTopDocuments(const vector<pair<int, vector<string>>>&    documents,
                                        const set<string>&                          stop_words, 
                                        const string&                               query) 
{
int  MAX_RESULT_DOCUMENT_COUNT=5;//константная переменная определяет количество топов
int nn=0;
vector<pair<int, int>> fad;
vector<pair<int, int>> res;
fad=FindAllDocuments(documents,stop_words,query);
sort(fad.begin(),fad.end());//сортировка по релевантности {релевантность, id}
reverse(fad.begin(),fad.end());//пересортировка по убыванию релевантности {релевантность, id}
//определение количества топов с учетом размера вектора
if (MAX_RESULT_DOCUMENT_COUNT>fad.size()) {MAX_RESULT_DOCUMENT_COUNT=fad.size();} 

for (const auto& aaa : fad) {
		
        if (nn<MAX_RESULT_DOCUMENT_COUNT) {
            res.push_back(pair<int,int> (aaa.second, aaa.first)); //{id,релевантность}  
        }
        else {break;}
        ++nn;
    }
return res;
    // Напишите функцию, используя FindAllDocuments
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
