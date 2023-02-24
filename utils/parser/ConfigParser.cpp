#include "ConfigParser.h"

namespace Parsing
{

ConfigParser::ConfigParser(std::string_view path_to_config)
{
	loadConfig(path_to_config);
}

void ConfigParser::loadConfig(std::string_view path_to_config)
{
	m_RootNode = YAML::LoadFile(path_to_config.data());
}

utils::TaskInfo ConfigParser::getTask(const YAML::Node& node) {
	utils::TaskInfo task;

	task.cmd 			= node["cmd"].as<std::string>();
	task.num_procs 		= node["numprocs"].as<int>();
	task.umask 			= node["umask"].as<int>();
	task.working_dir 	= node["workingdir"].as<std::string>();
	task.auto_start 	= node["autostart"].as<bool>();
	task.auto_restart 	= node["autorestart"].as<bool>();
	task.start_retries 	= node["startretries"].as<std::size_t>();
	task.start_time 	= node["starttime"].as<std::size_t>();
	task.stop_signal 	= parseSignal(node["stopsignal"].as<std::string>());
	task.stop_time 		= node["stoptime"].as<std::size_t>();
	task.stdout_file 	= node["stdout"].as<std::string>();
	task.stderr_file 	= node["stderr"].as<std::string>();

	task.exit_codes 	= getYamlListNode<int>(node["exitcodes"]);
	task.env 			= getYamlMapNode<std::string, std::string>(node["env"]);

	return task;
}

std::unordered_map<std::string, utils::TaskInfo> ConfigParser::getTasks()
{
	std::unordered_map<std::string, utils::TaskInfo> tasks;

	auto programsRoot = m_RootNode["programs"];
	for (auto it = programsRoot.begin(); it != programsRoot.end(); ++it) {
		tasks[it->first.as<std::string>()] = getTask(it->second);
	}

	return tasks;
}

utils::SIGNAL ConfigParser::parseSignal(const std::string& signal)
{
	auto res = m_signalsMap.find(signal);
	if (res == m_signalsMap.end())
	{
		throw std::runtime_error("Unknown signal: " + signal);
	}

	return res->second;
}

}