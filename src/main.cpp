#include <iostream>
#include <cstring>
#include <map>

#include "reed_muller.h"

int main(int argc, char** argv) {
	auto args = Utils::getArgsList(argc, argv);
	if (args.find(Utils::arg_t::help) != args.end()) {
		Utils::printHelp();
		return 0;
	}
	
	int8_t r = 0;
	int8_t m = 0;
	bool mode = 0;
	std::vector<std::string> messages;
	
	std::map<Utils::arg_t, std::string>::iterator it;
	if ((it = args.find(Utils::arg_t::r)) != args.end()) {
		r = int8_t(std::stoi(it->second));
		if (r < 0) {
			return -1;
		}
	} else {
		return -2;
	}
	
	if ((it = args.find(Utils::arg_t::m)) != args.end()) {
		m = int8_t(std::stoi(it->second));
		if (m < 0) {
			return -1;
		}
	} else {
		return -2;
	}
	
	if (r > m) {
		return -3;
	}
	
	if ((it = args.find(Utils::arg_t::mode)) != args.end()) {
		mode = bool(std::stoi(it->second));
	}
	
	if ((it = args.find(Utils::arg_t::message)) != args.end()) {
		messages = Utils::getMessageList(it->second);
	}
	
	if (messages.size() == 0) {
		return -4;
	}
	
	ReedMuller rm(r, m);
	
	if (mode == false) {
		for (auto message : messages) {
			std::string code = rm.encode(message);
			std::cout << code << std::endl;
		}
	} else {
		for (auto message : messages) {
			//TODO: need implementation
//			std::string code = rm.decode(message);
//			std::cout << code << std::endl;
		}
	}
	
	return 0;
}
