#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

////// Printing the array////////

void print(int *p, int len)
{
	for(int i = 0; i < len; i++)	
	{
		cout << *p << " ";
		p++;
	}
}

 //////////Get The current pointer's value ////////////

int get(int *p)
{
	return *p;
}


////////Replacing the value at given position//////////

int update(int *p, int n, int value, int len)
{

	if(n < 0 or n > len)
	{
		cout << "index is out of bound\n";
		return 0;
	} 
	int *q = p;
	for(int i = 0; i < len; i++)
	{
		if(i == n)
			*p = value;
		p++;
	}
	p = q;
	cout << "value is updated\n";
	print(p, len);
}

////////// backword the current pointer //////////

int back(int *p)
{
	cout << "\npervious value of array\n"; 
	p--;
	return *p;
}

////////// forword the current pointer //////////

int next(int *p)
{
	cout << "\nNext value of array\n"; 
	p++;
	return *p;
}

////////// start of the current pointer //////////

int Start(int *p)
{
	cout << "\nFirst value of array\n"; 
	return *p;
}

////////// End the current pointer //////////

int End(int *p)
{	
	cout << "\nLast value of array\n"; 
	return *p;
}

////////// Adding new value at certain position in array using current pointer //////////

int add(int *p , int m, int len)
{
	int index;
	cout << "\nWhich index you wanna add element\n";
	cin >> index;
	if (index < 0 or index >= len)
	{
		cout << "index out of bound\n";
		return 0;
	}
    p =  p + m;
    for(int i = m; i > index; i--)
    {
        swap(*p--, *p);
    }
    cout << "enter the element you wanna add\n";
    cin >>*p;
    p = p - index;
    print(p, m + 1);
}

////////// Removing value at certain position in array using current pointer //////////

int remove(int *p, int m, int len)
{
    int index;
    cout << "\nWhich index you wanna delete\n";
    cin >> index;
    if (index < 0 or index >= len)
	{
		cout << "index out of bound\n";
		return 0;
	}
    p = p + index;
    for(int i = index; i < m; i++)
    {
        swap(*p++, *p);
        
    }
    p = p - m;
    print(p, m - 1);

}

int main()
{	int length, m, *end = NULL, *start = NULL, index, var;
	cout << "enter the length of array\n";
	cin >> length;
	cout << "enter the length of elements\n";
	cin >> m;
	cout << "enter the elements\n";
	int arr[m];
	end = arr;
	int *current1 = arr;
	start = end;
	for(int i = 0; i < m; i++)
	{	cout << "enter the element\n";
		cin >> *end;
		end++;
		if(i == 2)
			current1 = current1 + i;     ///current pointer I make it at index 2;
	}
	end--;
    print(start, m);
	cout << endl;	
	cout << get(current1);
	cout << "\nenter the index you wanna replace\n";
	cin >> index;
	cout << "enter the value you wanna replace\n";
	cin >>  var;
	update(arr, index, var, m); 
	cout << back(current1);
	cout << next(current1);
	cout << Start(start);
	cout << End(end);
	add(start, m, length);
	remove(start, m, length);	
    return 0;

}













