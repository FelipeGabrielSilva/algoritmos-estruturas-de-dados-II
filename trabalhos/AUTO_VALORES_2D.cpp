#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    float a1, a2, b1, b2, a, b, c, delta, x1, x2;

    // Entradas
    cout << "Insira a1: ";
    cin >> a1;
    cout << "Insira b1: ";
    cin >> b1;
    cout << "Insira a2: ";
    cin >> a2;
    cout << "Insira b2: ";
    cin >> b2;

    // Exibe a matriz
    cout << "\nMatriz A: \n";
    cout << "[" << a1 << " " << b1 << "]\n";
    cout << "[" << a2 << " " << b2 << "]\n";

    // Cálculo do determinante
    a = 1;
    b = -a1 - b2;
    c = (a1 * b2) - (a2 * b1);

    // Cálculo do delta
    delta = b * b - 4 * a * c;

    cout << "\nDelta: " << delta << endl;

    // Verifica os autovalores
    if (delta < 0) {
        cout << "Não existem autovalores." << endl;
    } else if(delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "\nAutovalores: " << endl;
        cout << "Lambda 1 = " << x1 << endl;
        cout << "Lambda 2 = " << x2 << endl;
    } else{
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "\nAutovalores: " << endl;
        cout << "Lambda 1 = Lambda 2 = " << x1 << endl;
    }

    return 0;
}
