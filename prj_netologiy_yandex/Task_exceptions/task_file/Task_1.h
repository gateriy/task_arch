//#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <string>
#include"My_exception.h"

/*class My_Exeception : public std::exception {
public:
	My_Exeception(const std::string& mess) : mess(mess) {};

	const char* what() const noexcept override;

private:
	std::string mess{};
};
*/

int function(const std::string& str, const int& forbidden_length);

int StringToInt(const std::string& text_var);

void Task_1();

#endif 
