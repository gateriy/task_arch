#pragma once
#ifndef TASK_STATIC_H
#define TASK_STATIC_H

#include <iostream>
#include "Task_static.h"
#include <string>

/*
Создайте класс Greeter, который определяет один метод greet, 
принимающий на вход строку и возвращающий строку с приветствием 
значения той строки, которую ему передали.
Поместите этот класс в статическую библиотеку и воспользуйтесь им 
из консольного приложения для приветствия пользователя, который введёт своё имя.

Пример работы программы

Введите имя: Владислав
Здравствуйте, Владислав!
*/

namespace static_lib 
{
	class  Greeter
	{
	public:

		void greet();
	};
}
#endif // !TASK_STATIC_H

