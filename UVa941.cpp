#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

ll fat[21];

void calc() 
{
	fat[0] = 1;
	for(int i = 1; i < 21; ++i)
		fat[i] = fat[i - 1] * i;
}

string solve(string& s, ll p) 
{
	string ans = s;

	for(int i = 0; i < s.size(); ++i) 
	{
		sort(ans.begin() + i, ans.end());
		
		if (!p)
			return ans;
			
		int cp = i + p / fat[s.size() - i - 1];
		
		swap(ans[i], ans[cp]);
		
		p %= fat[s.size() - i - 1];
	}

	return ans;
}

int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);

	calc();
	int n;
	string s;
	ll p;

	cin >> n;

	for(int i = 0; i < n; ++i) 
	{
		cin >> s >> p;

		cout << solve(s, p) << '\n';
	}
}
