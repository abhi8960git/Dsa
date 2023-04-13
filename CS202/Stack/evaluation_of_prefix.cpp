#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
    stack<float> st;
    // string arr = "+/^82*45^*8/362";
    string arr ="+-10*7+32^72";

    cout << "\nEntered Prefix expression is : ";
    for (int i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < arr.length() / 2; i++)
    {
        swap(arr[i], arr[arr.length() - 1 - i]);
    }

    cout << "\nEntered Prefix expression after reversing is : ";
    for (int i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }

    float ans;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            st.push(int(arr[i] - '0'));
        }
        else
        {
            float v1 = st.top();
            st.pop();
            float v2 = st.top();
            st.pop();
            switch (arr[i])
            {
            case '+':
                ans = v1 + v2;
                st.push(ans);
                break;
            case '-':
                ans = v1 - v2;
                st.push(ans);
                break;
            case '*':
                ans = v1 * v2;
                st.push(ans);
                break;
            case '/':
                ans = v1 / v2;
                st.push(ans);
                break;
            case '^':
                ans = pow(v1, v2);
                st.push(ans);
                break;
            default:
                break;
            }
        }
    }
    cout << "\nAns is : " << st.top();
    return 0;
}