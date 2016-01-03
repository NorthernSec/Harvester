#include "module_facebook.h"

/*
 * init_module(logger):
 *	Initialize stuff for module.
 */
void module_facebook::init_module(logger *log_output) {
	this->log_output = log_output;
	this->name = "facebook_module";
}

/*
 * perform_search(string):
 *	Searches facebook for string.
 */
void module_facebook::perform_search(const std::string &target) {
	this->log_output->write(this->name, target);
}
