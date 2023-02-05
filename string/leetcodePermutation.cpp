#include <bits/stdc++.h>
using namespace std;

void perm(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                perm(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    int freq[n];
    for (int i = 0; i < n; i++)
        freq[i] = 0;
    vector<int> ds;
    perm(ds, nums, ans, freq);
    return ans;
}

int main()
{
    vector<int> num = {1, 2, 3};
    int n = num.size();
    vector<vector<int>> p = permute(num);
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < n; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
    return 0;
}
