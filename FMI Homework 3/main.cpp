#include <iostream>
#include "Trie.h"
#include <fstream>
/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Jordan Liliyanov Popov
* @idnumber 45166
* @task 3
* @compiler VC
*
*/
int countWords(const char*);
int evaluateText(const char*, Trie);
int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		Trie Dictionary;
		Dictionary.readFromFile(argv[1]);
		for (int i = 2; i < argc; ++i)
		{
			std::cout << evaluateText(argv[i], Dictionary) << std::endl;
		}
	}
	else
	{
		std::cerr << "No arguments for the program." << std::endl;
	}
	system("PAUSE");
	return 0;
}

int countWords(const char *fileName)
{
	char ch;
	int count = 1;
	std::ifstream f(fileName);
	while (f)
	{
		f.get(ch);
		if (ch == ' ')
		{
			count++;
		}
	}
	return count;
}

int evaluateText(const char *fileName, Trie Dictionary)
{
	int currentFilePointer = 0;
	char delimit[] = " \t\r\n\v\f.";
	int numberOfWords = countWords(fileName);
	int counter = 1;
	int wordLength = 0;
	int phraseLength = 0;
	int Value = 0;
	int oldValue = 0;
	const int MAX_WORD_LENGTH = 256;
	std::ifstream file;
	file.open(fileName);
	char word[MAX_WORD_LENGTH];
	while (counter <= numberOfWords)
	{
		file.clear();
		file.seekg(currentFilePointer, std::ios::beg);
		file.getline(word, MAX_WORD_LENGTH, ' ');
		counter++;
		if (strcmp(word, "") != 0)
		{
			char* wordOtherPart;
			char* wordCopy;
			char* otherPartRefactored;
			char* ptr;
			wordCopy = strtok_s(word, delimit, &wordOtherPart);
			wordLength = strlen(wordCopy);
			if (file)
			{
				Value += Dictionary.returnValue(wordCopy);
				oldValue = Value;
				for (int i = 1; i < Dictionary.getLongestPhrase(); i++)
				{
					char otherPart[MAX_WORD_LENGTH];
					file.getline(otherPart, MAX_WORD_LENGTH, ' ');
					otherPartRefactored = strtok_s(otherPart, delimit, &ptr);
					if (otherPartRefactored != nullptr)
					{
						strcat_s(wordCopy, strlen(wordCopy) + 3, " ");
						strcat_s(wordCopy, strlen(wordCopy) + strlen(otherPartRefactored) + 1, otherPartRefactored);
						phraseLength = strlen(wordCopy);
						int value = Dictionary.returnValue(wordCopy);
						Value += value;
					}
				}
			}
			if (oldValue != Value)
			{
				currentFilePointer += phraseLength + 1;
			}
			else
			{
				currentFilePointer += wordLength + 1;
			}
		}
	}
	return Value / numberOfWords;
}
