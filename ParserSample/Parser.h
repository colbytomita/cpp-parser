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
	ASTBooleanExprA* rdpBooleanExprA();
	ASTBooleanExprB* rdpBooleanExprB();
	ASTTerm* rdpTerm();
	ASTExpr* rdpExpr();
	ASTFactor* rdpFactor();
	ASTElement* rdpElement();
	ASTIf* rdpIf();
	ASTWhile* rdpWhile();
	ASTFunctionCall* rdpFunctionCall();
	ASTArgs* rdpArgs();
	ASTBlockStatement* rdpBlockStatement();
	ASTDeclaration* rdpDeclaration();

	bool getErrorDetected();
private:
	bool errorDetected;
	Scanner* scan;
	ASTProgram* program;
};