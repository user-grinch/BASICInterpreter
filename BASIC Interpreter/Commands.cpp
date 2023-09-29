module Commands;
import Vars;
import Util;

eReturnCodes fPrint(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	auto strs = GetWords(spec.args, ' ');
	
	std::string buf;
	for (std::string &str : strs) {
		// IsVar
		if (str[0] == '$') {
			auto new_logical_end = std::remove_if(str.begin(), str.end(), [](char a) { return a == '$'; });
			str.erase(new_logical_end, str.end());
			if (varStore.GetVar(str, buf) == eReturnCodes::Success) {
				str = buf;
			}
			else {
				std::cout << "Error: Unknown variable " << str << std::endl;
			}
		}
		std::cout << str << " ";
	}
	std::cout << std::endl;

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