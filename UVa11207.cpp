#include <bits/stdc++.h>



using namespace std;

int main()
{
	int n, res;
    double x, y, max_size;
    while (scanf("%d", &n) && n) 
    {
        max_size = -1;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf %lf", &x, &y);
            if (x < y) swap(x, y);
            double size = min(x, y) / 2;
            size = max(size, min(x / 4, y));
            if (size > max_size)
                max_size = size, res = i;
        }
        printf("%d\n", res);
    }
}
