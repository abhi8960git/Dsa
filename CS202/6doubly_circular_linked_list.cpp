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
    node *new_node = new node(data);
    if (start == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }
    else
    {
        new_node->prev = start->prev;
        start->prev->next = new_node;
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
}

void insertAtLast(node *&start, int data)
{
    node *new_node = new node(data);
    if (start == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }
    else
    {
        node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        new_node->prev = ptr;
        ptr->next = new_node;
        start->prev = new_node;
        new_node->next = start;
    }
}

void insertAtAnyPosition(node *&start, int position, int data)
{
    // Insert At First
    if (start == NULL || position <= 1)
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

    // Insert At Last
    if (ptr->next == start)
    {
        insertAtLast(start, data);
        return;
    }

    // Insert at Given Position
    node *new_node = new node(data);

    ptr->next->prev = new_node;
    new_node->next = ptr->next;
    new_node->prev = ptr;
    ptr->next = new_node;
}

void delete_first_node(node *&start)
{
    node *temp = start;

    //If list is empty
    if(temp == NULL)
    {
        cout<<"\nList is already empty.";
        return;
    }

    // If only Single node
    if (temp->next == start)
    {
        start = NULL;
        delete temp;
    }
    else
    { //If more than one node is present
        cout << "\nFirst node Deleted .";
        start->prev->next = start->next;
        start->next->prev = start->prev;
        start = start->next;
        delete temp;
    }
}
void delete_last_node(node *&start)
{
    node *temp = start;

    //If list is empty
    if(temp == NULL)
    {
        cout<<"\nList is already empty.";
        return;
    }

    // Single node
    if (temp->next == start)
    {
        start = NULL;
        delete temp;
    }
    // For more than 1 node
    else
    {
        cout << "\nLast node deleted .";
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->prev->next = start;
        start->prev = temp->prev;
        delete temp;
    }
}
void deleteAnyNode(node *&start, int position)
{
    //Is list is empty
    if (start == NULL)
    {
        cout << "\nCircular List is Alredy Empty !";
        return;
    }

    //Delete First Node
    if (position <= 1)
    {
        delete_first_node(start);
        return;
    }

    node *temp = start;
    int cnt = 1;
    while (cnt < position)
    {
        temp = temp->next;
        cnt++;
    }

    // Delete Last Node
    if (temp->next == start)
    {
        delete_last_node(start);
        return;
    }

    //Delete given node 
    cout << "\nDeleting " << position << " th node";
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void printList(node *&start)
{
    if (start == NULL)
    {
        cout << "\nCircular List is empty.";
        return;
    }
    cout << "\nList is : ";
    node *ptr = start;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != start);
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
            delete_first_node(start);
            break;

        case 5:
            delete_last_node(start);
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

/*

Press 1 to insert node at first :
Press 2 to insert node at last :
Press 3 to insert node at any position :
Press 4 to delete first node :
Press 5 to delete last node :
Press 6 to delete any node:
Press 7 to print list :
Press 8 to exit :
Enter choice : 1

Enter data : 10

Enter choice : 2

Enter data : 20

Enter choice : 2

Enter data : 30

Enter choice : 7

List is : 10 20 30
Enter choice : 1

Enter data : 5

Enter choice : 7

List is : 5 10 20 30
Enter choice : 3

Enter data and position : 15 3

Enter choice : 7

List is : 5 10 15 20 30
Enter choice : 4

Deleting First node .
Enter choice : 7

List is : 10 15 20 30
Enter choice : 5

Deleting Last node .
Enter choice : 7

List is : 10 15 20
Enter choice : 6

Enter position of node: 2

Deleting 2 th node
Enter choice : 7

List is : 10 20
Enter choice : 4

Deleting First node .
Enter choice : 7

List is : 20
Enter choice : 5

Enter choice : 7

Circular List is empty.
Enter choice : 8

Program is ended !

*/