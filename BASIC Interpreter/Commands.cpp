module Commands;

eReturnCodes fPrint(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	std::cout << spec.args << std::endl;
	return eReturnCodes::Success;
}

eReturnCodes fNewLine(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	std::cout << "\n";
	return eReturnCodes::Success;
}

eReturnCodes fTab(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	std::cout << "\t";
	return eReturnCodes::Success;
}