#include <iostream>

#include "ConfigParser.h"

int main(int argc, char** argv)
{
	Parsing::ConfigParser cf("../config.yaml");
	auto tmp = cf.getTasks();
	std::cout << "Hello world" << std::endl;

	return 0;
}
