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
}

void Trie::insert(const char * word, int value)
{
	Node* current = m_root;
	++current->prefixCount;
	for (int i = 0; i < strlen(word); ++i)
	{
		int letterIndex = (int)word[i] - (int)'a';
		if (current->m_children[letterIndex] == nullptr)
		{
			current->m_children[letterIndex] = new Node();
		}
		++current->m_children[letterIndex]->prefixCount;
		current = current->m_children[letterIndex];
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
		if (current->m_children[letterIndex] == nullptr)
		{
			return 0;
		}
		current = current->m_children[letterIndex];
	}
	return current->m_value;
}
