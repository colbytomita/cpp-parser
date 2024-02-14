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

void ASTBooleanExprA::setRightBoolB(ASTBooleanExprB* right_in)
{
	rightBoolB = right_in;
}

void ASTBooleanExprA::setOp(string op_in)
{
	op = op_in;
}

void ASTBooleanExprB::setLeftTerm(ASTTerm* left_in)
{
	leftTerm = left_in;
}

void ASTBooleanExprB::setRightTerm(ASTTerm* right_in)
{
	rightTerm = right_in;
}

void ASTBooleanExprB::setOp(string op_in)
{
	op = op_in;
}

void ASTTerm::setLeftExpr(ASTExpr* left_in)
{
	leftExpr = left_in;
}

void ASTTerm::setRightExpr(ASTExpr* right_in)
{
	rightExpr = right_in;
}

void ASTTerm::setOp(string op_in)
{
	op = op_in;
}

void ASTExpr::setLeftFactor(ASTFactor* left_in)
{
	leftFactor = left_in;
}

void ASTExpr::setRightFactor(ASTFactor* right_in)
{
	rightFactor = right_in;
}

void ASTExpr::setOp(string op_in)
{
	op = op_in;
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

void ASTWhile::setBooleanExprA(ASTBooleanExprA* bool_in)
{
	boolExprA = bool_in;
}

void ASTWhile::setStatement(ASTStatement* stmt_in)
{
	stmt = stmt_in;
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
	if (rightBoolB != NULL)
	{
		leftBoolB->print(depth);
		cout << " " << op << " ";
		rightBoolB->print(depth);
	}
	else
	{
		leftBoolB->print(depth);
	}
}

void ASTBooleanExprB::print(int depth)
{
	if (rightTerm != NULL)
	{
		leftTerm->print(depth);
		cout << " " << op << " ";
		rightTerm->print(depth);
	}
	else
	{
		leftTerm->print(depth);
	}
}

void ASTTerm::print(int depth)
{
	if (rightExpr != NULL)
	{
		leftExpr->print(depth);
		cout << " " << op << " ";
		rightExpr->print(depth);
	}
	else
	{
		leftExpr->print(depth);
	}
}

void ASTExpr::print(int depth)
{
	if (rightFactor != NULL)
	{
		leftFactor->print(depth);
		cout << " " << op << " ";
		rightFactor->print(depth);
	}
	else
	{
		leftFactor->print(depth);
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

void ASTIf::print(int depth)	// this shouldnt have curly braces, look at the block statements
{
	cout << "if (";
	boolExprA->print(depth);
	cout << ")\n";
	
	stmt->print(depth);
	
}

void ASTWhile::print(int depth)
{
	cout << "while (";
	boolExprA->print(depth);
	cout << ")\n";
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
	cout << type << " " << name << " = ";
	value->print(depth);
}


//this part is for determining correct semantics





//this part is for outputting the bytecode