//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include <iostream>
#include <string>

template <typename text, typename data> void Output(const text& A, const  data& B);

class Counter {
public:
	Counter(const int& _count);
	Counter();

	int LookCount();
	int AddCount();
	int SubtractCount();

private:
	int _count{0};
};

int FestCounter();

void Task_2();

#endif