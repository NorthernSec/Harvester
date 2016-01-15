#ifndef NETWORK_H
#define NETOWRK_H
/*
 * Network:
 *	Using libcurl.
 */
#include <string>
#include <vector>
#include <curl/curl.h>
#include <stdio.h>
#include "JSON.h"
#include "logger.h"

/* === Result data structure === */
struct result_data {
	std::string		title;
	std::string		url;
};

class network {
public:
	void					init_network(logger *);
	std::vector<struct result_data>		&fetch_url(const std::string &, bool);
	static size_t				curl_write_callback(void *, size_t, size_t, void *);
	void					parse_json(const std::string &);
private:
	std::vector<struct result_data>		results;
	logger					*log_output;
};


#endif
