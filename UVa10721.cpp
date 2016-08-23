#include <bits/stdc++.h>


using namespace std;


typedef long long i64;
i64 dp[60][60][60];
i64 solve(int n,int k,int m)
{
    if(k==0)
    {
        if(n)return 0;
        return 1;
    }
    i64 &ret=dp[n][k][m];
    if(ret!=-1)return ret;
    int i;
    ret=0;
    for(i=1;i<=m;i++)
    {
        if(n-i>=0)ret+=solve(n-i,k-1,m);
        else break;
    }
    return ret;
}
int main()
{
    int n,k,m;
    while(cin>>n>>k>>m)
    {
       memset(dp,-1,sizeof dp);
       cout<<solve(n,k,m)<<endl;
    }
    return 0;
}
