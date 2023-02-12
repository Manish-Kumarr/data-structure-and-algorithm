#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    vector<int> v;
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            v.push_back(-1);
        else if (st.size() > 0 && st.top().second > price[i])
            v.push_back(st.top().first);
        else if (st.size() > 0 && st.top().second <= price[i])
        {
            while (st.size() > 0 && st.top().second <= price[i])
                st.pop();
            if (st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top().first);
        }
        st.push({i, price[i]});
    }

    for (int i = 0; i < v.size(); i++)
        cout << i - v[i] << " ";
    cout << endl;

    return {};
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    calculateSpan(arr, n);
    return 0;
}
