import Parser;
import Processor;

/*
* Temp solution
* Should be replaced with CMD args later
*/
constexpr const char *FILE_NAME = "Foo.bas";

int main(int argc, char* argv[]) {
	Processor processor;

	Parser parser(FILE_NAME);
	parser.ParseCodeFile(processor.GetCommandStoreRef());

	processor.Run();
}