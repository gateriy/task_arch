//#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>

#include "Figure.h"

class Triangle :public Figure {
	//треугольник(стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
public:
	Triangle(double a, double b, double c, double A, double B, double C);

	void print_info() ;
	bool check() ;
};

#endif