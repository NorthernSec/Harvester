#ifndef MODULE_H
#define MODULE_H
/*
 * Module:
 *	Explain this stuff. Too lazy now.
 */
#include <string>
#include "logger.h"

class module {
public:
	virtual void		init_module(logger *) = 0;
	virtual void		perform_search(const std::string &) = 0;
	logger			*log_output;
	std::string		name;
};

#endif
