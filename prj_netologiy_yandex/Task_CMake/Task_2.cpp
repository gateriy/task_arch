#include"Task_2.h"

void print_info2(Figure* x) { x->print_info(); }

void Task_2() {

	std::cout << std::endl;

	Figure figure;
	Triangle triangle(10, 20, 30, 50, 60, 70);
	RightAngledTriangle rightAngledTriangle(10, 20, 30, 50, 60);
	RightAngledTriangle rightAngledTriangle2(10, 20, 30, 50, 40);
	IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
	AnEquilateralTriangle anEquilateralTriangle(30);

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhomb rhomb(30, 30, 40);

	figure.print_info();
	print_info2(&triangle);
	print_info2(&rightAngledTriangle);
	print_info2(&rightAngledTriangle2);
	print_info2(&isoscelesTriangle);
	print_info2(&anEquilateralTriangle);

	print_info2(&quadrangle);
	print_info2(&rectangle);
	print_info2(&square);
	print_info2(&parallelogram);
	print_info2(&rhomb);

	std::cout << std::endl;

}
