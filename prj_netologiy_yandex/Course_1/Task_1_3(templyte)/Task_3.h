//#pragma once
#ifndef TASK_3_H
#define TASK_3_H

#include <iostream>
#include <string>
#include <vector>

template<typename T>
class my_class
{
public:

	my_class() {
		_count = 0;
		_summ = 0;
	};
	~my_class() {};

	std::vector<T> get_vector() {
		return _vect_x;
	}

	//функтор, который подсчитывает сумму и количество чисел, делящихся на 3.
	void operator()(const std::vector<T>& x) { // определение оператора круглых скобок
		_vect_x = x;
		for (const auto& i : _vect_x) {

			if (i % 3 == 0) {
				++_count;
				_summ = _summ + i;
			}
		}
	};

	T get_sum() {
		return _summ;
	}

	int get_count() {
		return _count;
	}

private:
	std::vector<T> _vect_x{};
	int _count;
	T _summ;

};

void Task_3();

#endif