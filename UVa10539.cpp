#include <bits/stdc++.h>

#define sz 1000001
using namespace std;

typedef long long ll;

vector<ll>ans;
bitset<sz> flag;

void sieve()
{
    ll i, j, add;
    
    flag.set();
    flag.reset(0); flag.reset(1);
    
    for(i = 4; i < sz; i += 2)
        flag.reset(i);
    for(i = 3; i < sz; i += 2)
    {
        if(flag[i])
        {
            add = i * 2;
            for(j = i * i; j < sz; j += add)
                flag.reset(j);
        }
    }
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
    sieve();
    ll i, j;
    ll x, y;
    int tst, ansz;
    
    for(i = 2; i < sz; ++i)
    {
        if(flag[i])
            for(j = i * i; j < 1000000000001LL; j *= i)
                ans.push_back(j);
    }
    
    sort(ans.begin(),ans.end());
    
    ansz = ans.size();
    
    cin >> tst;
    
    while(tst--)
    {
    	cin >> x >> y;
    	
        i = (int)(lower_bound(ans.begin(), ans.end(), x) - ans.begin());
        
        while (ans[i] < x) ++i;
        
        j = (int)(upper_bound(ans.begin(), ans.end(), y) - ans.begin());
        
        while (ans[j] > y) --j;
        
        cout << (j - i + 1) << '\n';
    }

    return 0;
}
