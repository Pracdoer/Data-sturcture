#include <iostream>
using namespace std;


void print(int *p, int n)
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

	for(int i = 0; i < n; i++)
	{
		cout << *p << "  ";
		p++;
	}

}

void Assending_selectionSort(int *p, int n)   //// Assending order
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
	int *temp = p;
    int *q = p + 1;  
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
          if (*p > *q) 
            swap(*p, *q);
           q++;
        }
           p++; 
           q = p + 1;
    } 
    cout << "\nSorting in Assending Order\n";
    print(temp, n);


} 

void Dessending_selectionSort(int *p, int n)   //// Dessending order
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

	int *temp = p;
    int *q = p + 1;  
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
          if (*p < *q) 
            swap(*p, *q);
           q++;
        }
           p++; 
           q = p + 1;
    } 
    cout << "\nSorting in Dessending Order\n";
    print(temp, n);
} 

void assending_sort_recursive( int *p, int n ) {    // Assending order
    if (n < 1)
      return;
    int *q = p+ 1; 
    for(int i = 0; i < n - 1; i++)
    {
     
      if(*p > *q)
        swap(*p, *q);
        q++;
    }
    p = p + 1;
    assending_sort_recursive(p, --n);
}

void dessending_sort_recursive( int *p, int n ) {    // Assending order
    if (n < 1)
      return;
    int *q = p+ 1; 
    for(int i = 0; i < n - 1; i++)
    {
     
      if(*p < *q)
        swap(*p, *q);
        q++;
    }
    p = p + 1;
    dessending_sort_recursive(p, --n);
}


int main()
{
    int size,  num;
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
    assending_sort_recursive(p, size);
    cout << "\nAssending Order sort\n";
    print(p, size);
    cout << endl;
    dessending_sort_recursive(p, size);
    cout << "\nDessending Order sort\n";
    print(p, size);
    cout << endl;
    Assending_selectionSort(array, size);
    Dessending_selectionSort(array, size);
    return 0;
}