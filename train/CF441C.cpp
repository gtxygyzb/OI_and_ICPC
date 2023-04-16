#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int ax[N], ay[N], n, m, k;
void move(int &x, int &y)
{
    if (x & 1) ++y;
    else --y;
    if (y > m || y < 1)
    {
        ++x;
        y = x&1 ? 1 : m;
    }
}
int main()
{
    int x = 1, y = 1, top = 1;
    ax[top] = x; ay[top] = y;
    scanf("%d%d%d", &n, &m, &k);
    while (k)
    {
        if (k == 1)
        {
            while (1)
            {
                move(x, y);
                if (x > n)
                    break;
                ax[++top] = x;
                ay[top] = y;
            }
        }
        else
        {
            while (top < 2)
            {
                move(x, y);
                ax[++top] = x;
                ay[top] = y;
            }
        }
        printf("%d ", top);
        for (int i = 1; i <= top; i++)
            printf("%d %d ", ax[i], ay[i]);
        puts("");
        top = 0;
        --k;
    }
    return 0;
}