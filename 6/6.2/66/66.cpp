#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int main()
{

    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    int s = 0, d = 0;


    cout << "Введите количество строк" << "\n";
    cin >> s;
    cout << "Введите количество столбцов" << "\n";
    cin >> d;

    int** Array = new int* [s];
    for (int i = 0; i < s; i++)
        Array[i] = new int[d];


    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < d; j++)
        {
            Array[i][j] = rand() % 100;
            cout << Array[i][j] << "\t";
        }
        cout << endl;
    }


    int k = 0;
    cout << "Введите количество строк для добавления: ";
    cin >> k;
    int** Barray = new int* [s + k];
    for (int i = 0; i < s + k; i++)
        Barray[i] = new int[d];

    for (int i = 0; i < s + k; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (i >= k)
                Barray[i][j] = Array[i - k][j];
            else
                Barray[i][j] = rand() % 100;
            cout << Barray[i][j] << "\t";
        }
        cout << endl;
    }

   

}

