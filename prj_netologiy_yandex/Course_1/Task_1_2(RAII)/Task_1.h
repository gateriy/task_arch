//#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <string>


class smart_array {

public:

	smart_array(int sz) : size_x(sz) {  array = new int[size_x]; }

	~smart_array() { 
		std::cout << "-----------------------------------------------------" << std::endl;
		std::cout << "Класс smart_array закрыт! Память массива освобождена!" << std::endl;
		delete[] array; }

	void add_element(int x);

	int get_element(int index);

	int get_size_array() ;

	int get_size_added_array() ;

	//перегрузка оператора = для присвоение классов оберток массивов и ключевых параметров для них.
	smart_array& operator = (const smart_array& array_2) {
		
		this->count = array_2.count;
		this->size_x = array_2.size_x;
				
		delete[] this-> array;
		this -> array = new int[size_x];

		for (int i = 0; i < size_x; ++i) {
			this -> array[i] = array_2.array[i] ;
		}
		return *this;
	}

private:
	int* array;
	int size_x{};
	int count{ 0 };
};


void Task_1();


#endif 
