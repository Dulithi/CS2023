#include <iostream>
#include <chrono>
#include <random>
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

void iterativeQuickSort(int arr[], int low, int high) 
{
    int stack[high + 1 - low]; // create a stack
    int top = 0;

    stack[top] = low; // push initial values
    top++;
    stack[top] = high;


    while(top>0)
    {
        
        high = stack[top]; // pop high and low values
        top--;
        low = stack[top];

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


        if(low < i-1) // push the elements at the left of the pivot
        {
            stack[top] = low;
            top++;
            stack[top] = i-1;

        }

        if(i+1 < high)// push the elements at the right of the pivot
        {
            top++;
            stack[top] = i+1;
            top++;
            stack[top] = high;
            
        }

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
    iterativeQuickSort(randArray, 0, arrSize-1);
    
    
    // for(int i=0;i<arrSize;i++)
    //     cout<<randArray[i]<<" ";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is: "<< duration.count() << endl;
    return 0;
}
