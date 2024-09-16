#ifndef DLL_3_H
#define DLL_3_H

#include "dll_3.h"

#include <iostream>
#include <string>

#define DLL_3 __declspec(dllexport) //задается макрос связи

namespace dll_lib_3 {

	class DLL_3 Leaver
	{
	public:



		void leave();
	};
}
#endif // !TASK_DLL_H
