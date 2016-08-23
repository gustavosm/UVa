#include <bits/stdc++.h>
  
using namespace std;
vector<int> m[1000000];
 
int main ()
{
    int a, b, x, y, i;
    ios_base :: sync_with_stdio(0); cin.tie(0);
    while(cin >> x >> y)
    {
        int mx = -1;
        for (i = 1; i <= x; ++i)
        {
            cin >> a;
            --a;
            m[a].push_back(i);
            mx = max(mx, a);
        }
        for (i = 0; i < y; ++i)
        {
            cin >> a >> b;
            --b;
            --a;
            if (a < m[b].size())
                cout << m[b][a] << '\n';
            else cout << 0 << '\n';
        }
        for (i = 0; i <= mx; ++i) m[i].clear();
    }
}
