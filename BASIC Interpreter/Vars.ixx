module;
export module Vars;

import std;
import defines;

using any_t = std::variant<int, float, std::string>;

struct VarInfo {
	std::string name;
	any_t value;
};

/*
* Variable store class
* Store & Returns prgram variables
*/
export class VarStore {
private:
	std::vector<VarInfo> _data;

private:
	eReturnCodes GetValue(const std::string& name, any_t& value);
	eReturnCodes SetValue(const std::string& name, any_t value);

public:
	eReturnCodes GetVar(const std::string& name, std::string& val);
	eReturnCodes SetVar(CommandSpecification &spec);
};

export extern VarStore varStore;
