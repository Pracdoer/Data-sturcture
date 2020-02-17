#include <iostream>
using namespace std;

class Queue_array
{
private:
	int max, *queue, size, *front, *rear, *temp;
public:
	Queue_array()
	{
		cout << "enter the size of array\n";
		cin >> size;
		max = 10;
		queue = new int[max];
		front = NULL;
		rear = NULL;
		temp = NULL;

	}

	~Queue_array()
	{
		delete [] queue;
		delete front;
		delete rear;
		//delete temp;
	}

	void en_queue()
	{
		front = queue;
		rear = queue;
		for(int i = 0; i < size; i++)
		{
			cout << "enter the element\n";
			cin >> *rear;
			rear++;
		}
		rear--;
	}

	void print()
	{
		temp = queue;
		temp = front;
		for(int i = 0; i < size; i++)
		{
			cout << *temp << " "; 
			temp++;
		}
		temp = rear;
		cout << endl;
	}

	void pop()
	{
		front++;
		size--;
	}

};


int main()
{
	Queue_array a;
	a.en_queue();
	a.print();
	a.pop();
	a.print();
	return 0;
}