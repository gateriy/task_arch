#ifndef DLL_1_H
#define DLL_1_H

#include "dll_1.h"
//#include "dll_2.h"

#include <iostream>
#include <string>

#define DLL_1 __declspec(dllexport) //задается макрос связи

namespace dll_lib_1 {


	class DLL_1  Math_Game_0
	{
	public:

		double virtual math_game_0();

		double virtual math_game_1(double& way, double& speed);
	};


	class DLL_1  Math_Game_1 : public Math_Game_0
	{
	public:

		double  math_game_0();

		double math_game_1(double& way, double& speed) ;
	};
}
#endif // !TASK_DLL_H
