#include <iostream>
#include <iomanip>
using namespace std;

int m1, m2, m3;

class mdarray
{

	
public:
	int print(int *p, int n1);
	int print1(int **p, int n1, int n2);
	int print2(int ***p, int n1,int n2, int n3);
	int insert(int *p);
	int remove(int *p);
	int extand(int *p);
	int shrink(int *p);
	int insert1(int **p);
	int remove1(int **p);
	int insert2(int ***p);
	int remove2(int ***p);
	mdarray()
	{
		int x;
		cout << "how many dimension you want\n";
		cin >> x;
		if(x == 1)
		{	
			cout << "enter the length\n";
			cin >> m1;
			int *arr = new int[m1];
			cout << "enter elements\n";
			for(int i = 0; i < m1; i++)
				cin >> arr[i];
			print(arr, m1);
			insert(arr);
			remove(arr);
			extand(arr);
			shrink(arr);
			delete arr;
			
		} 
		if(x == 2)
		{
			cout << "enter the length of dimension 1\n";
			cin >> m1;
			cout << "enter the length of dimension 2\n";
			cin >> m2;
			int **arr ;
			arr = new int* [m1];
			cout << "enter elements\n";
			for(int i = 0; i < m1; i++)
			{
				arr[i] = new int [m2];
				for(int j = 0; j < m2; j++)
				{
					cin >> arr[i][j];
				}
			}
			print1(arr, m1, m2);
			insert1(arr);
			remove1(arr);

			for(int i = 0; i < m1; ++i) 
    			delete [] arr[i];
    		delete [] arr;
			
		}
		if(x == 3)
		{
			cout << "enter the length of dimension 1\n";
			cin >> m1;
			cout << "enter the length of dimension 2\n";
			cin >> m2;
			cout << "enter the length of dimension 3\n";
			cin >> m3;
			int ***arr;
			arr = new int** [m1];
			cout << "enter elements\n";
			for(int i = 0; i < m1; i++)
			{
				arr[i] = new int* [m2];
				for(int j = 0; j < m2; j++)
				{
					arr[i][j]= new int[m3];
					for(int k = 0; k < m3; k++)
					{
						cin >> arr[i][j][k];
					}	
				}
			}
			for(int i = 0; i < m1; ++i) 
    			delete [] arr[i];
    		delete [] arr;
			print2(arr, m1, m2, m3);
			insert2(arr);
			remove2(arr);

		} 
	}

	~mdarray()
	{
		cout << "distructor has been called\n";
	}
	
};

int mdarray::print(int *p, int n1)
{
	for(int i = 0; i < n1; i++)
	{
		cout << p[i] << " ";
	}
}

int mdarray::print1(int **p, int n1, int n2)
{
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < n2; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

int mdarray::print2(int ***p, int n1, int n2, int n3)
{
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < n2; j++)
		{
			for(int k = 0; k < n3; k++)
				cout << p[i][j][k] << " ";
		}
		cout << endl;
	}
}

int mdarray::insert(int *p)
{
	
	int n, x;
	if (n < 0 or n >= m1)
	{
		cout << "index out of bound\n";
		return 0;
	}
	cout << "\nenter the index you wanna insert \n";
	cin >> n;
	cout << "enter the value\n";
	cin >> x;
	p = p + n;
	*p = x;
	p = p - n;
	print(p, m1);
}

int mdarray::remove(int *p)
{
    int index;
    if (index < 0 or index >= m1)
	{
		cout << "index out of bound\n";
		return 0;
	}
    cout << "\nWhich index you wanna delete\n";
    cin >> index;
    if (index < 0 or index >= m1)
	{
		cout << "index out of bound\n";
		return 0;
	}
    p = p + index;
    for(int i = index; i < m1; i++)
    {
        swap(*p++, *p);
        
    }
    p = p - m1;
    print(p, m1 - 1);

}

int mdarray::extand(int *p)
{
	int n = m1 * 2;
	p = new int[n];
	cout << "size has been doubled \n";
}

int mdarray::shrink(int *p)
{
	int n = m1 / 2;
	p = new int[n];
	cout << "size has been halfed \n";
}


int mdarray::insert1(int **p)
{
	
	int n, x;
	if (n < 0 or n >= (m1*m2))
	{
		cout << "index out of bound\n";
		return 0;
	}
	cout << "\nenter the index you wanna insert \n";
	cin >> n;
	cout << "enter the value\n";
	cin >> x;
	p = p + n;
	**p = x;
	p = p - n;
	print1(p, m1, m2);
}

int mdarray::remove1(int **p)
{
    int index;
    cout << "\nWhich index you wanna delete\n";
    cin >> index;
    if (index < 0 or index >= (m1 * m2))
	{
		cout << "index out of bound\n";
		return 0;
	}
    p = p + index;
    for(int i = index; i < m1; i++)
    {
    	for(int j = 0; j < m2; j++)
        	swap(**p++, **p);
        
    }
    p = p - (m1 * m2);
    print1(p, m1, m2 - 1);

}

int mdarray::insert2(int ***p)
{
	
	int n, x;
	if (n < 0 or n >= (m1*m2*m3))
	{
		cout << "index out of bound\n";
		return 0;
	}
	cout << "\nenter the index you wanna insert \n";
	cin >> n;
	cout << "enter the value\n";
	cin >> x;
	p = p + n;
	***p = x;
	p = p - n;
	print2(p, m1, m2, m3);
}

int mdarray::remove2(int ***p)
{
    int index;
    cout << "\nWhich index you wanna delete\n";
    cin >> index;
    if (index < 0 or index >= (m1*m2*m3))
	{
		cout << "index out of bound\n";
		return 0;
	}
    p = p + index;
    for(int i = index; i < m1; i++)
    {
    	for(int j = 0; j < m2; j++)
        	swap(***p++, ***p);
        
    }
    p = p - (m1 * m2 * m3);
    print2(p, m1, m2, m3 -1);

}



int main()
{
	mdarray a;
	return 0;
}