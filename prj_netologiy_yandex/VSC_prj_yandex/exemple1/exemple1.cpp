п»ї// exemple1.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>

using namespace std;

class SearchServer {
public:
    // РїРµСЂРµРЅРµСЃРёС‚Рµ СЃСЋРґР° DocumentStatus
    enum class DocumentStatus {
        ACTUAL,
        IRRELEVANT,
        BANNED,
        REMOVED,
    };
};

int main() {
    // РІС‹РІРµРґРёС‚Рµ С‡РёСЃР»РµРЅРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ СЃС‚Р°С‚СѓСЃР° BANNED
    cout << static_cast<int>( SearchServer::DocumentStatus::BANNED) << endl;

        return 0;
} 
