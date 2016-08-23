#include <bits/stdc++.h>


using namespace std;

int compare(char a, char b)
{
	bool ma = (a == tolower(a));
	bool mb = (b == tolower(b));
	
	if (ma == mb) return a < b;
	else
	{
		if (ma) 
		{
			a = toupper(a);
			return a < b;
		}
		b = toupper(b);
		
		return a <= b;
	}
}
int main()
{
	string s;
	int cases;
	
	
	cin >> cases;
	
	
	while(cases--)
	{
		cin >> s;
		
		sort(s.begin(), s.end(), compare);
		
		do
		{
			cout << s << '\n';
		}while(next_permutation(s.begin(), s.end(), compare));
	}
}
