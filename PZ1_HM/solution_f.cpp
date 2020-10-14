#include "Header.h"

void straight_step(vector<float> L, vector<int> ai, vector<float> &F, int n, int m)
{
	vector<float> di(n), al(m), Y(n);
	int col_j;					
	float sum_Y = 0;			
	for (int i = 0; i < n; i++) di[i] = L[i];
	for (int i = 0; i < m; i++) al[i] = L[i + n];

	for (int i = 0; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++)
		{
			col_j = i + j - ai[i + 1];
			sum_Y += al[j] * Y[col_j];
		}

		Y[i] = (F[i] - sum_Y) / di[i];
		sum_Y = 0;
	}

	for (int i = 0; i < n; i++)
	{
		F[i] = Y[i];
	}
}

void middle_step(vector<float> &Y, vector<float> E, int n)		
{
	for (int i = 0; i < n; i++)
	{
		Y[i] = Y[i] * E[i];
	}
}

void reverse_step(vector<float> L, vector<float> &Z, vector<int> ai, int n, int m)
{
	vector<float> di(n), al(m), X(n), sum_X(n);
	int st_j;
	for (int i = 0; i < n; i++) di[i] = L[i];
	for (int i = 0; i < m; i++) al[i] = L[i + n];

	for (int i = n - 1; i >= 0; i--)
	{
		X[i] = (Z[i] - sum_X[i]) / di[i];
		for (int j = ai[i + 1] - 1; j >= ai[i]; j--)
		{
			st_j = i + j - ai[i + 1];
			sum_X[st_j] += al[j] * X[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		Z[i] = X[i];
	}
}


		