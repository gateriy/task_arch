//#pragma once
#ifndef TASK_3_H
#define TASK_3_H

#include <iostream>
#include <string>

template<typename T>
class smart_array {

public:

	smart_array() { _array = new T[_size_x]; }

	~smart_array() {
		//std::cout << "-----------------------------------------------------" << std::endl;
		//std::cout << "Класс smart_array закрыт! Память массива освобождена!" << std::endl;
		delete[] _array;
	}

	void push_back(T x) {
		if (_count < _size_x) {
			_array[_count] = x;
		}
		else {
			int size_old = _size_x;
			_size_x = _size_x * 2; //использую согласно алгоритмеке и для снижения асимтотики - удвоение массива 
			//при достижении его размера (!!!)
			T* array_2 = new T[_size_x];

			for (int i = 0; i < _size_x; ++i) {
				if (i < size_old) {
					array_2[i] = _array[i];
				}
				else {
					array_2[i] = {};
				}
			}

			array_2[_count] = x;
			delete[] _array;
			_array = new T[_size_x];

			for (int i = 0; i < _size_x; ++i) {
				_array[i] = array_2[i];
			}
			delete[] array_2;
		}
		++_count;
	};

	T at(int index) {
		if (index < _size_x) {
			return _array[index];
		}
		else {
			std::cout << "Overflow index array" << std::endl;
			return T{};
		}
	};

	int capacity() {
		return _size_x;
	};

	int size() {
		return _count;
	};

	//перегрузка оператора = для присвоение классов оберток массивов и ключевых параметров для них.
	/*
	smart_array& operator = (const smart_array& array_2) {

		this->_count = array_2._count;
		this->_size_x = array_2._size_x;

		delete[] this-> array;
		this -> array = new T [_size_x];

		for (int i = 0; i < _size_x; ++i) {
			this -> array[i] = array_2.array[i] ;
		}
		return *this;
	}
	*/

private:
	T* _array;
	int _size_x{ 5 };
	int _count{ 0 };
};

void Task_3();

#endif