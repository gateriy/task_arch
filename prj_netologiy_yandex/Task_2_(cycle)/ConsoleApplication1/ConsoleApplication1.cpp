п»ї//Р·Р°РґР°С‡Р° 2 С‚РµРјР° С†РёРєР»С‹.

#include <iostream>

//РїРѕРЅРёРјР№Р°СЋ С‡С‚Рѕ РґР»СЏ С‚Р°РєРѕР№ Р·Р°РґР°С‡Рё РёР·Р±С‹С‚РѕС‡РЅРѕ template, РЅРѕ СЃС‚Р°СЂР°СЋСЃСЊ СѓР¶Рµ РІС‹СЂР°Р±Р°С‚С‹С‹РІР°С‚СЊ РїСЂРёРІС‹С‡РєСѓ РІРµР·РґРµ РіРґРµ РјРѕР¶РЅРѕ РІС‹С…РѕРґРёС‚СЊ РЅР° С€Р°Р±Р»РѕРЅС‹....
template <typename data>
void Output(const  data& A) {
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
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}

	} while (true);
}

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ Р·Р°РїСЂР°С€РёРІР°РµС‚ Сѓ РїРѕР»СЊР·РѕРІР°С‚РµР»СЏ С†РµР»РѕРµ С‡РёСЃР»Рѕ Рё РІС‹РІРѕРґРёС‚ РЅР° СЌРєСЂР°РЅ СЃСѓРјРјСѓ РІСЃРµС… РµРіРѕ С†РёС„СЂ
//СЂРµР°Р»РёР·РѕРІР°Р» РєР°Рє СЂРµРєРѕРјРµРЅРґРѕРІР°РЅРЅРѕ РІ СѓР»РѕРІРёРё Рє Р·Р°РґР°С‡Рµ 

int SummNumeric() {
	
	int res{ 0 }, num{0}, num_x{0};

	std::cout << "Input numeric: ";
	std::cin >> num;
	std::cout << std::endl;

	while (true) {
		
		num_x = num % 10;
		num = num / 10;
	
	if (num_x == 0) { break; }	

	res = res + num_x;
	}
	return res;
}

int main() {

	do {

		Output(SummNumeric());

	} while (ExitProgram());
}

