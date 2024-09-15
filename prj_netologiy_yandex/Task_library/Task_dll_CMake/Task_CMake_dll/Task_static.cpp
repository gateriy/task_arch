#include "Task_static.h"

namespace static_lib 
{
	void Greeter::greet() {

	std::string text{};
	std::cout << std::endl;
	std::cout << "< Статическая библиотека >" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите имя: ";
	std::getline(std::cin >> std::ws, text);
	std::cout << "Здравствуйте, "<< text <<"!" << std::endl;
	std::cout << std::endl;
	}
}