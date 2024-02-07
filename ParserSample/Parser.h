#pragma once

#include <iostream>
#include <string>
#include "Scanner.h"
#include "AST.h"
using namespace std;



class Parser
{
public:
	Parser(string fname);
	ASTProgram* parse();

	void printError(string code, string message, int line);

	ASTProgram* rdpProgram();
	ASTFunction* rdpFunction();
	ASTParam* rdpParam();
	ASTStatements* rdpStatements();
	ASTStatement* rdpStatement();
	ASTAssign* rdpAssign();
	ASTFactor* rdpFactor();
	ASTElement* rdpElement();

	bool getErrorDetected();
private:
	bool errorDetected;
	Scanner* scan;
	ASTProgram* program;
};