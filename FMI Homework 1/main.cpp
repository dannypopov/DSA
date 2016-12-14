#include <iostream>
#include <fstream>
#include "Operator.h"
#include "Operators.h"
#include "myStack.h"
/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Jordan Liliyanov Popov
* @idnumber 45166
* @task 1
* @compiler VC
*
*/
char* transformeToPostfix(char*);
char* readPrefixExpression(char*);
double evaluatePostfix(Operators, char*);
int prefixSizeFromFile(const char*);
int performOperation(char, int, int);
bool validatePrefix(char*);

int main(int argc, char *argv[])
{

	char* prefix;
	char* prefixCoppy;
	char* postfix;
	if (argc != 1)
	{
		Operators arrayOfOperators;
		arrayOfOperators.readFromFile(argv[2]);
		prefix = readPrefixExpression(argv[1]);
		prefixCoppy = readPrefixExpression(argv[1]);
		if (validatePrefix(prefix))
		{
			postfix = transformeToPostfix(prefixCoppy);
			std::cout << postfix << std::endl;
			std::cout << evaluatePostfix(arrayOfOperators, postfix) << "\n";
		}
	}
	else
	{
		std::cerr << "No arguments for the program." << std::endl;
	}
	system("PAUSE");
	return 0;
}

double evaluatePostfix(Operators operatorsArray, char* postfixExpression)
{
	Stack<int> evaluatingStack;
	char* copyPostfix = postfixExpression;
	char* token;
	char* otherpart;
	int result = 0;
	token = strtok_s(copyPostfix, " ", &otherpart);
	while (token != nullptr)
	{
		if (!atoi(token) == 0)
		{
			evaluatingStack.push(atoi(token));
		}
		else
		{
			int lNumber;
			int rNumber;
			evaluatingStack.pop(rNumber);
			evaluatingStack.pop(lNumber);
			for (int i = 0; i < operatorsArray.getIndex(); ++i)
			{
				if (token[0] == operatorsArray[i].getSymbol())
				{
					result = performOperation(operatorsArray[i].getOperator(), lNumber, rNumber);
				}
			}
			evaluatingStack.push(result);
		}
		token = strtok_s(nullptr, " ", &otherpart);
	}
	evaluatingStack.pop(result);
	return result;
}

char* transformeToPostfix(char* prefixExpression)
{
	Stack<char*> prefix;
	Stack<char*> postfix;
	char* prefixExpressionCoppy = prefixExpression;
	char* postfixExpression;
	char *token;
	char* otherpart;
	token = strtok_s(prefixExpressionCoppy, " ", &otherpart);
	while (token != nullptr)
	{
		prefix.push(token);
		token = strtok_s(nullptr, " ", &otherpart);
	}
	while (!prefix.empty())
	{
		char* ch;
		prefix.pop(ch);
		if (!atoi(ch) == 0)
		{
			postfix.push(ch);
		}
		else
		{
			char* operandOne;
			char* operandTwo;
			postfix.pop(operandOne);
			postfix.pop(operandTwo);
			int resultSize = strlen(operandOne) + strlen(operandTwo) + strlen(ch) + 3; // 1 for '\0' and 2 for the spaces !
			char* result = new char[resultSize];
			result[resultSize] = '\0';
			strcpy_s(result, resultSize, operandOne);
			strcat_s(result, resultSize, " ");
			strcat_s(result, resultSize, operandTwo);
			strcat_s(result, resultSize, " ");
			strcat_s(result, resultSize, ch);
			postfix.push(result);
		}
	}
	postfix.pop(postfixExpression);
	return postfixExpression;
}
char* readPrefixExpression(char* fileName)
{
	int lineSize = prefixSizeFromFile(fileName) + 1;
	char* line = new char[lineSize];
	line[lineSize] = '\0';
	std::ifstream file;
	file.open(fileName);
	file.getline(line, lineSize);
	return line;
}
int prefixSizeFromFile(const char* fileName)
{
	std::ifstream file;
	file.open(fileName);
	int size = 0;
	char ch;
	while (file.get(ch))
	{
		if (ch != '\n')
		{
			size++;
		}
	}
	file.close();
	return size;
}
int performOperation(char operation, int operand1, int operand2)
{
	if (operation == '+')
	{
		return (operand1 + operand2);
	}
	else if (operation == '-')
	{
		return (operand1 - operand2);
	}
	else if (operation == '*')
	{
		return (operand1 * operand2);
	}
	else if (operation == '/')
	{
		return (operand1 / operand2);
	}
}
bool validatePrefix(char* prefix)
{
	char* prefixCopy = prefix;
	int counter = 1;
	char* token;
	char* otherpart;
	token = strtok_s(prefixCopy, " ", &otherpart);
	while (token != nullptr)
	{
		if (counter == 0)
		{
			return false;
		}
		if (!atoi(token) == 0)
		{
			counter--;
		}
		else
		{
			counter++;
		}
		token = strtok_s(nullptr, " ", &otherpart);
	}
	if (counter == 0)
	{
		return true;
	}
	std::cerr << "Error\n";
	exit(420);
	return false;
}
