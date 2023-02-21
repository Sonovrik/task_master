#pragma once

#include "yaml-cpp/yaml.h"

#include "utils.h"

class ConfigParser
{
private:
	YAML::Node m_RootNode;

private:
	TaskInfo getTask(YAML::Node& node);

public:
	ConfigParser() = delete;
	~ConfigParser() = default;

	ConfigParser(std::string_view path_to_config);

	void loadConfig(std::string_view path_to_config);

	std::unordered_map<std::string, TaskInfo> getTasks();

};

