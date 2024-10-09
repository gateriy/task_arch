//#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <string>

std::pair<int, int> input_sizes();
int* create_dynamic_array( int actual_size);
void print_dynamic_array(int* arr, int logical_size, int actual_size);
void delete_dynamic_array(int* arr);
void Task_1();

#endif 
