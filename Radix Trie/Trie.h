#ifndef TRIE_H
#define TRIE_H
class Node
{
private:
	Node** m_children;
	char* m_data;
	int m_value;
	int numberOfChildren;
	void copyData(const Node&);
	void unleashData();
public:
	Node(char* data = nullptr, int value = -1);
	Node(const Node&);
	Node& operator=(const Node&);
	~Node();
	int getValue()const;
	const char* getData() const;
	void setData(const char*);
	void setValue(int);
};
class Trie
{
private:
	Node* m_root;
	void unleashData(Node*);
public:
	Trie();
	~Trie();
	void addWord(const char*, int);
	bool searchWord(const char*);
	void deleteWord(const char*);
	int returnValue(const char*);

};
#endif // !TRIE_H
