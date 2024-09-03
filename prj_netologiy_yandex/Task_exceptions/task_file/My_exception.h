//#pragma once
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <exception>
#include<string>


class My_Exeception : public std::exception {
public:
	My_Exeception(const std::string& mess) : mess(mess) {};

	const char* what() const noexcept override;

private:
	std::string mess{};
};


#endif