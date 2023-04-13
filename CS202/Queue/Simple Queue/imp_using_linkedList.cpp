// Simple queue using linked list

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next = NULL;

    // structure constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at end
void insertAtLast(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(data);
        tail->next = temp;
        tail = temp;
    }
}

void firstelement(node *&head)
{
    if (head == NULL)
    {
        cout << "\nList is empty.";
        return;
    }
    cout << "\nFirst Element :" << head->data << " ";
}

void printList(node *&head)
{
    if (head == NULL)
    {
        cout << "\nList is empty.";
        return;
    }
    cout << "\nList is : ";
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void delete_node(node *&head, node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "\nList is already empty. ";
        return;
    }
    if (head->next == NULL && tail->next == NULL)
    {
        node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        temp = NULL;
        return;
    }
    else
    {
        node *temp = head;
        head = head->next;
        // Freeing memory of first node
        temp->next = NULL;
        delete temp;
    }
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    cout << "\nPress 1 to insert element: ";
    cout << "\nPress 2 to delete element: ";
    cout << "\nPress 3 to show first element : ";
    cout << "\nPress 4 to print list : ";
    cout << "\nPress 5 to exit : ";
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
            insertAtLast(head, tail, data);
            break;

        case 2:
            delete_node(head, tail);
            break;

        case 3:
            firstelement(head);
            break;

        case 4:
            printList(head);
            break;

        case 5:
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