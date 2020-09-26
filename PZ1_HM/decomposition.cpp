#include "Header.h"

void decomposition(vector<float> &A,  vector<int> ai, vector<float> &E, int n, int m) //���������� ������� �
{
	vector<float> di(n), al(m), alL(m), diL(n);
	int col_j, col_k, kd;
	float sum_tri = 0, sum_di = 0, eps = 0.1;
	

	for (int i = 0; i < n; i++) di[i] = A[i];
	for (int i = 0; i < m; i++) al[i] = A[n + i];


	for (int i = 0; i < n; i++)
	{
		for (int j = ai[i]; j < ai[i + 1]; j++)
		{
			col_j = i + j - ai[i + 1];		//col_j - ����� ������� ��� j -�� �������� ������� alL
			kd = ai[i + 1] - ai[i] - i;   //kd    - ������������� ������ ������ � ���������� ������ ������� ��� ������ ������
			col_k = j - col_j;				//col_k - ����� �������� ������� alL  ����������� � ������ �������� alL[k]
			for (int k = ai[col_j]; k < ai[col_j + 1]; k++)
			{
				if (kd < 0)
				{
					kd++;
					col_k++;
					continue;
				}
				
				/*
				 sum_tri		- ����� ��������� ��� �� ������������ ������ �������
				 sum_di		- ����� ��������� ��� ������������ ������ �������
				*/
				(col_j + k - ai[col_j + 1]) == 0 ? sum_tri += alL[col_k] * alL[k] : sum_tri -= alL[col_k] * alL[k];
				col_k++;
			}

			col_j % 2 == 0 ? alL[j] = (-sum_tri + al[j]) / diL[col_j] : alL[j] = (sum_tri - al[j]) / diL[col_j];
			col_j % 2 == 0 ? sum_di += powf(alL[j], 2) : sum_di -= powf(alL[j], 2);
			sum_tri = 0;

		}

		diL[i] = sqrt(abs(di[i] - sum_di));
		//i % 2 == 0 ? diL[i] = sqrt(di[i] - sum_di) : diL[i] = sqrt(sum_di - di[i]);
		if ((di[i] - sum_di) < 0)
		{
			E.push_back(-1);
		}
		else if ((di[i] - sum_di) > 0)
		{
			E.push_back(1);
		}
		else if (abs(di[i] - sum_di) < eps)
		{
			cout << "ERROR: division by zero" << endl;
			exit(1);
		}
		sum_di = 0;
	}



	for (int i = 0; i < n; i++) A[i] = diL[i];
	for (int i = 0; i < m; i++) A[i + n] = alL[i];
}