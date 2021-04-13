//Dantuluri Sairaju - 2018A7PS0306H
//Nitin Gopala Krishna Sontineni - 2018A7PS0262H
//Dinesh Nandyala - 2018A7PS0431H
//Charan Duggina - 2018A7PS0486H
#include "measure/measure.cpp"
#include "contour/contour.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream input_file;
	input_file.open("input.txt", ios::out);
	if(!input_file)
	{
		cout << "input file not created\n";
		return 0;
	}
	cout << "Enter number of rectangle input ";
	int r;
	scanf("%d",&r);
	vector<Rectangle> Rec;
	vector<Rectanglem> Recm;
	for(int i=0;i<r;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		Rectangle R(a,b,c,d);
		Rectanglem Rm(a,b,c,d);
		Rec.push_back(R);
		Recm.push_back(Rm);
		input_file << a <<","<< b <<","<< c <<","<< d <<"\n";
	}
	input_file.close();
	int area = measure(Recm);
	vector<LineSegment> ls,vs;
	Contour(Rec,ls,vs);
	cout << "area : " << area << "\n";
	
	fstream file_hori,file_verti;
	file_hori.open("horizontal.txt", ios::out);
	if (!file_hori) {
		cout << "horizontal file not created!";
	}
	else {
		for(int i=0;i<ls.size();i++)
		{
			file_hori << ls[i].coord <<","<<ls[i].intv.bottom<<"," << ls[i].intv.top << "\n";
		}
		file_hori.close();
	}
	
	file_verti.open("Hvertical.txt", ios::out);
	if (!file_verti) {
		cout << "vertical file not created!";
	}
	else {
		for(int i=0;i<vs.size();i++)
		{
			file_verti << vs[i].coord <<","<<vs[i].intv.bottom<<"," << vs[i].intv.top << "\n";
		}
		file_verti.close();
	}
	return 0;
}

