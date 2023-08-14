module;
export module Parser;

import std;
import defines;

/*
* Handles parsing BASIC code
* Format:
*		<COMMAND_NAME> <ARGUMENTS...> ( no line numbers )
*/
export class Parser {
private:
	std::string_view _filePath;		// Input file path
	std::string_view _cmdArgs;		// Store the commnad line args passed to the program

public:
	Parser(std::string_view filePath, std::string_view cmdArgs = "");
	~Parser();

	/*
	* Reads BASIC code file and fills internal structures
	* Must be called externally to initiate parsing
	*/
	eReturnCodes ParseCodeFile(commandstore_t& commandStore);

	/*
	* Prints the command spec in a prettfied manner to the console
	* For internal use only
	*/
	eReturnCodes PrettyPrint(commandstore_t& commandStore) const;
};

