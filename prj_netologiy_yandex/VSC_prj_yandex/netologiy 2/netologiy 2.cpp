// netologiy 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;


const vector<pair<string, string>> WORD_NUMERIC = {
		{"ноль", "нуля"},
		{"один", "одного"},
		{"два","двух"},
		{"три","трех"},
		{"четыре","четырех"},
		{"пять","пяти"},
		{"шесть","шести"},
		{"семь","семи"},
		{"восемь","восьми"},
		{"девять","девяти"},
		{"десять","десяти"},
		{"одинадцать","одинадцати"},
		{"двенадцать","двенадцати"},
		{"тринадцать","тринадцати"},
		{"четырнадцать","четырнадцати"},
		{"пятнадцать","пятнадцати"},
		{"шестнадцать","шестнадцати"},
		{"семнадцать","семнадцати"},
		{"восемнадцать","восемнадцати"},
		{"девятнадцать","девятнадцати"},
		{"двадцать","двадцати"},
		{"тридцать","тридцати"},
		{"сорок","сорока"},
		{"пятьдесят","пятидесяти"},
		{"шестьдесят","шестидясити"},
		{"семьдесят","семидесяти"},
		{"восемьдесят","восьмидесяти"},
		{"девяносто","девяносто"},
		{"сто","ста"}
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
		cout << "Введите целое число: ";
		cin >> x;
		cout << "Введите целое число: ";
		cin >> y;
		pair<string, string> a_b = Numeric_Word(x, y);

		if (x < 100 && y < 100 && x > -100 && y > -100) {
			if (x < 0) {
				minus_x = "минус ";
			}
			else minus_x = "";
			if (y < 0) {
				minus_y = "минус ";
			}
			else minus_y = "";

			if (x > y) {
				cout << minus_x << a_b.first << " больше " << minus_y  << a_b.second << "\n";
			}
			if (x < y) {
				cout << minus_x << a_b.second << " меньше " << minus_y << a_b.first << "\n";
			}
			if (x == y) {
				cout << minus_x << a_b.first << " равно " << minus_y << a_b.second << "\n";
			}
		}
		else cout << "Ошибка!Одно из чисел вне диапазона!" << "\n";

		cout << "продолжить y/n: ";
		cin >> asd;
			if (asd != "n") {
				asd = "y";
			} 

	}
	

	return 0;
}

