п»ї// Task_abstraktion.cpp : 
// // Р·Р°РґР°С‡Рё 1,2

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream> //РґР»СЏ СЂР°Р±РѕС‚С‹ СЃ С„Р°Р№Р»Р°РјРё
#include<algorithm>

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

//С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
class InOutFileVector {

public:

	//С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	void OupenFileWriteVector() {
		in_data_file.clear();
		do {
			x_line = 0;
			std::cout << "Р§С‚РµРЅРёРµ РґР°РЅРЅС‹С… РёР· С„Р°Р№Р»Р° *.txt" << std::endl;
			std::ifstream  f_in(InputTransformWay()); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ
			if (f_in.is_open()) {

				do {
					//f_in >> x_text;
					getline(f_in >> std::ws, x_text);
					++x_line; //РїСЂРѕС…РѕРґ РїРѕ С„Р°Р№Р»Сѓ РІ СЂРµР¶РёРјРµ СЃС‡РёС‚С‹РІР°РЅРёСЏ Рё РїРѕРґСЃС‡РµС‚ СЃС‚СЂРѕРє
				} while (!f_in.eof());
									
				f_in.clear(); //РѕС‡РёСЃС‚РєР° РїРѕС‚РѕРєР° РІРІРѕРґР° РёР· С„Р°Р№Р»Р°
				f_in.seekg(0, std::ios::beg);//РІРѕР·РІСЂР°С‚ РєСѓСЂСЃРѕСЂР° РІ РЅР°С‡Р°Р»Рѕ С„Р°Р№Р»Р°

				for (int i = 0; i < x_line; ++i) {
					//f_in >> x_text;
					getline(f_in >> std::ws, x_text);
					in_data_file.push_back(x_text);
				};

				f_in.close();
				std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ РїСЂРѕС‡РёС‚Р°РЅ!" << std::endl;
				std::cout << std::endl;
				break;
			}
			else {
				std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
			}
		} while (true);
	}

	//РІС‹РІРѕРґ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	std::vector<std::string> GetVector_1() {

		return in_data_file;
	}

	//РІРІРѕРґ РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	std::vector<std::string> SetVector_2(const std::vector < std::string>& a) {

		if (!a.empty()) {
		out_data_file.clear();

			for (const auto& i : a) {
				out_data_file.push_back(i);
			}
		}
		return out_data_file;
	}

	//РІС‹РІРѕРґ РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	std::vector<std::string> GetVector_2() {

		return out_data_file;
	}

	void InFileWriteVetor() {

		do {
			std::cout << "Р—Р°РїРёСЃСЊ РґР°РЅРЅС‹С… РІ С„Р°Р№Р» *.txt" << std::endl;
			std::ofstream  f_oupen(InputTransformWay()); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° Р·Р°РїРёСЃСЊ
			if (f_oupen.is_open()) {

				//f_oupen << cel << std::endl;

				for (const auto& i: out_data_file) {
					
					f_oupen << i << std::endl;
			
				};
				
				f_oupen.close();
				std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ Р·Р°РїРёСЃР°РЅ!" << std::endl;
				// std::cout << std::endl;
				break;
			}
			else {
				std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
			}
		} while (true);

	}

private:
	int x_line{};
	std::string x_text{};
	std::vector <std::string> in_data_file{};
	std::vector <std::string> out_data_file{};

	//СЃС‡РёС‹РІР°РЅРёРµ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
	std::string InputTransformWay() {
		std::string way{ "" };
		std::string way_file{ "" };

		std::cout << "Р’РІРµРґРёС‚Рµ РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ (РµСЃР»Рё С„Р°Р№Р» РЅРµ РІ РєРѕСЂРЅРµРІРѕРј РєР°С‚Р°Р»РѕРіРµ РїСЂРѕРіСЂР°РјРјС‹): ";
		getline(std::cin >> std::ws, way_file);

		for (auto& ch : way_file) {

			if (ch == '\\' || ch == '/') {

				way = way + '\\' + '\\';
			}
			else {
				way = way + ch;
			}
		}
		return way;
	}
};	

//-----------------------------------------

/*Р’Р°Рј РґР°РЅ С„Р°Р№Р» in.txt, РІ РєРѕС‚РѕСЂРѕРј РЅР°С…РѕРґРёС‚СЃСЏ N Р°РґСЂРµСЃРѕРІ. 
Р§РёСЃР»Рѕ N РёРґС‘С‚ РїРµСЂРІС‹Рј РІ С„Р°Р№Р»Рµ. 
РџРѕСЃР»Рµ С‡РёСЃР»Р° N СЂР°СЃРїРѕР»Р°РіР°СЋС‚СЃСЏ N Р±Р»РѕРєРѕРІ РїРѕ 4 СЃС‚СЂРѕРєРё РІ РєР°Р¶РґРѕРј. 
РљР°Р¶РґС‹Р№ Р±Р»РѕРє СЃРѕСЃС‚РѕРёС‚ РёР· СЃР»РµРґСѓСЋС‰РёС… СЃС‚СЂРѕРє: РЅР°Р·РІР°РЅРёРµ РіРѕСЂРѕРґР°, РЅР°Р·РІР°РЅРёРµ СѓР»РёС†С‹, РЅРѕРјРµСЂ РґРѕРјР°, РЅРѕРјРµСЂ РєРІР°СЂС‚РёСЂС‹.
Р—Р°РґР°С‡Р° РїСЂРѕРіСЂР°РјРјС‹ Р·Р°РєР»СЋС‡Р°РµС‚СЃСЏ РІ С‚РѕРј, С‡С‚РѕР±С‹ СЃС‡РёС‚Р°С‚СЊ Р°РґСЂРµСЃР° РёР· С„Р°Р№Р»Р° in.txt Рё 
РІС‹РІРµСЃС‚Рё РёС… РІ С„Р°Р№Р» out.txt РІ РґСЂСѓРіРѕРј С„РѕСЂРјР°С‚Рµ Рё РІ РѕР±СЂР°С‚РЅРѕРј РїРѕСЂСЏРґРєРµ. 
РќРµ Р·Р°Р±СѓРґСЊС‚Рµ РІС‹РІРµСЃС‚Рё РєРѕР»РёС‡РµСЃС‚РІРѕ Р°РґСЂРµСЃРѕРІ РІ РЅР°С‡Р°Р»Рµ.
Р¤РѕСЂРјР°С‚ РІС‹РІРѕРґР° Р°РґСЂРµСЃР°: <РЅР°Р·РІР°РЅРёРµ РіРѕСЂРѕРґР°>, <РЅР°Р·РІР°РЅРёРµ СѓР»РёС†С‹>, <РЅРѕРјРµСЂ РґРѕРјР°>, <РЅРѕРјРµСЂ РєРІР°СЂС‚РёСЂС‹>.


3
РњРѕСЃРєРІР°
РЎС‚СЂРѕРёС‚РµР»РµР№
34
12
РћРјСЃРє
РџСѓС€РєРёРЅР°
2
13
РќРѕРІРѕСЃРёР±РёСЂСЃРє
РњРёСЂР°
85
64


3
РќРѕРІРѕСЃРёР±РёСЂСЃРє, РњРёСЂР°, 85, 64
РћРјСЃРє, РџСѓС€РєРёРЅР°, 2, 13
РњРѕСЃРєРІР°, РЎС‚СЂРѕРёС‚РµР»РµР№, 34, 12

*/

class AdressData {

public:

	void OutputConsolVector_2() {

	std::cout << "------------------" << std::endl;
	for (const auto& i : in_out_file_vector.GetVector_2()) {
		std::cout << i << std::endl;
	}
    std::cout << "------------------" << std::endl;

}

	void OutputFileVector_2() {

	in_out_file_vector.InFileWriteVetor();

}
				
	void CreateVector_2() {
	
	_count = 0;

	for (const auto& i : in_out_file_vector.GetVector_1()) {
			
		if (_count > 0) {			

			if (_count < 4) {
				text = text + i + ", ";
			}
			else {
				text = text + i;
			}
			
			if (_count == 4) {

				vector_x.push_back(text);
				_count = 0;
				text = {};

			}
		}
		++_count;
	};
	
	if (!vector_x.empty()) {
		in_out_file_vector.SetVector_2(vector_x);
		vector_x.clear();
	}
}

	void CreateVector_1() {
	in_out_file_vector.OupenFileWriteVector();
}

	void ReversVector_2() {

		std::vector <std::string> vector_var{};

		for (const auto& i : in_out_file_vector.GetVector_2()) {
			vector_var.push_back(i);
		}
		if (!vector_var.empty()) {

			std::reverse(vector_var.begin(), vector_var.end());
			in_out_file_vector.SetVector_2(vector_var);
			vector_var.clear();
		}
	}

	void SortVector2() {

		std::vector <std::string> vector_var{};

		for (const auto& i : in_out_file_vector.GetVector_2()) {
			vector_var.push_back(i);
		}
		if (!vector_var.empty()) {
			std::sort(vector_var.begin(), vector_var.end());

			in_out_file_vector.SetVector_2(vector_var);

			vector_var.clear();
		}
	}

private:
	int _count{0};
	std::string text{};
	InOutFileVector in_out_file_vector;
	std::vector <std::string> vector_x{};
	std::map<std::string, std::string> map_x{};

};

void Task_1() {

	AdressData adressd_data;
	adressd_data.CreateVector_1();
	adressd_data.CreateVector_2();
	adressd_data.ReversVector_2();
	adressd_data.OutputConsolVector_2();
	adressd_data.OutputFileVector_2();
}

/*
Р’Р°Рј РґР°РЅ С„Р°Р№Р» in.txt, РІ РєРѕС‚РѕСЂРѕРј РЅР°С…РѕРґРёС‚СЃСЏ N Р°РґСЂРµСЃРѕРІ. 
Р§РёСЃР»Рѕ N РёРґС‘С‚ РїРµСЂРІС‹Рј РІ С„Р°Р№Р»Рµ. 
РџРѕСЃР»Рµ С‡РёСЃР»Р° N СЂР°СЃРїРѕР»Р°РіР°СЋС‚СЃСЏ N Р±Р»РѕРєРѕРІ РїРѕ 4 СЃС‚СЂРѕРєРё РІ РєР°Р¶РґРѕРј. 
РљР°Р¶РґС‹Р№ Р±Р»РѕРє СЃРѕСЃС‚РѕРёС‚ РёР· СЃР»РµРґСѓСЋС‰РёС… СЃС‚СЂРѕРє: РЅР°Р·РІР°РЅРёРµ РіРѕСЂРѕРґР°, РЅР°Р·РІР°РЅРёРµ СѓР»РёС†С‹, РЅРѕРјРµСЂ РґРѕРјР°, РЅРѕРјРµСЂ РєРІР°СЂС‚РёСЂС‹.
Р—Р°РґР°С‡Р° РїСЂРѕРіСЂР°РјРјС‹ Р·Р°РєР»СЋС‡Р°РµС‚СЃСЏ РІ С‚РѕРј, С‡С‚РѕР±С‹ СЃС‡РёС‚Р°С‚СЊ Р°РґСЂРµСЃР° РёР· С„Р°Р№Р»Р° in.txt, 
РѕС‚СЃРѕСЂС‚РёСЂРѕРІР°С‚СЊ РёС… РїРѕ РЅР°Р·РІР°РЅРёСЋ РіРѕСЂРѕРґР° Рё РІС‹РІРµСЃС‚Рё РѕС‚СЃРѕСЂС‚РёСЂРѕРІР°РЅРЅС‹Р№ СЃРїРёСЃРѕРє Р°РґСЂРµСЃРѕРІ 
РІ С„Р°Р№Р» out.txt РІ РґСЂСѓРіРѕРј С„РѕСЂРјР°С‚Рµ. РќРµ Р·Р°Р±СѓРґСЊС‚Рµ РІС‹РІРµСЃС‚Рё РєРѕР»РёС‡РµСЃС‚РІРѕ Р°РґСЂРµСЃРѕРІ РІ РЅР°С‡Р°Р»Рµ.
Р“РѕСЂРѕРґР° РґРѕР»Р¶РЅС‹ Р±С‹С‚СЊ РѕС‚СЃРѕСЂС‚РёСЂРѕРІР°РЅС‹ РІ Р°Р»С„Р°РІРёС‚РЅРѕРј РїРѕСЂСЏРґРєРµ.
Р¤РѕСЂРјР°С‚ РІС‹РІРѕРґР° Р°РґСЂРµСЃР°: <РЅР°Р·РІР°РЅРёРµ РіРѕСЂРѕРґР°>, <РЅР°Р·РІР°РЅРёРµ СѓР»РёС†С‹>, <РЅРѕРјРµСЂ РґРѕРјР°>, <РЅРѕРјРµСЂ РєРІР°СЂС‚РёСЂС‹>.

5
РњРѕСЃРєРІР°
РЎС‚СЂРѕРёС‚РµР»РµР№
34
12
РќРѕРІРѕРєСѓР·РЅРµС†Рє
РќР°СѓРєРё
5
16
РћРјСЃРє
РџСѓС€РєРёРЅР°
2
13
РњРѕСЃРєРІР°
РђСЂР±Р°С‚
4
1
РќРѕРІРѕСЃРёР±РёСЂСЃРє
РњРёСЂР°
85
64

5
РњРѕСЃРєРІР°, РЎС‚СЂРѕРёС‚РµР»РµР№, 34, 12
РњРѕСЃРєРІР°, РђСЂР±Р°С‚, 4, 1
РќРѕРІРѕРєСѓР·РЅРµС†Рє, РќР°СѓРєРё, 5, 16
РќРѕРІРѕСЃРёР±РёСЂСЃРє, РњРёСЂР°, 85, 64
РћРјСЃРє, РџСѓС€РєРёРЅР°, 2, 13
*/

void Task_2() {

	AdressData adressd_data;
	adressd_data.CreateVector_1();
	adressd_data.CreateVector_2();
	adressd_data.SortVector2();
	adressd_data.OutputConsolVector_2();
	adressd_data.OutputFileVector_2();
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