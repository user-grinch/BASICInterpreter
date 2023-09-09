module Vars;

eReturnCodes VarStore::GetValue(const std::string& name, std::any& value) {
	for (auto& e : _data) {
		if (name == e.name) {
			value = e.value;
			return eReturnCodes::VarFetchSuccess;
		}
	}

	return eReturnCodes::VarFetchFailure;
}

eReturnCodes VarStore::SetValue(std::string&& name, std::string&& value) {
	_data.emplace_back(name, value);
	return eReturnCodes::VarSetSuccess;
}