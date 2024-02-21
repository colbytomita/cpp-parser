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

void ASTStatement::setStmt(ASTNode* stmt_in)
{
	stmt = stmt_in;
}

void ASTAssign::setLeft(string left_in)
{
	left = left_in;
}

void ASTAssign::setRight(ASTBooleanExprA* right_in)
{
	right = right_in;
}

void ASTBooleanExprA::setLeftBoolB(ASTBooleanExprB* left_in)
{
	leftBoolB = left_in;
}

void ASTBooleanExprA::addRightBoolB(ASTBooleanExprB* right_in)
{
	rightBoolB.push_back(right_in);
}

void ASTBooleanExprA::addOp(string op_in)
{
	ops.push_back(op_in);
}

void ASTBooleanExprB::setLeftTerm(ASTTerm* left_in)
{
	leftTerm = left_in;
}

void ASTBooleanExprB::addRightTerm(ASTTerm* right_in)
{
	rightTerm.push_back(right_in);
}

void ASTBooleanExprB::addOp(string op_in)
{
	ops.push_back(op_in);
}

void ASTTerm::setLeftExpr(ASTExpr* left_in)
{
	leftExpr = left_in;
}

void ASTTerm::addRightExpr(ASTExpr* right_in)
{
	rightExpr.push_back(right_in);
}

void ASTTerm::addOp(string op_in)
{
	ops.push_back(op_in);
}

void ASTExpr::setLeftFactor(ASTFactor* left_in)
{
	leftFactor = left_in;
}

void ASTExpr::addRightFactor(ASTFactor* right_in)
{
	rightFactor.push_back(right_in);
}

void ASTExpr::addOp(string op_in)
{
	ops.push_back(op_in);
}

void ASTFactor::setBoolA(ASTBooleanExprA* bool_in)
{
	boolA = bool_in;
}

void ASTFactor::setElement(ASTElement* element_in)
{
	element = element_in;
}

void ASTElement::setValue(string value_in)
{
	value = value_in;
}

void ASTIf::setBooleanExprA(ASTBooleanExprA* bool_in)
{
	boolExprA = bool_in;
}

void ASTIf::setStatement(ASTStatement* stmt_in)
{
	stmt = stmt_in;
}

void ASTIf::setBlockStatement(bool isBlockStatement_in)
{
	isBlockStatement = isBlockStatement_in;
}

void ASTWhile::setBooleanExprA(ASTBooleanExprA* bool_in)
{
	boolExprA = bool_in;
}

void ASTWhile::setStatement(ASTStatement* stmt_in)
{
	stmt = stmt_in;
}

void ASTWhile::setBlockStatement(bool isBlockStatement_in)
{
	isBlockStatement = isBlockStatement_in;
}

void ASTFunctionCall::setName(string name_in)
{
	name = name_in;
}

void ASTFunctionCall::setArgs(ASTArgs* args_in)
{
	funcArgs = args_in;
}

void ASTArgs::addArg(ASTBooleanExprA* arg_in)
{
	args.push_back(arg_in);
}

void ASTBlockStatement::setStatements(ASTStatements* stmts_in)
{
	stmts = stmts_in;
}

void ASTDeclaration:: setType(string type_in)
{
	type = type_in;
}

void ASTDeclaration::setName(string name_in)
{
	name = name_in;
}

void ASTDeclaration::setValue(ASTBooleanExprA* value_in)
{
	value = value_in;
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
	stmts->print(depth);
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
		cout << "    ";
	}
	stmt->print(depth);
}

void ASTAssign::print(int depth)
{
	cout << left << " = ";
	right->print(depth);
	cout << ";\n";
}

void ASTBooleanExprA::print(int depth)
{
	leftBoolB->print(depth);
	for (int i = 0; i < rightBoolB.size(); i++)
	{
		cout << " " << ops[i] << " ";
		rightBoolB[i]->print(depth);
	}
}

void ASTBooleanExprB::print(int depth)
{
	leftTerm->print(depth);
	for (int i = 0; i < rightTerm.size(); i++)
	{
		cout << " " << ops[i] << " ";
		rightTerm[i]->print(depth);
	}
}

void ASTTerm::print(int depth)
{
	leftExpr->print(depth);
	for (int i = 0; i < rightExpr.size(); i++)
	{
		cout << " " << ops[i] << " ";
		rightExpr[i]->print(depth);
	}
}

void ASTExpr::print(int depth)
{
	leftFactor->print(depth);
	for (int i = 0; i < rightFactor.size(); i++)
	{
		cout << " " << ops[i] << " ";
		rightFactor[i]->print(depth);
	}
}

void ASTFactor::print(int depth)
{
	if (boolA != NULL)
	{
		cout << "(";
		boolA->print(depth);
		cout << ")";
	}
	else
	{
		element->print(depth);
	}
}

void ASTElement::print(int depth)
{
	cout << value;
}

void ASTIf::print(int depth)
{
	cout << "if (";
	boolExprA->print(depth);
	cout << ")\n";
	if(!isBlockStatement)
		cout << "    ";
	stmt->print(depth);
	
}

void ASTWhile::print(int depth)
{
	cout << "while (";
	boolExprA->print(depth);
	cout << ")\n";
	if(!isBlockStatement)
		cout << "    ";
	stmt->print(depth);
}

void ASTFunctionCall::print(int depth)
{
	cout << name << "(";
	funcArgs->print(depth);
	cout << ")";
}

void ASTArgs::print(int depth)
{
	for (int i = 0; i < args.size(); i++)
	{
		args[i]->print(depth);
		if (i != args.size() - 1)
		{
			cout << ", ";
		}
	}
}

void ASTBlockStatement::print(int depth)
{
	cout << "{\n";
	stmts->print(depth);
	for (int i = 0; i < depth; i++)
	{
		cout << "    ";
	}
	cout << "}\n";
}

void ASTDeclaration::print(int depth)
{
	cout << type << " " << name;
	if (value != NULL)
	{
		cout << " = ";
		value->print(depth);

	}
	cout << ";\n";
}


//this part is for determining correct semantics





//this part is for outputting the bytecode