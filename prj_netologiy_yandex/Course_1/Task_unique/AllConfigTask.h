#pragma once
#ifndef ALLCONFIGTASK_H
#define ALLCONFIGTASK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <Windows.h>

#include"Task_1.h"
#include"Task_2.h"
#include"Task_3.h"

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