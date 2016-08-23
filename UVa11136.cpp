#include <bits/stdc++.h>


using namespace std;


multiset<int> s;

int main()
{
	int n;
	int x;
	int k;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (1)
	{
		cin >> n;
		
		if (!n) return 0;
		
		long long cost = 0LL;
		while (n--)
		{
			cin >> k;
			for (int i = 0 ; i < k ; ++i)
			{
				cin >> x;
				s.insert(x);
			}
			
			multiset<int> :: iterator it = s.begin();
			multiset<int> :: reverse_iterator it2 = s.rbegin();
			
			cost += (*it2) - (*it);
			s.erase(it);
			s.erase(s.find(*it2));
		}
		cout << cost << '\n';
		s.clear();
	}
}
