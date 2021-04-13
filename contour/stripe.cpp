#include<bits/stdc++.h>
#include "stripefunctions.cpp"
using namespace std;
int distributor = 1;
void STRIPES(vector<Edge> V, Interval x_ext,vector<Interval> &L, vector<Interval> &R, vector<int> &P, vector<Stripe> &S)
{
	if(V.size() == 1)
	{
		//cout << "vsize 1\n";
		if(V[0].side.value == 'l')
		{
			L.push_back(V[0].intv);
		}
		else
		{
			R.push_back(V[0].intv);
		}
		
		P.push_back(numeric_limits<int>::min());
		P.push_back(V[0].intv.bottom);
		P.push_back(V[0].intv.top);
		P.push_back(numeric_limits<int>::max());
		
		vector<Interval> part = partition(P);
		
		int n = part.size();
		
		for(int i=0;i<n;i++)
		{
			Stripe str(x_ext,part[i],NULL);
			S.push_back(str); 
		}
		
		for(int i=0;i<S.size();i++)
		{
			if(S[i].y_interval == V[0].intv)
			{
				if(V[0].side.value == 'l')
				{
					ctree* sl = new ctree(V[0].coord,'l',NULL,NULL);
					S[i].tree=sl;
				}
				else
				{
					ctree* sl = new ctree(V[0].coord,'r',NULL,NULL);
					S[i].tree=sl;
				}
			}
		}
	}

	else if(V.size() > 1)
	{
		//cout << "vsize > 1\n";
		Edge xm=V[(int)(V.size()/2)];
		vector<Edge> V1;
		vector<Edge> V2;
		
		for(int i=0;i<V.size();i++)
		{
			if(V[i].coord < xm.coord)
				V1.push_back(V[i]);
			else if(V[i].coord > xm.coord)
				V2.push_back(V[i]);
			else if(V[i].coord == xm.coord)
			{
				if(distributor == 0)
				{
					V1.push_back(V[i]);
					distributor = 1;	
				}
				else if(distributor == 1)
				{
					V2.push_back(V[i]);
					distributor = 0;
				}
			}
		}
		Interval x_ext1(x_ext.bottom,xm.coord);
		Interval x_ext2(xm.coord,x_ext.top);
		
		vector<Interval> L1;
		vector<Interval> R1;
		vector<int> P1;
		vector<Stripe> S1;
		
		vector<Interval> L2;
		vector<Interval> R2;
		vector<int> P2;
		vector<Stripe> S2;
		
		STRIPES(V1,x_ext1,L1,R1,P1,S1);
		STRIPES(V2,x_ext2,L2,R2,P2,S2);
		
		vector<Interval> LR,L1_minus_LR,L1_union_L2,R2_minus_LR,R1_union_R2;
		
		LR = Intersection(L1,R2);
		
		//L1-LR
		L1_minus_LR = Difference(L1,LR);
		
		//(L1-LR) U L2
		L = Union(L1_minus_LR,L2);
		
		//(R2-LR) U R2
		R2_minus_LR = Difference(R2,LR);
		R = Union(R1,R2_minus_LR);
		
		//(P1 U P2)
		P = Unionint(P1,P2);
		
		vector<Stripe> S_left = copy(S1,P,x_ext1);
		vector<Stripe> S_right = copy(S2,P,x_ext2);
		
		blacken(S_left,R2_minus_LR);
		blacken(S_right,L1_minus_LR);
		
		S = concat(S_left,S_right,P,x_ext);
	}
}

vector<Stripe> Rectangle_dac(vector<Rectangle> R)
{
	vector<Edge> vrx;
	Interval x_ext(numeric_limits<int>::min(),numeric_limits<int>::max());
	
	for(int i=0;i<R.size();i++)
	{
		Interval in(R[i].y_bottom,R[i].y_top);
		Edge el(in,R[i].x_left,'l');
		Edge er(in,R[i].x_right,'r');
		vrx.push_back(el);
		vrx.push_back(er);
	}
	sort(vrx.begin(),vrx.end());
	//for(int i=0;i<vrx.size();i++)
		//cout << vrx[i].side.value << " (" << vrx[i].intv.bottom << " , " << vrx[i].intv.top << ")\n";
	vector<Interval> L;
	vector<Interval> R1;
	vector<int> P;
	vector<Stripe> S;
	//cout << "stripes entered\n";
	STRIPES(vrx,x_ext,L,R1,P,S);
	//litUnion(S);
	//cout << "stripes success\n";
	return S;
}

