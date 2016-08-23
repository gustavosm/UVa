#include <bits/stdc++.h>


using namespace std;

set<string> st;


int compare(string a, string b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

int main()
{
	string s;
	vector<string> v;
	int sts = 1;
	while (cin >> s)
	{
		v.push_back(s);
		
		while (1)
		{
			cin >> s;
			
			if (s == "9") break;
			
			v.push_back(s);
		}
		
		sort(v.begin(), v.end(), compare);
		
		st.insert(v[0]);
		int flag;
		
		for (int i = 1; i < v.size(); ++i)
		{
			string aux = v[i];
			flag = 0;
			
			for (int t = aux.size() - 1; t >= 0 ; --t)
			{
				string sb = aux.substr(0, t + 1);
			//	cout << sb << '\n';
				if (st.find(sb) != st.end())
				{
					flag = 1;
					break;
				}	
			}
			st.insert(aux);
			if (flag) break;
		}
		
		if (!flag) cout << "Set " << sts++ << " is immediately decodable\n";
		else cout << "Set " << sts++ << " is not immediately decodable\n";
		
		v.clear();
		st.clear();
	}
}
