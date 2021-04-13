#include<bits/stdc++.h>
#include "stripefunctionsm.cpp"
using namespace std;

int distributorm = 0;

void STRIPESM(vector<Edgem> V, Intervalm x_ext,vector<Intervalm> &L, vector<Intervalm> &R, vector<int> &P, vector<Stripem> &S)
{
	if(V.size() == 1)
	{
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
		
		vector<Intervalm> part = partitionm(P);
		
		int n = part.size();
		
		for(int i=0;i<n;i++)
		{
			vector<Intervalm> emp;
			Stripem str(x_ext,part[i],emp);
			S.push_back(str); 
		}
		
		for(int i=0;i<S.size();i++)
		{
			if(S[i].y_interval == V[0].intv)
			{
				if(V[0].side.value == 'l')
				{
					Intervalm sl(V[0].coord,x_ext.top);
					S[i].x_union.push_back(sl);
				}
				else
				{
					Intervalm sr(x_ext.bottom,V[0].coord);
					S[i].x_union.push_back(sr);
				}
			}
		}
	}

	else if(V.size() > 1)
	{
		Edgem xm=V[(int)(V.size()/2)];
		vector<Edgem> V1;
		vector<Edgem> V2;
		for(int i=0;i<V.size();i++)
		{
			if(V[i].coord < xm.coord)
				V1.push_back(V[i]);
			else if(V[i].coord > xm.coord)
				V2.push_back(V[i]);
			else if(V[i].coord == xm.coord)
			{
				if(distributorm == 0)
				{
					V1.push_back(V[i]);
					distributorm = 1;	
				}
				else if(distributorm == 1)
				{
					V2.push_back(V[i]);
					distributorm = 0;
				}
			}
		}
		Intervalm x_ext1(x_ext.bottom,xm.coord);
		Intervalm x_ext2(xm.coord,x_ext.top);
		
		vector<Intervalm> L1;
		vector<Intervalm> R1;
		vector<int> P1;
		vector<Stripem> S1;
		
		vector<Intervalm> L2;
		vector<Intervalm> R2;
		vector<int> P2;
		vector<Stripem> S2;
		
		STRIPESM(V1,x_ext1,L1,R1,P1,S1);
		STRIPESM(V2,x_ext2,L2,R2,P2,S2);
		
		vector<Intervalm> LR,L1_minus_LR,L1_union_L2,R2_minus_LR,R1_union_R2;
		
		LR = Intersectionm(L1,R2);
		
		//L1-LR
		L1_minus_LR = Differencem(L1,LR);
		
		//(L1-LR) U L2
		L = Unionm(L1_minus_LR,L2);
		
		//(R2-LR) U R2
		R2_minus_LR = Differencem(R2,LR);
		R = Unionm(R1,R2_minus_LR);
		
		//(P1 U P2)
		P = Unionintm(P1,P2);
		
		vector<Stripem> S_left = copym(S1,P,x_ext1);
		vector<Stripem> S_right = copym(S2,P,x_ext2);
		
		blackenm(S_left,R2_minus_LR);
		blackenm(S_right,L1_minus_LR);
		
		S = concatm(S_left,S_right,P,x_ext);
	}
}

vector<Stripem> Rectangle_dacm(vector<Rectanglem> R)
{
	vector<Edgem> vrx;
	Intervalm x_ext(numeric_limits<int>::min(),numeric_limits<int>::max());
	
	for(int i=0;i<R.size();i++)
	{
		Intervalm in(R[i].y_bottom,R[i].y_top);
		Edgem el(in,R[i].x_left,'l');
		Edgem er(in,R[i].x_right,'r');
		vrx.push_back(el);
		vrx.push_back(er);
	}
	sort(vrx.begin(),vrx.end());
	vector<Intervalm> L;
	vector<Intervalm> R1;
	vector<int> P;
	vector<Stripem> S;
	STRIPESM(vrx,x_ext,L,R1,P,S);
	//litUnion(S);
	return S;
}


