п»ї#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> ComputeTermFreqs(const vector<string>& terms) {
    // СЂРµР°Р»РёР·СѓР№С‚Рµ С„СѓРЅРєС†РёСЋ
    map<string, int> asd;


    for (const string& word : terms) {
        asd[word] +=1;
    }
    return asd;

}

int main() {
    const vector<string> terms = { "first"s, "time"s, "first"s, "class"s };
    for (const auto& [term, freq] : ComputeTermFreqs(terms)) {
        cout << term << " x "s << freq << endl;
    }
    // РІС‹РІРѕРґ:
    // class x 1
    // first x 2
    // time x 1
}