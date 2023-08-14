module defines;

eReturnCodes CommandSpecification::PrettyPrint() {
	std::clog << "Command: " << cmd << "\nLine: " << line << "\nArgs: " << args << "\n\n";
	return eReturnCodes::Success;
}