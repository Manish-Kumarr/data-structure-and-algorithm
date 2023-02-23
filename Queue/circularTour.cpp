#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    // Your code here
    int startIdx, end, petLeft, disLeft;
    startIdx = end = petLeft = disLeft = 0;
    int visit = 0;
    bool flag = false;
    bool f = false;
    do
    {
        end = end % n;
        petLeft += p[end].petrol;
        disLeft += p[end].distance;
        if (petLeft >= disLeft)
        {
            visit++;
            petLeft -= disLeft;
            disLeft = 0;
            if (!flag && startIdx == 0)
            {
                startIdx = end;
                flag = true;
            }
            f = true;
        }
        else
        {
            petLeft = disLeft = 0;
            // startIdx = end;
        }
        if (visit == n)
            return startIdx;
        end++;
    } while (end != startIdx);

    if (f == false)
        return -1;
}

int main()
{
    petrolPump p[] = {{55, 77}, {52, 61}, {33, 40}, {100, 69}};
    cout << tour(p, 4);
    return 0;
}
