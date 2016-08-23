#include <bits/stdc++.h>

using namespace std;


vector<vector<int> > v;

vector<int> visited;

void dfs(int n)
{
	visited[n] = 1;
	
	for (int i = 0 ; i < v[n].size(); ++i)
		if (!visited[v[n][i]]) 
			dfs(v[n][i]);
}


int main()
{
	int existe[27];
	int cases;
	int trees, acorns;
	
	string in;
	string vertices;
	
	cin >> cases;
	
	while (cases--)
	{
		v.assign(27, vector<int>());
		visited.assign(27, 0);
		
		memset(existe, 0, sizeof existe);
		
		while (1)
		{
			cin >> in;
			
			if (in[0] == '*') break;
			
			v[in[1] - 'A'].push_back(in[3] - 'A');
			v[in[3] - 'A'].push_back(in[1] - 'A');			
		}
		
		cin >> vertices;
		
		for (int i = 0 ; i < vertices.size(); i += 2)
			existe[vertices[i] - 'A'] = 1;
		trees = acorns = 0;
		
		for (int i = 0 ; i < 26; ++i)
		{
			if (existe[i])
			{
				if (!visited[i])
				{
					if (v[i].size() > 0) dfs(i), ++trees;
					else ++acorns;
					
					visited[i] = 1;
				}
			}
		}
		
		cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
		
		v.clear();
		visited.clear();
	}
}
