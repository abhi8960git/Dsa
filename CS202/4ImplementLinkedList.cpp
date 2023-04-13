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

// Insert at start
void insertAtStart(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }
}

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

// Insert at any position
void insertAtAnyPosition(node *&head, node *&tail, int position, int data)
{

    // Insert at start
    if (position == 1)
        insertAtStart(head, tail, data);

    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at end
    if (temp->next == NULL)
        insertAtLast(head, tail, data);
    else
    {
        // Insert in between two nodes
        node *newnode = new node(data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void printList(node *&head)
{
    if(head==NULL)
    {
        cout<<"\nList is empty.";
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
void delete_node(node *&head, node *&tail, int position)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"\nList is already empty. ";
        return;
    }
    if(head->next==NULL && tail->next==NULL)
    {
        node*temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        temp=NULL;
        return;
    }
    // deleting first

    if (position == 1)
    {
        node *temp = head;
        head = head->next;

        // Freeing memory of first node
        temp->next = NULL;
        delete temp;
    }

    // deleting any middle node or last node

    else
    {
        // 1 2 3 4 5 6 delete 4 / delete 6
        node *current = head;  // current = 1 / 1
        node *previous = NULL; // previous = 0 / 0
        int cnt = 1;
        while (cnt < position) // 4<4 / 6<6
        {
            previous = current;      // previous = 3 / 5
            current = current->next; // current = 4 / 6
            cnt++;                   // cnt = 4 / 6
        }
        // Deleting last node
        if (current->next == NULL) // 4->next = 5 / 6->next = NULL
        {
            tail = previous; // tail = 5
        }
        // Deleting middle node between two nodes
        previous->next = current->next; // 3->next = 4->next(5)
        current->next = NULL;           // 4->next=NULL
        delete current;
        current = NULL;
    }
}
int lengthOfList(node *&head)
{
    node *temp = head;
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

    node *head = NULL;
    node *tail = NULL;

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
            insertAtStart(head, tail, data);
            break;

        case 2:
            cout << "\nEnter data : ";
            cin >> data;
            insertAtLast(head, tail, data);
            break;

        case 3:
            cout << "\nEnter data and position : ";
            cin >> data >> position;
            insertAtAnyPosition(head, tail, position, data);
            break;

        case 4:
            delete_node(head, tail, 1);
            break;

        case 5:
            delete_node(head, tail, lengthOfList(head));
            break;

        case 6:
            cout << "\nEnter position of node: ";
            cin >> position;
            delete_node(head, tail, position);
            break;

        case 7:
            printList(head);
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

Enter choice : 1

Enter data : 5

Enter choice : 2

Enter data : 15

Enter choice : 7

List is : 5 10 15
Enter choice : 3

Enter data and position : 7 2

Enter choice : 7

List is : 5 7 10 15
Enter choice : 4

Enter choice : 7

List is : 7 10 15
Enter choice : 5

Enter choice : 7

List is : 7 10
Enter choice : 6

Enter position of node: 1

Enter choice : 7

List is : 10
Enter choice : 6

Enter position of node: 1

Enter choice : 7

List is empty.
Enter choice : 2

Enter data : 100

Enter choice : 7

List is : 100
Enter choice : 2

Enter data : 200

Enter choice : 7

List is : 100 200
Enter choice : 3

Enter data and position : 300 3

Enter choice : 7

List is : 100 200 300
Enter choice : 6

Enter position of node: 2

Enter choice : 7

List is : 100 300
Enter choice : 8

Program is ended !
*/