#include<bits/stdc++.h>
using namespace std;

class Point
{
	public:
	int x;
	int y;
	
	Point(int xp,int yp)
	{
		x=xp;
		y=yp;
	}
};

class Interval
{
	public:
	int bottom;
	int top;
	
	Interval(int x,int y)
	{
		bottom = x;
		top = y;
	}
	bool operator<(const Interval& rhs)
	{
		if(bottom != rhs.bottom)
        	return (bottom < rhs.bottom);
        
        else
        	return (top < rhs.top);
	}
  	bool operator==(const Interval& rhs)
	{
		return ((bottom == rhs.bottom)&&(top == rhs.top));
	}
};

class LineSegment
{
	public:
	Interval intv;
	int coord;
	
	LineSegment(Interval obj,int c):intv(obj),coord(c){}
	
	bool operator<(const LineSegment& rhs)
	{
		if(coord != rhs.coord)
        	return (coord < rhs.coord);
        
        else
        	return (intv < rhs.intv);
	}
  	bool operator==(const LineSegment& rhs)
	{
		return ((coord == rhs.coord)&&(intv == rhs.intv));
	}	
};

class Rectangle
{
	public:
	int x_left;
	int x_right;
	int y_bottom;
	int y_top;
	
	Rectangle(int xl,int xr,int yb,int yt):x_left(xl),x_right(xr),y_bottom(yb),y_top(yt){}
	Rectangle(Interval x,Interval y):x_left(x.bottom),x_right(x.top),y_bottom(y.bottom),y_top(y.top){}
};

class EdgeType
{
	public:
	char value;
	
	EdgeType(char t):value(t){}
};

class Edge
{
	public:
	Interval intv;
	int coord;
	EdgeType side;
	
	Edge(Interval obj,int c,EdgeType t):intv(obj),coord(c),side(t){}
	
	bool operator<(const Edge& rhs)
	{
		if(side.value!= rhs.side.value)
			if(side.value == 'l' || side.value == 'r')
				return (side.value == 'l');
		else if(coord != rhs.coord)
        	return (coord < rhs.coord);
        
        else if(intv.bottom != rhs.intv.bottom)
        	return (intv.bottom < rhs.intv.bottom);
        else if(intv.top != rhs.intv.top)
        	return (intv.top < rhs.intv.top);    
        return (side.value == 'b');    
	}
  	bool operator==(const Edge& rhs)
	{
		return ((coord == rhs.coord)&& (intv == rhs.intv));
	}
};

class ctree
{
	public:
	int x;
	char lru;
	ctree *lson;
	ctree *rson;
	ctree(int xl,char lrul,ctree *lsonl,ctree *rsonl):x(xl),lru(lrul),lson(lsonl),rson(rsonl){}
};

class Stripe
{
	public:
	Interval x_interval;
	Interval y_interval;
	ctree *tree;
	
	Stripe(Interval x,Interval y,ctree *xset):x_interval(x),y_interval(y),tree(xset){}
};	

