#include <bits/stdc++.h>


using namespace std;

int main()
{
	int v[15];
	int n;
	int cases;
	
	cin >> cases;
	
	for (int c = 1; c <= cases; ++c)
	{
		cin >> n;
		
		for (int i = 0 ; i < n ; ++i)
			cin >> v[i];
			
		sort(v, v + n);
		
		cout << "Case " << c << ": " << v[ n / 2 ] << '\n';
	}
}
