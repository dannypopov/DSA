#ifndef TRIE_H
#define TRIE_H
struct Node
{
	Node* m_children[27];
	bool isEnd;
	int m_value;
	int prefixCount;
};
class Trie
{
private:
	Node* m_root;
public:
	Trie();
	void init();
	void insert(const char*, int);
	bool search(const char*);
	int returnValue(const char*);

};
#endif // !TRIE_H
