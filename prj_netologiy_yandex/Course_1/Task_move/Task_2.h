//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include "AllConfigTask.h"

class big_intger {
	
public:

	big_intger() {
	};

	big_intger(const std::string& a) : _text(a) {};

	big_intger(big_intger&& other) noexcept // конструктор перемещения
		: _text(std::exchange(other._text, nullptr)) {};

	~big_intger() {};

	big_intger operator + (big_intger& other) 
	{
		return summ_y(this->_text, other._text);
	}

	big_intger operator * (big_intger& other) 
	{
		return multi(this->_text, other._text);
	}

	big_intger& operator = (big_intger&& other) noexcept // оператор перемещающего присваивания
	{
		std::swap(_text, other._text);
		return 	 *this;
	}

	operator std::string  () const {
		return get();
	}

	friend std::ostream& operator << (std::ostream& os, const big_intger& result);

	bool check(const std::string& x, const std::string& text);

private:
	std::string _text;	

	std::string get() const;

	std::string summ_y(const std::string& xx, const std::string& yy);

	std::string multi(const std::string& str_a, const std::string& str_b);

	std::vector<int> _transfor_vector(const std::string& var);

	std::vector<int> _summ_x(const std::vector<int>& a);

};

void Task_2();

#endif