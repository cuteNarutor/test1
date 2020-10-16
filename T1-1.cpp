#include <iostream>
#include <string>
using namespace std;

int GetMin(int a, int b, int c) {
	int min = a < b ? a : b;
	return min < c ? min : c;
}

int d(string p,string q) {
	int p_len = p.length();
	int q_len = q.length();

	int** D = new int* [p_len];
	for (int i = 0; i < p_len; i++) {
		D[i] = new int[q_len];
	}

	for (int i = 0; i < p_len; i++) {
		D[i][0] = i;
	}
	for (int j = 0; j < q_len; j++) {
		D[0][j] = j;
	}

	if (p[0] != q[0]) {
		D[0][0] = 1;
	}

	for (int i = 1; i < p_len; i++) {
		for (int j = 1; j < q_len; j++) {
			D[i][j] = GetMin(D[i - 1][j] + 1, D[i][j - 1] + 1, D[i - 1][j - 1] +( p[i-1] == q[j-1] ? 0 : 1));
		}
	}
	return D[p_len-1][q_len-1];
}

int main() {
	string p, q;
	getline(cin, p);
	getline(cin, q);
	cout << d(p, q);
	return 0;
}
//修改了.cpp文件