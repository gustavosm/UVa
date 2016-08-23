#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

ll cd[25];

ll dp[20000][25];

int n;
int N;

ll solve(int pos, int sum)
{
	if (sum > N) return (ll)INT_MIN;
	if (sum == N) return 0LL;
	if (pos == n) return 0LL;
	
	ll &ans = dp[sum][pos];
	
	if (ans == 0)
		ans = max(cd[pos] + solve(pos + 1, sum + cd[pos]), solve(pos + 1, sum));
		
	return ans;
}

void recupera(int pos, int sum)
{
	if (pos == n) return;
	if (sum == N) return;
	
	if (dp[sum][pos] - cd[pos] == dp[sum + cd[pos]][pos + 1])
	{
		cout << cd[pos] << ' ';
		recupera(pos + 1, sum + cd[pos]);
	}
	else
		recupera(pos + 1, sum);
}
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	while (cin >> N)
	{
		cin >> n;
		for (int i = 0 ; i < n; ++i)
			cin >> cd[i];
		memset(dp, 0, sizeof dp);
		ll sum = solve(0, 0);
		
		recupera(0, 0);
		cout << "sum:" << sum << '\n';		
	}
}
