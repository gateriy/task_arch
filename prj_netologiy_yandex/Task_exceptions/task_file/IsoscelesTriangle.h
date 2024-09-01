//#pragma once
#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include <iostream>
#include <string>

#include "Triangle.h"
#include "Figure.h"

class IsoscelesTriangle : public Triangle {
	//равнобедренный треугольник(стороны a и c равны, углы A и C равны)
public:
	IsoscelesTriangle(double a, double b, double A, double B);

	void print_info() ;
	bool check() ;
};

#endif