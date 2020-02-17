#include <iostream>
using namespace std;


/////////////////// Stack using array ///////////////////

class stack_list
{
private:
    int Max, *top , *stack, size;
public:
    stack_list()
    {
        Max = 10;
        top = NULL;
        stack = new int[Max];
       
    }
    ~stack_list()
    {
        delete [] stack;
        delete top;
    }
    
    int isEmpty()
    {
    	if(top == NULL)
    	{
    		cout << "stack is empty\n";
    		return 0;
    	}
    	return 1;
    }

    int isfull()
    {
    	if(top != NULL and top=  Max - 1)
    	{
    		cout << "stack is full\n";
    		return 0;
    	} 
    	return 1;
    }
    void push()
  	{
  		if(size >= Max)
  		{
  			cout << "the stack is overflowing\n";
  			return;
  		}
	    top = stack;
	    cout << "enter the size\n";
	    cin >> size;
	    for(int i = 0; i < size; i++)
	    {
	        int value;
	        cout << "enter the elements \n";
	        cin >> *top;
	        top++;
	    }
	    top--;
	}

	void pop()
    {
        if(top == NULL)
        {
            cout << "stack is empty\n";
            return;
        }
        top--;
        size--;
    }

	int Top()
    {
        return *top;
    }

	void print()
	{
	    top = stack;
	    for(int i = 0; i < size; i++)
	        cout << *(top + i) << " ";
	    cout << endl;
    }
 
};

int main()
{
    stack_list a;
    a.isEmpty();
    a.isfull();
    a.push();
    a.print();
    a.pop();
    a.print();
    return 0;
}