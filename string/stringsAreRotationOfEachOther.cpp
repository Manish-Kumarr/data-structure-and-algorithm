#include <bits/stdc++.h>
using namespace std;

// time o(n*n)
// space constant
bool checkString(string &s1, string &s2, int indexFound, int Size)
{
    for (int i = 0; i < Size; i++)
        if (s1[i] != s2[(indexFound + i) % Size])
            return false;
    return true;
}

void check(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> indexes;

    if (n != m)
    {
        cout << "s2 is not a rotation on s1";
        return;
    }
    char firstChar = s1[0];

    // every possible index
    for (int i = 0; i < n; i++)
        if (s2[i] == firstChar)
            indexes.push_back(i);

    bool isRotation = false;

    for (int idx : indexes)
    {
        isRotation = checkString(s1, s2, idx, n);
        if (isRotation)
            break;
    }

    if (isRotation)
        cout << "Strings are rotations of each other" << endl;
    else
        cout
            << "Strings are not rotations of each other" << endl;
}

// best time o(1) - worst o(n*n)
// space o(n)
bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;

    queue<char> q1;
    for (int i = 0; i < s.size(); i++)
        q1.push(s[i]);

    queue<char> q2;
    for (int i = 0; i < goal.size(); i++)
        q2.push(goal[i]);

    int k = goal.size();
    while (k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

// time = space = o(n)
bool areRotations(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

// Best mrthod o(n)
// space constant
int isCyclicRotation(string &p, string &q)
{
    int i, j, k, n = p.size();
    i = j = k = 0;
    bool reset = false;
    while (i < 2 * n)
    {
        if (k == n)
            return 1;
        if (p[i % n] == q[j % n])
        {
            i++, j++, k++;
        }
        else if (reset)
        {
            reset = false;
            i++;
        }
        else
        {
            reset = true;
            j = k = 0;
        }
    }
    return 0;
}

int main()
{
    string s1 = "AACD";
    string s2 = "ACDA";
    check(s1, s2);
    return 0;
}
