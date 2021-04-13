#include<bits/stdc++.h>
#include "setfunctions.cpp"
using namespace std;
vector<Interval> partition(vector<int> Y)
{
	int n = Y.size();
	vector<Interval> part;
	for(int i=0;i<n-1;i++)
	{
		Interval it(Y[i],Y[i+1]);
		part.push_back(it);
	}
	return part;
}

vector<Stripe> copy(vector<Stripe> S,vector<int> P,Interval x_int)		
{
	vector<Stripe> S1;
	vector<Interval> part = partition(P);
	for(int i=0;i<part.size();i++)
	{
		Stripe str(x_int,part[i],NULL);
		S1.push_back(str);
	}
	int i=0,j=0,n1 = S1.size(),n = S.size();
	
	while(i!= n1 && j!=n)
	{
		if(S[j].y_interval.top >= S1[i].y_interval.top && S[j].y_interval.bottom <= S1[i].y_interval.bottom)
		{
			S1[i++].tree = S[j].tree; //D
		}
		else
			j++;
	}
	return S1;
}

void blacken(vector<Stripe> &S,vector<Interval> J)
{
	for(int i=0;i<S.size();i++)
	{
		for(int j=0;j<J.size();j++) 
		{
			if(S[i].y_interval.top <= J[j].top && S[i].y_interval.bottom >= J[j].bottom)
			{
				S[i].tree = NULL; //E
			}
		}
	}
}	

vector<Stripe> concat(vector<Stripe> S1,vector<Stripe> S2,vector<int> P, Interval x_int)
{
	vector<Stripe> S;
	vector<Interval> part = partition(P);
	for(int i=0;i<part.size();i++)
	{
		Stripe str(x_int,part[i],NULL);
		S.push_back(str);
	}
	int i=0,j=0,k=0,n = S.size(),n1 = S1.size(),n2 = S2.size();
	int flag1 = 0,flag2 = 0;
	while(i!=n && j!=n1 && k!=n2)
	{
		if(S[i].y_interval == S1[j].y_interval && flag1 == 0)
		{
			flag1++;
		}
		else if(flag1 == 0)
			j++;
		
		if(S[i].y_interval == S2[k].y_interval && flag2 == 0)
		{
			flag2++;
		}
		else if(flag2 == 0)
			k++;
		
		if(flag1 == 1 && flag2 == 1)
		{
			if(S1[j].tree!=NULL && S2[k].tree!=NULL)
			{
				ctree *ct = new ctree(S1[j].x_interval.top,'u',S1[j].tree,S2[k].tree);
				S[i].tree = ct;
			}
			
			else if(S1[j].tree!=NULL && S2[k].tree==NULL)
			{
				S[i].tree = S1[j].tree;
			}
			
			else if(S1[j].tree==NULL && S2[k].tree!=NULL)
			{
				S[i].tree = S2[k].tree;
			}
			
			else if(S1[j].tree==NULL && S2[k].tree==NULL)
			{
				S[i].tree = NULL;
			}
			
			
			i++;
			flag1 = 0;
			flag2 = 0;
		}
	}	
	return S;
}
