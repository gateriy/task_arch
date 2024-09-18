#include "dll_3.h"

namespace dll_lib_3 {


	double Math_Game_3::math_game_1(double& way, double& speed)  {

		double res{ 0 };

		res = way / speed * 3;

		return res;
	}
}