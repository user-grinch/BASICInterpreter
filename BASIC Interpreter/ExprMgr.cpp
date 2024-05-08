module ExprMgr;

import Util;

ExprMgr exprMgr;

//eReturnCodes VarStore::GetValue(const std::string& name, any_t& value) {
//	for (auto& e : _data) {
//		if (e.name == name)
//		{
//			value = e.value;
//			return eReturnCodes::VarFetchSuccess;
//		}
//	}
//
//	return eReturnCodes::VarFetchFailure;
//}
//
//eReturnCodes VarStore::SetValue(const std::string& name, any_t value) {
//	for (auto& e : _data) {
//		if (e.name == name)
//		{
//			e.value = value;
//			return eReturnCodes::VarFetchSuccess;
//		}
//	}
//	_data.emplace_back(name, value);
//	return eReturnCodes::VarSetSuccess;
//}
//
//eReturnCodes VarStore::GetVar(const std::string& name, std::string& val) {
//	any_t v;
//	if (varStore.GetValue(name, v) != eReturnCodes::VarFetchSuccess) {
//		return eReturnCodes::VarFetchFailure;
//	}
//
//	if (const auto pInt = std::get_if<int>(&v); pInt) {
//		val = std::to_string(*pInt);
//	}
//	else if (const auto pFloat = std::get_if<float>(&v); pFloat) {
//		val = std::to_string(*pFloat);
//	}
//	else {
//		val = std::get<std::string>(v);
//	}
//
//	return eReturnCodes::VarFetchSuccess;
//}
//
//eReturnCodes VarStore::SetVar(CommandSpecification &spec) {
//	std::vector<std::string> words = GetWords(spec.args, '=');
//
//	spec.cmd.erase(std::remove(spec.cmd.begin(), spec.cmd.end(), VAR_PREFIX), spec.cmd.end());
//	// TODO: Separete number types
//	if (IsNumber(words[1])) {
//		varStore.SetValue(spec.cmd, std::stof(words[1]));
//	}
//	else {
//		varStore.SetValue(spec.cmd, words[1]);
//	}
//
//	return eReturnCodes::Success;
//}