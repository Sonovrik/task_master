#pragma once

#include "yaml-cpp/yaml.h"

#include <unordered_map>

class ConfigParser
{
private:
	struct TaskInfo {
		std::string cmd;
		int num_procs;
		int umask;
		std::string working_dir;
		bool auto_start;
		bool auto_restart;
		std::vector<int> exit_codes;
		std::size_t start_retries;
		std::size_t start_time;
		std::vector<int> stop_signals;
		std::size_t stop_time;

		std::string stdout_file;
		std::string stderr_file;
		std::unordered_map<std::string, std::string> env;
	};

private:
	YAML::Node m_RootNode;

public:
	ConfigParser() = delete;
	ConfigParser(const std::string& path_to_config);
	~ConfigParser() = default;
};

