#include <bits/stdc++.h>


using namespace std;


bool vis[35][35][6000];

bool used[6000];
int sig[35];

int n;
int num[35];


void calc(int idx, int open, int val)
{
	if (vis[idx][open][val + 3000])
		return;
	vis[idx][open][val + 3000] = true;
	
	if (idx == n)
	{
		used[val + 3000] = true;
		return;
	}
	
	int newval = val + num[idx] * sig[idx] * (open & 1? -1 : 1);
	if (sig[idx] == -1)
		calc(idx + 1, open + 1, newval);
	if (open > 0)
		calc(idx + 1, open - 1, newval);
	calc(idx + 1, open, newval);
}
int toint(string &nums)
{
	int ret = 0;
	for (int i = 0 ; i < nums.size(); ++i)
	{
		ret *= 10;
		ret += (nums[i] - '0');
	}
	return ret;
}
int main()
{
	string nums;
	string input;
	
	stringstream ss;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (getline(cin, input))
	{
		ss << input;
		int idx_num = 0;
		sig[0] = 1;
		while (ss >> nums)
		{
			if (nums == "-")
				sig[idx_num] = -1;
			else if (nums == "+")
				sig[idx_num] = 1;
			else
				num[idx_num++] = toint(nums);
		}
		
		n = idx_num;
		
		ss.clear();
		
		memset(vis, false, sizeof vis);
		memset(used, false, sizeof used);
		
		calc(0, 0, 0);
		int ans = 0;
		for (int i = 0 ; i < 6000; ++i)
			ans += used[i];
			
		cout << ans << '\n';
	}
}
