#include <bits/stdc++.h>

#define pb push_back
using namespace std;


bitset<1000005>b;
vector<int> p;

void sieve()
{
	p.pb(2);
	b.set();
	for (long long i = 3; i < 1000005; i += 2)
	{
		if (b[i])
		{
			p.pb(i);
			for (long long j = i * i ; j < 1000005; j += i)
				b.reset(j);
		}
	}
}


int main()
{
	int n;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	sieve();
	
	while (cin >> n)
	{
		if (!n) return 0;
		
		for (int i = 0; ; ++i)
		{
			int search = n - p[i];
			
			if (binary_search(p.begin(), p.end(), search))
			{
				cout << n << " = " << min(p[i], search) << " + " << max(p[i],search) << '\n';
				break;
			}
		}
	}
}
