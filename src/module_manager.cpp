#include "module_manager.h"

/*
 * init_module_manager(logger):
 *	Initiate the module manager, duh.
 */
void module_manager::init_module_manager(logger *log_output) {
	this->log_output = log_output;
}

/*
 * add_module(module):
 *	Add module to internal list of modules to be used.
 */
void module_manager::add_module(module *target) {
	target->init_module(this->log_output);
	this->log_output->write(this->name, target->name);
	this->modules.push_back(target);
}

/*
 * perform_search(string):
 *	Search all modules for string.
 */
void module_manager::perform_search(const std::string &target) {
	for (auto target_module : this->modules)
		target_module->perform_search(target);
}
