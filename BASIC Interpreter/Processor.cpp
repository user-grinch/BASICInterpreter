module Processor;

import Commands;
import Vars;

eReturnCodes Processor::_Init()
{
	RegisterCommand("PRINT", fPrint);
	RegisterCommand("NEWLINE", fNewLine);
	RegisterCommand("TAB", fTab);
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

		// setup variables
		if (e.cmd[0] == '$') {
			varStore.SetVar(e);
		} 
		else if (!found) {
			std::cerr << "Invalid command: " << e.cmd << std::endl;
			return eReturnCodes::UnknownCommand;
		}
	} 
	return eReturnCodes::Success;
}