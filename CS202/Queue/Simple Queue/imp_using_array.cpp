// Simple Queue

#include <iostream>
using namespace std;
struct queue
{
    int *que;
    int front;
    int rear;
    int size;

public:
    queue(int size)
    {
        this->size = size;
        que = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data)
    {
        if (rear == size - 1 || front == rear + 1 || front == size)
        {
            cout << "\nOver flow";
            return;
        }

        else
        {
            rear++;
            que[rear] = data;
            if (front == -1)
                front++;
        }
    }

    void dequeue()
    {
        if (front == -1 || front == rear + 1 || front == size)
        {
            cout << "\nUnderFlow";
        }
        else
        {
            front++;
        }
    }

    void frontelem()
    {
        if (front == -1)
        {
            cout << "\nEmpty";
        }
        else
        {
            cout << "\nFront element is : " << que[front];
        }
    }

    void print()
    {
        if (front == -1 || front == size)
        {
            cout << "\nEmpty";
            return;
        }
        cout << "\nlist is :";
        for (int i = front; i <= rear; i++)
        {
            cout << que[i] << " ";
        }
    }
};

int main()
{

    queue que(3);
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
            break;
        }
    }

    return 0;
}