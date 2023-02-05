#include <bits/stdc++.h>
using namespace std;

void perm(vector<string> &res, string s, string &str, int flag[])
{
    if (str.size() == s.size())
    {
        if (find(res.begin(), res.end(), str) == res.end())
            res.push_back(str);
        return;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!flag[i])
            {
                str.push_back(s[i]);
                flag[i] = 1;
                perm(res, s, str, flag);
                flag[i] = 0;
                str.pop_back();
            }
        }
    }
}

vector<string> find_permutation(string S)
{
    vector<string> res;
    string str = "";
    int flag[S.size()];
    for (int i = 0; i < S.size(); i++)
        flag[i] = 0;
    perm(res, S, str, flag);
    // for lexographical order
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<string> s = find_permutation("AAB");
    for (string x : s)
        cout << x << " ";
    return 0;
}
