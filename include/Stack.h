#include<iostream>

using namespace std;

class Stack
{
public:
	Stack();
	void Pop();
	void Push(char);
	~Stack();
private:
	char *stack;
	int stack_top;
};

