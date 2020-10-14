#include "Header.h"

void gauss(vector<float> A, vector<float>& F, vector<int> ai, int n, int m)
{

	vector<vector<float>> matrix;
	vector<float> di(n), al(m), X(n);
	float col_j, temp, max = 0, eps = 0.1;
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		vector<float> temp;
		for (int j = 0; j < n; j++)
		{
			temp.push_back(1);
		}
		matrix.push_back(temp);
	}

	for (int i = 0; i < n; i++) di[i] = A[i];
	for (int i = 0; i < m; i++) al[i] = A[n + i];

	for (int i = 0; i < n; i++)
	{
		matrix[i][i] = di[i];

		for (int j = ai[i]; j < ai[i + 1]; j++)
		{
			col_j = i + j - ai[i + 1];
			matrix[i][col_j] = al[j];
			matrix[col_j][i] = al[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		max = abs(matrix[i][i]); 

		for (int j = i + 1; j < n; j++)
		{
			if (abs(matrix[j][i]) > abs(max))
			{
				max = matrix[j][i];
				index = j;
			}
		}

		if (abs(max) < eps)
		{
			cout << "ERROR: zero column" << endl;
			exit(1);
		}

		for (int k = 0; k < n; k++) 
		{
			temp = matrix[i][k];
			matrix[i][k] = matrix[index][k];
			matrix[index][k] = temp;
		}

		temp = F[i];
		F[i] = F[index];
		F[index] = temp;

		for (int j = i; j < n; j++) 
		{
			temp = matrix[j][i];
			if (abs(temp) < eps) continue;
			for (int k = 0; k < n; k++)
			{
				matrix[j][k] = matrix[j][k] / temp;
			}

			F[j] = F[j] / temp;

			if (i == j) continue;

			for (int k = 0; k < n; k++) 
			{
				matrix[j][k] = matrix[j][k] - matrix[i][k];
			}
			F[j] = F[j] - F[i];
		}
	}

	for (int i = n - 1; i >= 0; i--) 
	{
		X[i] = F[i];
		for (int j = 0; j < i; j++)
		{
			F[j] = F[j] - matrix[j][i] * X[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		F[i] = X[i];
	}
}