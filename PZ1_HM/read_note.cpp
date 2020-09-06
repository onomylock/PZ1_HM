#include "Header.h"

int read_info(int n) //Считываем размерность матрицы А
{
	fstream finfo("info.txt");
	finfo >> n;
	finfo.close();

	return n;
}

void read_ai(vector<int> ai, int n, int m) //Считываем портрет матрицы А
{
	fstream fai("ai.txt");
	for (int i = 0; i < n + 1; i++) fai >> ai[i];
	m = ai[n + 1] - 1;
	fai.close();
}

void read_di(vector<float> di, int n) //Считываем значения диагонали матрицы А
{
	fstream fdi("di.txt");
	for (int i = 0; i < n; i++)	fdi >> di[i];	
	fdi.close();
}

void read_al(vector<float> al, int n, int m) //Считываем значения нижнего треугольника матрицы А
{
	fstream fal("al.txt");
	for (int i = m + n; i < 2*m + 1; i++) fal >> al[i];
	fal.close();
}

void read_vector(vector<float> vec, int n) //Считываем значения вектора F
{
	fstream fvec("vector.txt");
	for (int i = 0; i < n; i++) fvec >> vec[i];
	fvec.close();
}

void input(vector<float> A, vector<float> vec, vector<int> ai, int n, int m) //Процедура считывания информации из файлов
{
	read_info(n);
	read_ai(ai, n, m);
	read_di(A, n);
	read_al(A, n, m);
	read_vector(vec, n);
}
