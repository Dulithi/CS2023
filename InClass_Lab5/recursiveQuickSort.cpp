#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int* a, int* b) // function to swap two integers
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// high is the index of last element in arr
// low is the index of first element in arr

void recursiveQuickSort(int arr[], int low, int high) 
{

    if(low < high)
    {
        int pivot = arr[high]; // set last element as the pivot
        int i = low - 1;

        // partition the array around the pivot 
            // left --> lesser values than pivot
            // right --> larger values than pivot
        for(int j=low; j<high; j++)
        {
            if(pivot > arr[j])
            {
                i ++;
                swap(&arr[i], &arr[j]);
            }
        }
        i ++;
        swap(&arr[i], &arr[high]);

        // quicksort either parts of the array
        recursiveQuickSort(arr, low, i-1);
        recursiveQuickSort(arr, i+1, high);

    }

}


int main ()
{
    int arrSize;
    cout<<"Total elements in array: "; // get input size from user
    cin>> arrSize;
    int randArray[arrSize]; // create random array
    for(int i=0;i<arrSize;i++)
      randArray[i]=rand()%100;

    // finding the time taken for quicksort.

    auto start = high_resolution_clock::now(); 
    recursiveQuickSort(randArray, 0, arrSize-1);
    
    // for(int i=0;i<arrSize;i++)
    //     cout<<randArray[i]<<" ";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is: "<< duration.count() << endl;
    return 0;
}
