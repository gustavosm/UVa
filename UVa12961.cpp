#include <bits/stdc++.h>



using namespace std;


typedef long long ll;

ll v[30005];

int n, k;


int ranking()
{
	int ans = 0;
	
	for (int j = 0 ; j < n ; ++j)
	{
		ll b = (1L << (k - j - 1));
		for (int i = j; i < n; ++i)
		{
			if (v[i] & b)
			{
				swap(v[i], v[j]);
				break;
			}
		}
		
		if (!(v[j] & b)) break;
		
		++ans;
		
		for (int i = j + 1; i < n ; ++i)
		{
			if (v[i] & b)
			{
				v[i] ^= v[j];
			}
		}
	}
	return ans;
}

int main()
{
	ll x;
	while (cin >> n >> k)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			v[i] = 0;
			for (int j = 0 ; j < k ; ++j)
			{
				cin >> x;
				if (x & 1)
					v[i] |= (1L << j);
			}
		}
		
		if (n > k && ranking() >= k)
			cout << "N\n";
		else cout << "S\n";
	}
}
