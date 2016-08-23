#include <bits/stdc++.h>


using namespace std;

#define MAX_N 1000005

int n, p, q, A[MAX_N];
int L[MAX_N], L_id[MAX_N], P[MAX_N];

map<int, int> m;

int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int lis = 0, lis_end = 0;
	
	int cases;
	int x;
	
	cin >> cases;
	
	for (int c = 1; c <= cases; ++c)
	{
		cin >> n >> p >> q;
		
		++p;
		++q;
		
		m.clear();
		for (int i = 1 ; i <= p ; ++i)
		{
			cin >> x;
			m[x] = i;
		}
		n = 0;
		for (int j = 0 ; j < q; ++j)
		{
			cin >> x;
			if (m.count(x))
				A[n++] = m[x];
		}
		
		lis = lis_end = 0;
		for (int i = 0; i < n; ++i) 
		{
			int pos = lower_bound(L, L + lis, A[i]) - L;
			L[pos] = A[i];
			L_id[pos] = i;
			P[i] = pos ? L_id[pos - 1] : -1;
			if (pos + 1 > lis) 
			{
				lis = pos + 1;
				lis_end = i;
			}
		}
		cout << "Case " << c << ": " << lis << '\n';
	}
	

	return 0;
}
