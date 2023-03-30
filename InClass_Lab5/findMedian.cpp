#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;
using namespace std::chrono;


int main()
{

    int sizeOfArr;
    cout<< "Enter the size of the array: ";
    cin >> sizeOfArr;

    int arr[sizeOfArr];
    vector<int> sortedArray;
    

    for(int k = 0; k < sizeOfArr; k++)
    {
        cout<< "Enter number: ";
        cin >> arr[k];
        if(k==0)
        {
            sortedArray.push_back(arr[0]);
            float median = sortedArray.at(k+1/2); // calculate the median
            cout<<"Median: " << fixed << setprecision(1)<<median<< endl;
    
            continue;
        }
        bool inserted;
        for(int i =0; i <= k; i++)
        {
            
            inserted = false;
            if(sortedArray[i] > arr[k] )
            {
                sortedArray.insert(sortedArray.begin()+i, arr[k]);// insert element at the relavent position
                inserted = true;
                break;
            }
        }
        if(!inserted)
        {
            sortedArray.push_back(arr[k]);
        }
        
        int x = k+1;
        if(x % 2 == 0)
        {
            float median = (sortedArray.at((x-1)/2)+sortedArray.at(x/2))/2.0; // calculate the median
            cout<<"Median: " << fixed << setprecision(1)<<median<< endl;
        }
        else
        {
            float median = sortedArray.at(x/2); // calculate the median
            cout<<"Median: " << fixed << setprecision(1)<<median<< endl;
        }
        
    }
    
    return 0;
}