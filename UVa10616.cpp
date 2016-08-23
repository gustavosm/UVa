#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, d;
ll v[205];
ll dp[205][25][15];
bool calculei[205][25][15];

ll calc(int i, int j, int k)
{
	if (k == m)
	{
		if (!j) return 1;
		else return 0;
	}
	
	if (i == n) return 0;
	
	ll &ans = dp[i][j][k];
	if (!calculei[i][j][k])
		ans = calc(i + 1, j, k) + calc(i + 1, ((j + v[i]) % d + d) % d, k + 1);
	calculei[i][j][k] = true;
	return ans;
}

int main()
{
	int q;
	int st = 1;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n >> q;
		if (!n) return 0;
		cout << "SET " << st++ << ":\n";
		for (int i = 0 ; i < n ; ++i) cin >> v[i];
		
		for (int qr = 1; qr <= q; ++qr)
		{
			cin >> d >> m;
			memset(calculei, false, sizeof calculei);
			cout << "QUERY " << qr << ": " << calc(0, 0, 0) << '\n';
		}
	}
}
