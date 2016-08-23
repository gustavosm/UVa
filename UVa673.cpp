#include <bits/stdc++.h>


using namespace std;

int abre(char s)
{
	return s == '(' || s == '[';
}

int inverso(char c, char d)
{
	return ((c == '(' && d == ')') || (c == '[' && d == ']'));
}
int main()
{
	stack<char> s;
	
	int cases;
	bool ok;
	string s1;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> cases;
	
	cin.ignore();
	
	while (cases--)
	{
		getline(cin, s1);
		int i = 0 ;
		ok = true;
		while (i < s1.size())
		{
			if (s1[i] == ' ')
			{
				++i;
				continue;
			}
			if (abre(s1[i]))
				s.push(s1[i]);
			else
			{
				if (s.empty())
				{
					ok = false;
					break;
				}
				if (!inverso(s.top(), s1[i]))
				{
					ok = false;
					break;
				}
				s.pop();
			}
			++i;
		}
		if (ok && s.empty()) cout << "Yes\n";
		else cout << "No\n";
		while (!s.empty()) s.pop();
		
	}
	
}
