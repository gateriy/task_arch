п»ї// Task_class.cpp 
// Р·Р°РґР°С‡Рё 1,2

#include <iostream>
#include <string>
#include <Windows.h>

enum class Task {
	task_1 = 1,
	task_2,
};

template <typename text, typename data>
void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
	//std::cout << std::endl;
}

template <typename text, typename data>
data Input_X(const text& A, const data& B) {
	data cycle{ B };
	std::cout << A;
	std::cin >> cycle;
	return cycle;
}

bool ExitProgram()
{

	char exit_Y_N{};

	do
	{
		//std::cout << std::endl;
		std::cout << "Exit programm (Y/N): ";
		std::cin >> exit_Y_N;
		std::cout << std::endl;

		if (exit_Y_N == 'Y' || exit_Y_N == 'y') {
			return false;
			break;
		}
		else if (exit_Y_N == 'N' || exit_Y_N == 'n') {
			return true;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}

	} while (true);
}

/*РЎРѕР·РґР°Р№С‚Рµ РєР»Р°СЃСЃ Calculator. РљР»Р°СЃСЃ РґРѕР»Р¶РµРЅ СЃРѕРґРµСЂР¶Р°С‚СЊ РґРІР° РїРѕР»СЏ num1 Рё num2 РґР»СЏ С…СЂР°РЅРµРЅРёСЏ РґСЂРѕР±РЅС‹С… С‡РёСЃРµР». 
РўР°РєР¶Рµ РєР»Р°СЃСЃ РґРѕР»Р¶РµРЅ СЃРѕРґРµСЂР¶Р°С‚СЊ СЃР»РµРґСѓСЋС‰РёРµ РјРµС‚РѕРґС‹:
double add() - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ РІРѕР·РІСЂР°С‰Р°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚ СЃР»РѕР¶РµРЅРёСЏ num1 Рё num2
double multiply() - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ РІРѕР·РІСЂР°С‰Р°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚ РїРµСЂРµРјРЅРѕР¶РµРЅРёСЏ num1 Рё num2
double subtract_1_2() - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ РІРѕР·РІСЂР°С‰Р°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚ РІС‹С‡РёС‚Р°РЅРёСЏ num2 РёР· num1
double subtract_2_1() - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ РІРѕР·РІСЂР°С‰Р°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚ РІС‹С‡РёС‚Р°РЅРёСЏ num1 РёР· num2
double divide_1_2() - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ РІРѕР·РІСЂР°С‰Р°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚ РґРµР»РµРЅРёСЏ num1 РЅР° num2
double divide_2_1() - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ РІРѕР·РІСЂР°С‰Р°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚ РґРµР»РµРЅРёСЏ num2 РЅР° num1
bool set_num1(double num1) - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ СѓСЃС‚Р°РЅРѕРІРёС‚СЊ Р·РЅР°С‡РµРЅРёРµ РїРѕР»СЏ num1 СЂР°РІРЅРѕРµ Р·РЅР°С‡РµРЅРёСЋ Р°СЂРіСѓРјРµРЅС‚Р° 
num1 РІ СЃР»СѓС‡Р°Рµ, РµСЃР»Рё Р·РЅР°С‡РµРЅРёРµ Р°СЂРіСѓРјРµРЅС‚Р° РЅРµ СЂР°РІРЅРѕ 0. Р’РѕР·РІСЂР°С‰Р°РµС‚ true, РµСЃР»Рё СѓСЃС‚Р°РЅРѕРІРєР° РїСЂРѕРёР·РѕС€Р»Р° СѓСЃРїРµС€РЅРѕ, 
РІ РѕР±СЂР°С‚РЅРѕРј СЃР»СѓС‡Р°Рµ false
bool set_num2(double num2) - РјРµС‚РѕРґ РґРѕР»Р¶РµРЅ СѓСЃС‚Р°РЅРѕРІРёС‚СЊ Р·РЅР°С‡РµРЅРёРµ РїРѕР»СЏ num2 СЂР°РІРЅРѕРµ Р·РЅР°С‡РµРЅРёСЋ Р°СЂРіСѓРјРµРЅС‚Р° 
num2 РІ СЃР»СѓС‡Р°Рµ, РµСЃР»Рё Р·РЅР°С‡РµРЅРёРµ Р°СЂРіСѓРјРµРЅС‚Р° РЅРµ СЂР°РІРЅРѕ 0. Р’РѕР·РІСЂР°С‰Р°РµС‚ true, РµСЃР»Рё СѓСЃС‚Р°РЅРѕРІРєР° РїСЂРѕРёР·РѕС€Р»Р° СѓСЃРїРµС€РЅРѕ, 
РІ РѕР±СЂР°С‚РЅРѕРј СЃР»СѓС‡Р°Рµ false
РќР°РїРёС€РёС‚Рµ РєРѕРґ, РґРµРјРѕРЅСЃС‚СЂРёСЂСѓСЋС‰РёР№ СЂР°Р±РѕС‚Сѓ РєР»Р°СЃСЃР° Calculator. РџРѕРїСЂРѕСЃРёС‚Рµ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ РІРІРµСЃС‚Рё РґРІР° С‡РёСЃР»Р°. 
РџРѕСЃР»Рµ СЌС‚РѕРіРѕ РІС‹РІРµРґРёС‚Рµ РїРѕР»СЊР·РѕРІР°С‚РµР»СЋ СЂРµР·СѓР»СЊС‚Р°С‚С‹ РІСЃРµС… РѕРїРµСЂР°С†РёР№ РёР»Рё РїРѕРїСЂРѕСЃРёС‚Рµ РµРіРѕ РІРІРµСЃС‚Рё Р·РЅР°С‡РµРЅРёРµ РµС‰С‘ СЂР°Р·, 
РµСЃР»Рё РїСЂРµРґС‹РґСѓС‰РёР№ РІРІРѕРґ Р±С‹Р» РЅРµРєРѕСЂСЂРµРєС‚РµРЅ
РџСЂРѕРіСЂР°РјРјР° СЃРїСЂР°С€РёРІР°РµС‚ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ Р±РµСЃРєРѕРЅРµС‡РЅРѕ, РїРѕРєР° РѕРЅ СЃР°Рј РЅРµ Р·Р°РєСЂРѕРµС‚ РєРѕРЅСЃРѕР»СЊ*/

class Calculator {
public:

	/*Task_1(const double& num1, const double& num2) {
		this->num1 = num2;
		this->num2 = num2;
	}*/

	//Task_1(const double& _num1, const double& _num2) : num1{ _num1 }, num2{ _num2 }
	//{};
	Calculator() {};

	bool set_num1(const double& num1) {

		if (num1 != 0) {
		this->num1 = num1;
		}
		if (this->num1 == num1) {
			return true;
		}
		else { return false; }
	}
	bool set_num2(const double& num2) {

		if (num2 != 0) {
			this->num2 = num2;
		}
		if (this->num2 == num2) {
			return true;
		}
		else { return false; }
	}

	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num2 * num1;
	}
	double subtract_1_2() {
		return num2 - num1;
	}
	double subtract_2_1() {
		return num1 - num2;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}

private:
	double num1{ 0 };
	double num2{ 0 };		
};

double InputDataNum(const std::string& text) {
	double x{ 0 };
	do {
		std::cout << text;
		std::cin >> x;
		if (x == 0) {
			std::cout << "РќРµ РєРѕСЂСЂРµРєС‚РЅС‹Р№ РІРІРѕРґ!" << std::endl;
		}
		else {
			return x;
			break;
		}
	} while (true);
}

void Task_1() {

	Calculator СЃalculator{};

	int a{ 0 };
	int b = Input_X("Р’РІРµРґРёС‚Рµ РєРѕР»РёС‡РµСЃС‚РІРѕ С†РёРєР»РѕРІ: ",0.0);

	do {
		if (СЃalculator.set_num1(InputDataNum("Р’РІРµРґРёС‚Рµ num1: ")) == true &&
			 СЃalculator.set_num2(InputDataNum("Р’РІРµРґРёС‚Рµ num2: ")) == true) {
				std::cout << std::endl;
				Output("\tnum1 + num2 = ", СЃalculator.add());
				Output("\tnum1 * num2 = ", СЃalculator.multiply());
				Output("\tnum2 - num1 = ", СЃalculator.subtract_1_2());
				Output("\tnum1 - num2 = ", СЃalculator.subtract_2_1());
				Output("\tnum1 / num2 = ", СЃalculator.divide_1_2());
				Output("\tnum2 / num1 = ", СЃalculator.divide_2_1());
				std::cout << std::endl;
		}
	++a;
	} while (b != a);
}

/*
РЎРѕР·РґР°Р№С‚Рµ РєР»Р°СЃСЃ Counter. РљР»Р°СЃСЃ РґРѕР»Р¶РµРЅ РІС‹РїРѕР»РЅСЏС‚СЊ С„СѓРЅРєС†РёСЋ СЃС‡С‘С‚С‡РёРєР°, РґР»СЏ СЌС‚РѕРіРѕ РѕРЅ РґРѕР»Р¶РµРЅ РїСЂРµРґРѕСЃС‚Р°РІР»СЏС‚СЊ:

РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ СѓРІРµР»РёС‡РёС‚СЊ СЃРІРѕС‘ Р·РЅР°С‡РµРЅРёРµ РЅР° 1
РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ СѓРјРµРЅСЊС€РёС‚СЊ СЃРІРѕС‘ Р·РЅР°С‡РµРЅРёРµ РЅР° 1
РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ РїРѕСЃРјРѕС‚СЂРµС‚СЊ СЃРІРѕС‘ С‚РµРєСѓС‰РµРµ Р·РЅР°С‡РµРЅРёРµ
РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ СЃРѕР·РґР°РЅРёСЏ СЌРєР·РµРјРїР»СЏСЂР° РєР»Р°СЃСЃР° СЃ РЅР°С‡Р°Р»СЊРЅС‹Рј Р·РЅР°С‡РµРЅРёРµРј РїРѕ СѓРјРѕР»С‡Р°РЅРёСЋ (1)
РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ СЃРѕР·РґР°РЅРёСЏ СЌРєР·РµРјРїР»СЏСЂР° РєР»Р°СЃСЃР° СЃ РёРЅРёС†РёР°Р»РёР·РёСЂСѓСЋС‰РёРј РЅР°С‡Р°Р»СЊРЅС‹Рј Р·РЅР°С‡РµРЅРёРµРј

РћР±СЂР°С‚РёС‚Рµ РІРЅРёРјР°РЅРёРµ РЅР° С‚Рѕ, С‡С‚Рѕ Сѓ РІРЅРµС€РЅРµРіРѕ РєРѕРґР° РЅРµ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ РІРѕР·РјРѕР¶РЅРѕСЃС‚Рё РёР·РјРµРЅРёС‚СЊ РІРЅСѓС‚СЂРµРЅРЅРµРµ Р·РЅР°С‡РµРЅРёРµ 
СЃС‡С‘С‚С‡РёРєР° РЅР°РїСЂСЏРјСѓСЋ

РќР°РїРёС€РёС‚Рµ РєРѕРґ, РґРµРјРѕРЅСЃС‚СЂРёСЂСѓСЋС‰РёР№ СЂР°Р±РѕС‚Сѓ РєР»Р°СЃСЃР° Counter. РЎРїСЂРѕСЃРёС‚Рµ Сѓ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ, С…РѕС‡РµС‚ Р»Рё РѕРЅ СѓРєР°Р·Р°С‚СЊ 
РЅР°С‡Р°Р»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ РґР»СЏ СЃС‡С‘С‚С‡РёРєР°. Р•СЃР»Рё С…РѕС‡РµС‚, РґР°Р№С‚Рµ РµРјСѓ РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ СЌС‚Рѕ СЃРґРµР»Р°С‚СЊ. Р—Р°С‚РµРј РїСЂРµРґРѕСЃС‚Р°РІСЊС‚Рµ 
РїРѕР»СЊР·РѕРІР°С‚РµР»СЋ РІРѕР·РјРѕР¶РЅРѕСЃС‚СЊ РІРІРѕРґРёС‚СЊ РєРѕРјР°РЅРґС‹:

+: СѓРІРµР»РёС‡СЊС‚Рµ СЃС‡С‘С‚С‡РёРє РЅР° 1
-: СѓРјРµРЅСЊС€РёС‚Рµ СЃС‡С‘С‚С‡РёРє РЅР° 1
=: РІС‹РІРµРґРёС‚Рµ С‚РµРєСѓС‰РµРµ Р·РЅР°С‡РµРЅРёРµ СЃС‡С‘С‚С‡РёРєР°
x: Р·Р°РІРµСЂС€РёС‚Рµ СЂР°Р±РѕС‚Сѓ РїСЂРѕРіСЂР°РјРјС‹
*/

class Counter {
public:
	Counter(const int& _count)
	{
		this ->_count = _count;	
	};

	Counter() {
		_count = 1;
	};	

	int LookCount() {
		return _count;
	}
	int AddCount() {
		return ++_count;
	}
	int SubtractCount() {
		return --_count;
	}
	
private:
	int _count{};
};

int FestCounter() {
	int counter_x{ 0 };

	do
	{
		std::string Y_N{};
		std::cout << "Р’С‹ С…РѕС‚РёС‚Рµ СѓРєР°Р·Р°С‚СЊ РЅР°С‡Р°Р»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ СЃС‡С‘С‚С‡РёРєР°? Р’РІРµРґРёС‚Рµ РґР° РёР»Рё РЅРµС‚: ";
		std::cin >> Y_N;
		std::cout << std::endl;

		if (Y_N == "Р”" || Y_N == "Рґ" || Y_N=="РґР°") {
			std::cout << "Р’РІРµРґРёС‚Рµ РЅР°С‡Р°Р»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ СЃС‡РµС‚С‡РёРєР°: ";
			std::cin >> counter_x;
			break;
		}
		else if (Y_N == "Рќ" || Y_N == "РЅ" || Y_N == "РЅРµС‚") {
			counter_x = 1;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}
	} while (true);
	return counter_x;
}

void Task_2() {
	
	Counter counter(FestCounter());
	char comm{ };
	do {
		std::cout << "Р’РІРµРґРёС‚Рµ РєРѕРјР°РЅРґСѓ ('+', '-', '=' РёР»Рё 'x'): ";
		std::cin >> comm;
		if (comm == '+') {
			counter.AddCount();
		}
		else if (comm == '-') {
			counter.SubtractCount();
		}
		else if (comm == '=') {
			Output("РўРµРєСѓС‰РµРµ Р·РЅР°С‡РµРЅРёРµ СЃС‡РµС‚С‡РёРєР°: ", counter.LookCount());			
		}
		else if (comm == 'x' || comm == 'С…') {
			std::cout << "Р”Рѕ СЃРІРёРґР°РЅРёСЏ!" << std::endl;
			std::cout << std::endl;
			break;
		}
		else{ 
			std::cout << "РќРµ РєРѕСЂСЂРµРєС‚РЅС‹Рµ РґР°РЅРЅС‹Рµ! Р’РІРµРґРёС‚Рµ РїР°СЂР°РјРµС‚СЂ РїРѕРІС‚РѕСЂРЅРѕ."  << std::endl;
			std::cout << std::endl;
		}

	} while (true);
	
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		//system("CLS"); //РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё
		std::cout << "\033c";//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё
			bool exit = true;		

		do {

			std::string number_task{ };
			std::cout << "Input numder task (1, 2): ";
			std::cin >> number_task;
			std::cout << std::endl;


			if (number_task == "1" || number_task == "2") {

				switch (stoi(number_task))
				{
				case(static_cast<int>(Task::task_1)):				
					Task_1();
					exit = false;
					break;
				case(static_cast<int>(Task::task_2)):
					Task_2();
					exit = false;
					break;
				}
			}
			else {
				std::cout << "Incorrect data!" << std::endl;
				std::cout << std::endl;
				continue;
			}

		} while (exit);

	} while (ExitProgram());
}