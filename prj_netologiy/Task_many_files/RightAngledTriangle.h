//#pragma once
#ifndef RIGHTANGLEDTRIANGLE_H
#define RIGHTANGLEDTRIANGLE_H

#include <iostream>
#include <string>

#include "Triangle.h"
#include "Figure.h"

class RightAngledTriangle : public Triangle {
	//прямоугольный треугольник(угол C всегда равен 90);
public:
	RightAngledTriangle(double a, double b, double c, double A, double B);

	void print_info() ;
	bool check() ;
};

#endif