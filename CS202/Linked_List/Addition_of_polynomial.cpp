#include <iostream>
using namespace std;
struct poly_node
{
    int coef;
    int exp_power;
    poly_node *next;
    poly_node(int coef, int exp_power)
    {
        this->coef = coef;
        this->exp_power = exp_power;
        this->next = NULL;
    }
};

void insert(poly_node *&start, int coef, int exp_power)
{
    poly_node *temp = new poly_node(coef, exp_power);
    if (start == NULL)
    {
        start = temp;
        return;
    }
    else
    {
        poly_node *ptr = start;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void print(poly_node *&start1)
{
    if (start1 == NULL)
    {
        cout << "\nNo Polynomial Expression";
        return;
    }
    poly_node *ptr = start1;
    while (ptr)
    {
        cout << ptr->coef;
        if (ptr->exp_power)
            cout << "x^";
        if (ptr->exp_power)
            cout << ptr->exp_power;
        if (ptr->next)
            cout << " + ";

        ptr = ptr->next;
    }
    cout << "\n";
}

void addition(poly_node *&start1, poly_node *&start2, poly_node *&start3)
{
    poly_node *ptr1 = start1;
    poly_node *ptr2 = start2;

    while (ptr1 && ptr2)
    {
        // Power of x is equal
        if (ptr1->exp_power == ptr2->exp_power)
        {
            int coef = ptr1->coef + ptr2->coef;
            int exp_power = ptr1->exp_power;
            insert(start3, coef, exp_power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // power of x is greater in Poly 1
        if (ptr1->exp_power > ptr2->exp_power)
        {
            int coef = ptr1->coef;
            int exp_power = ptr1->exp_power;
            insert(start3, coef, exp_power);
            ptr1 = ptr1->next;
        }

        // power of x is greater in Poly 1
        else
        {
            int coef = ptr2->coef;
            int exp_power = ptr2->exp_power;
            insert(start3, coef, exp_power);
            ptr2 = ptr2->next;
        }
    }

    // If Poly 1 expression is not empty
    while (ptr1 != NULL)
    {
        int coef = ptr1->coef;
        int exp_power = ptr1->exp_power;
        insert(start3, coef, exp_power);
        ptr1 = ptr1->next;
    }

    // If Poly 1 expression is not empty
    while (ptr2 != NULL)
    {
        int coef = ptr2->coef;
        int exp_power = ptr2->exp_power;
        insert(start3, coef, exp_power);
        ptr2 = ptr2->next;
    }
}

int main()
{
    poly_node *start1 = NULL;

    insert(start1, 10, 5);
    insert(start1, 8, 4);
    insert(start1, 6, 3);
    insert(start1, 4, 2);
    insert(start1, 2, 1);
    insert(start1, 1, 0);

    cout << "\nFirst Polynomial Expression is : ";
    print(start1);

    poly_node *start2 = NULL;

    insert(start2, 20, 8);
    insert(start2, 10, 7);
    insert(start2, 8, 5);
    insert(start2, 6, 4);
    insert(start2, 4, 2);
    insert(start2, 2, 1);
    insert(start2, 1, 0);

    cout << "\nSecond Polynomial Expression is : ";
    print(start2);

    poly_node *start3 = NULL;

    addition(start1, start2, start3);
    cout << "\nAddition of These two polynomial is : ";
    print(start3);

    return 0;
}