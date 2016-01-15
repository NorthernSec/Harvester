#include "module_google.h"

/*
 * init_module(logger):
 *	Initialize stuff for module.
 */
void module_google::init_module(logger *log_output) {
	this->log_output = log_output;
	this->name = "google_module";

	this->google = new network;
	this->google->init_network(this->log_output);
}

/*
 * perform_search(string):
 *	Searches google for string.
 */
void module_google::perform_search(const std::string &target) {
	this->log_output->write(this->name, target);
	this->google->fetch_url(this->compile_url(target), true);
}

/*
 * compile_url(target):
 *	Wrapper for a stringstream to add target string to 
 *	google rest api url.
 */
std::string module_google::compile_url(const std::string &target) {
	std::stringstream	stream;

	stream << "https://ajax.googleapis.com/ajax/services/search/web?v=1.0&q=";
	stream << target.c_str();

	return (stream.str());
}
