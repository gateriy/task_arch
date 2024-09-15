#ifndef TASK_DLL_H
#define TASK_DLL_H

#include <iostream>
#include <string>
#include "Task_dll.h"

#define DLL_EXP						//задание константы макроса для выбора экспорт/импорт
#ifdef  DLL_EXP						//указание экспорта
#define DLL_1 __declspec(dllexport) //задается макрос связи
#else
#define DLL_1 __declspec(dllimport) //указание импорта
#endif								// DLL2

/*
Создайте класс Leaver, который определяет один метод leave, 
принимающий на вход строку и возвращающий строку с прощанием со 
значением той строки, которую ему передали.
Поместите этот класс в динамическую библиотеку и воспользуйтесь им 
из консольного приложения для прощания с пользователем, который введёт своё имя.

Пример работы программы

Введите имя: Анатолий
До свидания, Анатолий!
*/

namespace dll_lib {

	class DLL_1 Leaver
	{
	public:

		void leave();
	};
}
#endif // !TASK_DLL_H

