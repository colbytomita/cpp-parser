#include "Scanner.h"
#include "Parser.h"
#include "AST.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{


	if (argc < 2)
	{
		cout << "Usage: <executable name> <filename>";
	}

	Parser p(argv[1]);
	ASTProgram * prog = p.parse();
	if (!p.getErrorDetected())
	{
		prog->print(0);
	}

	cin.ignore();
}


