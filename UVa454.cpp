#include <bits/stdc++.h>


using namespace std;

void replace(string &s)
{
	sort(s.begin(), s.end());
	string aux;
	
	for (int i = 0 ; i < s.size(); ++i) if (s[i] != ' ') aux.push_back(s[i]);
	
	s.clear();
	s = move(aux);
}
int main()
{
	int cases;
	stringstream ss;
	vector<string> v;
	string aux, s, s2, aux2;
	
	cin >> cases;
	int pl = 0;
	getchar();
	getchar();
	
	while (cases--)
	{
		while(getline(cin, s))
		{
			if (s == "") break;
			v.push_back(s);
		}
		sort(v.begin(), v.end());

		for (int i = 0 ; i < v.size(); ++i)
		{

			aux = v[i];
	
			replace(aux);
			for (int j = i + 1; j < v.size(); ++j)
			{
				aux2 = v[j];
				replace(aux2);
				if (aux2 == aux)
				{
					cout << v[i] << " = " << v[j] << '\n';
				}
			}
		}
		v.clear();
		
		if (cases) cout << '\n';
	}
}
