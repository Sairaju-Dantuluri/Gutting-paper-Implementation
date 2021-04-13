#include<bits/stdc++.h>
#include "defclass.cpp"
using namespace std;

vector<Interval> Intersection(vector<Interval> v1,vector<Interval> v2)
{
	vector<Interval> v;
	int i=0,j=0,n1 = v1.size(),n2=v2.size();
	while(i!=n1 && j!=n2)
	{
		if(v2[j] < v1[i])
			j++;
		else if(v1[i] < v2[j])
			i++;
		else
		{
			v.push_back(v1[i]);
			i++;
			j++;
		}
	}
	return v;
}

vector<Interval> Difference(vector<Interval> v1,vector<Interval> v2)
{
	vector<Interval> v;
	int i=0,j=0,n1 = v1.size(),n2=v2.size();
	while(i!=n1 && j!=n2)
	{
		if(v2[j] < v1[i])
			j++;
		else if(v1[i] < v2[j])
		{
			v.push_back(v1[i++]);
		}
		else
		{
			i++;
			j++;
		}
	}
	if(i < n1)
	{
		while(i!=n1)
			v.push_back(v1[i++]);
	}
	return v;
}
vector<Interval> litUnion(vector<Interval> I)
{
	vector<Interval> temp;
		if(I.size() != 0)
		{
		
		Interval t = I[0];
		for(int j=0;j<I.size();j++)
		{
			int tb = t.bottom,tt = t.top,sb = I[j].bottom,st = I[j].top;
			if(tb >= sb && tt<= st)
			{
				t = I[j];
			}
				
			else if(tb <= sb && tt <= st && tt >= sb)
			{
				t.top = st;
			}
			
			else if(tt < sb)
			{
				temp.push_back(t);
				t.bottom = sb;
				t.top = st;
			}
			else if(j == I.size()-1)
			{
				temp.push_back(t);
			}
			
		}
		temp.push_back(t);
	}
	return temp;
}



// Under Intense Testing 

int min(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}

int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}


vector<LineSegment> litUnionls(vector<LineSegment> ls)
{
	
	vector<LineSegment> out;
	for(int i=0;i<ls.size()-1;i++)
	{
		while(ls[i].coord == ls[i+1].coord)
		{
			if(ls[i].intv.top >= ls[i+1].intv.bottom)
			{
				Interval c(min(ls[i].intv.bottom,ls[i+1].intv.bottom),max(ls[i].intv.top,ls[i+1].intv.top));
				ls[i+1].intv = c;	
			}
			else
			{
				out.push_back(ls[i]);
			}
			i++;
		}
		if(i==ls.size()-2)
		{
			out.push_back(ls[i]);
			out.push_back(ls[i+1]);
		}
		else
		{
			out.push_back(ls[i]);
		}
	}
	
	return out;
}





// Testing ends here.








vector<Interval> Union(vector<Interval> v1,vector<Interval> v2)
{	
	vector<Interval> v;
	int i=0,j=0,n1 = v1.size(),n2=v2.size();
	while(i!=n1 && j!=n2)
	{
		if(v2[j] < v1[i])
			v.push_back(v2[j++]);
		else if(v1[i] < v2[j])
			v.push_back(v1[i++]);
		else
		{
			v.push_back(v1[i++]);
			j++;
		}
	}
	if(i < n1)
	{
		while(i!=n1)
			v.push_back(v1[i++]);
	}
	if(j < n2)
	{
		while(j!=n2)
			v.push_back(v2[j++]);
	}
	return v;
}

vector<int> Unionint(vector<int> v1,vector<int> v2)
{	
	vector<int> v;
	int i=0,j=0,n1 = v1.size(),n2=v2.size();
	while(i!=n1 && j!=n2)
	{
		if(v2[j] < v1[i])
			v.push_back(v2[j++]);
		else if(v1[i] < v2[j])
			v.push_back(v1[i++]);
		else
		{
			v.push_back(v1[i++]);
			j++;
		}
	}
	if(i < n1)
	{
		while(i!=n1)
			v.push_back(v1[i++]);
	}
	if(j < n2)
	{
		while(j!=n2)
			v.push_back(v2[j++]);
	}
	return v;
}


