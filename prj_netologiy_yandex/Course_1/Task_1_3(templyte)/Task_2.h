//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include <iostream>
#include <string>

template<typename T> 
class Two_Array {

public:
	Two_Array(int r, int c) : _rows(r), _columns(c) {

		_table = new T*[_rows];

		for (int i = 0; i < _rows; ++i) {
			_table[i] = new T [_columns];
		}		
	};

	~Two_Array() {

		for (int i = 0; i < _rows; ++i) {
			delete[] _table[i];
		}	
		delete[] _table;
		//std::cout << "array destruction" << std::endl;
	};

	const std::pair<int,int> size() const { return { _rows, _columns }; }

	// определение оператора квадратных скобок
	T* operator [](int r) { return _table[r]; };

	// определение константного оператора квадратных скобок
	const T* operator [](int r) const { return _table[r]; };

private:
	T** _table;
	int _rows{ 0 }, _columns{ 0 };
};



void Task_2();

#endif