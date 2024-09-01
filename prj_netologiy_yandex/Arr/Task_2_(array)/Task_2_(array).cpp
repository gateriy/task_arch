п»ї//Task 2 array

#include <iostream>
#include <tuple>

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

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ СЃРѕР·РґР°С‘С‚ РјР°СЃСЃРёРІ С†РµР»С‹С… С‡РёСЃРµР» РЅР° 10 СЌР»РµРјРµРЅС‚РѕРІ, 
//РІС‹РІРѕРґРёС‚ РЅР° СЌРєСЂР°РЅ РІСЃРµ СЌР»РµРјРµРЅС‚С‹ РјР°СЃСЃРёРІР°, РЅР°С…РѕРґРёС‚ РјРёРЅРёРјР°Р»СЊРЅС‹Р№ Рё РјР°РєСЃРёРјР°Р»СЊРЅС‹Р№ СЌР»РµРјРµРЅС‚С‹ РјР°СЃСЃРёРІР° Рё РІС‹РІРѕРґРёС‚ РёС… РЅР° СЌРєСЂР°РЅ.

//input array random 
std::pair <int, int*> InArrRand() {

	const int size{ 10 }; //const array
	static int Arr_1[size]; //СЃС‚Р°С‚РёС‡РµСЃРєР°СЏ РїРµСЂРµРјРµРЅРЅР°СЏ С…СЂР°РЅРµРЅРёСЏ РјР°СЃСЃРёРІР°

	for (int i = 0; i < size; ++i) {
		Arr_1[i] = rand() % 100;
	}
	return { size,Arr_1 };
}

//СЂР°Р·РјРµСЂ, СЂР°РЅРґРѕРјРЅС‹Р№ СЃРіРµРЅРµСЂРёСЂРѕРІР°РЅРЅС‹Р№ РјР°СЃСЃРёРІ (СѓРєР°Р·Р°С‚РµР»СЊ),MAX, MIN -  С„СѓРЅРєС†РёСЏ С‡РµСЂРµ РєРѕСЂС‚РµР¶
std::tuple <int, int*, int, int> MaxMinArr() {

	std::pair <int, int*> arr_x = InArrRand(); //С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РјР°СЃСЃРёРІР° РЅР° РѕСЃРЅРѕРІРµ СЂР°РЅРґРѕРјРЅРѕР№ С„СѓРЅРєС†РёРё

	int* arr = arr_x.second;
	int size_y = arr_x.first;
	int res_max = arr_x.second[0];
	int res_min = arr_x.second[0];

	for (int i = 0; i < size_y; ++i) {
		for (int n = 0; n < size_y; ++n) {
				
				if (arr[i] >= arr[n] && res_max < arr[i]) {
					res_max = arr[i];
				}			
				if (arr[i] <= arr[n] && res_min > arr[i]) {
					res_min = arr[n];
				}
		}
	}
	return  std::make_tuple(size_y, arr, res_max, res_min );
}

int main() {

	do {

		int* arr_1;
		int size{ 0 }, max{ 0 }, min{ 0 };

		std::tie (size,arr_1,max,min) = MaxMinArr();

		std::cout << "Task 2 (arr)";
		std::cout << "\n" << std::endl;		

		bool fist_cycle = false;
		for (int i = 0; i < size; ++i) {
			if (fist_cycle) {
				std::cout << ", ";
			}
			fist_cycle = true;
			std::cout << arr_1[i];
		}	

		std::cout << "\n" << std::endl;
		std::cout << "Max array: " << max << std::endl;
		std::cout << "Min array: " << min;
		std::cout << "\n" << std::endl;

	} while (UserWantExitProgram());
}

