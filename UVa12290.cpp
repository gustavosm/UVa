#include <bits/stdc++.h>

using namespace std;


int main()
{
	map<int, int> m;
	
	char aux[30];
	
	for (int i = 7; i < 100000; i++)
	{
		sprintf(aux, "%d", i);
		
		if (strchr(aux, '7')) m[i]++;
		else  if (i % 7 == 0) m[i]++;
	}
	
	int n, m1, k;
	int p;
	int inc;
	int a;
	
	while(1)
	{
		cin >> n >> m1 >> k;
		if (!n && !m1 && !k) break;
		p = 1;
		a = 1;
		inc = 1;
		map<int, int> :: iterator it;
		it = m.begin();
		while (1)
		{
			if (it->first == a)
			{
				it++;
				if (p == m1) --k;
				
				if(!k)
				{
					cout << a << '\n';
					break;
				}
			}
			
			if (p == n) inc = -1;
			else if (p == 1) inc = 1;
			
			p += inc;
			++a;
		}
		
	}
}
