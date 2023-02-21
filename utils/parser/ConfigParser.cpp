#include "ConfigParser.h"

#include <iostream>

ConfigParser::ConfigParser(std::string_view path_to_config) {
	loadConfig(path_to_config);
}

void ConfigParser::loadConfig(std::string_view path_to_config) {
	m_RootNode = YAML::Load(path_to_config.data());
}

TaskInfo ConfigParser::getTask(YAML::Node& node) {
	return TaskInfo {

	};
}

std::unordered_map<std::string, TaskInfo> ConfigParser::getTasks()
{
	auto programs = m_RootNode["programs"];
	for (auto it = m_RootNode.begin(); it != m_RootNode.end(); ++it) {
		std::cout << it->first.as<std::string>() << std::endl;
		getTask(it->first);
	}

	std::unordered_map<std::string, TaskInfo> tasks;


	return std::unordered_map<std::string, TaskInfo>();
}
