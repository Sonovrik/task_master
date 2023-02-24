#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace utils
{

enum class SIGNAL : int
{
	TERM,
	USR1
};

struct TaskInfo
{
	std::string cmd;
	int num_procs;
	int umask;
	std::string working_dir;
	bool auto_start;
	bool auto_restart;
	std::vector<int> exit_codes;
	std::size_t start_retries;
	std::size_t start_time;
	SIGNAL stop_signal;
	std::size_t stop_time;

	std::string stdout_file;
	std::string stderr_file;
	std::unordered_map<std::string, std::string> env;
};

}
