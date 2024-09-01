п»ї// find_exemp2.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Document {
    int id;
    double relevance;
    int rating;
};

void SortDocuments(vector<Document>& matched_documents) {

    //РїРµСЂРІС‹Р№ РІР°СЂРёР°РЅС‚ СЃРѕСЂС‚РёСЂРѕРІРєРё

  /*  sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {        
            return lhs.rating > rhs.rating || 
                (lhs.rating==rhs.rating && lhs.relevance>rhs.relevance);
        });*/
    //РІС‚РѕСЂРѕР№ РІР°СЂРёР°РЅС‚ СЃРѕСЂС‚РёСЂРѕРІРєРё СЃ РїР°СЂР°РјРё

    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {
            return pair(lhs.rating, lhs.relevance) >
                   pair(rhs.rating, rhs.relevance);
        });

    /*
РћР¶РёРґР°РµРјС‹Р№ РІС‹РІРѕРґ:
102 0.3 5
101 1.2 4
100 0.5 4
*/

    /*Р’С‹ СЃРѕСЂС‚РёСЂРѕРІР°Р»Рё РЅР°Р№РґРµРЅРЅС‹Рµ РїРѕРёСЃРєРѕРІРѕР№ СЃРёСЃС‚РµРјРѕР№ РґРѕРєСѓРјРµРЅС‚С‹ РїРѕ СѓР±С‹РІР°РЅРёСЋ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё. 
    РќРµ РјРµРЅСЏСЏ РґР°РЅРЅРѕР№ С„СѓРЅРєС†РёРё, РёСЃРїСЂР°РІСЊС‚Рµ РєРѕРјРїР°СЂР°С‚РѕСЂ С‚Р°Рє,
    С‡С‚РѕР±С‹ РѕРЅ СЃРѕСЂС‚РёСЂРѕРІР°Р» РїРѕ СѓР±С‹РІР°РЅРёСЋ СЂРµР№С‚РёРЅРіР°. 
    Рђ РїСЂРё РѕРґРёРЅР°РєРѕРІРѕРј СЂРµР№С‚РёРЅРіРµ вЂ” РїРѕ СѓР±С‹РІР°РЅРёСЋ СЂРµР»РµРІР°РЅС‚РЅРѕСЃС‚Рё.*/

}

int main() {
    vector<Document> documents = { {100, 0.5, 4}, {101, 1.2, 4}, {102, 0.3, 5} };
    SortDocuments(documents);
    for (const Document& document : documents) {
        cout << document.id << ' ' << document.relevance << ' ' << document.rating << endl;
    }

    return 0;
}