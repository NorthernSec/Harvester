#include "logger.h"

/*
 * logger(file_name):
 *	Setup the logger to write to either specified
 *	file or stdout.
 */
logger::logger(const std::string &file_name) {
	if (file_name == "stdout") {
		this->buffer = std::cout.rdbuf();
	} else {
		this->file_output.open(file_name.c_str());
		this->buffer = this->file_output.rdbuf();
	}
}

/*
 * write(identifier, message):
 *	Write message to desired output.
 */
void logger::write(const std::string &identifier, const std::string &message) {
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);
	std::ostream target(this->buffer);
	target << "[Harvester][" << std::put_time(&tm, "%y-%m-%d %H:%M:%S") << "]";
	target << "[" << identifier << "]: " << message << std::endl;
}
