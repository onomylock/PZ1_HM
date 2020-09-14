#include "Header.h"

void decomposition(vector<float> A,  vector<int> ai, int n, int m) //Разложение матрицы А
{
	vector<float> di, al, alL, diL;
	int col_j, col_k, kd;
	float sum_tri = 0, sum_di = 0;
	

	for (int i = 0; i < n; i++) di[i] = A[i];
	for (int i = 0; i < m; i++) al[i] = A[n + i];


	for (int i = 0; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++)
		{
			col_j = i + j - ai[i + 1];		//col_j - номер столбца для j -го элемента массива alL
			kd = ai[i + 1] - ai[i] - i;   //kd    - сопоставление длинны строки и количества членов массива для данной строки
			col_k = j - col_j;				//col_k - номер элемента массива alL  находящийся в строке элемента alL[k]
			for (int k = ai[col_j]; k < ai[col_j + 1]; k++)
			{
				if (kd < 0)
				{
					kd++;
					col_k++;
					continue;
				}
				
				/*
				 sum_tri		- сумма элементов для не диагональных членов матрицы
				 sum_di		- сумма элементов для диагональных членов матрицы
				*/
				(col_j + k - ai[col_j + 1]) == 0 ? sum_tri += alL[col_k] * alL[k] : sum_tri -= alL[col_k] * alL[k];
				col_k++;
			}

			col_j % 2 == 0 ? alL[j] = (-sum_tri + al[j]) / diL[col_j] : alL[j] = (sum_tri - al[j]) / diL[col_j];
			col_j % 2 == 0 ? sum_di += powf(alL[j], 2) : sum_di -= powf(alL[j], 2);
			sum_tri = 0;

		}

		i % 2 == 0 ? diL[i] = sqrt(di[i] - sum_di) : diL[i] = sqrt(sum_di - di[i]);
		sum_di = 0;
	}

	A.clear();

	for (int i = 0; i < n; i++) A[i] = diL[i];
	for (int i = 0; i < m; i++) A[i + n] = diL[i];
		
}