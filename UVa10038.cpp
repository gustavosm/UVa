#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	int atual, ult;
	
	int freq[3005];
	
	while (cin >> n)
	{
		if (n == 1)
		{
			cin >> ult;
			cout << "Jolly\n";
		}
		else
		{
			memset(freq, 0, sizeof freq);
		
			cin >> ult;
			for (int i = 1 ; i < n; ++i)
			{
				cin >> atual;
				int mod = abs(ult - atual);
				if (mod <= n - 1) ++freq[mod];
				ult = atual;
			}
			int flag = 0;
			for (int i = 1 ; i < n ; ++i)
			{
				if (!freq[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag) cout << "Not jolly\n";
			else cout << "Jolly\n";
		}
	}
}
