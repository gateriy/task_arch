#include "dll_2.h"

namespace dll_lib_2 {


	double Math_Game_2::math_game_1(double& way, double& speed) {

		double res{ 0 };

		res = way / speed * 2;

		return res;
	}
}