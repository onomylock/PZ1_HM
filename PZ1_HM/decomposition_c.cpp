#include "Header.h"

void decomposition_c(vector<float>& A, vector<int> ai, vector<float>& E, int n, int m) 
{
	vector<float> di(n), al(m), alL(m), diL(n);
	int col_j, col_k, kd_i, kd_j;
	float eps = 0.1e-5;
	double sum_tri = 0, sum_di = 0;
	


	for (int i = 0; i < n; i++) di[i] = A[i];
	for (int i = 0; i < m; i++) al[i] = A[n + i];

	for (int i = 0; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++)
		{
			col_j = i + j - ai[i + 1];		
			kd_i = i - ai[i + 1] + ai[i];
			col_k = ai[i];
			kd_j = col_j - ai[col_j + 1] + ai[col_j];

			if (kd_j > kd_i)
			{
				col_k += kd_j - kd_i;
				kd_i = kd_j;
			}

			for (int k = ai[col_j] + (kd_i - kd_j); k < ai[col_j + 1]; k++)
			{
				E[col_j] > 0 ? sum_tri -= alL[col_k] * alL[k] : sum_tri += alL[col_k] * alL[k];
				col_k++;
			}

			E[col_j] > 0 ? alL[j] = (sum_tri + al[j]) / diL[col_j] : alL[j] = (sum_tri - al[j]) / diL[col_j];
			E[col_j] > 0 ? sum_di += pow(alL[j], 2) : sum_di -= pow(alL[j], 2);
			sum_tri = 0;

		}

		if ((di[i] - sum_di) < 0 && abs(di[i] - sum_di) > eps)
		{
			E.push_back(-1);
		}
		else if ((di[i] - sum_di) > 0 && abs(di[i] - sum_di) > eps)
		{
			E.push_back(1);
		}
		else if (abs(di[i] - sum_di) < eps)
		{
			cout << "ERROR: division by zero" << endl;
			exit(1);
		}

		diL[i] = sqrt(abs(di[i] - sum_di));

		sum_di = 0;
	}


	for (int i = 0; i < n; i++) A[i] = diL[i];
	for (int i = 0; i < m; i++) A[i + n] = alL[i];
}