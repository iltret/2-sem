#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
typedef double(*fptr1)(double);
typedef double(*fptr2)(double);
double f(double x)
{
    return 0.1 * pow(x, 2) - x * log(fabs(x));
}
double df(double x)
{
    return 0.2 * x - log(fabs(x)) - 1;
}
double Newton(fptr1 f, double e, fptr2 g)
{
    double x0, x1;
    x0 = double(1000 + rand() % 1000) / 1000;
    do
    {
        x1 = x0 - (*f)(x0) / (*g)(x0);
        x0 = x1;
    } while (fabs((*f)(x0)) > e);
    return x0;
}
double del(fptr1 f, double a, double b, double e)
{
    double x;
    do
    {
        x = (a + b) / 2;
        if ((*f)(a) * (*f)(x) < 0)
        {
            b = x;
        }
        else a = x;
    } while (fabs((*f)(x)) > e && fabs(a - b) > e);
    return x;
}
double iter(fptr1 f, double e)
{
    int n = 0;
    double x0, x1;
    x0 = double(1000 + rand() % 1000) / 1000;
    cout << x0 << endl;
    do
    {
        x1 = (*f)(x0) + x0;
        cout << x1 << " ";
        x0 = (*f)(x1) + x1;
        cout << x0 << " " << endl;
    } while (fabs(x1 - x0) > e);
    return x0;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int p;
    do
    {
        cout << "1.Решение методом Ньютона\n";
        cout << "2.Решение методом половинного деления\n";
        cout << "3.Решение методом итераций\n";
        cout << "4.Выход\n";
        cin >> p;
        switch (p)
        {
        case 1:
        {
            double res = Newton(f, 0.000001, df);
            cout << "\nX = " << res << endl;
            break;
        }

        case 2:
        {
            double res = del(f, 1, 2, 0.000001);
            cout << "\nX = " << res << endl;
            break;
        }

        case 3:
        {
            double res = iter(f, 0.000001);
            cout << "\nX = " << res << endl;
            break;
        }
        }
    } while (p != 4);
}