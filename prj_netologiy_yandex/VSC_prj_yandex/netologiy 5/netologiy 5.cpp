п»ї// netologiy 5.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <iostream>
#include <string>

int main() {

    std::string znac, pol;
    int age = 0;
    bool man_woman = false;
    bool erth_woter = false;
    bool age_m = false;
    bool age_w = false;
    bool correct = true;


    std::cout << "Р’РІРµРґРёС‚Рµ Р’Р°С€ РїРѕР»: ";
    std::cin >> pol;
    std::cout << "Р’РІРµРґРёС‚Рµ Р’Р°С€ Р·РЅР°Рє Р·РѕРґРёР°РєРєР°: ";
    std::cin >> znac;
    std::cout << "Р’РІРµРґРёС‚Рµ Р’Р°С€ РІРѕР·СЂР°СЃС‚: ";
    std::cin >> age;

    if (pol == "Рј") {
        man_woman = true;
    }
    else if (pol != "Р¶" || pol != "Рј") {
        correct = false;
    }

    if (age < 40 && man_woman == true) {
        age_m = true;
    }

    if (age >= 15 && age <= 30 && man_woman == false) {
        age_w = true;
    }

    if (znac == "РўРµР»РµС†" || znac == "Р”РµРІР°" || znac == "РљРѕР·РµСЂРѕРі") {
        erth_woter = true;
    }
    else if (znac == "Р Р°Рє" || znac == "Р С‹Р±С‹" || znac == "Р Р°Рє") {
            erth_woter = false;
    }
    else { correct == false; }
    
 

 
  


    if (man_woman == true && age_m == true && erth_woter == false && correct == true) {
        std::cout << "РЎРµРіРѕРґРЅСЏ РѕС‡РµРЅСЊ РїР»РѕРґРѕС‚РІРѕСЂРЅС‹Р№ РґРµРЅСЊ. РњРѕР¶РЅРѕ РґРѕР±РёС‚СЊСЃСЏ С‚РѕРіРѕ, С‡С‚Рѕ РїСЂРµР¶РґРµ РєР°Р·Р°Р»РѕСЃСЊ РїРѕС‡С‚Рё РЅРµРІРѕР·РјРѕР¶РЅС‹Рј.\n";
    }
    else if (man_woman == false && age_w == true && erth_woter == true && correct == true) {
        std::cout << "РЎРµРіРѕРґРЅСЏС€РЅРёР№ РІРµС‡РµСЂ РїРѕРґС…РѕРґРёС‚ РґР»СЏ РѕР±С‰РµРЅРёСЏ СЃ РґСЂСѓР·СЊСЏРјРё, РїСЂРѕРІРµРґРµРЅРёСЏ РґРѕРјР°С€РЅРёС… РїСЂР°Р·РґРЅРёРєРѕРІ Рё РёРјРїСЂРѕРІРёР·РёСЂРѕРІР°РЅРЅС‹С… РІРµС‡РµСЂРёРЅРѕРє. Р‘СѓРґРµС‚ РЅРµ С‚РѕР»СЊРєРѕ РІРµСЃРµР»Рѕ, РЅРѕ Рё РёРЅС‚РµСЂРµСЃРЅРѕ: РЅР°Р№РґС‘С‚СЃСЏ РґРµР»Рѕ, РєРѕС‚РѕСЂРѕРµ СѓРІР»РµС‡С‘С‚ РІСЃРµС….\n";
    }
    else {
        if (correct == true) {
            std::cout << "Р“РѕСЂРѕСЃРєРѕРї РґР»СЏ РІР°СЃ РЅР°С…РѕРґРёС‚СЃСЏ РІ СЂР°Р·СЂР°Р±РѕС‚РєРµ. РџСЂРёС…РѕРґРёС‚Рµ С‡СѓС‚РѕС‡РєСѓ РїРѕР·Р¶Рµ ;)\n";
        }
        else if ( correct == false) { std::cout << "РѕС€РёР±РєР° РІРІРѕРґР°"; }

    }
}