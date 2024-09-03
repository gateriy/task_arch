#include "My_exception.h"

const char* My_Exeception::what() const noexcept {

	return mess.c_str();//преобразование стринг в указатель на константную строку!

};