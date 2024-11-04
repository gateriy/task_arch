//#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//чтение файла и формирование первичного вектора
class InOutFileVector {

public:

	//чтение файла и формирование первичного вектора
	void OupenFileWriteVector();

	//вывод первичного вектора
	std::vector<std::string> GetVector_1();

	//ввод вторичного вектора
	std::vector<std::string> SetVector_2(const std::vector < std::string>& a);

	//вывод вторичного вектора
	std::vector<std::string> GetVector_2();

	//запись в файл
	void InFileWriteVetor();

	std::vector <std::vector<int>> CreateArrayVector(const std::vector < std::string>& a);

private:
	int x_line{};
	std::string x_text{};
	std::vector <std::string> in_data_file{};
	std::vector <std::string> out_data_file{};

	//счиывание пути к файлу и преобразование / или \ в "\\" пути к файлу с консоли
	std::string InputTransformWay();
};

std::vector<int> connection_point(const std::vector <std::vector<int>>& array, int point_x);

void input_connection_point(const std::vector <std::vector<int>>& array, int var);

void input_matrix_graf(const std::vector <std::vector<int>>& array);

std::vector <std::vector <std::pair<bool, int>> > Array_Pair(const std::vector <std::vector<int>>& array);

void input_matrix_graf_pair(const std::vector <std::vector<int>>& array);

void input_statuse_point(const std::vector <std::pair<bool, int>>& array);

std::vector <std::pair<bool, int>> Array_Pair_statuse(const std::vector <std::vector<int>>& array);

void input_go_res(const std::vector <int>& array);

void Task_1();

#endif 
