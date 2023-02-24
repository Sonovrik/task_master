#include <iostream>

#include "ConfigParser.h"

int main(int argc, char** argv)
{
	static const std::string path_to_config = "../config";
	std::unordered_map<std::string, utils::TaskInfo> tasks;
	Parsing::ConfigParser cf_parser;
	try
	{
		cf_parser.loadConfig(path_to_config);
		tasks = cf_parser.getTasks();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error while parsing: " << e.what() << std::endl;
		return -1;
	}

	std::cout << "Hello world" << std::endl;

	return 0;
}
