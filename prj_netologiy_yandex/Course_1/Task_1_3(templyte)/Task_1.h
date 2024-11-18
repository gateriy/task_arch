//#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <string>
#include <vector>

#include "AllConfigTask.h"

template <typename var> var square(var var_x);

template <> std::vector<int> square(std::vector<int> var_x);

template <typename var_T, typename vector_T>
void output_res(const var_T& var_y, const std::vector<vector_T>& vector_x);

void Task_1();

#endif 
