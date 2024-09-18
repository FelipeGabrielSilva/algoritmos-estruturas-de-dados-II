#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Paises
{
    int codigo_pais;
    string nome;
};

struct Cidades
{
    int codigo_cidade;
    string nome;
    string UF;
    int codigo_pais;
};

struct Guias
{
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
};

struct Clientes
{
    int codigo_cliente;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct Pacotes
{
    int codigo_pacote;
    string descricao;
    int codigo_guia;
    float valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct Vendas
{
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    float valor_total;
};

struct Indices_cod_pacote
{
    int codigo_pacote;
    int endereco_pacote;
};

struct Indices_cod_guia
{
    int codigo_guia;
    int endereco_guia;
};

struct Indices_cod_venda
{
    int codigo_venda;
    int endereco_venda;
};

struct Indices_cod_cliente
{
    int codigo_cliente;
    int endereco_cliente;
};

void leitura_dados_paises(struct Paises pais[], int &cont)
{
    int i = 0;

    for (; i < cont; i++)
    {
        cout << "\n\nCODIGO DO PAIS " << (i + 1) << ": ";
        cin >> pais[i].codigo_pais;
        cin.ignore();

        if (pais[i].codigo_pais > 0)
        {
            cout << "NOME: ";
            getline(cin, pais[i].nome);
        }
    }

    cont = i;
};

void leitura_dados_cidades(struct Cidades cidade[], int &cont)
{
    int i = 0;

    for (; i < cont; i++)
    {
        cout << "\n\nCODIGO DA CIDADE " << (i + 1) << ": ";
        cin >> cidade[i].codigo_cidade;

        if (cidade[i].codigo_cidade > 0)
        {
            cout << "NOME: ";
            getline(cin, cidade[i].nome);

            cout << "UF: ";
            getline(cin, cidade[i].UF);

            cout << "CODIGO PAIS: ";
            cin >> cidade[i].codigo_pais;
        }
    }

    cont = i;
};

void inclusao_guia(struct Indices_cod_guia indice_guia[], struct Guias guia[], int &cont)
{
    int cod;

    cout << "\nINFORME O CODIGO DO NOVO GUIA: ";
    cin >> cod;

    guia[cont].codigo_guia = cod;

    cout << "NOME: ";
    getline(cin, guia[cont].nome);

    cout << "ENDERECO: ";
    getline(cin, guia[cont].endereco);

    cout << "TELEFONE: ";
    getline(cin, guia[cont].telefone);

    cout << "CIDADE: ";
    cin >> guia[cont].codigo_cidade;

    int i;
    for (i = cont - 1; indice_guia[i].codigo_guia > cod; i--)
    {
        indice_guia[i + 1].codigo_guia = indice_guia[i].codigo_guia;
        indice_guia[i + 1].endereco_guia = indice_guia[i].endereco_guia;
    }

    indice_guia[i + 1].codigo_guia = cod;
    indice_guia[i + 1].endereco_guia = cont;

    cont++;

    cout << "\nINCLUSAO REALIZADA COM SUCESSO";
};

int main()
{
    int cont = 2;
    struct Paises pais[2];
    struct Cidades cidade[2];

    int tamGuia = 3;
    struct Guias guia[tamGuia] = {
        {101, "João Silva", "Rua A, 123", "1234-5678", 1},
        {102, "Maria Oliveira", "Avenida B, 456", "8765-4321", 2},
        {103, "Carlos Souza", "Travessa C, 789", "9999-8888", 3}};

    struct Indices_cod_guia indice_guia[tamGuia] =
        {
            {101, 0},
            {102, 1},
            {103, 2},
        };

    inclusao_guia(indice_guia, guia, tamGuia);

    for (int i = 0; i < cont; i++)
    {
        cout << guia[i].codigo_guia << endl;
        cout << guia[i].nome << endl;
        cout << guia[i].endereco << endl;
    }

    leitura_dados_paises(pais, cont);
    for (int i = 0; i < cont; i++)
    {
        cout << pais[i].codigo_pais;
        cout << pais[i].nome;
    }
    leitura_dados_cidades(cidade, cont);
    for (int i = 0; i < cont; i++)
    {
        cout << cidade[i].codigo_cidade;
        cout << cidade[i].nome;
        cout << cidade[i].UF;
        cout << cidade[i].codigo_pais;
    }

    return 0;
}