#include <bits/stdc++.h>


using namespace std;


typedef long long ll;


ll dp[205];
int n;
char s[205];

ll f(int idx)
{
	if (idx == n) return 0;
	
	if (s[idx] == '0') return dp[idx] = f(idx + 1);
	
	ll &ans = dp[idx];
	
	if (ans == -1)
	{
		ll num;
		
		int k = 1;
		
		while (idx + k <= n)
		{
			num = 0;
			for (int j = idx ; j < (idx + k); ++j)
				num = num * 10 + s[j] - '0';
			if (num > INT_MAX) break;
			ans = max(ans, num + f(idx + k));
			++k;		 
		}		
	}
	return ans;
}

int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> s;
		
		memset(dp, -1, sizeof dp);
		n = strlen(s);
		
		cout << f(0) << '\n';
	}
}
