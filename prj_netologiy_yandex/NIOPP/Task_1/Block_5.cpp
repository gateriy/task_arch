
#include "Block_5.h"

void Temperature::set_array(const int& nomber, const double& temp_var) {

	if ((nomber >= 0 && nomber < _quantity) && (temp_var <= _temperat_max && temp_var >= _temperat_min)) {

		for (int i = 0; i < _quantity; ++i) {
			_array_y[i] = false;
		}
		_array_x[nomber] = temp_var;
		_array_y[nomber] = true;
	}
	else {
		std::cerr << "Incorrect data nomber or temperat!" << std::endl;
	}
}

std::pair<int, double> Temperature::get_chang_temperat() {

	for (int i = 0; i < _quantity; ++i) {
		if (_array_y[i] == true) {
			return { (i + 1),_array_x[i] };
		};
	}
};

double Temperature::get_temperat_i(const int& nomber) {

	if ((nomber >= 0 && nomber < _quantity)) {
		return _array_x[nomber];
	}
	else {
		std::cerr << "Incorrect data nomber!" << std::endl;
	};
};

double Temperature::average_temperat() {
	double res{ 0 };

	for (int i = 0; i < _quantity; ++i) {
		res = res + _array_x[i];
	}
	return res / _quantity;
}


void block_5() {

	int var_y{ 0 }, quantity_x{ 0 };
	char end_x{ ' ' };
	double max_temperat{ 0 }, min_temperat{ 0 };
	bool first{ false };

	std::cout << "Ввведите количество датчиков: ";
	std::cin >> quantity_x;
	std::cout << "Ввведите предельную максимальную температуру: ";
	std::cin >> max_temperat;
	std::cout << "Ввведите предельную минимальную температуру: ";
	std::cin >> min_temperat;

	auto var_temp = Temperature(quantity_x, max_temperat, min_temperat);
	do {

		if (first == false || (end_x != '0' && end_x != '1' && end_x != '2')) {
			std::cout << "Имитация опроса датчиков! Запись только при изменении значения!" << std::endl;
			for (int i = 0; i < quantity_x; ++i) {
				std::cout << "Ввведите значение температуры датчика [" << (i + 1) << "]: ";
				std::cin >> var_y;

				if (var_temp.get_temperat_i(i) != var_y) {
					var_temp.set_array(i, var_y);
				}
			}
			first = true;
		}



		if (end_x == '2') {

			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Последнее измененное значение: датчик [" << var_temp.get_chang_temperat().first
				<< "], значение: [" << var_temp.get_chang_temperat().second << "]" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;

		}

		if (end_x == '1') {

			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Среднее значение температуры: [" << var_temp.average_temperat() << "]" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;

		}

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Выйти из программы 1 - среднея температура, 2 - последнее изменение, 0 - выход, повтор - любой символ!: ";
		std::cin >> end_x;
		std::cout << "-----------------------------------------" << std::endl;

		if (end_x == '0') { break; }
	} while (true);

};