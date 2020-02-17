#include <iostream>
using namespace std;




class s_hash 
{

private:

public:
    int num;
    int size = 10;
    int array[10];

    s_hash()
    {
        //cout << "enter size of array\n";
        //cin >> size;
        for(int i = 0; i < size; i++)
        {
            //cout << "enter the number \n";
            array[i] = -1;        
            //cin >> array[i];
        }


    }

    int hash_function(int n)
    {
        int i = n % size;
        return i;
    }

    void insert(int n)
    {
        int i = hash_function(n);
        if(array[i] == -1)
        {
            array[i] = n;
            return;
        }
        else 
        {
            if( i == size -1 && array[i] != -1)
            {
                i = 0;
                while(array[i] != -1 and i < size)
                {
                    i++;
                }
                if(i == size)
                {
                    cout << "error: can't add " << n << " array is full " << endl;
                    return;
                }
                array[i] = n;
                return;
            }

            while(array[i] != -1 and i < size)
            {
                i++;
            }
            if(i == size)
            {	
                cout << "error: can't add " << n << " array is full " << endl;
                return;
            }
            array[i] = n;
            return;

        }
    
    }

    void print()
    {
        for(int i = 0; i < size; i++)
        {
            cout << array[i] << "    " ;
        }
        cout << endl;
    }
};





int main()
{

    s_hash a;

    
    
    //a.print();
    a.num = 11;
    a.insert(a.num);
    a.num = 101;
    a.insert(a.num);
    a.num = 12;
    a.insert(a.num);
    a.num = 13;
    a.insert(a.num);
    a.num = 14;
    a.insert(a.num);
    a.num = 15;
    a.insert(a.num);
    a.num = 105;
    a.insert(a.num);
    a.num = 108;
    a.insert(a.num);
    a.num = 109;
    a.insert(a.num);
    a.num = 209;
    a.insert(a.num);
    a.num = 309;
    a.insert(a.num);
    a.num = 45;
    a.insert(a.num);
    a.num = 41;
    a.insert(a.num);
    cout << endl;
    a.print();
    return 0;

}