#include <iostream>
using namespace std;

struct node
{
	int value;
	node *next;
	
};

class Queue
{
private:
	node *front, *rear, *temp;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		temp = NULL;
	}
	~Queue()
	{
		
		while(temp != rear)
		{
			temp = front;	
			front = front->next;
			delete temp;
		}
		cout << endl;
		delete front;
		delete rear;
		delete temp;
	}

	void en_queue()
	{
		if(rear == NULL)
		{
			rear = new node;
			cin >> rear->value;
			rear->next = NULL;
			front = rear;
			return;
		}
		temp = rear;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new node;
		cin >> temp->next->value;
		temp->next->next = NULL;
		rear = temp->next;
	}

	void print()
	{
		temp = front;
		while(temp != rear->next)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void pop()
	{
		temp = front;
		while(temp->next != rear)
		{
			temp = temp->next;
		}
		delete rear;
		rear = temp;
		rear->next = NULL;
	}

};



int main()
{
	Queue a;
	int size;
	cout << "enter the size\n";
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		cout << "enter the elements\n";
		a.en_queue();
	}
	a.print();
	a.pop();
	a.print();
	return 0;

}