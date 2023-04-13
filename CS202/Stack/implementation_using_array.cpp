#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    int *stk;
    stack(int size)
    {
        this->size = size;
        stk = new int(size);
        top = -1;
    }
    void push(int);
    void pop();
    void print();
    void peek();
};
void stack ::push(int data)
{
    // if(top<size) //give an errror
    // if (size - top > 1)
    if (top != size - 1)
    {
        top++;
        stk[top] = data;
    }
    else
    {
        cout << "\nOverflow ! Stack is full.";
        return;
    }
}
void stack ::peek()
{
    if (top < 0)
    {
        cout << "\nStack is empty.";
        return;
    }
    else
    {
        cout << "\nTop element is " << stk[top];
    }
}
void stack ::pop()
{
    if (top < 0)
    {
        cout << "\nUnderflow ! Stack is empty.";
        return;
    }
    else
    {
        cout << "\nPooping " << stk[top];
        top--;
    }
}
void stack ::print()
{
    if (top < 0)
    {
        cout << "\nStack is empty.";
    }
    else
    {
        cout << "\nStack is : ";
        int temp = top;
        while (temp > -1)
        {
            cout << stk[temp] << " ";
            temp--;
        }
    }
}
int main()
{
    stack st(5);
    cout << "\nPress 1 to push an element : ";
    cout << "\nPress 2 to pop an element : ";
    cout << "\nPress 3 to print top value : ";
    cout << "\nPress 4 to print Full stack : ";
    cout << "\nPress 5 to exit : ";
    while (1)
    {
        int choice;
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "\nEnter the element : ";
            cin >> x;
            st.push(x);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            st.peek();
            break;

        case 4:
            st.print();
            break;

        case 5:
            cout << "\nProgram ended ! ";
            exit(0);
            break;

        default:
            cout << "\nInvalid choice. ";
            break;
        }
    }

    st.push(5);
    st.print();
    st.push(10);
    st.print();
    st.push(15);
    st.print();
    st.push(20);
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.push(100);
    st.push(200);
    st.push(300);
    st.push(400);
    st.push(500);
    st.push(600);
    st.push(700);
    st.push(800);
    st.push(900);
    st.push(1000);
    st.print();
    st.push(1100);
    st.push(1100);
    st.push(1100);
    st.print();
    st.pop();
    st.print();
    return 0;
}