#include <iostream>
using namespace std;


void print(int *p, int n)
{	
	cout << endl;
	if(n < 0)
	{	
		cout << "array is empty\n";
		return;
	}

	if(n == 0)
	{
		cout << "already sorted\n";
		return;
	}

	for(int i = 0; i < n; i++)
	{
		cout << *p << "  ";
		p++;
	}

}

void A_bubbleSort(int *p, int n)     // Assending order 
{ 
	if(n < 0)
	{	
		cout << "array is empty\n";
		return;
	}

	if(n == 0)
	{
		cout << "already sorted\n";
		return;
	}

  	int *s = p;
  	int *q = p;
  	for(int i = 0; i < n - 1; i++)
  	{ 
    	q = p + 1;
    	for(int j = 0; j < n - 1; j++)
    	{
      		if (*p > *q ) 
      		{
           		swap(*p, *q);
           		q++;
           		p++;
      		}
      		else
      		{
      			q++;
      			p++;
      		}
    	}
    	p =  s; 
	}
}

void D_bubbleSort(int *p, int n)   // Decending Order
{ 
	if(n < 0)
	{	
		cout << "array is empty\n";
		return;
	}

	if(n == 0)
	{
		cout << "already sorted\n";
		return;
	}
  	int *s = p;
  	int *q = p;
  	for(int i = 0; i < n - 1; i++)
  	{ 
    	q = p + 1;
    	for(int j = 0; j < n - 1; j++)
    	{
      		if (*p < *q ) 
      		{
           		swap(*p, *q);
           		q++;
           		p++;
      		}
      		else
      		{
      			q++;
      			p++;
      		}
    	}
    	p =  s; 
	}
}


void A_recursiveSort(int array[], int n, int size) {
    if (size  == n)
        return;

    if (array[size] > array[size + 1]) {
      swap(array[size], array[size + 1]);
      size = -1;
    }
    A_recursiveSort(array, n , size + 1);
}

void D_recursiveSort(int array[], int n, int size) {
    if (size  == n)
        return;

    if (array[size] < array[size + 1]) {
      swap(array[size], array[size + 1]);
      size = -1;
    }
    D_recursiveSort(array, n , size + 1);
}


int main()
{
    int size,  num, n = 0;
    cout << "enter the size \n";
    cin >> size ;
    int array[size];
    int *p = array,*q = array;

    for(int i = 0; i < size; i++)
    {
        cout << "enter the element\n";
        cin >> *p;
        p++;
    }
    p = q;
    
    A_bubbleSort(p, size);
    cout << "\nAssending order sort";
    print(p, size);
    D_bubbleSort(p, size);
    cout << "\nDessending order sort";
    A_recursiveSort(array, size - 1, n);
    print(array, size);
    D_recursiveSort(array, size - 1, n);
    print(array, size);
}