#include<bits/stdc++.h>
#include "setfunctionsm.cpp"
using namespace std;
vector<Intervalm> partitionm(vector<int> Y)
{
	int n = Y.size();
	vector<Intervalm> part;
	for(int i=0;i<n-1;i++)
	{
		Intervalm it(Y[i],Y[i+1]);
		part.push_back(it);
	}
	return part;
}

vector<Stripem> copym(vector<Stripem> S,vector<int> P,Intervalm x_int)		
{
	vector<Stripem> S1;
	vector<Intervalm> null;
	vector<Intervalm> part = partitionm(P);
	for(int i=0;i<part.size();i++)
	{
		Stripem str(x_int,part[i],null);
		S1.push_back(str);
	}
	int i=0,j=0,n1 = S1.size(),n = S.size();
	
	while(i!= n1 && j!=n)
	{
		if(S[j].y_interval.top >= S1[i].y_interval.top && S[j].y_interval.bottom <= S1[i].y_interval.bottom)
		{
			S1[i++].x_union = S[j].x_union;
		}
		else
			j++;
	}
	return S1;
}

void blackenm(vector<Stripem> &S,vector<Intervalm> J)
{
	for(int i=0;i<S.size();i++)
	{
		for(int j=0;j<J.size();j++)  //Need to optimize
		{
			if(S[i].y_interval.top <= J[j].top && S[i].y_interval.bottom >= J[j].bottom)
			{
				vector<Intervalm> temp;
				temp.push_back(S[i].x_interval);
				S[i].x_union = temp;
			}
		}
	}
}	

vector<Stripem> concatm(vector<Stripem> S1,vector<Stripem> S2,vector<int> P, Intervalm x_int)
{
	vector<Stripem> S;
	vector<Intervalm> null;
	vector<Intervalm> part = partitionm(P);
	for(int i=0;i<part.size();i++)
	{
		Stripem str(x_int,part[i],null);
		S.push_back(str);
	}
	int i=0,j=0,k=0,n = S.size(),n1 = S1.size(),n2 = S2.size();
	int flag1 = 0,flag2 = 0;
	while(i!=n && j!=n1 && k!=n2)
	{
		if(S[i].y_interval == S1[j].y_interval && flag1 == 0)
		{
			vector<Intervalm> temp1;
			S[i].x_union = Unionm(S[i].x_union,S1[j].x_union);
			flag1++;
		}
		else if(flag1 == 0)
			j++;
		
		if(S[i].y_interval == S2[k].y_interval && flag2 == 0)
		{
			vector<Intervalm> temp2;
			S[i].x_union = Unionm(S[i].x_union,S2[k].x_union);
			flag2++;
		}
		else if(flag2 == 0)
			k++;
		
		if(flag1 == 1 && flag2 == 1)
		{
			i++;
			flag1 = 0;
			flag2 = 0;
		}
	}	
	return S;
}
