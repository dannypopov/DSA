#include "Trie.h"
#include <iostream>
Trie::Trie()
{
	init();
}
void Trie::init()
{
	m_root = new Node();
	m_root->isEnd = false;
	m_root->prefixCount = 0;
	longestPhrase = 1;
}

void Trie::insert(const char * word, int value)
{
	int countSpaces = 1;
	Node* current = m_root;
	++current->prefixCount;
	for (int i = 0; i < strlen(word); ++i)
	{
		int letterIndex = (int)word[i] - (int)'a';
		if (letterIndex == -65)
		{
			letterIndex = 26;
			++countSpaces;
		}
		if (current->m_children[letterIndex] == nullptr)
		{
			current->m_children[letterIndex] = new Node();
		}
		++current->m_children[letterIndex]->prefixCount;
		current = current->m_children[letterIndex];
	}
	if (countSpaces > longestPhrase)
	{
		longestPhrase = countSpaces;
	}
	current->isEnd = true;
	current->m_value = value;
}

bool Trie::search(const char * word)
{
	Node* current = m_root;
	for (int i = 0; i < strlen(word); ++i)
	{
		int letterIndex = (int)word[i] - (int)'a';
		if (current->m_children[letterIndex] == nullptr)
		{
			return false;
		}
		current = current->m_children[letterIndex];
	}
	return current->isEnd;
}

int Trie::returnValue(const char *word)
{
	Node* current = m_root;
	for (int i = 0; i < strlen(word); ++i)
	{
		int letterIndex = (int)word[i] - (int)'a';
		if (letterIndex == -65)
		{
			letterIndex = 26;
		}
		if (current->m_children[letterIndex] == nullptr)
		{
			return 0;
		}
		current = current->m_children[letterIndex];
	}
	return current->m_value;
}

void Trie::readFromFile(const char *fileName)
{

	const int MAX_LINE_LENGTH = 256;
	std::ifstream file;
	file.open(fileName);
	char line[MAX_LINE_LENGTH];
	while (file)
	{
		file.getline(line, MAX_LINE_LENGTH, '\n');
		if (file)
		{
			int tmpValue;
			char tmp[256];
			tmp[0] = '\0';
			char* token;
			char* otherPart;
			token = strtok_s(line, " ", &otherPart);
			int numberOfWords = 1;
			while (token != nullptr)
			{
				if ((token[0] >= '0'&& token[0] <= '9') || (token[0] == '-'))
				{
					tmpValue = atoi(token);
				}
				else
				{
					if (numberOfWords > 1)
					{
						int length = strlen(tmp);
						tmp[length] = ' ';
						tmp[length + 1] = '\0';
					}
					int nullIndex = strlen(tmp) + strlen(token) + 1;
					strcat_s(tmp, nullIndex, token);
					++numberOfWords;
				}
				token = strtok_s(nullptr, " ", &otherPart);
			}
			this->insert(tmp, tmpValue);
		}
	}
}

int Trie::getLongestPhrase() const
{
	return longestPhrase;
}
