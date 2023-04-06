#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// create a node to store integer value data and node pointer next
class Node 
{
    public:
        int data;
        Node* next;

    public:
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

// create class Stack 
class Stack
{
    Node* top; // create node pointer top.

    public:
        Stack()
        {
            top = NULL; // set top as null when initiating
        }

        // method to push or insert a value to the stack from the top.
        void push(int value)
        {
            Node* newNode = new Node(value); //create a new node and allocate memory

            if (!newNode) // check if heap is full.
            {
                cout<< "Stack Overflow" << endl;
            }
            else // set the new node as the top.
            {
                newNode->next = top;
                top = newNode;
            }
        }

        // method to pop or remove the topmost element from the top of the stack
        int pop()
        {
            if (top == NULL) // check if the stack is empty
            {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            else
            {
                Node* temp = top;
                top = top->next;
                return temp->data;
            }
        }
        
        // method to check whether the stack is empty
        bool isEmpty()
        {
            return top==NULL;
        }

        // method to show the topmost element of the stack 
        int StackTop()
        {
            if (top == NULL) // check if the stack is empty
            {
                cout << "Stack is Empty" << endl;
                return 0;
            }
            else
            {
                return top->data;
            }
        }

        // method to print each elements in the stack to the terminal
        void dispaly()
        {
            if (top == NULL) // check if the stack is empty
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                // iterate through each element starting from the top element
                Node* current = top; 
                while (current != NULL) // check if you have reached the end
                {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
        }
};

int main()
{
    auto start = high_resolution_clock::now(); 
    Stack stackLinkedList;

    // push 10 random elements to the stack
    for(int n = 0; n <10; n++)
    {
        stackLinkedList.push(rand() % 100);
    }

    stackLinkedList.dispaly();

    // pop 5 last elements from the stack
    for(int k = 0; k<5; k++)
    {
        stackLinkedList.pop();
    }

    stackLinkedList.dispaly();

    // push 4 random elements to the stack
    for(int j = 0; j <4; j++)
    {
        stackLinkedList.push(rand() % 100);
    }

    stackLinkedList.dispaly();

    // calculate time taken for the execution
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is: "<< duration.count() << endl;
    return 0;
}