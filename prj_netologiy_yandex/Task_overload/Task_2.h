//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include <iostream>
#include <string>
#include <numeric>
#include <cmath>

class Fraction2
{
private:
	int numerator_;
	int denominator_;
	std::pair<int, int> VarNod(int& x, int& y);

public:
	Fraction2(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction2& operator ++ () { 
		numerator_=numerator_ + denominator_; 
		return *this; }

	Fraction2 operator ++ (int)
	{
		Fraction2 temp = *this;
		++(*this);
		return temp;
	}

	Fraction2& operator -- () { 
		numerator_ = numerator_ - denominator_; 
		return *this; }

	Fraction2 operator -- (int)
	{
		Fraction2 temp = *this;
		--(*this);
		return temp;
	}

	Fraction2 operator + (Fraction2& var)	
	{
		int num_x{ numerator_ * var.denominator_ + var.numerator_ * denominator_ };
		int den_x{ denominator_ * var.denominator_ };
		return Fraction2(VarNod(num_x, den_x).first, VarNod(num_x, den_x).second);
	}

	Fraction2 operator - (Fraction2& var)
	{
		int num_x{ numerator_ * var.denominator_ - var.numerator_ * denominator_ };
		int den_x{ denominator_ * var.denominator_ };
		return Fraction2(VarNod(num_x, den_x).first, VarNod(num_x, den_x).second);
	}

	Fraction2 operator / (Fraction2& var)
	{
		int num_x{ numerator_ * var.denominator_ };
		int den_x{ denominator_ * var.numerator_ };
		return Fraction2(VarNod(num_x, den_x).first, VarNod(num_x, den_x).second);
	}

	Fraction2 operator * (Fraction2& var)
	{
		int num_x{ numerator_ * var.numerator_ };
		int den_x{ denominator_ * var.denominator_ };
		return Fraction2(VarNod(num_x, den_x).first, VarNod(num_x, den_x).second);
	}

	std::pair<int, int> GetVarFraction();	

};

int InputVar(const std::string& text);

void Output_2(const std::string& A_1, const  int& B_1, const std::string& A_2, const  int& B_2);

void Task_2();

#endif