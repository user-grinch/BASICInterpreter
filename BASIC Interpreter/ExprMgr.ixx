#include "include/exprtk.hpp"
module;
export module ExprMgr;

import std;
import defines;


using any_t = std::variant<int, float, std::string>;

struct VarInfo {
	std::string name;
	any_t value;
};

export class ExprMgr {
private:
	exprtk::symbol_table<std::string> symbol_table;
	exprtk::expression<std::string> expression;
	exprtk::parser<std::string> parser;

public:
	eReturnCodes GetValue(const std::string& name, any_t& value);
	eReturnCodes SetValue(const std::string& name, any_t value);

	eReturnCodes GetVar(const std::string& name, std::string& val);
	eReturnCodes SetVar(CommandSpecification &spec);
};

export extern ExprMgr exprMgr;
