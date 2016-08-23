#include <bits/stdc++.h>


using namespace std;

struct point
{
	int x;
	int y;
};
double dp[1 << 17];
int n;
point v[17];

double dist(point &a, point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

double calc(int mask)
{
	if (mask == (1 << n) - 1) return 0.0;
	
	double &ans = dp[mask];
	
	if (ans == 99999.99)
	{
		int i;
		for (i = 0 ; i < n; ++i)
			if (!(mask & (1 << i))) break;
		for (int j = i + 1; j < n ; ++j)
		{
			if (!(mask & (1 << j)))
				ans = min(ans, dist(v[i], v[j]) + calc(mask | (1 << i) | (1 << j)));
		}
	}
	return ans;
}

int main()
{
	string s;
	int c = 1;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n;
		if (!n) break;
		
		n *= 2;
	
		for (int i = 0 ; i < n ; ++i)
			cin >> s >> v[i].x >> v[i].y;
			
		for (int i = 0 ; i < (1 << n) ; ++i)
			dp[i] = 99999.99;
		
		cout << "Case " << c++ << ": " << setprecision(2) << fixed << calc(0) << '\n';
	}
}
