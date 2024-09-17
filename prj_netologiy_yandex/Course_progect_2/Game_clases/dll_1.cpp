#include "dll_1.h"

namespace dll_lib_1 {

	void Leaver::leave() {


		std::cout << std::endl;
		std::cout << "DLL_1";
		std::cout << std::endl;

	}

	void Leaver::get_var_game() {
		//system("cls");
		system("COLOR 5");
		/*
		 0 = Черный 8 = Серый
		 1 = Синий 9 = Светло-синий
		 2 = Зеленый A = Светло-зеленый
		 3 = Голубой B = Светло-голубой
		 4 = Красный C = Светло-красный
		 5 = Лиловый D = Светло-лиловый
		 6 = Желтый E = Светло-желтый
		 7 = Белый F = Ярко-белый
		 */

		dll_lib_2::Math_Game_0 game_0;

		_vid_tc_time.clear();

		if (!_var_list_vid_tc.empty()) {
			for (auto& i : _var_list_vid_tc) {

				switch (i)
				{
				case(1):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i)});
					break;
				case(2):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i) });
					break;
				case(3):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i) });
					break;
				case(4):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i) });
					break;
				case(5):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i) });
					break;
				case(6):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i) });
					break;
				case(7):
					_vid_tc_time.insert({ game_0.math_game_0(_way, _vid_tc_speed.at(i)),_vid_tc.at(i) });
					break;
				default:
					break;
				}
			}

			std::vector<std::pair<double, std::string> > v(_vid_tc_time.begin(), _vid_tc_time.end());
			reverse(v.begin(), v.end());
			for (auto& i : v) {
				std::cout << "Время: " << i.first << "\t(час) << " << i.second << std::endl;
			}
		}

	}

	void Leaver::get_var_type() {

		system("cls");
		system("COLOR 5");
		/*
		 0 = Черный 8 = Серый
		 1 = Синий 9 = Светло-синий
		 2 = Зеленый A = Светло-зеленый
		 3 = Голубой B = Светло-голубой
		 4 = Красный C = Светло-красный
		 5 = Лиловый D = Светло-лиловый
		 6 = Желтый E = Светло-желтый
		 7 = Белый F = Ярко-белый
		 */

		dll_lib_2::Math_Game_0 game_0;

		if (_var_vid_game != 0) {
			std::cout << "Вид гонки:" << std::endl;
			std::cout << _var_vid_game << "\t<<  " << _vid_game.at(_var_vid_game) << std::endl;
		}
		if (!_var_list_vid_tc.empty()) {
			std::cout << "Выбранные ТС:" << std::endl;
			for (auto& i : _var_list_vid_tc) {

				if (i >= 1 && i <= 4 && _var_vid_game == 1) {
					std::cout << i << "\t<<  " << _vid_tc.at(i) << std::endl;
				}
				if (i >= 5 && i <= 7 && _var_vid_game == 2) {
					std::cout << i << "\t<<  " << _vid_tc.at(i) << std::endl;
				}
				if (_var_vid_game == 3 || _var_vid_game == 0) {
					std::cout << i << "\t<<  " << _vid_tc.at(i) << std::endl;
				}
			}
		}
		if (_way != 0) {
			std::cout << "Длина пути гонки:" << std::endl;
			std::cout << "\t<<  " << _way << std::endl;
		}
		for (int i = 0; i < 100; ++i) {
		std::cout << "-";
		Sleep(10);
		}
		std::cout << std::endl;
	}

	int Leaver::input_char_to_int(std::vector<int> aray_var) {

		std::vector <char> text{ '0','1','2','3','4','5','6','7','8','9' };
		std::string text_var{ "" };
		bool norm{ false };
		int var_menu{ 0 };

		do {
			std::cin >> text_var;
						
			for (char& i : text_var) {
				norm = false;
				for (char& x : text) {

					if (i == x) {
						norm = true;
						break;
					}
				}
				if (norm == false) { break; }
			}

			if (norm == true) {
				var_menu= std::stoi(text_var);
				norm = false;

				for (auto& i : aray_var) {

					if (i == var_menu) {
						return var_menu;
					}
				}			 
			}
			if (norm == false) {
				std::cout << "Не корректный символ или номер! Повторите ввод: ";
			}
		}while(norm==false);
	}

	double Leaver::input_char_to_double() {

		std::vector <char> text{ '0','1','2','3','4','5','6','7','8','9','.'};
		std::string text_var{ "" };
		bool norm{ false };
		int fast_point{ 0 };
		
		do {
			std::cin >> text_var;
			fast_point=0;

			for (char& i : text_var) {
				norm = false;

					if (i == '.') {
						++fast_point;						
					}

				for (char& x : text) {

					if (i == x && (fast_point==1 || fast_point == 0)) {
						norm = true;
						break;
					}
				}
				if (norm == false) { break; }
			}

			if (norm == true) {
				return std::stod(text_var);
				norm = false;
			}
			if (norm == false) {
				std::cout << "Не корректный символ! Повторите ввод: ";
			}
		} while (norm == false);
	}

	int Leaver::menu_var() {

		int x{ 0 }, y{ 0 };
		bool next_x{ false };
				
		do {
			system("cls");
			system("COLOR 6");
/*
 0 = Черный 8 = Серый
 1 = Синий 9 = Светло-синий
 2 = Зеленый A = Светло-зеленый
 3 = Голубой B = Светло-голубой
 4 = Красный C = Светло-красный
 5 = Лиловый D = Светло-лиловый
 6 = Желтый E = Светло-желтый
 7 = Белый F = Ярко-белый
 */

			if (_var_vid_game != 0) {
				std::cout << "Вид гонки:" << std::endl;
				std::cout <<"\t<<  " << _vid_game.at(_var_vid_game) << std::endl;
			}
			if (!_var_list_vid_tc.empty()) {
				std::cout << "Выбранные ТС:" << std::endl;
				for (auto& i : _var_list_vid_tc) {

					if (i >= 1 && i <= 4 && _var_vid_game == 1) {
						std::cout << "\t<<  " << _vid_tc.at(i) << std::endl;
					}
					if (i >= 5 && i <= 7 && _var_vid_game == 2) {
						std::cout << "\t<<  " << _vid_tc.at(i) << std::endl;
					}
					if (_var_vid_game == 3 || _var_vid_game == 0) {
						std::cout << "\t<<  " << _vid_tc.at(i) << std::endl;
					}
				}
			}	
			if (_way != 0) {
				std::cout << "Длина пути гонки:" << std::endl;
				std::cout << "\t<<  " << _way << std::endl;
			}
			std::cout << "_______________________________________________________________________________________" << std::endl;
			std::cout << "Основное меню (0 выход, 1 выбор ТС, 2 вид гонок, 3 ввести длину пути, 4 начать гонку): ";
			x = input_char_to_int({ 0,1,2,3,4 });

			switch (x)
			{
			case(0):
				system("COLOR 8");
				system("cls");
				return  x;
			case(4):
				system("COLOR 4");
				system("cls");
				return  x;
			case(2):
				system("COLOR 3");
				system("cls");
				std::cout << "Введите вид гонок (1 только для наземных ТС, 2 только для воздушных ТС, 3 для наземных и воздушных ТС): ";
				_var_vid_game = input_char_to_int({ 1,2,3 });
				break;
			case(3):
				system("COLOR 7");
				system("cls");
				std::cout << "Введите длину пути: ";
				_way = input_char_to_double();
				break;
			case(1):
				system("COLOR 2");
				system("cls");

				std::cout << "Введите тип ТС (0 сбросить выбор ТС, 1 наземные, 2 воздушные): ";
				_var_type_tc = input_char_to_int({ 0,1,2 });

				if (_var_type_tc == 0) {
					std::cout << "Введите тип ТС (1 наземные, 2 воздушные): ";
					_var_type_tc = input_char_to_int({ 1,2 });
					_var_list_vid_tc.clear();
				}

				do {
					system("cls");

					if (!_var_list_vid_tc.empty()) {
						std::cout << "Выбранные ТС:" << std::endl;
						for (auto& i : _var_list_vid_tc) {
							std::cout << "\t<<  " << _vid_tc.at(i) << std::endl;
						}
					}

					if (_var_type_tc == 1) {
						std::cout << "Введите вид ТС (0 выход, 1 верблюд, 2 верблюд - быстроход, 3 кентавр, 4 ботинки - вездеходы): ";
						y = input_char_to_int({ 0,1,2,3,4 });
						if (y != 0) { _var_list_vid_tc.insert(y); }
					}

					if (_var_type_tc == 2) {
						std::cout << "Введите вид ТС (0 выход, 1 ковёр-самолёт, 2 орёл, 3 метла): ";
						y = input_char_to_int({ 0,1,2,3 });
						if (y != 0) { _var_list_vid_tc.insert(y+4); }
					}
				} while (y!=0);
				break;
			default:
				break;
			}
		} while (true);		
	}







}