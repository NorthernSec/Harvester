#ifndef MODULE_GOOGLE_H
#define MODULE_GOOGLE_H
/*
 * Module Google:
 *	Explain this stuff. Too lazy now.
 */
#include <sstream>
#include "module.h"
#include "network.h"

class module_google : public module {
public:
	virtual void		init_module(logger *);
	virtual void		perform_search(const std::string &);
private:
	network			*google;

	std::string		compile_url(const std::string &);
};

#endif
