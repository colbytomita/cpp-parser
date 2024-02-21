#pragma once

#include <vector>
#include <string>
using namespace std;


class ASTFunction;	//
class ASTParam;	//
class ASTProgram;	//
class ASTStatements;	//
class ASTStatement;	//
class ASTArgs;	//
class ASTWhile;	//
class ASTIf;	//
class ASTAssign;	//
class ASTFunctionCall;	//
class ASTBlockStatement;	//
class ASTDeclaration;	//
class ASTBooleanExprA;	//
class ASTBooleanExprB;	//	
class ASTTerm;	//
class ASTExpr;	//
class ASTFactor;	//
class ASTElement;	//



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
	void setStmt(ASTNode* stmt);
	void print(int depth);
private:
	ASTNode* stmt;
};

class ASTAssign : public ASTNode
{
public:
	void setLeft(string lhs);
	void setRight(ASTBooleanExprA* rhs);
	void print(int depth);
private:
	string left;
	ASTBooleanExprA* right;
};

class ASTBooleanExprA : public ASTNode
{
public:
	void setLeftBoolB(ASTBooleanExprB* leftBoolB);
	void addRightBoolB(ASTBooleanExprB* rightBoolB);
	void addOp(string op);
	void print(int depth);
private:
	ASTBooleanExprB* leftBoolB;
	vector<ASTBooleanExprB*> rightBoolB;
	vector<string> ops;
};

class ASTBooleanExprB : public ASTNode
{
public:
	void setLeftTerm(ASTTerm* leftTerm);
	void addRightTerm(ASTTerm* rightTerm);
	void addOp(string op);
	void print(int depth);
private:
	ASTTerm* leftTerm;
	vector<ASTTerm*> rightTerm;
	vector<string> ops;
};

class ASTTerm : public ASTNode
{
public:
	void setLeftExpr(ASTExpr* leftExpr);
	void addRightExpr(ASTExpr* rightExpr);
	void addOp(string op);
	void print(int depth);
private:
	ASTExpr* leftExpr;
	vector<ASTExpr*> rightExpr;
	vector<string> ops;
};

class ASTExpr : public ASTNode
{
public:
	void setLeftFactor(ASTFactor* leftFactor);
	void addRightFactor(ASTFactor* rightFactor);
	void addOp(string op);
	void print(int depth);
private:
	ASTFactor* leftFactor;
	vector<ASTFactor*> rightFactor;
	vector<string> ops;
};

class ASTFactor : public ASTNode
{
public:
	void setElement(ASTElement* element);
	void setBoolA(ASTBooleanExprA* boolA);
	void print(int depth);
private:
	ASTElement* element;
	ASTBooleanExprA* boolA;
};

class ASTElement : public ASTNode
{
public:
	void setValue(string value);
	void print(int depth);
private:
	string value;
};

class ASTIf : public ASTNode
{
public:
	void setBooleanExprA(ASTBooleanExprA* boolExprA);
	void setStatement(ASTStatement* stmt);
	void setBlockStatement(bool type);
	void print(int depth);
private:
	ASTBooleanExprA* boolExprA;
	ASTStatement* stmt;
	bool isBlockStatement;
};

class ASTWhile : public ASTNode
{
public:
	void setBooleanExprA(ASTBooleanExprA* boolExprA);
	void setStatement(ASTStatement* stmt);
	void setBlockStatement(bool type);
	void print(int depth);
private:
	ASTBooleanExprA* boolExprA;
	ASTStatement* stmt;
	bool isBlockStatement;
};

class ASTFunctionCall : public ASTNode
{
public:
	void setName(string name);
	void setArgs(ASTArgs* funcArgs);
	void print(int depth);
private:
	string name;
	ASTArgs* funcArgs;
};

class ASTArgs : public ASTNode
{
public:
	void addArg(ASTBooleanExprA* arg);
	void print(int depth);
private:
	vector<ASTBooleanExprA*> args;	// might need to change this
};

class ASTBlockStatement : public ASTNode
{
public:
	void setStatements(ASTStatements* stmts);
	void print(int depth);
private:
	ASTStatements* stmts;
};

class ASTDeclaration : public ASTNode
{
public:
	void setType(string type);
	void setName(string name);
	void setValue(ASTBooleanExprA* value);
	void print(int depth);
private:
	string type;
	string name;
	ASTBooleanExprA* value;
};