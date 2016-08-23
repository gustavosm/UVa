#include <bits/stdc++.h>


using namespace std;

int coinvalue[] = {1, 5, 10, 25, 50};
int dp[6][7500];

int calc(int type, int restante)
{
	if (restante == 0) return 1;
	if (restante < 0 || type == 5) return 0;
	
	int &ans = dp[type][restante];
	
	if (ans == -1)
		ans = calc(type + 1, restante) + calc(type, restante - coinvalue[type]);
	return ans;
}
int main()
{
	int n;
	memset(dp, -1, sizeof dp);
	while (cin >> n)
	{		
		cout << calc(0, n) << '\n';
	}
}
