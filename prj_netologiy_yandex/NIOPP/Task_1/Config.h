#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <exception>
#include <algorithm>
#include <bitset>

 
#include "Block_1.h"
#include "Block_2.h"
#include "Block_3.h"
#include "Block_4.h"
#include "Block_5.h"

class Config {

public:
	void InteractiveVarTask(const std::string& v_text) noexcept;

private:
	std::string number_task{ };
	bool exit = true;
	std::string text{};
	enum class Task;
	void VarTaskNumber() noexcept;
	bool ExitProgram() noexcept;
	void ConsolLang1251() noexcept;
};

#endif