#include "AST.h"

#include <iostream>
#include <string>
using namespace std;

//this part is the functions for creating the tree

void ASTProgram::addFunction(ASTFunction* theFunction)
{
	functions.push_back(theFunction);
}

void ASTFunction::setName(string name_in)
{
	name = name_in;
}

void ASTFunction::setParam(ASTParam * theParam)
{
	params = theParam;
}

void ASTFunction::setStatements(ASTNode* stmts)
{
	this->stmts = stmts;
}

void ASTParam::addParam(string type, string name)
{
	types.push_back(type);
	names.push_back(name);
}

void ASTStatements::addStatement(ASTStatement* stmt)
{
	statements.push_back(stmt);
}

void ASTAssign::setLeft(string left_in)
{
	left = left_in;
}

void ASTAssign::setRight(ASTFactor* right_in)
{
	right = right_in;
}

void ASTFactor::setFactor(ASTFactor* factor_in)
{
	factor = factor_in;
}

void ASTFactor::setElement(ASTElement* element_in)
{
	element = element_in;
}

void ASTElement::setType(string type_in)
{
	type = type_in;
}


//this part is the functions for printing the tree

void ASTProgram::print(int depth)
{
	for (int i = 0; i < functions.size(); i++)
	{
		functions[i]->print(0);

		if(i!= functions.size() -1 ) 
			cout << "\n";
	}
}

void ASTFunction::print(int depth)
{
	cout << name << "(";
	params->print(0);
	cout << ")\n";
	cout << "{\n";
	//stmts->print(depth + 1);
	cout << "}\n";
}


void ASTParam::print(int depth)
{
	for (int i = 0; i < names.size(); i++)
	{
		cout << types[i] << " " << names[i];
		if (i != names.size() - 1)
		{
			cout << ", ";
		}
	}
}


void ASTStatements::print(int depth)
{
	for (int i = 0; i < statements.size(); i++)
	{
		statements[i]->print(depth + 1);
	}
}

void ASTStatement::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "  ";
	}
	cout << "Statement\n";
}

void ASTAssign::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "  ";
	}
	cout << "Assign\n";
}

void ASTFactor::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "  ";
	}
	cout << "Factor\n";
}

void ASTElement::print(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "  ";
	}
	cout << "Element\n";
}



//this part is for determining correct semantics





//this part is for outputting the bytecode