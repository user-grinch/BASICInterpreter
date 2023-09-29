module Vars;

import Util;

VarStore varStore;

eReturnCodes VarStore::GetValue(const std::string& name, any_t& value) {
	for (auto& e : _data) {
		if (name.compare(e.name.c_str())) {
			value = e.value;
			return eReturnCodes::VarFetchSuccess;
		}
	}

	return eReturnCodes::VarFetchFailure;
}

eReturnCodes VarStore::SetValue(const std::string& name, any_t value) {
	_data.emplace_back(name, value);
	return eReturnCodes::VarSetSuccess;
}

eReturnCodes VarStore::GetVar(const std::string& name, std::string& val) {
	any_t v;
	varStore.GetValue(name, v);

	if (const auto pInt = std::get_if<int>(&v); pInt) {
		val = std::to_string(*pInt);
	}
	else if (const auto pFloat = std::get_if<float>(&v); pFloat) {
		val = std::to_string(*pFloat);
	}
	else {
		val = std::get<std::string>(v);
	}

	return eReturnCodes::Success;
}

eReturnCodes VarStore::SetVar(CommandSpecification &spec) {
	std::vector<std::string> words = GetWords(spec.args, '=');

	auto new_logical_end = std::remove(spec.cmd.begin(), spec.cmd.end(), '$');
	spec.cmd.erase(new_logical_end, spec.cmd.end());
	// TODO: Separete number types
	if (IsNumber(words[1])) {
		varStore.SetValue(spec.cmd, std::stof(words[1]));
	}
	else {
		varStore.SetValue(spec.cmd, words[1]);
	}

	return eReturnCodes::Success;
}