#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const double precisao = 0.001;
    // double a = 0, b = 3;
    double a = 0, b = 10;

    // Fun��o f(x) = sen(x) - cos(x)
    auto f = [](double x)
    {
        // return sin(x) - cos(x);
        return x - cos(x) - 1;
    };

    // M�todo da Bissec��o para encontrar o intervalo
    if (f(a) * f(b) >= 0)
    {
        cout << "A fun��o n�o muda de sinal nesse intervalo!" << endl;
    }
    else
    {
        double meio;
        while ((b - a) >= precisao)
        {
            meio = (a + b) / 2;

            // Verifica se f(meio) � 0 ou se o intervalo j� � pequeno o suficiente
            if (f(meio) == 0.0)
                break;
            else if (f(meio) * f(a) < 0)
                b = meio;
            else
                a = meio;
        }

        cout << fixed << setprecision(4); // Trava a precis�o em 4 casas decimais
        cout << "Intervalo encontrado: [" << a << ", " << b << "]" << endl;
    }

    // M�todo da Secante para determinar a raiz com precis�o
    double x0 = a;
    double x1 = b;
    double x2;

    while (fabs(x1 - x0) >= precisao)
    {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }

    cout << fixed << setprecision(4); // Trava a precis�o em 4 casas decimais
    cout << "Raiz encontrada: " << x1 << endl;
    cout << "F(" << x1 << ") = " << f(x1) << " < 0.001" << endl;

    return 0;
}
