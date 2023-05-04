#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2*root + 1;
   int right = 2*root + 2;

   // finding largest among root, left and right
   int largest = root;
   if (left < n && arr[largest] < arr[left])
      largest = left;

   if ( right < n && arr[largest] < arr[right])
      largest = right;

   // swap the root and largest if the root is not the largest
   if (largest != root)
   {
      int temp = arr[largest];
      arr[largest] = arr[root];
      arr[root] = temp;
      // heapify 
      heapify(arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = n/2 - 1; i>=0; i--)
   {
      heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   for(int i = n-1; i>=0; i--)
   {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;

      heapify(arr, i, 0);
   }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n = 0;
   cout<< "Enter size of the array: ";
   cin >> n;
   cout<< "Enter numbers:" << endl;
   int heap_arr[n];
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   for (int i = 0; i < n; i++) {
    cin >> heap_arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}