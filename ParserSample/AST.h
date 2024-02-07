#pragma once

#include <vector>
#include <string>
using namespace std;


class ASTFunction;
class ASTParam;
class ASTProgram;
class ASTStatements;
class ASTStatement;
class ASTArgs;
class ASTWhile;
class ASTIf;
class ASTAssign;
class ASTFunctionCall;
class ASTBlockStatement;
class ASTDeclaration;
class ASTBooleanExprA;
class ASTBooleanExprB;
class ASTTerm;
class ASTExpr;
class ASTFactor;
class ASTElement;



//parent of all the nodes in the tree
class ASTNode
{
public:
	virtual void print(int depth) = 0;
private:

};

//this is the node for the program rule
class ASTProgram : public ASTNode
{
public:
	void addFunction(ASTFunction * theFunction);
	void print(int depth);
private:
	vector<ASTFunction*> functions;

};

//this is the node for the function rule
class ASTFunction : public ASTNode
{
public:
	void setParam(ASTParam* params_in);
	void setName(string name);
	void print(int depth);
	void setStatements(ASTNode* stmts);
private:
	ASTParam* params;
	string name;
	ASTNode* stmts;

};

//this is the node for the param rule. Note that the ith type corresponds to the ith name
class ASTParam : public ASTNode
{
public:
	void addParam(string type, string name);
	void print(int depth);
private:
	vector<string> types;
	vector<string> names;


};

class ASTStatements : public ASTNode
{
public:
	void addStatement(ASTStatement* stmt);
	void print(int depth);
private:
	vector<ASTStatement*> statements;
};

class ASTStatement : public ASTNode
{
public:
	void setAssign(ASTAssign* assign);
	void print(int depth);
private:
	ASTAssign* assign;
};

class ASTAssign : public ASTNode
{
public:
	void setLeft(string lhs);
	void setRight(ASTFactor* rhs);
	void print(int depth);
private:
	string left;	// might need to change this to an element
	ASTFactor* right;
};

class ASTFactor : public ASTNode
{
public:
	void setElement(ASTElement* element);
	void setFactor(ASTFactor* factor);
	void print(int depth);
private:
	ASTElement* element;
	ASTFactor* factor;
};

class ASTElement : public ASTNode
{
public:
	void setValue(string value);
	void print(int depth);
private:
	string value;
};