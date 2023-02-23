#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[], int n, int k)
{
    int i = 0, j = 0;
    deque<int> maxRecord;
    deque<int> minRecord;
    int sum = 0;

    while (j < n)
    {

        if (maxRecord.empty() || arr[j] < maxRecord.back())
            maxRecord.push_back(arr[j]);
        else if (arr[j] > maxRecord.back())
        {
            while (!maxRecord.empty() && arr[j] > maxRecord.back())
                maxRecord.pop_back();
            maxRecord.push_back(arr[j]);
        }
        if (minRecord.empty() || arr[j] > minRecord.back())
            minRecord.push_back(arr[j]);
        else if (arr[j] < minRecord.back())
        {
            while (!minRecord.empty() && arr[j] < minRecord.back())
                minRecord.pop_back();
            minRecord.push_back(arr[j]);
        }

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            sum += minRecord.front() + maxRecord.front();
            if (maxRecord.front() == arr[i])
                maxRecord.pop_front();
            if (minRecord.front() == arr[i])
                minRecord.pop_front();
            i++;
            j++;
        }
    }

    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, n, k);
    return 0;
}
