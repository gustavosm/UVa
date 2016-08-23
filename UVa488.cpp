#include <bits/stdc++.h>


using namespace std;


int main()
{
	int a, f;
	int cases;
	
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> a >> f;
		
		while (f--)
		{
			int flag = 1;
			int i = 1;
			
			while (1)
			{
				for (int j = 0; j < i; ++j)
					cout << i;
				cout << '\n';
				
				if (i == a) flag = 0;
				if (flag) ++i;
				else --i;
				
				
				if (i == 0) break;
			}
			if (f) cout << '\n';
		}
		if (cases) cout << '\n';
	}
}
