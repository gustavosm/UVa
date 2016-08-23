#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

struct point{
	double x;
	double y;
	
	point(){x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y){}
	
	bool operator == (const point &other) const {
		if (fabs(x - other.x) > EPS) return x < other.x;
		return y < other.y;
	}
	bool operator != (const point &other) const{
		return ((fabs(x - other.x) > EPS) || (fabs(y - other.y) > EPS));
	}
};

double _rotate[2];

double raio;
point centro;

inline point circle(point& a, point& b, point& c)
{
	double d = 2.*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
	
	return point(((a.x*a.x + a.y*a.y)*(b.y - c.y) + (b.x*b.x + b.y*b.y)*(c.y - a.y) + (c.x*c.x + c.y*c.y) * (a.y - b.y))/d,
				  ((a.x*a.x + a.y*a.y)*(c.x - b.x) + (b.x*b.x + b.y*b.y)*(a.x - c.x) + (c.x*c.x + c.y*c.y) * (b.x - a.x))/d);
}

point rotaciona(point &a)
{
	double x = a.x * _rotate[0] - a.y* _rotate[1];
	double y = a.x * _rotate[1] + a.y * _rotate[0];
	
	return point((fabs(x) < EPS ? 0 : x), (fabs(y) < EPS ? 0 : y));
}

void preenche_rotaciona(int n)
{
	double angle = 360. / n ;
	
	angle *= (M_PI / 180.);
	
	_rotate[0] = cos(angle);
	_rotate[1] = sin(angle);
}
vector<point> polygon(int n, point & faz_parte)
{
	vector<point> ret;
	point next_p = point(faz_parte.x - centro.x, faz_parte.y - centro.y);
	while (ret.size() < n)
	{
		ret.push_back(next_p);
		next_p = rotaciona(next_p);
	}
	return ret;
}

int main()
{
	int n;
	point points[3];
	vector<point> pol;
	double x, y;
	double mnx, mny, mxx, mxy;
	int polyg = 0;
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		preenche_rotaciona(n);
		for (int i = 0 ; i < 3; ++i)
		{
			cin >> x >> y;
			points[i] = point(x, y);
		}
		
		centro = circle(points[0], points[1], points[2]);
		pol = polygon(n, points[0]);
		
		mnx = mxx = pol[0].x;
		mny = mxy = pol[0].y;
		for (int i = 1 ; i < pol.size() ; ++i)
		{
			mnx = min(mnx, pol[i].x);
			mny = min(mny, pol[i].y);
			mxx = max(mxx, pol[i].x);
			mxy = max(mxy, pol[i].y);
		}
		
		double ans = (mxx - mnx) * (mxy - mny);
		cout << "Polygon " << (++polyg) << ": " << fixed << setprecision(3) << ans << '\n';
		
		pol.clear();
	}
}
