#include "dll_1.h"

namespace dll_lib {

	double Math_Game_0::math_game(const double& way_x, const int& n_tc) { return 0; };

	double Math_Game_1::math_game(const double& way_x, const int& n_tc) {
		 
		// { 2,   {40,10,5 ,6.5,8} }
		// { n_tc {0  1  2  3   4} }

		_time_tc = way_x / _vid_tc_speed_param.at(n_tc).at(0);

		int count_sleep{ static_cast<int>(_time_tc / _vid_tc_speed_param.at(n_tc).at(1)) };
				 
		switch (count_sleep)
		{
		case(0):
			return _time_tc;
		case(1):
			return _time_tc + _vid_tc_speed_param.at(n_tc).at(2);
		case(2):
			return _time_tc + _vid_tc_speed_param.at(n_tc).at(2) + _vid_tc_speed_param.at(n_tc).at(3);
		default:
			return _time_tc + _vid_tc_speed_param.at(n_tc).at(2) + _vid_tc_speed_param.at(n_tc).at(3) +
				(count_sleep - 2) * _vid_tc_speed_param.at(n_tc).at(4);
		}
	}
}