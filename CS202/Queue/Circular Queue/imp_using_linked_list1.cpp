// queue using linked list

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void enqueue(node *&start, int data)
{
    node *temp = new node(data);
    if (start == NULL)
    {
        start = temp;
        start->next = start;
        return;
    }

    node *curr = start;
    while (curr->next != start)
    {
        curr = curr->next;
    }
    temp->next = start;
    curr->next = temp;
}
void dequeue(node *&start)
{

    if (start == NULL)
    {
        cout << "\nQueue is already empty.";
        return;
    }

    node *curr = start;

    if (start->next == start)
    {
        start = NULL;
        delete curr;
    }
    else
    {
        node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        start = start->next;
        ptr->next = start;
        delete curr;
    }
}
void printQueue(node *&start)
{
    if (start == NULL)
    {
        cout << "\nQueue is empty";
        return;
    }

    cout<<"\nQueue is :";
    node *curr = start;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != start);
}
void frontElement(node *&start)
{
    if (start == NULL)
    {
        cout << "\nQueue is empty.";
        return;
    }
    cout << "\nFront element is :" << start->data;
}

int main()
{
    // cout<<"\t\tCIRCULAR QUEUE USING LINKED LIST \n\n";
    node *start = NULL;
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
            enqueue(start, val);
            break;

        case 2:
            dequeue(start);
            break;

        case 3:
            frontElement(start);
            break;

        case 4:
            printQueue(start);
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

/*

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


Enter Choice : 1

Enter element : 4


Enter Choice : 1

Enter element : 5


Enter Choice : 4

Queue is : 1 2 3 4 5

Enter Choice : 3

Front element is :1

Enter Choice : 2


Enter Choice : 2


Enter Choice : 3

Front element is :3

Enter Choice : 4

Queue is : 3 4 5

Enter Choice : 2


Enter Choice : 3

Front element is :4

Enter Choice : 4

Queue is : 4 5

Enter Choice : 2


Enter Choice : 2


Enter Choice : 2

Queue is already empty.

Enter Choice : 4

Queue is :
Queue is empty

Enter Choice : 1

Enter element : 6


Enter Choice : 1

Enter element : 7


Enter Choice : 4

Queue is : 6 7

Enter Choice : 5

Program Ended!

*/