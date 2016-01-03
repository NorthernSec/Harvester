#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H
/*
 * Module Manager:
 *	For ease of use and less repetetive code.
 */
#include <vector>
#include "module.h"

class module_manager {
public:
	void				init_module_manager(logger *);
	void				add_module(module *);
	void				perform_search(const std::string &);
private:
	std::vector<module *>		modules;
	logger				*log_output;
	const std::string		name = "module_manager";
};
#endif
