#include <bits/stdc++.h>
using namespace std;

int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0;
    int h = row.size() - 1;

    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }

    return l;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    // code here
    int l = 1;
    int h = 1e9;

    while (l <= h)
    {
        int mid = (l + h) >> 1;
        int count = 0;
        for (int i = 0; i < R; i++)
            count += countSmallerThanMid(matrix[i], mid);

        if (count <= (R * C) / 2)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return l;
}

int main()
{
    vector<vector<int>> a = {{2, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};
    cout << median(a, 3, 3);
    return 0;
}
