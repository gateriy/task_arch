//#pragma once
#ifndef ANEQUILATERALTRIANGLE_H
#define ANEQUILATERALTRIANGLE_H

#include <iostream>
#include <string>

#include "Triangle.h"
#include "Figure.h"

class AnEquilateralTriangle : public Triangle {
	//равносторонний треугольник(все стороны равны, все углы равны 60);
public:
	AnEquilateralTriangle(double a);

	void print_info() ;
	bool check() ;
};

#endif