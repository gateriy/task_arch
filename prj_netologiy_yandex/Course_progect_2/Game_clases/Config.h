#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <Windows.h>
#include <algorithm>

#include "dll_2.h"

	class  Config_class
	{
	public:
		
		void  get_var_type();
		bool  get_var_game();
		int	  menu_var();
		int   input_char_to_int(std::vector<int> aray_var);

	protected:

		std::map<int, std::string>    _type_tc		    { {1,"наземные"}, {2,"воздушные"} };
		std::map<int, std::string>    _vid_tc	        { {1,"верблюд"}, {2,"верблюд - быстроход"},{3,"кентавр"},{4,"ботинки - вездеходы"}, {5,"ковёр-самолёт"},{6,"орёл"},{7, "метла"} };		
		std::map<int, double>	      _vid_tc_speed		{ {1,10},{2,40},{3,15},{4,6},{5,10},{6,8},{7, 15} };
		std::vector<std::pair<double, std::string>> _vid_tc_time		{ {} };
		std::map<int, std::string>    _vid_game			{ {1,"только для наземных ТС"}, {2,"только для воздушных ТС"},{3, "для наземных и воздушных ТС"} };		
		std::set<int>			      _var_list_vid_tc	{};

		int		_var_vid_tc		{ 0 };
		int		_var_type_tc	{ 0 };
		int		_var_vid_game	{ 0 };
		double	_way			{ 0.0 };


		double input_char_to_double();
	};
#endif;

