module Parser;

Parser::Parser(std::string_view filePath, std::string_view cmdArgs) {
	std::swap(filePath, _filePath);
	std::swap(cmdArgs, _cmdArgs);
}

Parser::~Parser() {

}

eReturnCodes Parser::ParseCodeFile(commandstore_t& commandStore) {
	std::ifstream inputFile;
	inputFile.open(_filePath, std::ios::in);

	if (!inputFile.good()) {
		return eReturnCodes::ReadFailure;
	}

	std::uint32_t line = 1;
	std::string cmd;
	while (!inputFile.eof()) {
		char buf[BUFFER_SIZE];
		std::fill(&buf[0], &buf[BUFFER_SIZE], '\0');

		inputFile >> cmd;
		inputFile.getline(buf, BUFFER_SIZE, '\n');

		// ignore the first char, it's always a space
		commandStore.push_back({ line, std::move(cmd), std::string(&buf[1], BUFFER_SIZE-1) });
		++line;
	}

	if (DEBUG_INFO) {
		PrettyPrint(commandStore);
	}
	return eReturnCodes::Success;
}

eReturnCodes Parser::PrettyPrint(commandstore_t& commandStore) const {
	for (auto e : commandStore) {
		e.PrettyPrint();
	}
	return eReturnCodes::Success;
}