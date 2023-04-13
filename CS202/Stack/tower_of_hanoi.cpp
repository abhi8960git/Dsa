#include <iostream>
using namespace std;
int cnt = 0;
void move(int n, char src, char des, char spare)
{
    if (n >= 1)
    {
        move(n - 1, src, spare, des);
        cout << "\n"
             << n << " Move from " << src << " to " << des;
        move(n - 1, spare, des, src);
        cnt++;
        return;
    }
    // move(n - 1, src, spare, des);
    // move(1,src,des,spare);
    // move(n - 1, spare, des, src);
}
int main()
{
    int n = 3;
    move(n, 'S', 'D', 'H');
    // total steps = 2^n  - 1
    cout << "\nTotal steps " << cnt;
    return 0;
}