#include "dll_2.h"

namespace dll_lib {


	double Math_Game_2::math_game(const double& way_x, const int& n_tc) {

		//{ 5, { 10,1000,0,5000,3,10000,10,5 } },
		//{ 6, { 8, 0,   6,0,   6,0,    6, 6 } },
		double new_way{ 0 };

		if (way_x < _vid_tc_speed_param.at(n_tc).at(1)) {

			new_way = way_x * (100 - _vid_tc_speed_param.at(n_tc).at(2))/100;
			
		} else if (way_x < _vid_tc_speed_param.at(n_tc).at(3)) {

			new_way = way_x * (100 - _vid_tc_speed_param.at(n_tc).at(4))/100;

		} else if (way_x < _vid_tc_speed_param.at(n_tc).at(5)) {

			new_way = way_x * (100 - _vid_tc_speed_param.at(n_tc).at(6))/100;

		} else if (way_x >= _vid_tc_speed_param.at(n_tc).at(5)) {

			new_way = way_x * (100 - _vid_tc_speed_param.at(n_tc).at(7))/100;

		}

		return _time_tc = new_way / _vid_tc_speed_param.at(n_tc).at(0);
	}
}