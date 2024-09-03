//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include <iostream>
#include <string>


class Fraction2
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction2(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction2& operator ++ () { numerator_=numerator_ + denominator_; return *this; }
	Fraction2 operator ++ (int)
	{
		Fraction2 temp = *this;
		++(*this);
		return temp;
	}
	Fraction2& operator -- () { numerator_ = numerator_ - denominator_; return *this; }
	Fraction2 operator -- (int)
	{
		Fraction2 temp = *this;
		--(*this);
		return temp;
	}

	Fraction2 operator + (Fraction2& var)	
	{
		return Fraction2 (numerator_ * var.denominator_ + var.numerator_ * denominator_, denominator_ * var.denominator_);
	}

	Fraction2 operator - (Fraction2& var)
	{
		return Fraction2(numerator_ * var.denominator_ - var.numerator_ * denominator_, denominator_ * var.denominator_);
	}

	Fraction2 operator / (Fraction2& var)
	{
		return Fraction2(numerator_ * var.denominator_, denominator_ * var.numerator_);
	}

	Fraction2 operator * (Fraction2& var)
	{
		return Fraction2(numerator_ *  var.numerator_ , denominator_ * var.denominator_);
	}











	std::pair<int, int> GetVarFraction();

	
};


int InputVar(const std::string& text);

void Output_2(const std::string& A_1, const  int& B_1, const std::string& A_2, const  int& B_2);

void Task_2();

#endif