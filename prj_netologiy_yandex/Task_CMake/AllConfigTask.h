#pragma once
#ifndef ALLCONFIGTASK_H
#define ALLCONFIGTASK_H

#include <iostream>
#include <string>
#include <Windows.h>

#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"


template <typename text, typename data> data InputVar(const text& A, const  data& B) {
	//идентификатор типа переменной
	data var = B;
	std::cout << A;
	std::cin >> var;
	//std::cout << std::endl;
	return var;
}

template <typename text, typename data> void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
};


class AllConfigTask {

public:
	void InteractiveVarTask(const std::string& v_text);

private:
	std::string number_task{ };
	bool exit = true;
	std::string text{};
	enum class Task;
	void VarTaskNumber();
	bool ExitProgram();
	void ConsolLang1251();
};

#endif // !ALLCONFIGTASK