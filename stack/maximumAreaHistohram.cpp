#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    long long ans = 0;
    long long mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            mn = min(mn, arr[j]);
            int width = j + 1;
            ans = max(ans, mn * width);
        }
    }
    return ans;
}

int main()
{
    long long arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << getMaxArea(arr, n);
    return 0;
}
