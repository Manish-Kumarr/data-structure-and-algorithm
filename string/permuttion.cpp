#include <bits/stdc++.h>
using namespace std;

void permutation(char s[], int k)
{
    static int flag[10] = {0};
    static char res[10];

    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res << " ";
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (flag[i] == 0)
            {
                res[k] = s[i];
                flag[i] = 1;
                permutation(s, k + 1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    char s[] = "ABC";
    permutation(s, 0);
    return 0;
}
