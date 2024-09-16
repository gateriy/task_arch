#ifndef DLL_2_H
#define DLL_2_H

#include "dll_2.h"

#include <iostream>
#include <string>

#define DLL_2 __declspec(dllexport) //задается макрос связи

namespace dll_lib_2 {

	class DLL_2 Leaver
	{
	public:



		void leave();
	};
}
#endif // !TASK_DLL_H