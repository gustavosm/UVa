#include <bits/stdc++.h>


using namespace std;


int main()
{
	map<string, int> m;
	
	int n;
	string s;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n)
	{
		cin >> s;
		int mx = -1;
		string ans;
		for (int i = 0 ; i < s.size() - n + 1 ; ++i)
		{
			string aux = s.substr(i, n);
			int &freq = m[aux];
			++freq;
			if (freq > mx)
			{
				mx = freq;
				ans = aux;
			}
		}
		cout << ans << '\n';
		m.clear();
	}
}
