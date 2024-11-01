#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const double precisao = 0.000001;
    // double a = 0, b = 3;
    double a = 0, b = 10;

    // funcao f(x) = sen(x) - cos(x)
    auto f = [](double x)
    {
        // return sin(x) - cos(x);
        return x - cos(x) - 1;
    };

    // metodo da bisseccao para encontrar o intervalo
    if (f(a) * f(b) >= 0)
    {
        cout << "A funcao nao muda de sinal nesse intervalo!" << endl;
    }
    else
    {
        double meio;
        while ((b - a) >= precisao)
        {
            meio = (a + b) / 2;

            if (f(meio) == 0.0)
                break;
            else if (f(meio) * f(a) < 0)
                b = meio;
            else
                a = meio;
        }

        cout << fixed << setprecision(9);
        cout << "Intervalo encontrado: [" << a << ", " << b << "]" << endl;
    }

    // metodo da secante para determinar a raiz com trava
    double x0 = a;
    double x1 = b;
    double x2;

    while (fabs(x1 - x0) >= precisao)
    {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }

    cout << fixed << setprecision(9);
    cout << "Raiz encontrada: " << x1 << endl;
    cout << "F(" << x1 << ") = " << f(x1) << " < 0.001" << endl;

    return 0;
}
