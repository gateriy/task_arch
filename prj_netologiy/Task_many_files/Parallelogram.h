//#pragma once
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <iostream>
#include <string>

#include "Quadrangle.h"
#include "Figure.h"

class Parallelogram : public Quadrangle {
	//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
public:
	Parallelogram(double a, double b, double A, double B);

	void print_info() ;
	bool check() ;
};

#endif