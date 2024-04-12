#pragma once
#include <exception>

class OutOfPancakeException : public std::exception
{
public:
	const char* what() {
		return "OutOfPancakeException: Too many pancakes requested!";
	}
};