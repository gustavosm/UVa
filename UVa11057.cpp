#include <bits/stdc++.h>


using namespace std;

vector<int> p;
int n;

int bs(int b, int e, int val, int npode)
{
	int mid;
	
	while (b <= e)
	{
		mid = (b + e) / 2;
		
		if (p[mid] == val && mid != npode)
			return mid;
		else if (p[mid] == val && mid == npode)
		{
			if (mid > 0 && p[mid - 1] == val)
				return mid - 1;
			if (mid < n - 1 && p[mid + 1] == val)
				return mid + 1;
			return -1;
		}
		else
		{
			if (p[mid] < val) b = mid + 1;
			else  e = mid - 1;
		}
	}
	return -1;
}

int main()
{	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int k;
	while (cin >> n)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			int x;
			cin >> x;
			p.push_back(x);
		}
		sort(p.begin(), p.end());
		
		cin >> k;
		int diff = 198237120;
		int v1, v2;
		for (int i = 0 ; i < n ; ++i)
		{
			int c;
			if ((c = bs(0, n - 1, k - p[i], i)) != -1)
			{
				if (diff > abs(p[c] - p[i]))
				{
					diff = abs(p[c] - p[i]);
					v1 = min(p[c], p[i]);
					v2 = max(p[c], p[i]);
				}	
			}
		}
		cout << "Peter should buy books whose prices are " << v1 << " and " << v2 << ".\n\n";
		p.clear();
	}
}
