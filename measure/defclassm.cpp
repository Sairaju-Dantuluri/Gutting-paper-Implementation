#include<bits/stdc++.h>
using namespace std;

class Pointm
{
	public:
	int x;
	int y;
	
	Pointm(int xp,int yp)
	{
		x=xp;
		y=yp;
	}
};

class Intervalm
{
	public:
	int bottom;
	int top;
	
	Intervalm(int x,int y)
	{
		bottom = x;
		top = y;
	}
	bool operator<(const Intervalm& rhs)
	{
		if(bottom != rhs.bottom)
        	return (bottom < rhs.bottom);
        
        else
        	return (top < rhs.top);
	}
  	bool operator==(const Intervalm& rhs)
	{
		return ((bottom == rhs.bottom)&&(top == rhs.top));
	}
};

class LineSegmentm
{
	public:
	Intervalm intv;
	int coord;
	
	LineSegmentm(Intervalm obj,int c):intv(obj),coord(c){}	
};

class Rectanglem
{
	public:
	int x_left;
	int x_right;
	int y_bottom;
	int y_top;
	
	Rectanglem(int xl,int xr,int yb,int yt):x_left(xl),x_right(xr),y_bottom(yb),y_top(yt){}
	Rectanglem(Intervalm x,Intervalm y):x_left(x.bottom),x_right(x.top),y_bottom(y.bottom),y_top(y.top){}
};

class EdgeTypem
{
	public:
	char value;
	
	EdgeTypem(char t)
	{
		value = t;
	}
};

class Edgem
{
	public:
	Intervalm intv;
	int coord;
	EdgeTypem side;
	
	Edgem(Intervalm obj,int c,EdgeTypem t):intv(obj),coord(c),side(t){}
	
	bool operator<(const Edgem& rhs)
	{
		if(coord != rhs.coord)
        	return (coord < rhs.coord);
        
        else if(intv.bottom != rhs.intv.bottom)
        	return (intv.bottom < rhs.intv.bottom);
        else
        	return (intv.top < rhs.intv.top);        
	}
  	bool operator==(const Edgem& rhs)
	{
		return ((coord == rhs.coord)&& (intv == rhs.intv));
	}
};

class Stripem
{
	public:
	Intervalm x_interval;
	Intervalm y_interval;
	vector<Intervalm> x_union;
	
	Stripem(Intervalm x,Intervalm y,vector<Intervalm> xset):x_interval(x),y_interval(y),x_union(xset){}
};	

