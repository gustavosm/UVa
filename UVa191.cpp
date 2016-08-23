#include <bits/stdc++.h>

#define EPS 1e-9
using namespace std;

struct line
{
	double a, b, c;
};
struct point
{
	double x, y;
	
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y){}
	
	bool operator < (const point &other) const
	{
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
	bool operator == (const point &other) const
	{
		return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
	}
	bool operator <= (const point &other) const
	{
		return (*this) < other || (*this) == other;
	}
};
void pointsToLine(point p1, point p2, line &l) 
{
	if (fabs(p1.x - p2.x) < EPS)
	{
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	} 
	else 
	{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	} 
}
bool areParallel(line l1, line l2) 
{
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool areIntersect(line l1, line l2, point &p) 
{
	if (areParallel(l1, l2)) return false;

	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true; 
}

int main()
{
	int xstart, xend, ystart, yend, xleft, ytop, xright, ybottom;
	line l1, l2, l3, l4, l5;
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> xstart >> xend >> ystart >> yend >> xleft >> ytop >> xright >> ybottom;
		
		if (xleft > xright) swap(xleft, xright);
		if (ytop < ybottom) swap(ytop, ybottom);
		
		pointsToLine(point(xstart, ystart), point(xend, yend), l1);
		pointsToLine(point(xleft, ytop), point(xleft, ybottom), l2);
		pointsToLine(point(xleft, ytop), point(xright, ytop), l3);
		pointsToLine(point(xright, ytop), point(xright, ybottom), l4);
		pointsToLine(point(xright, ybottom), point(xleft, ybottom), l5);
		
		point c;
		if (areIntersect(l1, l2, c))
		{
			if (point(xleft, ybottom) <= c && c <= point(xleft, ytop))
				cout << "T\n";
			else
			{
				if (areIntersect(l1, l3, c))
				{
					if (point(xleft, ytop) <= c && c <= point(xright, ytop))
						cout << "T\n";
					else
					{
						if (areIntersect(l1, l4, c))
						{
							if (point(xright, ybottom) <= c && c <= point(xright, ytop) )
								cout << "T\n";
							else
							{
								if (areIntersect(l1, l5, c))
								{									
									if (point(xleft, ybottom) <= c && c <= point(xright, ybottom))
										cout << "T\n";
									else cout << "F\n";
								}
								else cout << "F\n";
							}
						}
						else cout << "F\n";
					}
				}
				else cout << "F\n";
			}
		}
		else cout << "F\n";
	}
}
