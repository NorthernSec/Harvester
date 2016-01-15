#include "network.h"

/*
 * init_network(logger):
 *	...
 */
void network::init_network(logger *log_output) {
	this->log_output = log_output;
}

/*
 * fetch_url(url, json):
 *	Fetches a url.
 */
std::vector<struct result_data> &network::fetch_url(const std::string &url, bool json) {
	std::string	buffer;
	CURL 		*curl;
	CURLcode	res;

	curl = curl_easy_init();
	if (!curl)
		this->log_output->write("network", "Could not initiate curl.");

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, network::curl_write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
		this->log_output->write("network", curl_easy_strerror(res));
	curl_easy_cleanup(curl);

	if (json)
		this->parse_json(buffer);

	return (this->results);	
}

/*
 * curl_write_callback(...):
 *	Store curl result in string.
 */
size_t network::curl_write_callback(void *content, size_t size, size_t mem, void *target) {
	((std::string *)target)->append((char *)content, size * mem);
	
	return (size * mem);
}

/*
 * parse_json(string):
 *	Parse string as JSON and fill our result vector.
 */
void network::parse_json(const std::string &target) {
	JSONValue *json = JSON::Parse(target.c_str());
	JSONObject root;
	JSONObject response;
	JSONArray response_results;

	if (json == NULL)
		this->log_output->write("network::parse_json", "JSON string error.");

	root = json->AsObject();
	response = root[L"responseData"]->AsObject();
	response_results = response[L"results"]->AsArray();	
	for (size_t index = 0; index < response_results.size(); index++) {
		std::vector<std::wstring> keys = response_results[index]->ObjectKeys();
		std::vector<std::wstring>::iterator iter = keys.begin();
		while (iter != keys.end()) {
			std::wcout << (*iter).c_str() << ": ";

			JSONValue *top = JSON::Parse(response_results[index]->Stringify().c_str());
			JSONValue *value = top->Child((*iter).c_str());
			if (value != NULL)
				std::wcout << value->Stringify().c_str() << std::endl;
			std::wcout.flush();
			iter++;
		}
	}
	
}
