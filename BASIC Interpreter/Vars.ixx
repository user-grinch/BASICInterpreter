module;
export module Vars;

import std;
import defines;

struct VarInfo {
	std::string name;
	std::any value;
};

/*
* Variable store class
* Store & Returns prgram variables
*/
export class VarStore {
private:
	std::vector<VarInfo> _data;

public:
	eReturnCodes GetValue(const std::string& name, std::any& value);
	eReturnCodes SetValue(std::string&& name, std::string&& value);
};
