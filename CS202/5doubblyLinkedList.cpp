// Date - 16.02.2023
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next = NULL;
    node *prev = NULL;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertAtStart(node *&start, int data)
{
    node *temp = new node(data);
    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        temp->prev = NULL;
        start = temp;
    }
}
void insertAtLast(node *&start, int data)
{
    node *temp = new node(data);
    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
        ptr = temp;
    }
}
void insertAtAnyPosition(node *&start, int position, int data)
{
    if (start == NULL || position == 1)
    {
        insertAtStart(start, data);
        return;
    }
    node *ptr = start;
    int cnt = 1;
    while (cnt < position - 1)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (ptr->next == NULL)
    {
        insertAtLast(start, data);
        return;
    }
    else
    {
        node *NodeToInsert = new node(data);
        NodeToInsert->next = ptr->next;
        ptr->next->prev = NodeToInsert;
        ptr->next = NodeToInsert;
        NodeToInsert->prev = ptr;
    }
}
void deleteAnyNode(node *&start, int position)
{
    if (start == NULL)
    {
        return;
    }
    if (start->next == NULL)
    {
        node *temp = start;
        start = NULL;
        delete temp;
        return;
    }
    if (position == 1)
    {
        node *ptr = start;
        start = start->next;
        start->prev = NULL;
        ptr->next = NULL;
        delete ptr;
    }
    else
    {
        node *forward = NULL;
        node *current = start;
        node *previous = NULL;

        int cnt = 1;
        while (cnt < position && current->next != NULL)
        {
            previous = current;
            current = current->next;
            cnt++;
        }
        if (current->next == NULL)
        {
            previous->next = NULL;
            current->prev = NULL;
            delete current;
        }
        else
        {
            forward = current->next;
            previous->next = current->next;
            current->next->prev = previous;
            delete current;
        }
    }
}
void printList(node *&start)
{
    if (start == NULL)
    {
        cout << "\nList is already empty.";
        return;
    }
    else
    {
        cout << "\nList is : ";
        node *ptr = start;
        while (ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}
int lengthOfList(node *&start)
{
    node *temp = start;
    int cnt = 0;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    node *start = NULL;

    cout << "\nPress 1 to insert node at first : ";
    cout << "\nPress 2 to insert node at last : ";
    cout << "\nPress 3 to insert node at any position : ";
    cout << "\nPress 4 to delete first node : ";
    cout << "\nPress 5 to delete last node : ";
    cout << "\nPress 6 to delete any node: ";
    cout << "\nPress 7 to print list : ";
    cout << "\nPress 8 to exit : ";
    int choice;
    int data;
    int position;
    while (1)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter data : ";
            cin >> data;
            insertAtStart(start, data);
            break;

        case 2:
            cout << "\nEnter data : ";
            cin >> data;
            insertAtLast(start, data);
            break;

        case 3:
            cout << "\nEnter data and position : ";
            cin >> data >> position;
            insertAtAnyPosition(start, position, data);
            break;

        case 4:
            deleteAnyNode(start, 1);
            break;

        case 5:
            deleteAnyNode(start, lengthOfList(start));
            break;

        case 6:
            cout << "\nEnter position of node: ";
            cin >> position;
            deleteAnyNode(start, position);
            break;

        case 7:
            printList(start);
            break;

        case 8:
            cout << "\nProgram is ended !";
            exit(0);
            break;

        default:
            cout << "\nInvalid choice please give valid choice. ";
            break;
        }
    }
    return 0;
}