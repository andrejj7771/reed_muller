#include "utils.h"

namespace Utils {
	
	int8_t abs(int8_t value) {
		//WARNING: be careful
		return value < 0 ? -value : value;
	}
	
	uint64_t factorial(int8_t num) {
		if (num == 0 || num == 1) {
			return 1;
		} else if (num == 2) {
			return 2;
		}
		
		return static_cast<uint64_t>(num) * factorial(num - 1);
	}
	
	uint64_t numOfCombinations(int8_t by, int8_t from) {
		uint64_t res = factorial(from) / (factorial(by) * factorial(from - by));
		
		return res;
	}
	
	uint64_t sumOfCombinations(int8_t r, int8_t m, Vec3D & combination) {
		uint64_t sum = 1;
		
		for (int8_t i = 1; i <= r; ++i) {
			sum += numOfCombinations(i, m);
			if (i > 1) {
				combination.push_back(combinationList(m, i));
			}
		}
		
		return sum;
	}
	
	bool combination(std::vector<int> & a, int n, int m) {
		int k = m;
		for (int i = k - 1; i >= 0; --i) {
			if (a[i] < n - k + i + 1) {
				++a[i];
				for (int j = i + 1; j < k; ++j) {
					a[j] = a[j - 1] + 1;
				}
				return true;
			}
		}
		return false;
	}
	
	Vec2D combinationList(int n, int m) {
		Vec2D combMatrix;
		std::vector<int> combVec;
		
		for (int i = 0; i < n; i++) {
			combVec.push_back(i + 1);
		}
		
		std::vector<int> copy = combVec;
		copy.resize(size_t(m));
		combMatrix.push_back(copy);
		
		if (n >= m) {
			while (combination(combVec, n, m) == true) {
				copy = combVec;
				copy.resize(size_t(m));
				combMatrix.push_back(copy);
			}
		}
		return combMatrix;
	}
	
	void printHelp() {
		printf("[--help | -h]		show help\n"		// has no value
			   "[-r]			blah blah blah\n"		// positive number arg has no default value r < m
			   "[-m]			blah blah blah\n"		// positive number arg has no default value
			   "[--mode | -m 0/1]	encode/decode mode"	// number arg by default - 0
			   "[--message | -ms <message>] your messages to encode/decode\n"); // string arg has no default value
	}
	
	std::map<arg_t, std::string> getArgsList(int argc, char **argv) {
		std::map<arg_t, std::string> args; // arg type - arg value
		// this argument always exists
		args[arg_t::path] = argv[0];
		
		if (argc > 1) {
			for (int i = 1; i < argc; i += 2) {
				std::string name = argv[i];
				// this argument should be the last,
				// because the next arguments will be interpreted as messages
				// the one which can have a string value.
				if (name == "--message" || name == "-ms") {
					std::string messages = "";
					for (i++; i < argc; ++i) {
						messages.append(argv[i]);
						messages += " ";
					}
					messages.pop_back(); // remove the last symbol
					args[arg_t::message] = messages;
				}
				// the one which has no value, but has a high prioriry,
				// the next arguments will be ignored
				else if (name == "--help") {
					args[arg_t::help] = "";
					return args;
				}
				// other arguments
				else {
					// this arguments should be checked for validity of the value
					std::string value;
					try {
						value = argv[i + 1];
						// if this code won't throw an exception, then argument is valid
						std::stoi(value);
					} catch (std::exception & e) {
						printf("%s -> %s", __FUNCTION__, e.what());
						value = "-1";
					}
					
					if (name == "-r") {
						args[arg_t::r] = value;
					} else if (name == "-m") {
						args[arg_t::m] = value;
					}
					// this argument may not have a value
					// will be inited with default value - 0 (encode mode)
					else if (name == "--mode" || name == "-md") {
						if (value != "1" && value != "0") {
							args[arg_t::mode] = "0";
						} else {
							args[arg_t::mode] = value;
							// this argument may not have a value
							// will be inited with default value - 0 (encode mode)
						}
					}
				}
			}
		}
		
		return args;
	}
	
	std::vector<std::string> getMessageList(const std::string & messages) {
		size_t prev = 0;
		size_t pos = 0;
		
		std::vector<std::string> res;
		while(pos <= messages.size() || pos != std::string::npos) {
			pos = messages.find_first_of(" ", prev);
			res.push_back(messages.substr(prev, pos));
			if (pos != std::string::npos) {
				prev = pos + 1;
			}
		}
		
		return res;
	}
}
