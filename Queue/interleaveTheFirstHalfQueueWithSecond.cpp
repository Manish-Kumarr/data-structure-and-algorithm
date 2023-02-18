#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    queue<int> q1;
    int n = q.size();
    int sz = q.size() / 2;
    while (sz--)
    {
        q1.push(q.front());
        q.pop();
    }
    while (!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    interLeaveQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
