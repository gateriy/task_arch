#ifndef DLL_1_H
#define DLL_1_H

#include "dll_1.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>


#define DLL_1 __declspec(dllexport) //задается макрос связи

namespace dll_lib_1 {

	class DLL_1 Leaver
	{
	public:



		void leave();

		std::string get_var_type(const int& vid, const int& var);
		int input_char_to_int();
		std::pair<int, int> menu_var();


	private:

		std::map<int, std::string> _type_tc		{ {1,"наземные"}, {2,"воздушные"} };
		std::map<int, std::string> _vid_tc_erf	{ {1,"верблюд"}, {2,"верблюд - быстроход"},{3,"кентавр"},{4,"ботинки - вездеходы"} };
		std::map<int, std::string> _vid_tc_air	{ {5,"ковёр-самолёт"}, {6,"орёл"},{7, "метла"} };
		std::map<int, std::string> _vid_game	{ {1,"только для наземных ТС"}, {2,"только для воздушных ТС"},{3, "для наземных и воздушных ТС"} };
		
	};
}
#endif // !TASK_DLL_H

