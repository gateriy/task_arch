п»ї//Task 3 array

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

//РќР°РїРёС€РёС‚Рµ РїСЂРѕРіСЂР°РјРјСѓ, РєРѕС‚РѕСЂР°СЏ СЃРѕР·РґР°С‘С‚ Рё РёРЅРёС†РёР°Р»РёР·РёСЂСѓРµС‚ РґРІСѓРјРµСЂРЅС‹Р№ РјР°СЃСЃРёРІ С†РµР»С‹С… С‡РёСЃРµР» СЂР°Р·РјРµСЂРЅРѕСЃС‚СЊСЋ 3С…6, 
//РІС‹РІРѕРґРёС‚ РЅР° СЌРєСЂР°РЅ РІСЃРµ СЌР»РµРјРµРЅС‚С‹ РјР°СЃСЃРёРІР° РІ РІРёРґРµ С‚Р°Р±Р»РёС‡РєРё,
//РЅР°С…РѕРґРёС‚ РёРЅРґРµРєСЃС‹ РјРёРЅРёРјР°Р»СЊРЅРѕРіРѕ Рё РјР°РєСЃРёРјР°Р»СЊРЅРѕРіРѕ СЌР»РµРјРµРЅС‚РѕРІ РјР°СЃСЃРёРІР° Рё РІС‹РІРѕРґРёС‚ РёС… РЅР° СЌРєСЂР°РЅ.

int main() {

	do {
		std::cout << "Task 3 (arr)";
		std::cout << "\n" << std::endl;	

		//РєРѕРЅСЃС‚Р°РЅС‚С‹ СЂР°Р·РјРµСЂР° РјР°СЃСЃРёРІР°
		const int SIZE = 3; 
		const int SIZE_2 = 6; 
		int arr_1[SIZE][SIZE_2] = { {0,1,2,3,-4,5},{0,1,7,-3,4,7},{-1,1,2,7,10,8} };

		int res_max = arr_1[0][0];
		int res_min = arr_1[0][0];
		int index_x, index_y, index_x_m, index_y_m;

		for (const auto& d : arr_1) {
			bool fist_cycle = false;
			for (const auto& i : d) {
				if (fist_cycle) {
					std::cout << ",\t";
				}
				fist_cycle = true;
				std::cout << i; //output
			}
			std::cout << std::endl;
		}

		//max or min index
		for (int d = 0; d < SIZE; ++d) {			
			for (int i = 0; i < SIZE_2; ++i) {
				for (int n = 0; n < SIZE_2; ++n) {

					if (arr_1[d][i] >= arr_1[d][n] && res_max < arr_1[d][i]) {
						res_max = arr_1[d][i];
						index_x = d;
						index_y = i;
					}
					if (arr_1[d][i] <= arr_1[d][n] && res_min > arr_1[d][i]) {
						res_min = arr_1[d][n];
						index_x_m = d;
						index_y_m = n;
					}
				}
			}
		}

		std::cout << std::endl;
		std::cout << "Max array: " << res_max << "\tIndex: [" << index_x << "] [" << index_y << "]" << std::endl;
		std::cout << "Min array: " << res_min << "\tIndex: [" << index_x_m << "] [" << index_y_m << "]";
		std::cout << "\n" << std::endl;

	} while (UserWantExitProgram());
}

