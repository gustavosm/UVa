#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100010

char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() 
{ 
	int i = 0, j = -1; b[0] = -1; 
	while (i < m) 
	{ 
		while (j >= 0 && P[i] != P[j]) j = b[j]; 
		i++; j++; 
		b[i] = j; 
	} 
}
int kmpSearch() 
{
	int i = 0, j = 0;
	
	while (i < n) 
	{
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;

		if (i == n) return j; 
	} 
	return 0;
}

int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> T)
	{
		strcpy(P, T);
		n = m = strlen(P);
		reverse(P, P + m);
		kmpPreprocess();
		int idx = n - kmpSearch();
		
		cout << T;
		for (int i = idx - 1; i >= 0; --i) cout << T[i];
		cout << '\n';
	}
}
