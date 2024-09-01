п»ї//Task 1 array

#include <iostream>

//С„СѓРЅРєС†РёСЏ РІС‹С…РѕРґР° РёР· РїСЂРѕРіСЂР°РјРјС‹
bool UserWantExitProgram()
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

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ СЃРѕР·РґР°С‘С‚ РјР°СЃСЃРёРІ С†РµР»С‹С… С‡РёСЃРµР» РЅР° 10 СЌР»РµРјРµРЅС‚РѕРІ
//Рё РІС‹РІРѕРґРёС‚ РЅР° СЌРєСЂР°РЅ РІСЃРµ СЌР»РµРјРµРЅС‚С‹ РјР°СЃСЃРёРІР° С‡РµСЂРµР· Р·Р°РїСЏС‚СѓСЋ Рё РїСЂРѕР±РµР»(, ).

//input array random
std::pair <int, int*> InArrRand() {

	const int size{ 10 }; //const array
	static int Arr_1[size]; //СЃС‚Р°С‚РёС‡РµСЃРєР°СЏ РїРµСЂРµРјРµРЅРЅР°СЏ С…СЂР°РЅРµРЅРёСЏ РјР°СЃСЃРёРІР°

	for (int i = 0; i < size; ++i) {
		Arr_1[i] = rand()%100;
	}
	return { size,Arr_1 };
}

int main() {

	do {
		std::cout << "Task 1 (arr)";
		std::cout << "\n"<<std::endl;

		bool fist_cycle = false;
		int* p = InArrRand().second;
		//int size = sizeof(p) / sizeof(p[0]);

		for (int n=0;n< InArrRand().first;++n){

			if (fist_cycle) {
				std::cout << ", ";
			}
			fist_cycle = true;
			std::cout << p[n];
		}
		std::cout << "\n" << std::endl;
					
	} while (UserWantExitProgram());
}

