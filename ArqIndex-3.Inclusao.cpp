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

void inclusao(struct indice index[], struct cliente cli[], int &cont)
{
    if (cont >= 5) // Verifica se o array está cheio
    {
        cout << "LIMITE DE CLIENTES ALCANCADO\n";
        return;
    }

    int cod;

    cout << "\nINFORME O CODIGO DO NOVO CLIENTE: ";
    cin >> cod;

    cli[cont].codigo = cod;

    cout << "NOME: ";
    cin >> cli[cont].nome;

    cout << "CIDADE: ";
    cin >> cli[cont].cidade;

    cout << "UF: ";
    cin >> cli[cont].uf;

    int i;
    for (i = cont - 1; index[i].codigo > cod; i--)
    {
        index[i + 1].codigo = index[i].codigo;
        index[i + 1].ender = index[i].ender;
    }

    index[i + 1].codigo = cod;
    index[i + 1].ender = cont;

    cont++;

    cout << "\nINCLUSAO REALIZADA COM SUCESSO";
};

void busca_binaria(struct indice index[], struct cliente dados[], int &cont)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    int cod;

    cout << "\nINFORME O CODIGO DO CLIENTE: ";
    cin >> cod;

    for (; f >= i && cod != index[m].codigo; m = (i + f) / 2)
    {
        if (cod > index[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == index[m].codigo)
    {
        cout << "\n\nCLIENTE ENCONTRADO";

        i = index[m].codigo;
        i = i - 1;

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
    int contador = 0;

    leitura_dados(dados, contador);
    leitura_indice(index, contador);

    for (int codpesq = 9; codpesq != 0;)
    {
        cout << "\n\n1. PROCURAR CLIENTE \n2. ADICIONAR CLIENTE \n0. ENCERRAR \n\nACAO: ";
        cin >> codpesq;

        switch (codpesq)
        {
        case 1:
            busca_binaria(index, dados, contador);
            break;

        case 2:
            inclusao(index, dados, contador);
            break;
        }
    }

    return 0;
};