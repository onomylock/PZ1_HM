#include "Header.h"

void decomposition(vector<float> A,  vector<int> ai, int n, int m) //Разложение матрицы А
{
	vector<float> arr, L;
	int sign = 1;
	float sum;
	/*for (int i = 0; i < n; i++)
	{
		i % 2 == 0 ? sign = -1 : sign = 1;
		L[i] = sqrt(sign*());
	}*/



	L[0] = sqrt(di[0]);

	for (int i = 1; i < n; i++)
	{
		i % 2 == 0 ? sum -= di[i] : sum += di[i];

		for (int k = 0; k < i; k++) 
		{
			k % 2 == 0 ? sum -= L[k] : sum += L[k];
		}

		L[i] = sqrt(sum);
	}
}