#include "measure/measure.cpp"
#include "contour/contour.cpp"
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

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
	auto start = high_resolution_clock::now();
	int area = measure(Recm);
	vector<LineSegment> ls,vs;
	int cont = Contour(Rec,ls,vs);
	auto stop = high_resolution_clock::now();
	cout << "area : " << area << "\n";
	cout << "contour : " << cont << "\n";
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
	
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << duration.count() << "ms"<< endl << "\n";
	return 0;
}

