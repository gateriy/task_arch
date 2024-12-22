#pragma once

#include "Config.h"

class Temperature {
public:

	Temperature(const int& quantity, const double& temperat_max, const double& temperat_min) {
		this->_quantity = quantity;
		this->_temperat_max = temperat_max;
		this->_temperat_min = temperat_min;
		this->_array_x = new double[_quantity] { 0 };
	};

	~Temperature() {
		delete[] _array_x;
	};

	bool set_array(const int& nomber, const double& temp_var);

	std::pair<int, double> get_chang_temperat();

	double get_temperat_i(const int& nomber);

	double average_temperat();

private:
	int _quantity{ 0 };
	double _temperat_max{ 0 }, _temperat_min{ 0 };
	double* _array_x;
	int _sensor_end{ 0 };
};

void block_5();
