#include "Header.h"

int main() {

	vector<float> A(1000), F(100);
	vector<int> ai(100);
	int n, m;

	input(A, F, ai, n, m);				// Считываем значения из текстовых файлов
	decomposition(A, ai, n, m);		// Раскладываем матрицу A и находим значения матрицы L
	straight_step(A, ai, F, n, m);	// Прямой ход решения СЛАУ
	middle_step(F, n);					// Средний ход решения СЛАУ
	reverse_step(A, F, ai, n, m);		// Обратный ход решения СЛАУ, запись результата в массив F
	
	ofstream out("output.txt");

	for (auto element : F)
		out << element << endl;
	out.close();

	return 0;
}