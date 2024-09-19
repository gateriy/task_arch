#ifndef DLL_1_H
#define DLL_1_H

#include "dll_1.h"
//#include "dll_2.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

#define DLL_1 __declspec(dllexport) //задается макрос связи

namespace dll_lib {

	//общий
	class DLL_1  Math_Game_0
	{
	public:

		virtual double math_game(const double& way_x, const int& n_tc );
		
	protected:

		double _time_tc{ 0 };	

		 std::map<int, std::vector<double>> _vid_tc_speed_param
		 {  {1, {10,30,5 ,8  ,8}				},
			{2, {40,10,5 ,6.5,8}				},
			{3, {15,8 ,2 ,2  ,2}				},
			{4, {6, 60,10,5  ,5}				},
			{5, {10,1000,0,5000,3,10000,10,5}	},
			{6, {8, 0,   6,0,   6,0,    6, 6}	},
			{7, {20,1000,1}						}  };
	};

	//1 верблюд, 2 верблюд - быстроход, 3 кентавр, 4 ботинки - вездеходы
	class DLL_1  Math_Game_1 : public Math_Game_0
	{
	public:

		double math_game(const double& way_x, const int& n_tc) override;
	
	};
}
#endif // !TASK_DLL_H
