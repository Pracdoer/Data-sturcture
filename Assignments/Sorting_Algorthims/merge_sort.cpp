#include <iostream>
using namespace std;

int mid;
void merge_sort(int arr[], int n)
{
	
	if(mid > 1) {

		mid = n/2;
		cout << mid;
		
		merge_sort(arr, n);
	}
	int *left = arr;
	int *right = arr+mid + 1;
	//cout << mid;
	// for(int i = 0; i < mid; i++)
	// {
	// 	cout  << "left " << *(left + i) << endl ;
	// 	//left++;
	// // cout << *left;
	// }

	
	// for(int j = mid + 1; j < n; j++)
	// {
	// 	cout <<  << endl;
	// 	//cout  << "right " << *(right + j) << endl ;
	// 	//left++;
	// // cout << *left;
	// }





}


// void merge_sort(int *arr, int n){
// //   if n > 1{
// //     int mid = n/2;
// //     int *left = arr;
// //     int *right = left + mid;
// //     n = n/2;
// //     merge_sort(left, mid);
// //     merge_sort(right, mid);
// //     if(*left < *right){
// //       *arr = *left;
// //       arr++;}
// //     else{
// //       *arr = *right;
// //       arr++;}}
// // }


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
        cin >> array[i];
    }
    // p = q;
    merge_sort(array, size);


	return 0;
}