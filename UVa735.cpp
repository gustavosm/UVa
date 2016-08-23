#include <bits/stdc++.h>


using namespace std;
#define mp make_pair

typedef long long ll;

set<int> pts;
set<set<int> > s;
vector<int> possivel;
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	pts.insert(0);
	for (int i = 1; i < 21; ++i)
	{
		pts.insert(i);
		pts.insert(i * 2);
		pts.insert(i * 3);
	}
	pts.insert(50);
	for(set<int> :: iterator it = pts.begin(); it != pts.end(); ++it)
		possivel.push_back(*it);
		
	int n;
	
	while (cin >> n)
	{	
		if (n <= 0) break;
		
		s.clear();
		ll perm = 0LL;
		for (int i = 0 ; i < possivel.size() && (n - possivel[i] >= 0); ++i) 
			for (int j = 0 ; j < possivel.size() && (n - possivel[i] - possivel[j] >= 0); ++j)
				for (int k = 0 ; k < possivel.size() && (n - possivel[i] - possivel[j] - possivel[k] >= 0); ++k)
					if (possivel[i] + possivel[j] + possivel[k] == n)
					{
						set<int> comb;
						comb.insert(i); 
						comb.insert(j); 
						comb.insert(k);
						s.insert(comb);
					}
			
		for (set<set<int> > :: iterator it = s.begin(); it != s.end(); ++it)
		{
			if ((*it).size() == 1) ++perm;
			else if ((*it).size() == 2) perm += 3;
			else if ((*it).size() == 3) perm += 6;
		}
		
		if (s.size() > 0) 
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << s.size() << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << ".\n";
		} 
		else 
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
		
		for (int i = 0; i < 70; ++i) cout << "*";
		cout << '\n';
	}	
	cout << "END OF OUTPUT\n";
}
