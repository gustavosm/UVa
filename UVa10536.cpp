#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 16);
int dp[N];
string g[5];

static int dr[] = {0, 0, 1, -1};
static int dc[] = {1, -1, 0, 0};

int calc(int n) 
{
    if(n == N - 1)
        return 1;
        
    int &ans = dp[n];
    
    if (ans == -1)
    {
    	ans = 0;
		for(int i = 0; i < 4; ++i)
		{
		    for(int j = 0; j < 4; ++j)
		    {
		        if((n >> (i * 4 + j)) & 1)
		            continue;
		        ans |= (!calc(n | (1 << (i * 4 + j))));
		        if(ans)
		            return ans;
		            
		        for(int k = 0; k < 4; ++k) 
		        {
		            int x, y, pin = 0;
		            x = i, y = j;
		            if(x - dr[k] >= 0 && x - dr[k] < 4 && y - dc[k] >= 0 && y - dc[k] < 4)
		               	continue;
		            else
		            {
				        for(int l = 0; l < 3; ++l) 
				        {
				            pin |= 1 << (x * 4 + y);
				            ans |= !calc(n | pin);
				            
				            if(ans)
				                return ans;
				            x += dr[k], y += dc[k];
				            
				            if(x < 0 || y < 0 || x >= 4 || y >= 4)
                        		break;
				            if((n >> (x * 4 + y)) & 1)
				                break;
				        }
				    }
		        }
		    }
    	}
    }
    return ans;
}
int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
    int cases;
    int i, j, k;
    cin >> cases;
    
    memset(dp, -1, sizeof dp);
    while(cases--) 
    {
        int n = 0;
        for(i = 0; i < 4; ++i)
        	cin >> g[i];
        	
        for(i = 0; i < 4; ++i) 
        {
            for(j = 0; j < 4; ++j)
            {
                if(g[i][j] == 'X')
                    n |= 1 << (i * 4 + j);
            }
        }
        int ans = calc(n);
        if (!ans)
	        cout << "LOSING\n";
        else cout << "WINNING\n";
    }
    return 0;
}
