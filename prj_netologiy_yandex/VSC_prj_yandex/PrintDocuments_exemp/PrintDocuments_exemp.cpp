п»ї// PrintDocuments_exemp.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Document {
    int id;
    int rating;
};

//vector<pair<int, int>> doc = {};

void PrintDocuments(vector<Document> documents, size_t skip_start, size_t skip_finish) {

    if (skip_start <= static_cast<size_t>(documents.size())+1 && skip_start >= 0 &&
        skip_finish <= static_cast<size_t>(documents.size())  && skip_finish >= 0 &&
        documents.empty()==0) {

        sort(documents.begin(), documents.end(), [](Document lh, Document rh) {
            return lh.rating > rh.rating;
            });

       /*for (size_t i = 0; i < documents.size(); ++i) {
            if (i + 1 > skip_start && i < static_cast<int>(documents.size())-skip_finish) {
                doc.push_back({ documents.at(i).id,documents.at(i).rating});
            }

        }*/

       for (size_t i = skip_start;  i < static_cast<size_t>(documents.size()) - skip_finish; ++i) {
         //  if (i + 1 > skip_start && i < static_cast<size_t>(documents.size()) - skip_finish) {
              // doc.push_back({ documents.at(i).id,documents.at(i).rating });

            cout << "{ id = "s << documents.at(i).id << ", rating = "s << documents.at(i).rating << " }"s << endl;
       }        
    }
}

int main() {
    PrintDocuments({ {} },{1}, {2});
    

}