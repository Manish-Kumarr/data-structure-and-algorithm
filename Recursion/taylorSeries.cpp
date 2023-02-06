#include <bits/stdc++.h>
using namespace std;

double taylorSeries(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;

    r = taylorSeries(x, n - 1);
    p = p * x;
    f = f * n;
    return (r + (p / f));
}

// Horner's rule
double e(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + (x / n) * s;
    return e(x, n - 1);
}

int main()
{
    int x = 1;
    int n = 10;
    cout << taylorSeries(x, n);
    return 0;
}
