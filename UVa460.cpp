#include<bits/stdc++.h>

using namespace std;

int main() 
{
	int i,a,b,c,d,p,q,r,s,N,max1,max2,min1,min2; 
	scanf("%d",&N); 
	for(i=0;i<N;i++) 
	{ 
		if (i) cout << '\n';
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&p,&q,&r,&s);
		max1=max(a,p); 
		max2=max(b,q); 
		min1=min(c,r); 
		min2=min(d,s); 
		if(max1>=min1 || max2>=min2) printf("No Overlap\n"); 
		else printf("%d %d %d %d\n",max1,max2,min1,min2); 
	} 
	return 0; 
}
