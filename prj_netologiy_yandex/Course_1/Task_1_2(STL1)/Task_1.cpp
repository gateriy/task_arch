#include "Task_1.h"

/*
Задача 1. Частота символов
Описание
Нужно посчитать, сколько раз каждый символ встречается в заданном тексте, 
и отсортировать по убыванию частоты.

Пример правильной работы программы
[IN]: Hello world!!
[OUT]:
l: 3
o: 2
!: 2
 : 1
H: 1
e: 1
d: 1
w: 1
r: 1

*/


void Task_1() {
	std::string text{};
	std::multiset <char> char_x{};
	std::vector<std::pair<char,int>> res{};

	std::cout << "Введите фразу: ";
	getline(std::cin >> std::ws, text);
	std::cout << std::endl;

	sort(text.begin(), text.end());

	for (const auto& x : text) {
		char_x.insert(x);
	}

	text.erase(unique(text.begin(), text.end()), text.end());

	for (const auto& y : text) {
		res.push_back({ y, char_x.count(y) });

	}
	
	sort(res.begin(), res.end(), []( std::pair<char,int>& a, std::pair<char, int>& b) {
		return a.second > b.second; });

	std::cout << "Результат - частота повторения символов:" << std::endl;
	for (const auto& f : res) {
		std::cout << f.first << " := " << f.second << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << std::endl;
};