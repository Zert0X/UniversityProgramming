#include <iostream>
using namespace std;
int main()
{
	int N;
	int M;
	int** T;
	cout << "M(Columns): "; cin >> M;
	cout << "N(Rows): "; cin >> N;

	T = new int* [N];
	for (int i = 0; i < N; i++)
		T[i] = new int[M];

	for (int i = 0; i < N; i++) {
		cout << "\n";
		for (int j = 0; j < M; j++) {
			T[i][j] = rand() % 100 - 210;
			printf("|%3d", T[i][j]);
		}
		printf("|");
	}
	//filling res with 1
	int** res = new int* [M];
	for (int i = 0; i < M; i++)
		res[i] = new int[2];

	for (int i = 0; i < M; i++) {
		res[i][0] = 1;
		res[i][1] = 0;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (T[j][i] < 0) {
				res[i][0] = res[i][0] * T[j][i];
				res[i][1] = 1;
			}
		}
	}
	//output matrix
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << "\n";
		for (int j = 0; j < M; j++) {
			printf("|%3d", T[i][j]);
		}
		printf("|");
	}
	//output res array
		cout << "\n";
		for (int i = 0; i < M; i++) {
			
			res[i][1] == 1 ? printf("|%3d", res[i][0]): printf("|%3d", 0);
		}
		printf("|");
}
