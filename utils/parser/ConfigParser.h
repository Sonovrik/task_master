#pragma once

#include "yaml-cpp/yaml.h"

#include "utils.h"

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

namespace Parsing
{

class ConfigParser
{
private:
	YAML::Node m_RootNode;

	inline const static std::map<std::string, utils::SIGNAL> m_signalsMap {
			{"TERM", utils::SIGNAL::TERM},
			{"USR1", utils::SIGNAL::USR1},
	};

private:
	template<typename T>
	std::vector<T> getYamlListNode(const YAML::Node& node)
	{
		std::vector<T> res;
		for (auto it = node.begin(); it != node.end(); ++it)
		{
			if (it->Type() != YAML::NodeType::Scalar)
			{
				throw std::runtime_error("Node is not scalar type");
			}
			res.push_back(it->as<T>());
		}

		return res;
	}

	template<typename T, typename N>
	std::unordered_map<T, N> getYamlMapNode(const YAML::Node& node)
	{
		std::unordered_map<T, N> res;
		for (auto it = node.begin(); it != node.end(); ++it)
		{
			res[it->first.as<T>()] = it->second.as<N>();
		}

		return res;
	}

private:
	utils::TaskInfo getTask(const YAML::Node& node);

	static utils::SIGNAL parseSignal(const std::string& signal);

public:
	ConfigParser() = default;
	~ConfigParser() = default;

	ConfigParser(std::string_view path_to_config);

	void loadConfig(std::string_view path_to_config);

	std::unordered_map<std::string, utils::TaskInfo> getTasks();
};

}