#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// change the maximum size of the stack here
const int MAX_SIZE = 10;

// create class Stack
class Stack
{
    private:
        int top;
        int arr[MAX_SIZE];

    public:
        Stack()
        {
            top = -1; // set index of last element initially to mark thet the stack is empty
        }

        // method to push or insert a value to the stack from the top.
        void push(int value)
        {
            if (top >= MAX_SIZE-1) // check if the stack is full
            {
                cout << "Stack Overflow"<< endl; 
            }
            else // add the element to the stack through top
            {
                top ++;
                arr[top] = value;
            }
        }

        // method to pop or remove the topmost element from the top of the stack
        int pop()
        {
            if(top < 0) // check if the stack is empty
            {
                cout << "Stack Underflow"<< endl;
                return 0;
            }
            else
            {
                top--;
                return arr[top + 1];
            }
        
        }

        // method to check whether the stack is empty
        bool isEmpty()
        {
            return (top <0);
        }

        // method to check whether the stack is full
        bool isFull()
        {
            return (top >= MAX_SIZE-1);
        }

        // method to show the topmost element of the stack 
        int stackTop()
        {
            if(top < 0) // check if the stack is empty
            {
                cout << "Stack is empty"<< endl;
                return 0;
            }
            else
            {
                return arr[top];
            }
        
        }

        // method to print each elements in the stack to the terminal
        void dispaly()
        {
            if(top < 0) // check if the stack is empty
            {
                cout << "Stack is empty"<< endl;
            }
            else // iterate through the array from last element to first element
            {
                for(int i = top; i >= 0; i--)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        
        }

};


int main()
{
    auto start = high_resolution_clock::now(); 
    Stack stackArray;

    // push 10 random elements to the stack
    for(int n = 0; n <10; n++)
    {
        stackArray.push(rand() % 100);
    }

    stackArray.dispaly();

    // pop 5 last elements from the stack
    for(int k = 0; k<5; k++)
    {
        stackArray.pop();
    }

    stackArray.dispaly();

    // push 4 random elements to the stack
    for(int j = 0; j <4; j++)
    {
        stackArray.push(rand() % 100);
    }

    stackArray.dispaly();

    // calculate time taken for the execution
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is: "<< duration.count() << endl;
    return 0;
}