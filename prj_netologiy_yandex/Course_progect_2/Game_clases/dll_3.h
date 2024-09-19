#ifndef DLL_3_H
#define DLL_3_H

#include "dll_1.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

#define DLL_3 __declspec(dllexport) //задается макрос связи

namespace dll_lib {

	//3 метла
	class DLL_3 Math_Game_3 : public Math_Game_0
	{
	public:

		double math_game(const double& way_x, const int& n_tc) override;

	};
}
#endif // !TASK_DLL_H
