#include "Header.h"

int main() {

	vector<float> A(1000), F;
	vector<int> ai;
	int n = 0, m = 0, ch;

	input(A, F, ai, n, m);				// ��������� �������� �� ��������� ������

	cout << "Choose the method: " << endl;
	cout << "1) Cholesky method: " << endl;
	cout << "2) Gaussian method: " << endl;

	cin >> ch;

	switch (ch)
	{
		case 1:
		{
			decomposition(A, ai, n, m);		// ������������ ������� A � ������� �������� ������� L
			straight_step(A, ai, F, n, m);	// ������ ��� ������� ����
			middle_step(F, n);					// ������� ��� ������� ����
			reverse_step(A, F, ai, n, m);		// �������� ��� ������� ����, ������ ���������� � ������ F
		
			ofstream out("output_X.txt");

			for (int i = 0; i < n; i++)
			{
				out << F[i] << endl;
			}
			out.close();
		
			break;
		}

		case 2:
		{
			gauss(A, F, ai, n, m);

			ofstream out("output_G.txt");

			for (int i = 0; i < n; i++)
			{
				out << F[i] << endl;
			}
			out.close();

			break;
		}
	}
	
	return 0;
}