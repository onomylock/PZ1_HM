#include "Header.h"

void decomposition(vector<float> A,  vector<int> ai, int n, int m) //Разложение матрицы А
{
	vector<float> di, al, alL, diL;
	int sign = 1;
	float sum;
	

	for (int i = 0; i < n; i++) di[i] = A[i];
	for (int i = 0; i < m; i++) al[i] = A[n + i];


	for (int i = 0; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++)
		{
			
			j % 2 == 0 ? diL[i] += powf(alL[j]) : diL[i] -= powf(alL[j]);
			for (int k = 0; k < j; k++)
			{

			}
		}

		i % 2 == 0 ? diL[i] = powf(diL[i] + di[i]) : dil[i] = powf(diL[i] - di[i]);
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++) 
		{
			for (int k = ai[j]; k < j; k++)
			{
				k % 2 == 0? sum -=
			}
		}

		
	}
}