#include <iostream>
#include <cmath>
using namespace std;
// For linked list top is always a leftmost node
struct node
{
    int data;
    node *next = NULL;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Insertion at start
void push(node *&top, int data)
{
    node *temp = new node(data);
    if (!top)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

// Delete top element
void pop(node *&top)
{
    if (!top)
    {
        cout << "\nStack is already empty. ";
        return;
    }
    node *temp = top;
    top = top->next;
    delete temp;
}

// Show top element
int peek(node *&top)
{
    if (!top)
    {
        // Stack is empty.
        return -1;
    }
    return top->data;
}

// Print all element
void print(node *&top)
{
    if (!top)
    {
        cout << "\nStack is empty. ";
        return;
    }
    cout << "\nStack is : ";
    node *temp = top;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//Take Expression
string takeExpression()
{
    string exp = "";
    char ch ;
    cout << "\nEnter the expression and after completing enter &: ";
    cin >> ch;
    while (ch != '&')
    {
        exp += ch;
        cin >> ch;
    }

    return exp;
}

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix

void infixToPostfix(node *&top, string exp)
{
    string result;

    for (int i = 0; i < exp.length(); i++)
    {

        char c = exp[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // ‘(‘, push it to the stack.
        else if (c == '(')
            push(top, '(' - 0);

        // If the scanned character is an ‘)’, pop and add to output string from the stack until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (peek(top) != '(' - 0)
            {
                result += char(peek(top));
                pop(top);
            }
            pop(top);
        }

        // If an operator is scanned
        else
        {
            while (top && prec(exp[i]) <= prec(char(peek(top))))
            {
                result += char(peek(top));
                pop(top);
            }
            push(top, c - 0);
        }
    }

    // Pop all the remaining elements from the stack
    while (top)
    {
        result += char(peek(top));
        pop(top);
    }

    cout << "\nPostfix expression is : " << result << endl;
}

//Function to evaluate postfix expression
void evaluatepostfix(node *&top, string exp)
{
    // cout << "\nEntered Postfix expression is : ";

    // for (int i = 0; i < exp.length(); i++)
    // {
    //     cout << exp[i] << " ";
    // }

    int ans;
    for (int i = 0;i<exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(top, int(exp[i] - '0'));
        }
        else
        {
            int v1 = peek(top);
            pop(top);
            int v2 = peek(top);
            pop(top);
            switch (exp[i])
            {
            case '+':
                ans = v2 + v1;
                push(top, ans);
                break;
            case '-':
                ans = v2 - v1;
                push(top, ans);
                break;
            case '*':
                ans = v2 * v1;
                push(top, ans);
                break;
            case '/':
                ans = v2 / v1;
                push(top, ans);
                break;
            case '^':
                ans = pow(v2, v1);
                push(top, ans);
                break;
            default:
                break;
            }
        }
    }
    cout << "\nAns is : " << peek(top);
}
int main()
{
    node *top = NULL;
    cout << "\nPress 1 to push an element : ";
    cout << "\nPress 2 to pop an element : ";
    cout << "\nPress 3 to print top value : ";
    cout << "\nPress 4 to print Full node : ";
    cout << "\nPress 5 to convert an infix expression to postfix expression : ";
    cout << "\nPress 6 to evaluatepostfix postfix expression : ";
    cout << "\nPress 7 to exit : ";
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
            push(top, x);
            break;

        case 2:
            pop(top);
            break;

        case 3:
            cout << peek(top);
            break;

        case 4:
            print(top);
            break;

        case 5:
            infixToPostfix(top, takeExpression());
            break;

        case 6:
            evaluatepostfix(top, takeExpression());
            break;

        case 7:
            cout << "\nProgram ended ! ";
            exit(0);
            break;

        default:
            cout << "\nInvalid choice. ";
            break;
        }
    }
    return 0;
}

/*

Press 1 to push an element :
Press 2 to pop an element :
Press 3 to print top value :
Press 4 to print Full node :
Press 5 to convert infix expression to postfix expression :
Press 6 to evaluate postfix expression :
Press 7 to exit :
Enter choice : 1

Enter the element : 10

Enter choice : 1

Enter the element : 20

Enter choice : 4

Stack is : 20 10
Enter choice : 1

Enter the element : 30

Enter choice : 4

Stack is : 30 20 10
Enter choice : 3
30
Enter choice : 2

Enter choice : 2

Enter choice : 2

Enter choice : 4

Stack is empty.
Enter choice : 5

Enter the infix expression and after completing enter &:
 A+B*C+d&

Postfix expression is : ABC*+d+

Enter choice : 5

Enter the expression and after completing enter &:
 ((A+B)-C*(D/E))+F&

Postfix expression is : AB+CDE/*-F+

Enter choice : 6

Enter the expression and after completing enter &:
 23*45+*&

Entered Postfix expression is : 2 3 * 4 5 + *
Ans is : 54
Enter choice : 6

Enter the expression and after completing enter &:
 523**
&

Entered Postfix expression is : 5 2 3 * *
Ans is : 30
Enter choice : 7

Program ended !

*/

/*

Infix to Postfix -

1> A+B*C+d === ABC*+D+
2> ((A+B)–C*(D/ E))+F === AB+CDE/*-F+

Evaluation of Postfix -

1> 23*45+* = 54
2> 523** = 30
*/