#include "Header.h"

int main() {

	vector<float> A(1000), F;
	vector<int> ai;
	int n = 0, m = 0;

	input(A, F, ai, n, m);				// ��������� �������� �� ��������� ������
	decomposition(A, ai, n, m);		// ������������ ������� A � ������� �������� ������� L
	straight_step(A, ai, F, n, m);	// ������ ��� ������� ����
	middle_step(F, n);					// ������� ��� ������� ����
	reverse_step(A, F, ai, n, m);		// �������� ��� ������� ����, ������ ���������� � ������ F
	
	ofstream out("output.txt");

	for (int i = 0; i < n; i++)
	{
		out << F[i] << endl;
	}
	out.close();

	return 0;
}