module;
export module Processor;

import std;
import defines;

/*
* Core processing class
* Excutes commands from the internal store
*/
export class Processor {
private:
	commandstore_t _commandStore; // Stores BASIC script commands in a list
	commandlinks_t _commandRegistry; // Link commands to their function callbacks


	/*
	* Fills commandRegistry with command definations
	*/
	eReturnCodes _Init();
public:
	Processor() {}
	~Processor() {}

	/*
	* Returns reference to internal command store struct
	*/
	commandstore_t& GetCommandStoreRef() { return _commandStore; }

	/*
	* Registers a command to the registry
	*/
	eReturnCodes RegisterCommand(std::string&& funcName, std::function<funcargs_t> func);

	/*
	* Runs commands one by one
	*/
	eReturnCodes Run();
};