#include <iostream>
using namespace std;

struct indice
{
    int codigo;
    int ender;
};

struct cliente
{
    int codigo;
    string nome;
    string cidade;
    string uf;
};

void leitura_dados(struct cliente cli[], int &cont)
{
    int i = 0;

    for (; i < cont; i++)
    {
        cout << "\n\nCODIGO DO CLIENTE " << (i + 1) << ": ";
        cin >> cli[i].codigo;

        if (cli[i].codigo > 0)
        {
            cout << "NOME: ";
            cin >> cli[i].nome;

            cout << "CIDADE: ";
            cin >> cli[i].cidade;

            cout << "UF: ";
            cin >> cli[i].uf;
        }
    }
};

void leitura_indice(struct indice index[], int &cont)
{
    for (int i = 0; i < cont; i++)
    {
        cout << "\n\nCODIGO DO INDICE " << (i + 1) << ": ";
        cin >> index[i].codigo;

        cout << "ENDERECO FISICO NA AREA DE DADOS: ";
        cin >> index[i].ender;
    }
};

void busca_binaria(struct indice index[], struct cliente dados[], int &cont, int cod)
{
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    for (; f >= i && cod != index[m].codigo; m = (i + f) / 2)
    {
        if (cod > index[m].codigo)
            i = m + 1;
        else
            i = m - 1;
    }

    if (cod == index[m].codigo)
    {
        cout << "\n\nCLIENTE ENCONTRADO";

        i = index[m].codigo;

        cout << "\nCODIGO: " << dados[i].codigo;
        cout << "\nNOME: " << dados[i].nome;
        cout << "\nCIDADE: " << dados[i].cidade;
        cout << "\nUF: " << dados[i].uf;
    }
    else
    {
        cout << "\n\nCLIENTE NAO ENCONTRADO";
    }
}

int main()
{
    struct indice index[5];
    struct cliente dados[5];
    int contador = 5;

    leitura_dados(dados, contador);
    leitura_indice(index, contador);

    for (int codpesq = 9; codpesq != 0;)
    {
        cout << "\n\nINFORME O CODIGO DO CLIENTE A SER BUSCADO (0 PARA ENCERRAR): ";
        cin >> codpesq;

        if (codpesq != 0)
        {
            busca_binaria(index, dados, contador, codpesq);
        }
    }

    return 0;
};