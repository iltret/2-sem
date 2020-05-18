#include <iostream>

using namespace std;

int n, q = 0, k = 0;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива А: ";
	cin >> n;
	cout << "Введите элементы массива А: ";
	int* A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int nb;
	cout << "Введите размер массива В: ";
	cin >> nb;
	cout << "Введите элементы массива B: ";
	int* B = new int[nb];
	for (int j = 0; j < nb; j++)
	{
		cin >> B[j];
	}
	int nc = 0;
	int* C = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < nb; j++)
		{
			if (A[i] == B[j]) {
				q++;
			}
		}
		if (q < 2) {
			C[k] = A[i];
			nc++;
			k++;
		}
		q = 0;
	}
	cout << "Получившийся массив С: ";
	for (int k = 0; k < nc; k++)
	{
		cout << C[k] << " ";
	}

}
