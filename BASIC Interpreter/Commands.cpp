module Commands;
import Vars;
import Util;

eReturnCodes fPrint(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	auto strs = GetWords(spec.args, ' ');
	
	std::string buf = "";
	for (std::string &str : strs) {
		
		// Checking for var & printing it's value
		if (str[0] == VAR_PREFIX) {
			str.erase(std::remove(str.begin(), str.end(), VAR_PREFIX), str.end());
			if (varStore.GetVar(str, str) != eReturnCodes::VarFetchSuccess) {
				std::cerr << "Error: Unknown variable " << str << std::endl;
				return eReturnCodes::VarFetchFailure;
			}
		}
		buf += str + " ";
	}
	std::cout << buf << std::endl;

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