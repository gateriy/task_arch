//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include "AllConfigTask.h"

class big_intger {
	
public:

	bool check(const std::string& x, const std::string& text);

	std::string summ_y(const std::string& xx, const std::string& yy);

	std::string multi(const std::string& str_a, const std::string& str_b);

private:

	std::vector<int> _transfor_vector(const std::string& var);

	std::vector<int> _summ_x(const std::vector<int>& a);

};

void Task_2();

#endif