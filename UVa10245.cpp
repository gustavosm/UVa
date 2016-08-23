#include <bits/stdc++.h>

#define MAX 10000.00000
#define EPS 1e-9
using namespace std;

struct point{
	double x, y;
	
	point(){x = y = 0.0;}
	point(double _x, double _y) : x(_x) , y(_y){}
	
	bool operator < (const point &other) const
	{
		if (fabs(other.x - x) > EPS) return x < other.x;
		return y < other.y;
	}
	
};

point p[10005];

double dist(point& a, point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

double closest_pair(int a, int b)
{
	if (b - a == 1) return dist(p[a], p[b]);
	if (a == b) return MAX;
	int mid = ((a + b) >> 1);
	double d1 = closest_pair(a, mid);
	double d2 = closest_pair(mid + 1, b);
	
	double ret = min(d1, d2);
	
	int j = mid;
	double xp = p[j].x;
	
	do{
		int k = mid + 1;
		while(xp - p[k].x < ret && k <= b)
		{
			d1 = dist(p[k],p[j]);
			ret = min(ret,d1);
			++k;
		}
		--j;
	}while(xp - p[j].x < ret && j >= a);
	
	return ret;
}

int main()
{
	int n;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0 ; i < n ; ++i)
			cin >> p[i].x >> p[i].y;
		
		sort(p, p + n);
		
		double ans = closest_pair(0, n - 1);
		
		if (MAX - ans > EPS) cout << setprecision(4) << fixed << ans << '\n';
		else cout << "INFINITY\n";
	}
}
