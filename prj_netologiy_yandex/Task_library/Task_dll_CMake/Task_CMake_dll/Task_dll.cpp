#include "Task_dll.h"

namespace dll_lib {

	void Leaver::leave() {

		std::string text{};
		std::cout << std::endl;
		std::cout << "< Динамическая библиотека >" << std::endl;
		std::cout << std::endl;
		std::cout << "Введите имя: ";
		std::getline(std::cin >> std::ws, text);
		std::cout << "До свидания, " << text << "!" << std::endl;
		std::cout << std::endl;

	}
}