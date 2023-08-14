module;
export module defines;

import std;

export constexpr std::uint32_t BUFFER_SIZE = 256;

export enum class eReturnCodes {
	// Generic
	Failure,
	Success,

	// IO errors
	ReadFailure,
	WriteFailure,

	// CMD errors
	CommandFailure,
	UnknownCommand,
};

export struct CommandSpecification {
public:
	std::uint32_t line;		// Contains the line number of that command, for internal use only
	std::string cmd;		// Used command name
	std::string args;		// Arguments passed alongside the command

	// Helper: Easily visualize data in console
	eReturnCodes PrettyPrint();
};

// temp for later use
export struct ReturnSpecification {

};

export using funcargs_t = eReturnCodes(CommandSpecification, ReturnSpecification&);
export struct CommandLink {
public:
	std::string cmd;
	std::function<funcargs_t> func;
};

export using commandstore_t = std::vector<CommandSpecification>;
export using commandlinks_t = std::vector<CommandLink>;