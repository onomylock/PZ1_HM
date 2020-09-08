#include "Header.h"

void decomposition(vector<float> A,  vector<int> ai, int n, int m) //Разложение матрицы А
{
	vector<float> di, al, alL, diL;
	float sum;
	vector<int> aiL;
	/*for (int i = 0; i < n; i++)
	{
		i % 2 == 0 ? sign = -1 : sign = 1;
		L[i] = sqrt(sign*());
	}*/

	for (int i = 0; i < n; i++) di[i] = A[i];
	for (int i = 0; i < m; i++) al[i] = A[n + i];
	

	diL[0] = sqrt(di[0]);

	for (int i = 1; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++) 
		{
			for (int k = ai[j]; k < j; k++)
			{
				k % 2 == 0? 
			}
		}
		
	}
}

void foo() 
{
	
}