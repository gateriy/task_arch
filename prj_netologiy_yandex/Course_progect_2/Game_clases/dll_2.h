#ifndef DLL_2_H
#define DLL_2_H

#include "dll_2.h"


#include <iostream>
#include <string>

#define DLL_2 __declspec(dllexport) //задается макрос связи

namespace dll_lib_2 {

	class DLL_2  Math_Game_0 
	{
	public:

		double math_game_0(double& way, double& speed);
	};
}
#endif // !TASK_DLL_H