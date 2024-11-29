#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <fstream>
 
#include "Read_file.h"

class Config {

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

#endif