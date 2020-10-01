#include "Header.h"

int main() {

	vector<float> Af(1000), Ff, Ef;
	vector<double> Ad(1000), Fd, Ed;
	vector<int> ai;
	int n = 0, m = 0, ch, precision;

	

	cout << "Choose the method : " << endl;
	cout << "1) Cholesky method: " << endl;
	cout << "2) Gaussian method: " << endl;

	cin >> ch;

	cout << "Choose calculation precision: " << endl;
	cout << "1) float precision: " << endl;
	cout << "2) double precision: " << endl;

	cin >> precision;

	switch (precision)
	{
		case 1:
		{
			input(Af, Ff, ai, n, m);		// Считываем значения из текстовых файлов
			
			if (ch == 1)
			{

				decomposition(Af, ai, Ef, n, m);		// Раскладываем матрицу A и находим значения матрицы L
				straight_step(Af, ai, Ff, n, m);		// Прямой ход решения СЛАУ
				middle_step(Ff, Ef, n);					// Средний ход решения СЛАУ
				reverse_step(Af, Ff, ai, n, m);		// Обратный ход решения СЛАУ, запись результата в массив F
				
				ofstream out("output_X.txt");

				out.precision(7);

				for (int i = 0; i < n; i++)
				{
					out << Ff[i] << endl;
				}
				out.close();
			}	
			else if (ch == 2)
			{
				gauss(Af, Ff, ai, n, m);

				ofstream out("output_G.txt");

				out.precision(7);

				for (int i = 0; i < n; i++)
				{
					out << Ff[i] << endl;
				}
				out.close();
			}
			break;
		}
	
		case 2:
		{
			input(Ad, Fd, ai, n, m);				// Считываем значения из текстовых файлов
			
			if (ch == 1)
			{
				decomposition(Ad, ai, Ed, n, m);		// Раскладываем матрицу A и находим значения матрицы L
				straight_step(Ad, ai, Fd, n, m);		// Прямой ход решения СЛАУ
				middle_step(Fd, Ed, n);					// Средний ход решения СЛАУ
				reverse_step(Ad, Fd, ai, n, m);		// Обратный ход решения СЛАУ, запись результата в массив F
				
				ofstream out("output_X.txt");

				out.precision(15);

				for (int i = 0; i < n; i++)
				{
					out << Fd[i] << endl;
				}
				out.close();
			}
			else if (ch == 2)
			{
				gauss(Ad, Fd, ai, n, m);

				ofstream out("output_G.txt");

				out.precision(15);

				for (int i = 0; i < n; i++)
				{
					out << Fd[i] << endl;
				}
				out.close();
			}
			break;
		}
	}

	return 0;
}