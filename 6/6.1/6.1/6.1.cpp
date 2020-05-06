#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	n = rand() % 40 + 10;
	cout << n << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50;
		cout << a[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i] << ' ';
			a[i] = a[i + 1];
		}
	}
	delete[] a;
	return 0;
}