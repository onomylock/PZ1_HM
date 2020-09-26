#include "Header.h"

int main() {

	vector<float> A(1000), F;
	vector<int> ai;
	int n = 0, m = 0, ch;

	input(A, F, ai, n, m);				// Считываем значения из текстовых файлов

	cout << "Choose the method: " << endl;
	cout << "1) Cholesky method: " << endl;
	cout << "2) Gaussian method: " << endl;

	cin >> ch;

	switch (ch)
	{
		case 1:
		{
			decomposition(A, ai, n, m);		// Раскладываем матрицу A и находим значения матрицы L
			straight_step(A, ai, F, n, m);	// Прямой ход решения СЛАУ
			middle_step(F, n);					// Средний ход решения СЛАУ
			reverse_step(A, F, ai, n, m);		// Обратный ход решения СЛАУ, запись результата в массив F
		
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