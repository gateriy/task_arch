п»ї//Р·Р°РґР°С‡Рё 8,9,10

#include <iostream>
#include <vector>
#include <string>

enum Task {
	summ=1,
	summ_numeric,
	composition_numeric
	

};

template <typename data>
void Output(const  data& A ) {
	//std::cout << std::endl;
	std::cout << "Result :" << A << std::endl;
	std::cout << std::endl;
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

		if (exit_Y_N == 'Y') {
			return false;
			break;
		}
		else if (exit_Y_N == 'N') {
			return true;
			break;
		}else  {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}			

	} while (true);		
}

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ Р·Р°РїСЂР°С€РёРІР°РµС‚ Сѓ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ С†РµР»С‹Рµ С‡РёСЃР»Р° РґРѕ С‚РµС… РїРѕСЂ, РїРѕРєР° РїРѕР»СЊР·РѕРІР°С‚РµР»СЊ РЅРµ РІРІРµРґС‘С‚ С‡РёСЃР»Рѕ 0.
//РџРѕСЃР»Рµ С‚РѕРіРѕ, РєР°Рє РїРѕР»СЊР·РѕРІР°С‚РµР»СЊ РІРІС‘Р» С‡РёСЃР»Рѕ 0, РїСЂРѕРіСЂР°РјРјР° РІС‹РІРѕРґРёС‚ СЃСѓРјРјСѓ РІРІРµРґС‘РЅРЅС‹С… РїРѕР»СЊР·РѕРІР°С‚РµР»РµРј С‡РёСЃРµР» Рё Р·Р°РІРµСЂС€Р°РµС‚ СЂР°Р±РѕС‚Сѓ.
double SummN() {

	std::vector<double> numeric{};
	int i{ 0 }, input{ 0 }, summ{ 0 };

	do
	{
		//std::cout << std::endl;
		std::cout << "Input numeric <" << ++i << "> (ignor 0): ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == 0) {
			break;
		}
		else {
			numeric.push_back(input);
		}

	} while (true);

	for (const auto& a : numeric) {
		summ = summ+a;
	}
	return summ;
}

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ Р·Р°РїСЂР°С€РёРІР°РµС‚ Сѓ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ С†РµР»РѕРµ С‡РёСЃР»Рѕ Рё РІС‹РІРѕРґРёС‚ РЅР° СЌРєСЂР°РЅ СЃСѓРјРјСѓ РІСЃРµС… РµРіРѕ С†РёС„СЂ
//СЂРµР°Р»РёР·РѕРІР°Р» С‡РµСЂРµР· РєРѕРЅРІРµСЂС‚Р°С†РёСЋ string Рё vector (РїРѕ РїСЂРµРґР»РѕР¶РµРЅРЅРѕРјСѓ РІР°СЂРёР°РЅС‚Сѓ РЅРµ РїРѕС€РµР»)
int SummNumeric() {
	std::string num{}, num_x{};
	std::vector<int>numeric{};
	int res{0};

	std::cout << "Input numeric: ";
	std::cin >> num;
	std::cout << std::endl;
	
	for  (const auto& i : num) {
		num_x = i;
		numeric.push_back(stoi(num_x));
	}
	if (!numeric.empty()) {
		for (const auto& n : numeric) {
			res = res + n;
			//std::cout << n << std::endl;

		}
	}
	else res = 0;

	return res;
}

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ Р·Р°РїСЂР°С€РёРІР°РµС‚ Сѓ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ С†РµР»РѕРµ С‡РёСЃР»Рѕ Рё РІС‹РІРѕРґРёС‚ РЅР° СЌРєСЂР°РЅ С‚Р°Р±Р»РёС†Сѓ СѓРјРЅРѕР¶РµРЅРёСЏ РґР»СЏ СЌС‚РѕРіРѕ С‡РёСЃР»Р°.
void CompositionNumeric() {
	long int num_x{0}, range{ 0 };
//	std::vector<int>numeric{ 0 };

	std::cout << "Input numeric: ";
	std::cin >> num_x;
	std::cout << std::endl;

	std::cout << "Input range: ";
	std::cin >> range;
	std::cout << std::endl;
	std::cout << num_x << std::endl;

	for (int i=1; i <= range; ++i) {		
		std::cout << num_x << "\tx\t" << i << "\t=\t" << num_x *i << std::endl;
	}

}

int main(){

	do {
			bool exit{ true };

		do {

			std::string number_programm{ };
			std::cout << "Input numder task (1, 2, 3): ";
			std::cin >> number_programm;
			std::cout << std::endl;

			if (number_programm == "1" || number_programm == "2" || number_programm == "3") {

				switch (stoi(number_programm))
				{
				case(Task::summ):
					Output(SummN());				
					exit = false;
					break;
				case(Task::summ_numeric):
					Output(SummNumeric());
					exit = false;
					break;
				case(Task::composition_numeric):
					CompositionNumeric();
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

