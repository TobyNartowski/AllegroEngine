#include "Logger.hpp"

Logger::Logger() {}

Logger &Logger::getLogger() {
	static Logger instance;
	return instance;
}

void Logger::logSuccess(std::string msg) { 
	std::cout << LOGGER_SUCCESS << "[+] " + msg << LOGGER_NORMAL << std::endl;
}

void Logger::logNormal(std::string msg) {
	std::cout << " - " + msg << std::endl;
}


void Logger::logError(std::string msg) {
	std::cout << LOGGER_FAILURE << "[-] " + msg << LOGGER_FAILURE << std::endl;
}
