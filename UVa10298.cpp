#include <bits/stdc++.h>

#define MAXN 1000010

using namespace std;

int F[MAXN];

void kmp_init(string& P)
{
    F[0] = 0;  F[1] = 0;  
    int i = 1, j = 0;
    while(i < P.size()) 
    {
        if (P[i] == P[j])
            F[++i] = ++j;
        else if (!j)
            F[++i] = 0;
        else
            j = F[j];
    }
}

int kmp(string& P, string& T) 
{
    kmp_init(P);
    int i = 1, j = 0;
    int n = T.size(), m = P.size();
    
    while(i - j <= n - m) 
    {
        while(j < m && P[j] == T[i]) 
        {
            ++i;
            ++j;
        }
        
        if (j == m) return i - m;
        else if (j == 0) ++i;
        
        j = F[j];
    }
}


int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
    string P, T;
    while(cin >> P) 
    {
    	if (P[0] == '.') return 0;
        T = P+P;
        cout << P.size() / kmp(P, T) << endl;
    }
}
