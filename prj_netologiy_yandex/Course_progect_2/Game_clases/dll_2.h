#ifndef DLL_2_H
#define DLL_2_H

#include "dll_1.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

#define DLL_2 __declspec(dllexport) //задается макрос связи

namespace dll_lib {

	//1 ковёр-самолёт, 2 орёл
	class DLL_2 Math_Game_2 : public Math_Game_0
	{
	public:

		double math_game(const double& way_x, const int& n_tc) override;

	};
}
#endif // !TASK_DLL_H
