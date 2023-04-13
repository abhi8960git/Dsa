// Circular Queue using array

#include <iostream>
using namespace std;
struct queue
{
    int *que;
    int front;
    int rear;
    int size;
    
    queue(int size)
    {
        this->size = size;
        que = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull()
    {
        if (front == 0 && rear == size - 1 || (front == rear + 1))
        {
            return true;
        }
        return false;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        if ((front == -1 && rear == -1))
            return true;
        else
            return false;
    }

    //Insert data to queue
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "\nOverflow!";
            return;
        }

        if (rear == size - 1 && front != 0)
        {
            rear = -1;
        }

        rear++;
        que[rear] = data;
        if (front == -1)
        {
            front++;
        }
    }

    //Delete data from queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\nUnderflow !";
            return;
        }

        front = (front + 1) % size;
        if((front == rear+1) || (front == 0 && rear == size-1))
        {
            front = -1;
            rear = -1;
        }
    }

    //Give front data
    void frontelem()
    {
        if (isEmpty())
        {
            cout << "\nEmpty";
        }
        else
        {
            cout << "\nFront element is : " << que[front];
        }
    }

    // Function to display values of Circular Queue
    void print()
    {
        if (isEmpty())
        {
            cout << "\nEmpty Queue";
        }
        else
        {
            cout << "\nCircular Queue is : ";
            for (int i = front; i != rear; i = (i + 1) % size)
            {
                cout << que[i] << " ";
            }
            cout << que[rear];
        }
    }
};

int main()
{
    // cout<<"\t\tCIRCULAR QUEUE USING ARRAY \n\n";
    int n;
    cout<<"\nEnter size of queue : ";
    cin>>n;
    queue que(n);
    int choice;
    cout << "\nPress 1 to insert element in queue : ";
    cout << "\nPress 2 to delete element from queue : ";
    cout << "\nPress 3 to get front element of queue : ";
    cout << "\nPress 4 to show all element of queue : ";
    cout << "\nPress 5 to exit : ";
    while (1)
    {
        cout << "\n\nEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int val;
            cout << "\nEnter element : ";
            cin >> val;
            que.enqueue(val);
            break;

        case 2:
            que.dequeue();
            break;

        case 3:
            que.frontelem();
            break;

        case 4:
            que.print();
            break;

        case 5:
            cout << "\nProgram Ended!";
            exit(0);
            break;

        default:
            cout<<"\nInvalid choice.";
            break;
        }
    }

    return 0;
}

/*

Enter size of queue : 5

Press 1 to insert element in queue : 
Press 2 to delete element from queue : 
Press 3 to get front element of queue : 
Press 4 to show all element of queue : 
Press 5 to exit : 

Enter Choice : 1

Enter element : 1


Enter Choice : 1

Enter element : 2


Enter Choice : 1

Enter element : 3


Enter Choice : 4

Circular Queue is : 1 2 3

Enter Choice : 3

Front element is : 1

Enter Choice : 1

Enter element : 4


Enter Choice : 1

Enter element : 5


Enter Choice : 4

Circular Queue is : 1 2 3 4 5

Enter Choice : 1

Enter element : 6

Overflow!

Enter Choice : 4

Circular Queue is : 1 2 3 4 5

Enter Choice : 2


Enter Choice : 2


Enter Choice : 4

Circular Queue is : 3 4 5

Enter Choice : 1

Enter element : 6


Enter Choice : 1

Enter element : 7


Enter Choice : 4

Circular Queue is : 3 4 5 6 7

Enter Choice : 1

Enter element : 8

Overflow!

Enter Choice : 4

Circular Queue is : 3 4 5 6 7

Enter Choice : 2


Enter Choice : 2


Enter Choice : 3

Front element is : 5

Enter Choice : 4

Circular Queue is : 5 6 7

Enter Choice : 2


Enter Choice : 4

Circular Queue is : 6 7

Enter Choice : 2


Enter Choice : 2


Enter Choice : 4

Empty Queue

Enter Choice : 2

Underflow !

Enter Choice : 5

Program Ended!

*/