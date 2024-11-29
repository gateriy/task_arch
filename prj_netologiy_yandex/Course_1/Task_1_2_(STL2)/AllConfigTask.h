#pragma once
#ifndef ALLCONFIGTASK_H
#define ALLCONFIGTASK_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <set>
#include <vector>
#include <algorithm>
#include <list>


#include"Task_1.h"
#include"Task_2.h"
#include"Task_3.h"

template <typename T, typename F>
void print_container(const T& var_x, const F& text);

template <typename text, typename data> void Output(const text& A, const  data& B);

template <typename text, typename data> data InputVar(const text& A, const  data& B);


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