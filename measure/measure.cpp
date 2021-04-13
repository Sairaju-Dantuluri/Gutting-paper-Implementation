#include "stripem.cpp"

int measure(vector<Rectanglem> R)
{
	vector<Stripem> S = Rectangle_dacm(R);
	int area=0;
	for(int i=0;i<S.size();i++)
	{
		int l = S[i].y_interval.top - S[i].y_interval.bottom;
		for(int j=0;j<S[i].x_union.size();j++)
		{
			int b = (S[i].x_union)[j].top - (S[i].x_union)[j].bottom;
			area += (l*b);
		}
	}
	return area;
}
