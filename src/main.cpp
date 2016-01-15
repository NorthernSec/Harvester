/*
 * Harvester:
 *	A tool used to extract social data concering a person
 *	based on basic input (Name, E-Mail, Username etc...).
 *
 *	A NorthenSec Production.
 *	Author: Robin Abony <robin.abony@gmail.com>
 *	Author: Pieter-Jan Moreels <pieterjan.moreels@gmail.com>
 */
#include "main.h"

/*
 * main(argc, argv):
 *	Main entrypoint of application.
 */
int main(int argc, char **argv) {
	/* Setup logger. */
	logger log_output("stdout");
	log_output.write("main", "Testing logger output");

	/* Setup the module manager. */
	module_manager manager;
	manager.init_module_manager(&log_output);

	/* Add modules. */
	module_facebook facebook;
	module_google google;
	manager.add_module((module *)&facebook);
	manager.add_module((module *)&google);

	/* Perform search. */
	manager.perform_search("robin.abony@gmail.com");

	return (0);
}
