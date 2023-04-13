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
void print(poly_node *&start)
{
    if (start == NULL)
    {
        cout << "\nNo Polynomial Expression";
        return;
    }
    poly_node *ptr = start;
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
int main()
{
    poly_node *start = NULL;
    insert(start, 10, 5);
    insert(start, 8, 4);
    insert(start, 6, 3);
    insert(start, 4, 2);
    insert(start, 2, 1);
    insert(start, 1, 0);
    cout << "\nPolynomial Expression is : ";
    print(start);
    return 0;
}