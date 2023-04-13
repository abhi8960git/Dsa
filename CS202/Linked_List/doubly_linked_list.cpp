#include <iostream>
using namespace std;
class node
{
public:
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
void insertAtStart(node *&head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtLast(node *&head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}
void printList(node *&head)
{
    if (head == NULL)
    {
        cout << "\nList is empty.";
    }
    else
    {
        cout << "\nList is : ";
        node *print = head;
        while (print != NULL)
        {
            cout << print->data << " ";
            print = print->next;
        }
    }
    cout << "\n";
}
void insert_in_between(node *&head, int data, int position)
{
    if (head == NULL || position == 1 || position == 0)
    {
        insertAtStart(head, data);
        // return; //if we don't write return the we have to write else after is statement
    }
    else
    {
        node *newNode = new node(data);
        node *temp = head;
        int cnt = 1;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL)
        {
            insertAtLast(head, data);
            // return; //if we don't write return the we have to write else after is statement
        }
        else
        {
            newNode->next = temp->next;

            temp->next->prev = newNode;

            newNode->prev = temp;

            temp->next = newNode;
        }
    }
}
void deleteStart(node *&head)
{
    if (head == NULL)
    {
        cout << "\nList is already empty";
    }
    node *ptr = head;
    node *back = NULL;

    // only 1 node
    if (ptr->next == NULL)
    {
        head = NULL;
        delete ptr;
        // ptr=NULL;
    }

    // for 2 or more node
    else
    {
        head = head->next;
        head->prev = NULL;
        delete ptr;
        // ptr=NULL;
    }
}
void deleteEnd(node *&head)
{
    if (head == NULL)
    {
        cout << "\nList is already empty";
    }
    node *ptr = head;
    node *back = NULL;
    // Only 1 node
    if (ptr->next == NULL)
    {
        head = NULL;
        delete ptr;
    }

    // 2 or more nodes
    else
    {
        while (ptr->next != NULL)
        {
            back = ptr;
            ptr = ptr->next;
        }
        back->next = NULL;
        delete ptr;
    }
}
void delete_from_in_between(node *&head, int postion)
{
    if (head == NULL)
    {
        cout << "\nList is already empty.";
        return;
    }
    if (postion == 1)
    {
        deleteStart(head);
        return;
    }
    node *ptr = head;
    node *back = NULL;
    int cnt = 1;
    while (cnt < postion)
    {
        back = ptr;
        ptr = ptr->next;
        cnt++;
    }
    if (ptr->next == NULL)
    {
        back->next = NULL;
        delete ptr;
    }
    else
    {
        back->next = ptr->next;
        ptr->next->prev = back;
        delete ptr;
    }
}
int main()
{
    node *start = NULL;
    printList(start);
    insertAtLast(start, 5);
    printList(start);
    insertAtStart(start, 0);
    printList(start);
    insertAtLast(start, 10);
    printList(start);
    insertAtLast(start, 15);
    printList(start);
    insertAtStart(start, 18);
    printList(start);
    insert_in_between(start, 100, 1);
    printList(start);
    insert_in_between(start, 100, 5);
    printList(start);
    insert_in_between(start, 100, 3);
    printList(start);
    insert_in_between(start, 100, 8);
    printList(start);
    insert_in_between(start, 100, 10);
    printList(start);
    cout << "\nAfter Deleting : ";
    deleteStart(start);
    deleteEnd(start);
    delete_from_in_between(start, 3);
    printList(start);
    delete_from_in_between(start, 4);
    printList(start);
    delete_from_in_between(start, 1);
    printList(start);
    return 0;
}