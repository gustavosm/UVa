#include <bits/stdc++.h>


using namespace std;
void lower_case(string &s)
{
	int i = 0;
	while (i < s.size())
	{
		s[i] = tolower(s[i]);
		++i;
	}
}
int main()
{
	map<string, vector<string> > m;
	vector<string> ans;
	string s;
	
	while (cin >> s)
	{
		if (s == "#") break;
		
		string aux = s;
		lower_case(s);
		sort(s.begin(), s.end());
		
		m[s].push_back(aux);
	}
	for (map<string, vector<string> > :: iterator it = m.begin(); it != m.end(); ++it)
	{
		vector<string> &v = it->second;
		if ((v.size()) == 1) ans.push_back(v[0]);
	}
	sort(ans.begin(), ans.end());
	
	for (int i = 0 ; i < ans.size(); ++i)
	{
		cout << ans[i] << '\n';
	}
	m.clear();
	ans.clear();
}
