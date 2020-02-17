#include <iostream>
using namespace std;

struct node
{
	int value;
	node *next;
};


class Stack_link_list
{
private:
	node *top, *stack, *temp;
public:
	Stack_link_list()
	{
		top = NULL;
		stack = NULL;
		temp = NULL;
	}
	~Stack_link_list()
	{
		temp = stack;
		while(temp != top)
		{
			temp = stack;
			stack = stack->next;
			delete temp;  
		}
		delete top;
	}

	void push()
	{
		if(stack == NULL)
		{
			stack = new node;
			cin >> stack->value;
			stack->next = NULL;
			top = stack;
			return;
		}
		temp = stack;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new node;
		cin >> temp->next->value;
		temp->next->next = NULL;
		top = temp->next;
	}

	void print()
	{
		if(top==NULL)
    	{
        	cout<<"\nThe stack is empty!!!";
        	return;
    	}
		temp = stack;
		while(temp != top->next)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void pop()
	{
		if(top == NULL)
    	{
        	cout<<"\nThe stack is empty!!!\n";
        	return;
    	}
		temp = stack;
		while(temp->next != top)
		{
			temp = temp->next;
		}
		delete top;
		temp->next = NULL;
		top = temp;
	}

	void Top()
	{
		cout << "top of the stack is " << top->value;
		cout << endl;
		return;
	}
};


int main()
{

	Stack_link_list a;
	int size;
	cout <<"enter the size\n";
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		cout << "enter the values\n";
		a.push();
	}
	a.print();
	a.pop();
	a.print();
	a.Top();

	return 0;
}