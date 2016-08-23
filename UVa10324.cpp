#include <bits/stdc++.h>


using namespace std;


int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	string in;
	int queries;
	int arr[1000006];
	int c = 0;
	int a, b;
	while (cin >> in)
	{
		arr[0] = in[0] - '0';
		for (int i = 1; i < in.size(); ++i)
			arr[i] = in[i] - '0' + arr[i - 1];
			
		cin >> queries;
		
		cout << "Case " << (++c) << ":\n";
		while (queries--)
		{
			cin >> a >> b;
			
			int mn = min(a, b);
			int mx = max(a, b);
			
			int sum = arr[mx] - (mn - 1 >= 0? arr[mn - 1] : 0);
			
			if (sum == 0) cout << "Yes\n";
			else if (sum == (mx - mn + 1)) cout << "Yes\n";
			else cout << "No\n";
		}
	}
		
}
