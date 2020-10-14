#include "Header.h"

void read_di(vector<double>& di, int n) 
{
	ifstream fdi("di.txt");
	for (int i = 0; i < n; i++)	fdi >> di[i];
	fdi.close();
}

void read_al(vector<double>& al, int n, int m) 
{
	ifstream fal("al.txt");
	for (int i = n; i < m + n; i++) fal >> al[i];
	fal.close();
}

void read_vector(vector<double>& F, int n) 
{
	ifstream fvec("vector.txt");
	double num;
	for (int i = 0; i < n; i++)
	{
		fvec >> num;
		F.push_back(num);
	}

	fvec.close();
}

void input(vector<double>& A, vector<double>& F, vector<int>& ai, int& n, int& m) 
{
	read_info(n);
	read_ai(ai, n, m);
	read_di(A, n);
	read_al(A, n, m);
	read_vector(F, n);
}
