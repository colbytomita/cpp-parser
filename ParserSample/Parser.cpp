#include "Parser.h"

void Parser::printError(string code, string message, int line)
{
	if(!errorDetected)
		cout << "Error: "<< code << " on line: " << line << " " << message << ". Recieved " << scan->toString(scan->currentTokenType()) << " \"" << scan->currentTokenString() << "\"." << endl;
	errorDetected = true;
}

Parser::Parser(string fname)
{
	scan = new Scanner(fname);
	errorDetected = false;
	program = 0;
}

bool Parser::getErrorDetected()
{
	return errorDetected;
}

ASTProgram* Parser::parse()
{
	program = rdpProgram();
	return program;
}

ASTProgram* Parser::rdpProgram()
{
	ASTProgram* theProg = new ASTProgram();

	while (scan->currentTokenType() == STRING) //notice we don't advance. You only advance when you are "eating" the terminal
	{
		theProg->addFunction(rdpFunction());
	}

	//so if its not a string and the final isn't empty...
	if (scan->currentTokenType() != NONE && scan->currentTokenType() != ENDOFFILE)
	{
		printError("ASTProgram01","Expected String or EOF recieved "+scan->toString(scan->currentTokenType()),scan->getLine());
	}
	return theProg;
}

ASTFunction* Parser::rdpFunction()
{
	//create the node
	ASTFunction* theFunction = new ASTFunction();

	//check that the first thing is a string
	string name;
	if (scan->currentTokenType() == STRING)
	{
		name = scan->currentTokenString(); //get it
		theFunction->setName(name); //set it
		scan->advance(); // advance the scanner to look at the next thing
	}
	else //if not a string through an error
	{
		printError("ASTFunction01", "Expected String for function name", scan->getLine());

		scan->advance(); // always advance in an error, otherwise you might get stuck in a loop
	}

	//eat the paren
	if (scan->currentTokenType() == LPAREN)
	{
		scan->advance();
	}
	else
	{
		printError("ASTFunction02", "Expected LPAREN for function name", scan->getLine());
		scan->advance(); // always advance in an error, otherwise you might get stuck in a loop
	}

	//call rdp param. I let param decide if there is any params to read.
	theFunction->setParam(rdpParam());

	//but notice that the function still eats the rparen
	if (scan->currentTokenType() == RPAREN)
	{
		scan->advance();
	}
	else
	{
		printError("ASTFunction03", "Expected RPAREN for function name", scan->getLine());
		scan->advance(); // always advance in an error, otherwise you might get stuck in a loop
	}


	//eat the lbrace
	if (scan->currentTokenType() == LBRACE)
	{
		scan->advance();
	}
	else
	{
		printError("ASTFunction04", "Expected LBRACE for function name", scan->getLine());
		scan->advance(); // always advance in an error, otherwise you might get stuck in a loop
	}



	//this is approximately the function my code has 
	//theFunction->setStatements(rdpStatements());

	if (scan->currentTokenType() == RBRACE)
	{
		scan->advance();
	}
	else
	{
		printError("ASTFunction05", "Expected RBRACE for function name", scan->getLine());
		scan->advance(); // always advance in an error, otherwise you might get stuck in a loop
	}

	return theFunction;
}

ASTParam* Parser::rdpParam()
{
	ASTParam* params = new ASTParam();

	while (scan->currentTokenType() == STRING)
	{
		string type = scan->currentTokenString();
		scan->advance();
		string name;
		if (scan->currentTokenType() == STRING)
		{
			name = scan->currentTokenString();
			scan->advance();
		}
		else
		{
			printError("ASTParams01", "Expected String for for param name", scan->getLine());

			scan->advance(); // always advance in an error, otherwise you might get stuck in a loop
		}

		params->addParam(type, name);

		if (scan->currentTokenType() == COMMA)
		{
			scan->advance();
		}
		else if (scan->currentTokenType() == RPAREN)
		{
			//handled by astfunction
		}
		else
		{
			printError("ASTParams02", "Expected COMMA or RPAREN", scan->getLine());
			scan->advance(); // always advance in an error, otherwise you might get stuck in a loop

		}
	}

	return params;
}

//use scan->currentStatus(); to see the scanner's current status (what it is looking at)
