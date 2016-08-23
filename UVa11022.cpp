#include <bits/stdc++.h>


using namespace std;

map<string, int> m;

int ok(int b, int e, string &s)
{
	if (s.size() - e < e - b) return 1;
	
	for (int i = 0 ; i < e - b;  ++i)
		if (s[b + i] != s[e + i]) return 1;
	return 0;
}

int solve(string s)
{
	if (m.count(s)) return m[s];
	
	int ans;
	int sz = s.size();
	
	ans = s.size();
	
	for (int i = 0 ; i < sz; ++i)
	{
		for (int j = i + 1 ; j < sz; ++j)
		{
			string aux = s;
			while (!ok(i, j, aux))
				aux = aux.substr(0, i) + aux.substr(j);
			if (aux != s)
				ans = min(ans, solve(aux.substr(0, i)) + solve(aux.substr(i, j - i)) + solve(aux.substr(j)));
		}
	}
	m[s] = ans;
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	string s;
	
	while (1)
	{
		cin >> s;
		if (s[0] == '*') return 0;
		
		cout << solve(s) << '\n';
		//m.clear(); n precisa limpar o mapa
	}
}
