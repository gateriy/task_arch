#include"Task_2.h"

/*
В этом задании вы создадите простой макрос.
Ваша задача — определить макрос SUB, который должен вычитать 
числа друг из друга и использоваться следующим образом:
*/

#define SUB(x,y) ((x) -(y))

void Task_2() {

	int a = 6;
	int b = 5;
	int c = 2;
	std::cout << SUB(a, b) << std::endl;
	std::cout << SUB(a, b) * c << std::endl;
	std::cout << SUB(a, b + c) * c << std::endl;

};