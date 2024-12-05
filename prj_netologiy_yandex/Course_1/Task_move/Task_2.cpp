#include"Task_2.h"

/*
Задача 2. Большие числа
Описание
Вам нужно реализовать класс для работы с большими числами, 
которые не помещаются в стандартные типы данных.

Для этого класса нужно определить методы:

конструктор перемещения;
перемещающий оператор присваивания;
оператор сложения двух больших чисел;
оператор умножения на число.
Для реализации этого класса можно воспользоваться std::string или std::vector.

Пример правильной работы программы
auto number1 = big_integer("114575");
auto number2 = big_integer("78524");
auto result = number1 + number2;
std::cout << result; // 193099
*/


bool big_intger:: check(const std::string& x, const std::string& text) {
	for (const char& i : x) {		
		if (i != '1' && i != '2' && i != '3' && i != '4' && i != '5' && i != '6' && i != '7' && i != '8' && i != '9' && i != '0') {
			std::cout << text << std::endl;
			return false;
		}
	}
	return true;
};

std::vector<int> big_intger :: _transfor_vector(const std::string& var) {
	std::vector<int> xx{};
	for (const auto& i : var) {
		xx.push_back(i - '0');
	}
	return xx;
}

std::vector<int> big_intger :: _summ_x(const std::vector<int>& a) {
	std::vector<int> res_i{};
	int end_x{ 0 }, first_x{ 0 };

	for (int i = static_cast<int>((a.size() - 1)); i >= 0; --i) {

		end_x = (a.at(i) + first_x) % 10;	
		first_x = (a.at(i) + first_x) / 10; 	
		res_i.push_back(end_x);			
	}
	if (first_x != 0) { res_i.push_back(first_x); }  

	std::reverse(res_i.begin(), res_i.end());
	return res_i;
}

std::string big_intger :: summ_y(const std::string& xx, const std::string& yy) {
	
	if (xx.empty() || xx=="0") { return yy; }
	if (yy.empty() || yy=="0") { return xx; }

	std::string res{};
	std::vector<int> x{}, var{}, y{};
	int count{ 0 }, r1{ 0 }, r2{ 0 };

	if (xx.size() >= yy.size()) {
		x = _transfor_vector(xx);
		y = _transfor_vector(yy);
	}
	else {
		y = _transfor_vector(xx);
		x = _transfor_vector(yy);
	}
	count = static_cast<int>((y.size() - 1));

	for (int i = static_cast<int>((x.size() - 1)); i >= 0; --i) {

		r1 = x.at(i);
		if (count >= 0) {
			r2 = y.at(count) ;
			--count;
		}
		else { r2 = 0; }

		var.push_back((r1 + r2));
	}
	std::reverse(var.begin(), var.end());

	for (const auto& i : _summ_x(var)) {
		res = res + std::to_string(i);
	}	
	return std::move(res);
}

std::string big_intger::multi(const std::string& str_a, const std::string& str_b) {

	if (str_a.empty() || str_a == "0") { return "0"; }
	if (str_b.empty() || str_b == "0") { return "0"; }

	std::vector<int>vec_var{}, x{}, y{};
	std::vector< std::vector<int> > matrix{};
	std::string res{};
	int count{ 0 }, first{ 0 }, end{ 0 }, summ_var{ 0 };
	

	if (str_a.size() >= str_b.size()) {
		x = _transfor_vector(str_b);
		y = _transfor_vector(str_a);
	}
	else {
		x = _transfor_vector(str_a);
		y = _transfor_vector(str_b);
	}

	for (int i = static_cast<int>((x.size() - 1)); i >= 0; --i) {
		vec_var.push_back(0);
		for (int j = 0; j < y.size(); ++j) {
			vec_var.push_back((y.at(j) * x.at(i)));
		}
		matrix.push_back(_summ_x(vec_var));
		vec_var.clear();
		++count;
	}

	for (int i = 0; i < count; ++i) {
		first = (count - 1) - i;
		end = (count - 1) - first;

		for (int z = 0; z < first; ++z) {
			matrix.at(i).insert(matrix.at(i).begin(), 0);
		}
		for (int z = 0; z < end; ++z) {
			matrix.at(i).push_back(0);
		}
	}

	for (int f = 0; f < matrix.at(0).size(); ++f) {
		for (int i = 0; i < count; ++i) {
			summ_var = summ_var + matrix.at(i).at(f);
		}
		vec_var.push_back(summ_var);
		summ_var = 0;
	}
	
	if (vec_var.at(0) == 0) {
		vec_var.erase(vec_var.begin());
	}

	for (const auto& i : _summ_x(vec_var)) { 
		res = res + std::to_string(i);
	}
	return std::move(res);
}

std::string big_intger::get() const {
	return std::move(_text);
}


std::ostream& operator << (std::ostream& os, const big_intger& result)
{
	os << result._text;
	return os;
}


void Task_2() {

	std::string a, b,exit;
	auto result = big_intger() ;

	do {
		do {
			std::cout << "Введите число а: ";
			std::getline(std::cin >> std::ws, a);
		} while (!result.check(a, "Не корректный ввод цифры! Повторите ввод!"));

		do {
			std::cout << "Введите число b: ";
			std::getline(std::cin >> std::ws, b);
		} while (!result.check(b, "Не корректный ввод цифры! Повторите ввод!"));
	
		{
			auto x = big_intger(a);
			auto y = big_intger(b);

			std::string summ = x + y;
			std::string multi = x * y;
	
			std::cout << "----------------------------------------" << std::endl;
			std::cout << a << " + " << b << " = " << summ << std::endl;
			std::cout << a << " * " << b << " = " << multi << std::endl;
			std::cout << "----------------------------------------" << std::endl;
		}

		{
			auto x = big_intger(a);
			auto y = big_intger(b);

			auto summ_1 = x + y;		
			auto multi_1 = x * y;

			std::cout << "----------------------------------------" << std::endl;
			std::cout << a << " + " << b << " = " << summ_1 << std::endl;
			std::cout << a << " * " << b << " = " << multi_1 << std::endl;
			std::cout << "----------------------------------------" << std::endl;
		}

		std::cout << "Exit (y or n): ";
		std::cin >> exit;
		if (exit == "y") {
			std::cout << "----------------------------------------" << std::endl;
			break;
		}

	} while (true);
};