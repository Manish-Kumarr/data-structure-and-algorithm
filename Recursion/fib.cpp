#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int arr[31];
    memset(arr, -1, sizeof(arr));
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if (arr[n - 2] == -1)
            arr[n - 2] = fib(n - 2);
        if (arr[n - 1] == -1)
            arr[n - 1] = fib(n - 1);
        return arr[n - 2] + arr[n - 1];
    }
    return 0;
}

int main()
{
    cout << fib(7);
    return 0;
}
