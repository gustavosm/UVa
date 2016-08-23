#include <bits/stdc++.h>


using namespace std;

struct point
{
	int x, y;
	
	point() { x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {}
	
	bool operator < (const point &other) const
	{
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
};

struct point2
{
	double x, y;
	
	point2() { x = y = 0;}
	point2(double _x, double _y) : x(_x), y(_y) {}
};

struct vec
{
	double x, y;
	vec() {x = y = 0;}
	vec(double _x, double _y) : x(_x), y(_y){}
};

vec toVec(point a, point b)
{
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x;}

int ccw(point &p, point &q, point &r)
{
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

void convexHull(vector<point> &pts, vector<point> &up, vector<point> &dn)
{
	up.assign(pts.size(),point());
	dn.assign(pts.size(),point());
	int i = 0, j = 0;
	
	for(vector<point>::iterator it = pts.begin(); it != pts.end(); ++it){
		while(i > 1 && ccw(up[i-2], up[i-1], *it)) i--;
		while(j > 1 && !ccw(dn[j-2], dn[j-1], *it)) j--;
		
		up[i++] = *it;
		dn[j++] = *it;
	}
	up.resize(i);
	dn.resize(j);
}

double dot(vec a, vec b) {return a.x * b.x + a.y * b.y;}
vec scale(vec a, double u)
{
	return vec(a.x * u, a.y * u);
}
point2 translate(point p, vec v)
{
	return point2(p.x + v.x, p.y + v.y);
}

double dist(point p, point2 c)
{
	return hypot(p.x - c.x, p.y - c.y);
}
double dtol(point& p, point& a, point& b)
{
    point2 c;
     
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / dot(ab, ab);
    c = translate(a, scale(ab, u));
    double d = dist(p, c);
    return d;
}

int main()
{
	int n;
	vector<point> pts;
	vector<point> up;
	vector<point> dn;
	int x, y;
	int c = 1;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y;
			
			pts.push_back(point(x, y));
		}
		sort(pts.begin(), pts.end());
		
		convexHull(pts, up, dn);
		
		pts.clear();
		
		for (int i = 0 ; i < up.size(); ++i)
			pts.push_back(up[i]);
		for (int i = dn.size() - 2 ; i > 0 ; --i)
			pts.push_back(dn[i]);
			
		
		n = pts.size();			
		double ans = 1e9;
		for (int i = 0 ; i < n; ++i)
		{
			double mn = 0.0;
			for (int j = 0 ; j < n; ++j)
			{
				mn = max(mn, dtol(pts[j], pts[i], pts[(i + 1) % n]));				
			}
			ans = min(mn, ans);
		}
		cout << "Case " << c++ << ": " << setprecision(2) << fixed << ans << '\n';
		pts.clear();
		up.clear();
		dn.clear();
	}
}
