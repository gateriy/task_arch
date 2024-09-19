#include "dll_3.h"

namespace dll_lib {


	double  Math_Game_3::math_game(const double& way_x, const int& n_tc)  {

		//{ 7, {20,1000,1} }

		double new_way{ 0 };

		new_way = way_x * (100 - static_cast<int>(way_x / _vid_tc_speed_param.at(n_tc).at(1)) )/100;
	
		return 	_time_tc = new_way / _vid_tc_speed_param.at(n_tc).at(0);
	}
}