#include <bits/stdc++.h>
using namespace std;

// Using recursion
double power(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return power((x * x), n >> 1);
    else
        return x * power((x * x), (n - 1) >> 1);
}

// Using loop
double myPow(double m, int n)
{
    double ans = 1.0;
    long nn = n;

    if (nn < 0)
        nn = -1 * nn;

    while (nn > 0)
    {
        if (nn % 2 == 0)
        {
            m = m * m;
            nn = nn / 2;
        }
        else
        {
            ans = ans * m;
            nn = nn - 1;
        }
    }

    if (n < 0)
        ans = double(1.0) / double(ans);

    return ans;
}

int main()
{
    int x = 2;
    int pow = 9;
    cout << power(x, pow);
    return 0;
}
