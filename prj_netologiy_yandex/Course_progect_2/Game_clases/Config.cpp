#include "Config.h"

#define TIME 1

	std::string Config_class::doubleToString(double number, int precision) {
	std::ostringstream stream;
	stream.precision(precision);
	stream << std::fixed << number;
	return stream.str();
}

	void Config_class::time_cout_char(const std::string& t1, const std::string& t2,
					const std::string& t3, const std::string& t4,
					const std::string& t5, bool end_l ,int time, int color) {

	/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
	*/

	std::string text { t1 + t2 + t3 + t4 + t5 };

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (char a : text) {
		std::cout << a;
		Sleep(time);
	}
	if (end_l == true) { std::cout << std::endl; }
}

	bool Config_class::get_var_game( int color) {

		int count_erf{ 0 }, count_air{ 0 };
		bool norm{ false };

		if (!_var_list_vid_tc.empty() && _way>0 && _var_vid_game !=0) {

			if (_var_vid_game == 3 && _var_list_vid_tc.size() < 2) {
				return false;
			}									
			for (auto& i : _var_list_vid_tc) {
				if (i >= 1 && i <= 4) {
					++count_erf;
				}
				if (i >= 5 && i <= 7) {
					++count_air;
				}
			}
			if (_var_vid_game == 1 && count_erf < 2) {
				return false;
			}
			if (_var_vid_game == 2 && count_air < 2) {
				return false;
			}	
	
			_vid_tc_time.clear();

			dll_lib::Math_Game_1 game_1;
			dll_lib::Math_Game_2 game_2;
			dll_lib::Math_Game_3 game_3;

			for (int i : _var_list_vid_tc) {

				if ((_var_vid_game == 1 || _var_vid_game == 3) && i>=1 && i <=4 ) {
					
					_vid_tc_time.push_back({ game_1.math_game(_way, i),_vid_tc.at(i)});
				}
				if ((_var_vid_game == 2 || _var_vid_game == 3) && i>=5 && i<=6) {
				
					_vid_tc_time.push_back({ game_2.math_game(_way, i),_vid_tc.at(i) });
				}
				if ((_var_vid_game == 2 || _var_vid_game == 3) && i ==7 ) {

					_vid_tc_time.push_back({ game_3.math_game(_way, i),_vid_tc.at(i) });					
				}
			}

			time_cout_char("---------------------------------------------------------------", "", "", "", "", true, TIME, color);
									
			std::sort(_vid_tc_time.begin(), _vid_tc_time.end(),
			[](std::pair<double, std::string>& a, std::pair<double, std::string>& b) {
			return a.first > b.first;});
		
			for (auto& i : _vid_tc_time) {
				time_cout_char("Время: ", doubleToString(i.first,2), "\t(час) << ", i.second, "", true, TIME, color);
			}

			_vid_tc_time.clear();
		   return true;

		} else { return false; }
	}

	void Config_class::get_var_type(int color) {

		system("cls");
		time_cout_char("ИГРА ГОНКА ПРИВЕТСТВУЕТ ВАС!!!!!", "", "", "", "", true, 1, 4);

		if (_var_vid_game != 0) {
			time_cout_char("Вид гонки:","","","","", true, TIME, color);
			time_cout_char("\t<<  ", _vid_game.at(_var_vid_game), "", "", "", true, TIME, color);
		}
		if (!_var_list_vid_tc.empty()) {
			time_cout_char("Выбранные ТС:", "", "", "", "", true, TIME, color);
			for (auto& i : _var_list_vid_tc) {

				if (i >= 1 && i <= 4 && _var_vid_game == 1) {					
					time_cout_char("\t<<  ", _vid_tc.at(i), "", "", "", true, TIME, color);
				}
				if (i >= 5 && i <= 7 && _var_vid_game == 2) {
					time_cout_char("\t<<  ", _vid_tc.at(i), "", "", "", true, TIME, color);
				}
				if (_var_vid_game == 3 || _var_vid_game == 0) {
					time_cout_char("\t<<  ", _vid_tc.at(i), "", "", "", true, TIME, color);
				}
			}
		}
		if (_way != 0) {
			time_cout_char("Длина пути гонки:", "", "", "", "", true, TIME, color);
			time_cout_char("\t<<  ", doubleToString(_way, 2), "", "", "", true, TIME, color);			
		}
	}

	int Config_class::input_char_to_int(const std::vector<int>& aray_var) {

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
				time_cout_char("Не корректный символ! Повторите ввод: ", "", "", "", "", false, 0, 4);
			}
		}while(norm==false);
	}

	double Config_class::input_char_to_double() {

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
				time_cout_char("Не корректный символ! Повторите ввод: ", "", "", "", "", false, 0, 4);
			}
		} while (norm == false);
	}

	int Config_class::menu_var(int color, int time) {

		int x{ 0 }, y{ 0 };
		bool next_x{ false };
				
		do {
						
			get_var_type(color);

			time_cout_char("_____________________________________________________________________________________", "", "", "", "", true, 0, 6);
			time_cout_char("Основное меню (0 выход, 1 выбор ТС, 2 вид гонок, 3 ввести длину пути, 4 начать гонку): ", "", "", "", "", false, time, 6);
			x = input_char_to_int({ 0,1,2,3,4 });

			switch (x)
			{
			case(0):
				system("COLOR 8");
				system("cls");
				return  x;
			case(4):				
				system("cls");
				return  x;
			case(2):
				system("cls");
				time_cout_char("Введите вид гонок (1 только для наземных ТС, 2 только для воздушных ТС, 3 для наземных и воздушных ТС): ", "", "", "", "", false, time, 3);
				_var_vid_game = input_char_to_int({ 1,2,3 });
				break;
			case(3):
				system("cls");
				time_cout_char("Введите длину пути: ", "", "", "", "", false, time, 1);
				_way = input_char_to_double();
				break;
			case(1):
				system("cls");
				time_cout_char("Введите тип ТС (0 сбросить выбор ТС, 1 наземные, 2 воздушные): ", "", "", "", "", false, time, 2);
				_var_type_tc = input_char_to_int({ 0,1,2 });

				if (_var_type_tc == 0) {
					time_cout_char("Введите тип ТС (1 наземные, 2 воздушные): ", "", "", "", "", false, time, 2);
					_var_type_tc = input_char_to_int({ 1,2 });
					_var_list_vid_tc.clear();
				}

				do {
					system("cls");
					if (!_var_list_vid_tc.empty()) {
						time_cout_char("Выбранные ТС:", "", "", "", "", true, time, 2);
						for (auto& i : _var_list_vid_tc) {
						time_cout_char("\t<<  ", _vid_tc.at(i), "", "", "", true, time, 2);
						}
					}

					if (_var_type_tc == 1) {
						time_cout_char("Введите вид ТС (0 выход, 1 верблюд, 2 верблюд - быстроход, 3 кентавр, 4 ботинки - вездеходы): ", "", "", "", "", false, time, 2);
						y = input_char_to_int({ 0,1,2,3,4 });
						if (y != 0) { _var_list_vid_tc.insert(y); }
					}

					if (_var_type_tc == 2) {
						time_cout_char("Введите вид ТС (0 выход, 1 ковёр-самолёт, 2 орёл, 3 метла): ", "", "", "", "", false, time, 2);
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

/*

 0 = Черный		8 = Серый
 1 = Синий		9 = Светло-синий
 2 = Зеленый	A = Светло-зеленый
 3 = Голубой	B = Светло-голубой
 4 = Красный	C = Светло-красный
 5 = Лиловый	D = Светло-лиловый
 6 = Желтый		E = Светло-желтый
 7 = Белый		F = Ярко-белый

 */