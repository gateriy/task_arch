п»ї// 5_task_unit_test.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

class Synonyms {
public:
    void Add(const string& first_word, const string& second_word) {
        synonyms_[first_word].insert(second_word);
        synonyms_[second_word].insert(first_word);
    }

    size_t GetSynonymCount(const string& word) const {
        if (synonyms_.count(word) != 0) {
            return synonyms_.at(word).size();
        }
        return 0;
    }

    bool AreSynonyms(const string& first_word, const string& second_word) const {
        // РќР°РїРёС€РёС‚Рµ РЅРµРґРѕСЃС‚Р°СЋС‰РёР№ РєРѕРґ
        
 //CHECK word1 word2 вЂ” РІС‹РІРµСЃС‚Рё YES, РµСЃР»Рё СЃР»РѕРІР° word1 Рё word2 РІ РґР°РЅРЅС‹Р№ РјРѕРјРµРЅС‚ Р±СѓРґСѓС‚ СЃРёРЅРѕРЅРёРјР°РјРё. Р•СЃР»Рё РЅРµ Р±СѓРґСѓС‚ вЂ” РІС‹РІРµСЃС‚Рё NO;

/*
ADD program code
ADD code cipher
COUNT cipher
1
CHECK code program
YES
CHECK program cipher
NO
EXIT

*/ 

if (!synonyms_.at(first_word).empty()) {
    if (synonyms_.at(first_word).count(second_word)) {
        return true;
    }
    if (synonyms_.at(second_word).count(first_word)) {
        return true;
    }
}
        return false;
    }

private:
    map<string, set<string>> synonyms_;
};

void TestAddingSynonymsIncreasesTheirCount() {
    Synonyms synonyms;
    assert(synonyms.GetSynonymCount("music"s) == 0);
    assert(synonyms.GetSynonymCount("melody"s) == 0);

    synonyms.Add("music"s, "melody"s);
    assert(synonyms.GetSynonymCount("music"s) == 1);
    assert(synonyms.GetSynonymCount("melody"s) == 1);

    synonyms.Add("music"s, "tune"s);
    assert(synonyms.GetSynonymCount("music"s) == 2);
    assert(synonyms.GetSynonymCount("tune"s) == 1);
    assert(synonyms.GetSynonymCount("melody"s) == 1);
}

void TestAreSynonyms() {
    // РќР°РїРёС€РёС‚Рµ РЅРµРґРѕСЃС‚Р°СЋС‰РёР№ РєРѕРґ
    Synonyms synonyms;
   
    synonyms.Add("music"s, "melody"s);
    assert(synonyms.AreSynonyms("music"s, "melody"s) == 1);
    assert(synonyms.AreSynonyms("melody"s, "music"s) == 1);

    synonyms.Add("music"s, "tune"s);

    assert(synonyms.AreSynonyms("tune"s, "melody"s) == 0);
    assert(synonyms.AreSynonyms("melody"s,"tune"s) == 0);

}

void TestSynonyms() {
    TestAddingSynonymsIncreasesTheirCount();
    TestAreSynonyms();
}

int main() {
    TestSynonyms();

    Synonyms synonyms;

    string line;
    while (getline(cin, line)) {
        istringstream command(line);
        string action;
        command >> action;

        if (action == "ADD"s) {
            string first_word, second_word;
            command >> first_word >> second_word;
            synonyms.Add(first_word, second_word);
        }
        else if (action == "COUNT"s) {
            string word;
            command >> word;
            cout << synonyms.GetSynonymCount(word) << endl;
        }
        else if (action == "CHECK"s) {
            string first_word, second_word;
            command >> first_word >> second_word;
            if (synonyms.AreSynonyms(first_word, second_word)) {
                cout << "YES"s << endl;
            }
            else {
                cout << "NO"s << endl;
            }
        }
        else if (action == "EXIT"s) {
            break;
        }
    }
}