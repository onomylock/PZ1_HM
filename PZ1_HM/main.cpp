#include "Header.h"

int main() {

	vector<float> A(1000), F(100);
	vector<int> ai(100);
	int n, m;

	input(A, F, ai, n, m);				// ��������� �������� �� ��������� ������
	decomposition(A, ai, n, m);		// ������������ ������� A � ������� �������� ������� L
	straight_step(A, ai, F, n, m);	// ������ ��� ������� ����
	middle_step(F, n);					// ������� ��� ������� ����
	reverse_step(A, F, ai, n, m);		// �������� ��� ������� ����, ������ ���������� � ������ F
	
	ofstream out("output.txt");

	for (auto element : F)
		out << element << endl;
	out.close();

	return 0;
}