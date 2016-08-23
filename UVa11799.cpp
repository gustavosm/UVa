#include <bits/stdc++.h>


using namespace std;


int main()
{
	int tc;
	

	int maior = -1;
	int x;
	int n;

	cin >> tc;
	
	for (int c = 1; c <= tc; ++c)
	{
		maior = -1;
		cin >> n;
		
		for (int i = 0 ;i < n ; ++i)
		{
			cin >> x;
			if (maior < x) maior = x;
		}
		
		cout << "Case " << c << ": " << maior << '\n';
	}
}
