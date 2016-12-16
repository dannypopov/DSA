#include <iostream>
#include "Trie.h"
#include <fstream>
int countWords(const char*);
int evaluateText(const char*, Trie);
int main()
{
	Trie Test;
	Test.init();
	Test.readFromFile("test.txt");
	std::cout << evaluateText("test1.txt", Test) << std::endl;
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
	int numberOfWords = countWords(fileName);
	int wordLength = 0;
	int phraseLength = 0;
	int Value = 0;
	int oldValue = 0;
	const int MAX_WORD_LENGTH = 256;
	std::ifstream file;
	file.open(fileName);
	char word[MAX_WORD_LENGTH];
	while (file)
	{
		int currentFilePointer = file.tellg();
		file.getline(word, MAX_WORD_LENGTH, ' ');
		wordLength = strlen(word);
		if (file)
		{
			Value += Dictionary.returnValue(word);
			oldValue = Value;
			for (int i = 1; i < Dictionary.getLongestPhrase(); i++)
			{
				char otherPart[MAX_WORD_LENGTH];
				file.getline(otherPart, MAX_WORD_LENGTH, ' ');
				strcat_s(word, strlen(word) + 3, " ");
				strcat_s(word, strlen(word) + strlen(otherPart) + 1, otherPart);
				phraseLength = strlen(word);
				int value = Dictionary.returnValue(word);
				Value += value;
			}
		}
		if (oldValue != Value)
		{
			file.seekg(currentFilePointer + phraseLength + 1, std::ios::beg);
		}
		else
		{
			file.seekg(currentFilePointer + wordLength + 1, std::ios::beg);
		}
	}
	return Value / numberOfWords;
}
