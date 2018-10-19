#pragma once

#include <iostream>

#define LOGGER_FAILURE "\033[1;31m"
#define LOGGER_NORMAL "\033"
#define LOGGER_SUCCESS "\033[1;32m"

class Logger {
private:
	Logger();
public:
	static Logger& getLogger();

	Logger(Logger const&) = delete;
	void operator=(Logger const&) = delete;

	void logSuccess(std::string msg);
	void logNormal(std::string msg);
	void logError(std::string msg);
};
