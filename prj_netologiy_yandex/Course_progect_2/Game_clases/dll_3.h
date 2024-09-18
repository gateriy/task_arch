#ifndef DLL_3_H
#define DLL_3_H

#include "dll_1.h"
//#include "dll_3.h"

#include <iostream>
#include <string>

#define DLL_3 __declspec(dllexport) //задается макрос связи

namespace dll_lib_3 {

	class DLL_3 Math_Game_3 : public dll_lib_1::Math_Game_0
	{
	public:

		double math_game_1(double& way, double& speed) override;

	};
}
#endif // !TASK_DLL_H
