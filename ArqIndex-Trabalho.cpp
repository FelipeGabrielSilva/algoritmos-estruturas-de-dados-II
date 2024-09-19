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

bool buscaBinaria_guia(struct Indices_cod_guia indice_guia[], struct Guias guia[], int contGuia, int codigo_ser_buscado)
{
    int i = 0;
    int f = contGuia - 1;

    while (i <= f)
    {
        int m = (i + f) / 2;

        if (codigo_ser_buscado == indice_guia[m].codigo_guia)
        {
            return true;
        }
        else if (codigo_ser_buscado > indice_guia[m].codigo_guia)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }

    return false;
}

bool buscaBinaria_cidade(struct Cidades cidade[], int contCidade, int codigo_ser_buscado)
{
    int i = 0;
    int f = contCidade - 1;

    while (i <= f)
    {
        int m = (i + f) / 2;

        if (codigo_ser_buscado == cidade[m].codigo_cidade)
        {
            return true;
        }
        else if (codigo_ser_buscado > cidade[m].codigo_cidade)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }

    return false;
}

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
            cin >> pais[i].nome;
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
            cin >> cidade[i].nome;

            cout << "UF: ";
            cin >> cidade[i].UF;

            cout << "CODIGO PAIS: ";
            cin >> cidade[i].codigo_pais;
        }
    }

    cont = i;
};

void inclusao_guia(struct Indices_cod_guia indice_guia[], struct Guias guia[], int &contGuia)
{
    if (contGuia >= 10)
    {
        cout << "LIMITE DE GUIAS ALCANCADO\n";
        return;
    }

    int cod;

    cout << "\nINFORME O CODIGO DO NOVO GUIA: ";
    cin >> cod;

    bool resultado = buscaBinaria_guia(indice_guia, guia, contGuia, cod);

    if (resultado == false)
    {
        guia[contGuia].codigo_guia = cod;

        cout << "NOME: ";
        cin >> guia[contGuia].nome;

        cout << "ENDERECO: ";
        cin >> guia[contGuia].endereco;

        cout << "TELEFONE: ";
        cin >> guia[contGuia].telefone;

        cout << "CIDADE: ";
        cin >> guia[contGuia].codigo_cidade;

        int i;
        for (i = contGuia - 1; i >= 0 && indice_guia[i].codigo_guia > cod; i--)
        {
            indice_guia[i + 1].codigo_guia = indice_guia[i].codigo_guia;
            indice_guia[i + 1].endereco_guia = indice_guia[i].endereco_guia;
        }

        indice_guia[i + 1].codigo_guia = cod;
        indice_guia[i + 1].endereco_guia = contGuia;

        contGuia++;

        cout << "\nINCLUSAO REALIZADA COM SUCESSO";
        return;
    }
    else
    {
        cout << "\nNAO FOI POSSIVEL REALIZAR A INCLUSAO";
        return;
    }
};

int main()
{
    int contPais = 0;
    int contCidade = 0;
    int contGuia = 0;
    struct Paises pais[10];
    struct Cidades cidade[10];

    struct Guias guia[10];
    struct Indices_cod_guia indice_guia[10];

    for (int codpesq = 9; codpesq != 0;)
    {
        cout << "\n\n1. INCLUIR GUIA \n2. ADICIONAR PAIS \n3. ADICIONAR CIDADE \n0. ENCERRAR \n\nACAO: ";
        cin >> codpesq;

        switch (codpesq)
        {
        case 1:
            inclusao_guia(indice_guia, guia, contGuia);
            break;

            /* case 2:
                leitura_dados_paises(pais, contPais);
                break;

            case 3:
                leitura_dados_cidades(cidade, contCidade);
                break; */
        }
    }

    return 0;
}