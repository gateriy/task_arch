//#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <string>
#include <numeric>
#include <cmath>


class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	std::pair<int, int> GetVarFraction();

	std::pair<int, int> VarNod(int& x, int& y);

	bool operator == (Fraction& new_var);
	bool operator != (Fraction& new_var);
	bool operator > (Fraction& new_var);
	bool operator < (Fraction& new_var);
	bool operator >= (Fraction& new_var);
	bool operator <= (Fraction& new_var);

	//void VVV() {
	//	std::cout << (this->numerator_)<<this->denominator_<< std::endl;
	//}
};

void Task_1();

#endif 
