#ifndef LOGGER_H
#define LOGGER_H
/*
 * Logging tool:
 *	Writes output to specified file.
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

class logger {
public:
	logger(const std::string &);

	void			write(const std::string &, const std::string &);
private:
	std::streambuf		*buffer;
	std::ofstream		file_output;
};

#endif
