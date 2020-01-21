#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

#include "reed_muller.h"

using sum_pair = std::pair<int, int>;

std::vector<sum_pair> genCheckSum(int m, int i) {
	std::vector<sum_pair> sums;
	std::vector<int> bl;		//black list
	
	int offset = 1 << (m - i);
	int p = 0;
	for (int j = 0; p < (1 << m) - 1; ++j) {
		int t = j;
		p = t + offset;
		
		if (std::find(bl.begin(), bl.end(), p) == bl.end() &&
				std::find(bl.begin(), bl.end(), t) == bl.end())
		{
			bl.push_back(t);
			bl.push_back(p);
			
			sums.push_back({t, p});
		}
	}
	
	return sums;
}

int main(int argc, char** argv) {
	for (int i = 1; i <= 3; ++i) {
		auto s = genCheckSum(3, i);
		std::cout << i << std::endl;
	}
	
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
