#include <iostream>
#include <cmath>
using namespace std;

double funcao(double n)
{
    return n * n * sin(n);
}

double funcaoExercicio2(double n)
{
    return 1 / (1 + n);
}

double funcaoExercicio3(double n)
{
    return n / (1 + (4 * (n * n)));
}

double regraTrapezio(double (*f)(double), double a, double b, int n)
{
    double h = (b - a) / n;

    double integral = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++)
    {
        integral += f(a + i * h);
    }

    integral *= h;

    return integral;
}

int main()
{

    int n;
    double a, b;

    cout << "\nInforme um valor para o limite inferior: ";
    cin >> a;

    cout << "\nInforme um valor para o limite superior: ";
    cin >> b;

    cout << "\nInforme o numero de subintervalos: ";
    cin >> n;

    double resultado = regraTrapezio(funcaoExercicio3, a, b, n);
    cout << "\nO resultado e " << resultado << endl;

    return 0;
}