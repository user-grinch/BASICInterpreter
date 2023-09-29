module;
export module Util;

import std;

export bool IsNumber(const std::string& s) {
	for (char const& ch : s) {
		if (ch == '\0') {
			break;
		}

		if (std::isdigit(ch) == 0) {
			return false;
		}
	}
	return true;
}

export std::vector<std::string> GetWords(std::string s, char split) {
	std::vector<std::string> res;
	size_t pos = 0;

	if (split != ' ') {
		std::erase(s, ' ');
	}
	while (pos < s.size()) {
		pos = s.find(split);
		res.push_back(s.substr(0, pos));
		s.erase(0, pos + 1);
	}
	return res;
}