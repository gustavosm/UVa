#include <bits/stdc++.h>


using namespace std;


int main()
{
	int v[3];
	
	int tc;
	
	cin >> tc;
	
	for (int c = 1; c <= tc; ++c)
	{
		cin >> v[0] >> v[1] >> v[2];
		
		sort(v, v + 3);
		
		cout << "Case " << c << ": " << v[1] << '\n';
	}
}
