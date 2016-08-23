#include <bits/stdc++.h>


using namespace std;

int main()
{
	int h, m;
	
	
	while (scanf("%d:%d", &h, &m), h || m)
	{
		double ang1 = (double)h * 30.;
		double ang2 = (double)m * 5.5;
		
		double aux = min(ang1, ang2);
		ang1 = max(ang1, ang2);
		ang2 = aux;
		
		printf("%.3lf\n", min(ang1 - ang2, 360 - ang1 + ang2));
	}
}
