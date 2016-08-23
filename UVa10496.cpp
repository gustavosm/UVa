#include <bits/stdc++.h>


using namespace std;

int Ox[15];
int Oy[15];
int d[15][15];
int dp[15][1100];

int n;

int dist(int i, int j)
{
	return abs(Ox[i] - Ox[j]) + abs(Oy[i] - Oy[j]);
}

int calc(int pos, int mask)
{
	if (mask == (1 << n) - 1) return d[pos][0];
	
	int &ans = dp[pos][mask];
	
	if (ans == -1)
	{
		ans = INT_MAX;
		for (int i = 0 ; i < n ; ++i)
		{
			if (i != pos && !(mask & (1 << i)))
			{
				ans = min(ans, d[pos][i] + calc(i, mask | (1 << i)));
			}
		}
	}
	return ans;
}
int main()
{
	int cases;
	int x, y;
	int tx, ty;
	//Entrada: coordenadas dos pontos (vertices)... a distancia entre os vertices eh calculada por distancia de manhatan
	cin >> cases;
	
	while (cases--)
	{
		cin >> tx >> ty; //tamanho da matriz -> dimensoes tx e ty
		
		cin >> Ox[0] >> Oy[0]; // coordenada do ponto de origem
		cin >> n; // quantos pontos tao no grafo
		
		for (int i = 1 ; i <= n ; ++i)
		{
			cin >> Ox[i] >> Oy[i];
		}
		++n;
		
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
			{
				d[i][j] = dist(i, j); //pre calcula as distancias entre os vertices
			}
		}
		memset(dp, -1, sizeof dp);
		cout << "The shortest path has length " << calc(0, 1) << '\n'; //faz a dp pra encontrar o menor caminho que passa por todos os vertices
	}
}
