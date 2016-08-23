#include <bits/stdc++.h>


using namespace std;
 
int A[2500], Ma[2500], Mb[2500];
int N, T;
 
int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> T;
    for(int t = 0; t < T; ++t)
    {
    	cin >> N;
        for(int i = 0; i < N; ++i)
            cin >> A[i];
 
        for(int i = N - 1; i >= 0; --i) 
        {
            Ma[i] = 1;
            for(int j = i + 1; j < N; ++j)
            {
                if(A[i] < A[j]) 
                    Ma[i] = max(Ma[j] + 1, Ma[i]);
                
            }
        }
        for(int i = N - 1; i >= 0; --i) 
        {
            Mb[i] = 1;
            for(int j = i + 1; j < N; ++j) 
            {
                if(A[i] > A[j]) 
                    Mb[i] = max(Mb[j] + 1, Mb[i]);
            
            }
        }
        
        int ans = 0;
        for(int i = 0; i < N; i++) 
            ans = max(ans, Ma[i] + Mb[i] - 1);
        
        cout << ans << '\n';
    }
}
