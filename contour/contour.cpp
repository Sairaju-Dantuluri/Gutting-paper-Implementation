#include "stripe.cpp"

vector<ctree> Intersectiontree(Interval hx,ctree* s)
{
	vector<ctree> temp;
	if(s==NULL)
	{
		return temp;
	}
	if(s->rson!=NULL && s->lson!=NULL)
	{
		vector<ctree> temp1,temp2;
		if(s->lson!=NULL)
			temp1 = Intersectiontree(hx,s->lson);
		if(s->rson!=NULL)
			temp2 = Intersectiontree(hx,s->rson);
		for(int i=0;i<temp1.size();i++)
			temp.push_back(temp1[i]);
		for(int i=0;i<temp2.size();i++)
			temp.push_back(temp2[i]);
	}
	else
	{
		ctree* leaf = new ctree(s->x,s->lru,NULL,NULL);
		temp.push_back(*leaf);
	}
	return temp;
}

vector<Interval> diff(Interval hx,vector<ctree> t)
{
	vector<Interval> intv,h_int,h_diff;
	if(t.size() == 0)
	{
		h_diff.push_back(hx);
		return h_diff;
	}
	for(int i=0;i<t.size()/2;i++)
		intv.push_back(Interval((t[2*i]).x,(t[2*i+1]).x));
	for(int i=0;i<intv.size();i++)
	{
		if(intv[i].bottom <= hx.bottom && intv[i].top >= hx.top)
			return h_diff;
	}
	for(int i=0;i<intv.size();i++)
	{
		if((intv[i].bottom > hx.bottom && intv[i].bottom < hx.top)||(intv[i].top > hx.bottom && intv[i].top < hx.top))
		{
			h_int.push_back(intv[i]);
		}
	}
	if(h_int.size() == 0)
	{
		h_diff.push_back(hx);
		return h_diff;
	}
		
	if(h_int[0].bottom > hx.bottom)
		h_diff.push_back(Interval(hx.bottom,h_int[0].bottom));
	int x = h_int[0].top;	
	for(int i=1;i<(h_int.size());i++)
	{
		h_diff.push_back(Interval(x,h_int[i].bottom));
		x = h_int[i].top;
	}
		
	if(h_int[h_int.size()-1].top < hx.top)
		h_diff.push_back(Interval(h_int[h_int.size()-1].top,hx.top));
	return h_diff;
}

vector<LineSegment> Contour_pieces(Edge H,vector<Stripe> S)
{
	vector<LineSegment> ls;
	int I;
	for(int i=0;i<S.size();i++)
	{
		if(H.side.value == 'b' && S[i].y_interval.top == H.coord)
		{
			I=i;
			break;
		}
		else if(H.side.value != 'b' && S[i].y_interval.bottom == H.coord)
		{
			I=i;
			break;
		}
			
	}
	vector<Interval> cont;
	if(S[I].tree!=NULL)
	{
		vector<ctree> h_inter_sunion = Intersectiontree(H.intv,S[I].tree);
	
		cont = diff(H.intv,h_inter_sunion);
	}
	else
	{
		cont.push_back(H.intv);
	}
	for(int i=0;i<cont.size();i++)
	{
		ls.push_back(LineSegment(cont[i],H.coord));
	}
	return ls;
}

vector<LineSegment> fillgaps(vector<LineSegment> ls)
{
	vector<int> x;
	for(int i=0;i<ls.size();i++)
	{
		x.push_back(ls[i].intv.bottom);
		x.push_back(ls[i].intv.top);
	}
	sort(x.begin(),x.end());
	vector<int>::iterator ip;
	ip = unique(x.begin(),x.end());
	x.resize(distance(x.begin(), ip));
	int flag = 0;
	vector<LineSegment> temp;
	for(int i=0;i<x.size();i++)
	{
		int ind,end;
		for(int j=0;j<ls.size();j++)
		{
			if(x[i] == ls[j].intv.bottom && flag == 0)
			{
				flag = 1;
				ind = ls[j].coord;
			}
			
			else if(x[i] == ls[j].intv.top && flag == 0)
			{
				flag = 1;
				ind = ls[j].coord;
			}
			else if(x[i] == ls[j].intv.bottom && flag == 1)
			{
				flag = 2;
				end = ls[j].coord;
			}
			
			else if(x[i] == ls[j].intv.top && flag == 1)
			{
				flag = 2;
				end = ls[j].coord;
			}
			
			if(flag == 2)
			{
				Interval intve(ind,end);
				LineSegment t(intve,x[i]);
				temp.push_back(t);
				flag = 0;
			}
			
		}
	}
	return temp;
}


int Contour(vector<Rectangle> R,vector<LineSegment> &ls,vector<LineSegment> &vs)
{
	if(R.size() == 0)
	{
		return 0;
	}
	vector<Stripe> S = Rectangle_dac(R);
	vector<LineSegment> ls1,ls2;
	for(int i=0;i<R.size();i++)
	{
		Interval intve(R[i].x_left,R[i].x_right);
		EdgeType et1('b');
		Edge ed1(intve,R[i].y_bottom,et1);

		ls1 = Contour_pieces(ed1,S);

		for(int j=0;j<ls1.size();j++)
		{
			ls.push_back(ls1[j]);
		}
		EdgeType et2('t');
		Edge ed2(intve,R[i].y_top,et2);
	
		ls2 = Contour_pieces(ed2,S);
	
		for(int j=0;j<ls2.size();j++)
		{
			ls.push_back(ls2[j]);
		}
	}
	sort(ls.begin(),ls.end());
	ls = litUnionls(ls);
	if(ls.size()!=0)
		vs = fillgaps(ls);
	int cont=0;
	for(int i=0;i<ls.size();i++)
	{
		cont+=(ls[i].intv.top-ls[i].intv.bottom);
	}
	for(int i=0;i<vs.size();i++)
	{
		cont+=(vs[i].intv.top-vs[i].intv.bottom);
	}
	return cont;
}
