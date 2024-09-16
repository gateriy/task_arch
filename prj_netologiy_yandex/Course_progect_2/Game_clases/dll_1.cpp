#include "dll_1.h"

namespace dll_lib_1 {

	void Leaver::leave() {


		std::cout << std::endl;
		std::cout << "DLL_1";
		std::cout << std::endl;

	}

	std::string Leaver::get_var_type(const int& vid, const int& var) {

		do {
			switch (vid)
			{
			case (1):
				return _type_tc.at(var);
			case (2):
				return _vid_tc_erf.at(var);
			case (3):
				return _vid_tc_air.at(var);
			case (4):
				return _vid_game.at(var);
			case (0):
				return "До свидания!!!";

			default:
				std::cout << "Не корректные данные! Повторите ввод" << std::endl;
				break;
			}
		} while (true);
	}

	int Leaver::input_char_to_int() {
		std::vector <char> text{ '0','1','2','3','4','5','6','7','8','9' };
		std::string text_var{ "" };
		bool norm{ false };

		do {

		std::cin >> text_var;

		norm = false;
		for (char& i : text_var) {
			for (char& x : text) {
				if (i==x){
					norm = true;
					break;
				}
				else { 
					norm = false; 
				}
			}
			if (norm == false) { break; }
		}
		if (norm == true) {
			return std::stoi(text_var);
		}
		if (norm == false) {
			std::cout << "Не числовой символ! Повторите ввод" << std::endl;
		}
		}while(norm==false);
	}

	std::pair<int, int> Leaver::menu_var() {
		int x{ 0 }, y{ 0 };
		bool next_x{ false };

		do {
			std::cout << "Введите выбор меню (0 выход, 1 тип ТС, 2 вид наземного ТС, 3 вид воздущного ТС, 4 вид гонок): ";
			x = input_char_to_int();

			if (x == 0 || x == 1 || x == 2 || x == 3 || x == 4) {
				break;
			}
			else {				
				std::cout << "Не корректные данные! Повторите ввод" << std::endl;
			}
		} while (true);

		do{
			switch (x)
			{
			case(0):
				return { x,0 };
				
			case(1):
				std::cout << "Введите тип ТС (1 наземные, 2 воздушные): ";
				y = input_char_to_int();
				if (y == 1 || y == 2) {					
					return { x,y };
				} else { break; }
			case(2):
				std::cout << "Введите вид ТС (1 верблюд, 2 верблюд - быстроход, 3 кентавр, 4 ботинки - вездеходы): ";
				y = input_char_to_int();
				if (y == 1 || y == 2 || y == 3 || y == 4) {					
					return { x,y };
				}
				else {break;}
			case(3):
				std::cout << "Введите вид ТС (5 ковёр-самолёт, 6 орёл, 7 метла): ";
				y = input_char_to_int();
				if (y == 5 || y == 6 || y == 7) {
					return { x,y };
				}
				else { break; }
			case(4):
				std::cout << "Введите вид гонок (1 только для наземных ТС, 2 только для воздушных ТС, 3 для наземных и воздушных ТС): ";
				y = input_char_to_int();
				if (y == 1 || y == 2 || y == 3) {
					return { x,y };
				}
				else { break; }
			default:
				break;
			}

			std::cout << "Не корректные данные! Повторите ввод" << std::endl;
						
		} while (true);		
	}


}