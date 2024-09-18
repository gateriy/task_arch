#ifndef DLL_2_H
#define DLL_2_H

#include "dll_1.h"
//#include "dll_3.h"

#include <iostream>
#include <string>

#define DLL_2 __declspec(dllexport) //задается макрос связи

namespace dll_lib_2 {

	class DLL_2 Math_Game_2 : public dll_lib_1::Math_Game_0
	{
	public:

		double math_game_1(double& way, double& speed) override;

	};
}
#endif // !TASK_DLL_H
