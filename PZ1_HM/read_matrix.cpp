#include "Header.h"

int read_info(int n) 
{
	fstream finfo("info.txt");
	finfo >> n;
	finfo.close();

	return n;
}

void read_ai(vector<int> ai, int n, int m) 
{
	fstream fai("ai.txt");
	for (int i = 0; i < n + 1; i++) fai >> ai[i];
	m = ai[n + 1] - 1;
	fai.close();
}

void read_di(vector<float> di, int n) 
{
	fstream fdi("di.txt");
	for (int i = 0; i < n; i++)	fdi >> di[i];	
	fdi.close();
}

void read_al(vector<float> al, int n, int m) 
{
	fstream fal("al.txt");
	for (int i = m + n; i < 2*m + 1; i++) fal >> al[i];
	fal.close();
}

void read_vector(vector<float> vec, int n)
{
	fstream fvec("vector.txt");
	for (int i = 0; i < n; i++) fvec >> vec[i];
	fvec.close();
}

void input(vector<float> A, vector<float> vec, vector<int> ai, int n, int m) 
{
	read_info(n);
	read_ai(ai, n, m);
	read_di(A, n);
	read_al(A, n, m);
	read_vector(vec, n);
}
