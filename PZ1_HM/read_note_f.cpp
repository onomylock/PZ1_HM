#include "Header.h"

void read_info(int &n) 
{
	ifstream finfo("info.txt");
	finfo >> n;
	finfo.close();
}

void read_ai(vector<int> &ai, int n, int &m) 
{
	ifstream fai("ai.txt");
	float num;
	for (int i = 0; i < n + 1; i++)
	{
		fai >> num;
		ai.push_back(num);
	}
	m = ai[n];
	fai.close();
}

void read_di(vector<float> &di, int n) 
{
	ifstream fdi("di.txt");
	for (int i = 0; i < n; i++)	fdi >> di[i];	
	fdi.close();
}

void read_al(vector<float> &al, int n, int m) 
{
	ifstream fal("al.txt");
	for (int i = n; i < m + n; i++) fal >> al[i];
	fal.close();
}

void read_vector(vector<float> &F, int n) 
{
	ifstream fvec("vector.txt");
	float num;
	for (int i = 0; i < n; i++)
	{
		fvec >> num;
		F.push_back(num);
	}
	
	fvec.close();
}

void input(vector<float> &A, vector<float> &F, vector<int> &ai, int &n, int &m) 
{
	read_info(n);
	read_ai(ai, n, m);
	read_di(A, n);
	read_al(A, n, m);
	read_vector(F, n);
}
