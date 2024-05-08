module Processor;

import Commands;
import Vars;

eReturnCodes Processor::_Init()
{
	RegisterCommand("PRINT", fPrint);
	RegisterCommand("INPUT", fInput);
	RegisterCommand("NEWLINE", fNewLine);
	RegisterCommand("TAB", fTab);
	RegisterCommand("REM", fRem);
	return eReturnCodes::Success;
}

eReturnCodes Processor::RegisterCommand(std::string&& funcName, std::function<funcargs_t> func)
{
	_commandRegistry.emplace_back(funcName, func);
	return eReturnCodes::Success;
}

eReturnCodes Processor::Run() {

	if (_commandRegistry.empty()) {
		_Init();
	}

	for (CommandSpecification& e : _commandStore) {

		// First check for known commands
		bool found = false;
		for (auto& f : _commandRegistry) {
			if (e.cmd == f.cmd) {
				ReturnSpecification spec;
				if (f.func(e, spec) != eReturnCodes::Success) {
					std::cerr << "Command \"" << e.cmd << "\" failed at line " << e.line << std::endl;
					return eReturnCodes::CommandFailure;
				}
				found = true;
				break;
			}
		}
		
		// Then check for variable arithmatic
		if (!found) {
			RemoveWhiteSpaces(e.cmd);
		}

		// setup variables
		if (e.cmd[0] == VAR_PREFIX) {
			varStore.SetVar(e);
		} 
		else if (!found) {
			std::cerr << "Invalid command: " << e.cmd << " on line: " << e.line << std::endl;
			return eReturnCodes::UnknownCommand;
		}
	} 
	return eReturnCodes::Success;
}

bool Processor::IsOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}
void Processor::RemoveWhiteSpaces(std::string& str) {
	str.erase(std::remove_if(str.begin(), str.end(), std::isspace));
}