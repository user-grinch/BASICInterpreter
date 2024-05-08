module Commands;
import Vars;
import Util;

eReturnCodes fRem(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	if (PRINT_COMMENTS) {
		std::string buf = "Comment: ";
		auto strs = GetWords(spec.args, ' ');
		for (std::string& str : strs) {
			buf += str;
			if (*(&str + 1) == "") {
				break;
			}
			else {
				buf += ' ';
			}
		}
		std::cout << buf << std::endl;
	}
	return eReturnCodes::Success;
}

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
		buf += str;
		if (*(&str + 1) == "") {
			break;
		} else {
			buf += ' ';
		}
	}
	std::cout << buf << std::endl;

	return eReturnCodes::Success;
}

eReturnCodes fInput(CommandSpecification spec, ReturnSpecification& rtnSpec) {
	auto strs = GetWords(spec.args, ' ');

	std::string buf = "";
	for (std::string& str : strs) {
		// Checking for var
		if (str[0] == VAR_PREFIX) {
			std::cout << buf;
			str.erase(std::remove(str.begin(), str.end(), VAR_PREFIX), str.end());
			std::string in;
			std::cin >> in;

			if (IsNumber(in)) {
				varStore.SetValue(str, std::stof(in));
			}
			else {
				varStore.SetValue(str, in);
			}
			break;
		}
		buf += str + " ";
	}
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