#include<bits/stdc++.h>
#include "defclassm.cpp"
using namespace std;

vector<Intervalm> Intersectionm(vector<Intervalm> v1,vector<Intervalm> v2)
{
	vector<Intervalm> v;
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

vector<Intervalm> Differencem(vector<Intervalm> v1,vector<Intervalm> v2)
{
	vector<Intervalm> v;
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

vector<Intervalm> Unionm(vector<Intervalm> v1,vector<Intervalm> v2)
{	
	vector<Intervalm> v;
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

vector<int> Unionintm(vector<int> v1,vector<int> v2)
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

