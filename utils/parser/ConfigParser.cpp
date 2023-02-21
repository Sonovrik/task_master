#include "ConfigParser.h"

ConfigParser::ConfigParser(const std::string& path_to_config) {
	m_RootNode = YAML::Load(path_to_config);
}
