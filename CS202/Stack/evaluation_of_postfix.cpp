#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
    stack<int> st;
    string arr = "623+-382/+*2^3+";

    cout << "\nEntered Postfix expression is : ";
    for (int i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }

    int ans;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            st.push(int(arr[i] - '0'));
        }
        else
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            switch (arr[i])
            {
            case '+':
                ans = v2 + v1;
                st.push(ans);
                break;
            case '-':
                ans = v2 - v1;
                st.push(ans);
                break;
            case '*':
                ans = v2 * v1;
                st.push(ans);
                break;
            case '/':
                ans = v2 / v1;
                st.push(ans);
                break;
             case '^':
                ans = pow(v2,v1);
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