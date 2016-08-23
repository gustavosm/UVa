#include <bits/stdc++.h>


using namespace std;



int main()
{
	ios_base :: sync_with_stdio(0);
	
	int l, x, w, o, h;
	
	
	
	while (scanf("%d %d %d %d", &l, &w, &h, &o) != EOF)
	{
		double x = l * tan(o * M_PI / 180.);
		if (x <= (double)h)
			printf("%.3lf mL\n", ((h + h - x) * l * w) / 2.);
		else
		{
			x = tan((90 - o) * M_PI / 180.) * h;
			
			printf("%.3lf mL\n", ((x * h) / 2.) * w);
		}
	}
}
