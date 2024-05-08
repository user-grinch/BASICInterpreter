module;
export module Commands;

import defines;

export {
	eReturnCodes fPrint(CommandSpecification spec, ReturnSpecification& rtnSpec);
	eReturnCodes fInput(CommandSpecification spec, ReturnSpecification& rtnSpec);

	eReturnCodes fNewLine(CommandSpecification spec, ReturnSpecification& rtnSpec);
	eReturnCodes fTab(CommandSpecification spec, ReturnSpecification& rtnSpec);
	eReturnCodes fRem(CommandSpecification spec, ReturnSpecification& rtnSpec);
}