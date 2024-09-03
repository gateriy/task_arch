#pragma once
#ifndef ALLCONFIGTASK_H
#define ALLCONFIGTASK_H

#include <iostream>
#include <string>
#include <Windows.h>

#include"Task_1.h"
#include"Task_2.h"
#include"Task_3.h"


template < typename data> void Output(const std::string& A, const  data& B);

template < typename data> void Output_2
(const std::string& A_1, const  data& B_1, const std::string& A_2, const  data& B_2);

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