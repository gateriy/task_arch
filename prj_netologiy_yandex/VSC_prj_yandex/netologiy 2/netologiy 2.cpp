п»ї// netologiy 2.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;


const vector<pair<string, string>> WORD_NUMERIC = {
		{"РЅРѕР»СЊ", "РЅСѓР»СЏ"},
		{"РѕРґРёРЅ", "РѕРґРЅРѕРіРѕ"},
		{"РґРІР°","РґРІСѓС…"},
		{"С‚СЂРё","С‚СЂРµС…"},
		{"С‡РµС‚С‹СЂРµ","С‡РµС‚С‹СЂРµС…"},
		{"РїСЏС‚СЊ","РїСЏС‚Рё"},
		{"С€РµСЃС‚СЊ","С€РµСЃС‚Рё"},
		{"СЃРµРјСЊ","СЃРµРјРё"},
		{"РІРѕСЃРµРјСЊ","РІРѕСЃСЊРјРё"},
		{"РґРµРІСЏС‚СЊ","РґРµРІСЏС‚Рё"},
		{"РґРµСЃСЏС‚СЊ","РґРµСЃСЏС‚Рё"},
		{"РѕРґРёРЅР°РґС†Р°С‚СЊ","РѕРґРёРЅР°РґС†Р°С‚Рё"},
		{"РґРІРµРЅР°РґС†Р°С‚СЊ","РґРІРµРЅР°РґС†Р°С‚Рё"},
		{"С‚СЂРёРЅР°РґС†Р°С‚СЊ","С‚СЂРёРЅР°РґС†Р°С‚Рё"},
		{"С‡РµС‚С‹СЂРЅР°РґС†Р°С‚СЊ","С‡РµС‚С‹СЂРЅР°РґС†Р°С‚Рё"},
		{"РїСЏС‚РЅР°РґС†Р°С‚СЊ","РїСЏС‚РЅР°РґС†Р°С‚Рё"},
		{"С€РµСЃС‚РЅР°РґС†Р°С‚СЊ","С€РµСЃС‚РЅР°РґС†Р°С‚Рё"},
		{"СЃРµРјРЅР°РґС†Р°С‚СЊ","СЃРµРјРЅР°РґС†Р°С‚Рё"},
		{"РІРѕСЃРµРјРЅР°РґС†Р°С‚СЊ","РІРѕСЃРµРјРЅР°РґС†Р°С‚Рё"},
		{"РґРµРІСЏС‚РЅР°РґС†Р°С‚СЊ","РґРµРІСЏС‚РЅР°РґС†Р°С‚Рё"},
		{"РґРІР°РґС†Р°С‚СЊ","РґРІР°РґС†Р°С‚Рё"},
		{"С‚СЂРёРґС†Р°С‚СЊ","С‚СЂРёРґС†Р°С‚Рё"},
		{"СЃРѕСЂРѕРє","СЃРѕСЂРѕРєР°"},
		{"РїСЏС‚СЊРґРµСЃСЏС‚","РїСЏС‚РёРґРµСЃСЏС‚Рё"},
		{"С€РµСЃС‚СЊРґРµСЃСЏС‚","С€РµСЃС‚РёРґСЏСЃРёС‚Рё"},
		{"СЃРµРјСЊРґРµСЃСЏС‚","СЃРµРјРёРґРµСЃСЏС‚Рё"},
		{"РІРѕСЃРµРјСЊРґРµСЃСЏС‚","РІРѕСЃСЊРјРёРґРµСЃСЏС‚Рё"},
		{"РґРµРІСЏРЅРѕСЃС‚Рѕ","РґРµРІСЏРЅРѕСЃС‚Рѕ"},
		{"СЃС‚Рѕ","СЃС‚Р°"}
};


pair<string, string> Numeric_Word(const int& x_fist, const int& x_last)  {
	
	string a, b;
	string a_10 = "";
	string b_10 = "";
	int x_a = 0; 
	int x_a_a = 0;
	int x_b = 0;
	int x_b_b = 0;

	//if (abs(x_fist)< WORD_NUMERIC.size()&& abs(x_last) < WORD_NUMERIC.size()) {

		if (abs(x_fist) < 19) {
			x_a = abs(x_fist);
		}

		if ( abs(x_last) < 19) {
			x_b = abs(x_last);
		}

		if (abs(x_fist) > 19 && abs(x_fist)<100) {
			x_a = abs(x_fist)%10;

			x_a_a = 20+((abs(x_fist) - x_a)/10-2);

			a_10 = WORD_NUMERIC.at(x_a_a).first + " ";
		}

		if (abs(x_last) > 19 && abs(x_last) < 100) {
			x_b = abs(x_last) % 10;

			x_b_b = 20+((abs(x_last) - x_b)/10-2);
			b_10 = WORD_NUMERIC.at(x_b_b).second + " ";

		}



//	} 

		if (x_fist > x_last) {
			
			a = a_10 + WORD_NUMERIC.at(x_a).first;
			b = b_10 + WORD_NUMERIC.at(x_b).second;

		}

		if (x_fist < x_last) {

			b = a_10 + WORD_NUMERIC.at(x_a).first;
			a = b_10 + WORD_NUMERIC.at(x_b).second;

		}
	
		if (x_fist == x_last) {

			b = a_10 + WORD_NUMERIC.at(x_a).first;
			a = b;

		}

	return { a,b };
}



int main() {
	setlocale(LC_ALL, "Russian");

	int x = 0, y = 0;
	string minus_x,minus_y;
	string asd = "y";

	while (asd != "n")
	{
		cout << "Р’РІРµРґРёС‚Рµ С†РµР»РѕРµ С‡РёСЃР»Рѕ: ";
		cin >> x;
		cout << "Р’РІРµРґРёС‚Рµ С†РµР»РѕРµ С‡РёСЃР»Рѕ: ";
		cin >> y;
		pair<string, string> a_b = Numeric_Word(x, y);

		if (x < 100 && y < 100 && x > -100 && y > -100) {
			if (x < 0) {
				minus_x = "РјРёРЅСѓСЃ ";
			}
			else minus_x = "";
			if (y < 0) {
				minus_y = "РјРёРЅСѓСЃ ";
			}
			else minus_y = "";

			if (x > y) {
				cout << minus_x << a_b.first << " Р±РѕР»СЊС€Рµ " << minus_y  << a_b.second << "\n";
			}
			if (x < y) {
				cout << minus_x << a_b.second << " РјРµРЅСЊС€Рµ " << minus_y << a_b.first << "\n";
			}
			if (x == y) {
				cout << minus_x << a_b.first << " СЂР°РІРЅРѕ " << minus_y << a_b.second << "\n";
			}
		}
		else cout << "РћС€РёР±РєР°!РћРґРЅРѕ РёР· С‡РёСЃРµР» РІРЅРµ РґРёР°РїР°Р·РѕРЅР°!" << "\n";

		cout << "РїСЂРѕРґРѕР»Р¶РёС‚СЊ y/n: ";
		cin >> asd;
			if (asd != "n") {
				asd = "y";
			} 

	}
	

	return 0;
}

