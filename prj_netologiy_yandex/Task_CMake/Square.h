//#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>

#include "Rectangle.h"
#include "Figure.h"
#include "Quadrangle.h"

class Square : public Rectangle {
	//квадрат(все стороны равны, все углы равны 90);
public:
	Square(double a);

	void print_info() override;
	bool check() override;
};

#endif