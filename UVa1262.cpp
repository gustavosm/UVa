#include <bits/stdc++.h>


using namespace std;


int main()
{
	int cases;
	string s;
	vector<string> v1, v2;
	string pos[7];
	int k;
	
	cin >> cases;
	
	while(cases--)
	{
		cin >> k;
		
		for (int i = 0 ; i < 6; ++i)
		{
			cin >> s;
			v1.push_back(move(s));
		}
		for (int i = 0 ; i < 6; ++i)
		{
			cin >> s;
			v2.push_back(move(s));
		}
		
		int i = 0;
		int flag;
		for (int z = 0 ; z < 5; ++z)
		{
			flag = 0;
			for (int i = 0 ; i < 6; ++i)
			{
				for (int j = 0 ; j < 6; ++j)
				{
					if (v1[i][z] == v2[j][z])
						pos[z].push_back(v1[i][z]);
				}
			}
			sort(pos[z].begin(), pos[z].end());
		}
		string aux;
		bool deu = false;
		flag = (pos[0].size() && pos[1].size() && pos[2].size() && pos[3].size() && pos[4].size());
		
		if (!flag) cout << "NO\n";
		else
		{
			for (int i = 0 ; i < pos[0].size() && !deu; ++i)
			{
				for (int j = 0; j < pos[1].size() && !deu; ++j)
				{
					for (int z = 0 ; z < pos[2].size() && !deu; ++z)
					{
						for (int l = 0 ; l < pos[3].size() && !deu; ++l)
						{
							for (int m = 0 ; m < pos[4].size() && !deu; ++m)
							{							
								--k;								
								if (!k)
								{
									aux.push_back(pos[0][i]);
									aux.push_back(pos[1][j]);
									aux.push_back(pos[2][z]);
									aux.push_back(pos[3][l]);
									aux.push_back(pos[4][m]);
									cout << aux << '\n';
									deu = 1;
								}
								aux.clear();
							}
						}
					}
				}
			}
			
			if (!deu) cout << "NO\n";
		}
		for (int i = 0 ; i < 5 ;++i) pos[i].clear();
		v1.clear();
		v2.clear();
		
	}
}
