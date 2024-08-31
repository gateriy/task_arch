//#pragma once
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

class Figure {

public:
	Figure();
	Figure(double a, double b, double c, double d, double A, double B, double C, double D);

	void virtual print_info();
	bool virtual check();

protected:
	void get_var_task_3(int number_of_sides);

	double a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 }, A{ 0 }, B{ 0 }, C{ 0 }, D{ 0 };
	std::string text_var{ "Фигура:" };
	int count{ 0 };//номер фигуры (пока не исрользуется)
};

#endif