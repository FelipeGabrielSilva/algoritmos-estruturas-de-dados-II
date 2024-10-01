#include <iostream>
#include <string>

using namespace std;

// paises: Codigo_pais, nome
struct pais
{
    int seqpais;
    string nome;
};

struct idx_pais
{
    int seqpais;
    int endereco;
};

// Cidades: Codigo_cidade, nome, UF, Codigo_pais
struct cidade
{
    int seqcidade;
    string nome;
    string uf;
    int seqpais;
};

struct idx_cidade
{
    int seqcidade;
    int endereco;
};

// Guias: Codigo_guia, nome, Endereco, telefone, Codigo_cidade
struct guia
{
    int seqguia;
    string nome;
    string endereco;
    string telefone;
    int seqcidade;
    int status;
};

struct idx_guia
{
    int seqguia;
    int endereco;
};

// Clientes: Codigo_cliente, nome, Endereco, Codigo_cidade,
struct cliente
{
    int seqcliente;
    string nome;
    string endereco;
    int seqcidade;
    int status;
};

struct idx_cliente
{
    int seqcliente;
    int endereco;
};

/*Pacotes: Codigo_pacote, Descricao, Codigo_guia, valor_por_pessoa, total_participantes, quant_max_participantes
** Criar dois �ndices: Codigo_pacote e Codigo_guia*/

struct pacote
{
    int seqpacote;
    string descricao;
    int seqguia;
    float valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct idx_pacote
{
    int seqpacote;
    int seqguia;
    int endereco;
};

/*Vendas: Codigo_venda, Codigo_cliente, Codigo_pacote, quantidade_pessoas, valor_total
** Criar dois �ndices: Codigo_venda e Codigo_cliente*/

struct venda
{
    int seqvenda;
    int seqcliente;
    int seqpacote;
    int quantidade_pessoas;
    float valor_total;
};

struct idx_venda
{
    int seqvenda;
    int seqcliente;
    int endereco;
};

// 1) Escreva fun��es espec�ficas para a leitura dos dados das estruturas: paises, Cidades.

void ler_pais(pais paises[], idx_pais idx_paises[], int &cont_pais)
{
    int cod_temp = cont_pais + 1;

    if (cont_pais < 10)
    {
        cout << "Pais Numero " << cod_temp << ":" << endl;
        paises[cont_pais].seqpais = cod_temp;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, paises[cont_pais].nome);

        idx_paises[cont_pais].seqpais = cod_temp;
        idx_paises[cont_pais].endereco = cont_pais;

        cont_pais++;
    }
    else
    {
        cout << "Limite de paises atingido!";
    }
}

void ler_cidade(cidade cidades[], idx_cidade idx_cidades[], int &cont_cidade, pais paises[], idx_pais idx_paises[], int cont_pais)
{
    int cod_temp = cont_cidade + 1;

    if (cont_cidade < 10)
    {
        cout << "Cidade Numero " << cod_temp << ":" << endl;
        cidades[cont_cidade].seqcidade = cod_temp;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, cidades[cont_cidade].nome);

        cout << "UF: ";
        getline(cin, cidades[cont_cidade].uf);

        int cod_temp_pais;
        cout << "Codigo do Pais: ";
        cin >> cod_temp_pais;

        cidades[cont_cidade].seqpais = cod_temp_pais;

        bool pais_existe = false;
        for (int i = 0; i < cont_pais; i++)
        {
            if (cod_temp_pais == idx_paises[i].seqpais)
            {
                cout << "Pais: " << paises[idx_paises[i].endereco].nome << endl;
                pais_existe = true;
                break;
            }
        }

        if (!pais_existe)
        {
            cout << "Pais nao existe!" << endl;
            return;
        }

        idx_cidades[cont_cidade].seqcidade = cod_temp;
        idx_cidades[cont_cidade].endereco = cont_cidade;

        cont_cidade++;
    }
    else
    {
        cout << "Limite de cidades atingido!";
    }
}

/*2) Escreva uma fun��o para permitir a inclus�o de novos registros na tabela de Guias.
2.1) O programa dever� garantir que o Codigo do guia a ser inserido nao existe na tabela de Guias.
2.2) Quando o usu�rio digitar o Codigo da cidade, o programa dever� buscar este Codigo na tabela de Cidades e exibir o nome da cidade e UF e o nome do pais.*/

void ler_guia(guia guias[], idx_guia idx_guias[], int &cont_guia, cidade cidades[], idx_cidade idx_cidades[], int cont_cidade, pais paises[], idx_pais idx_paises[], int cont_pais)
{
    if (cont_guia >= 10)
    {
        cout << "Limite de guias atingido!" << endl;
        return;
    }

    int cod_temp = cont_guia + 1;

    cout << "Guia Numero " << cod_temp << ":" << endl;
    guias[cont_guia].seqguia = cod_temp;
    cin.ignore();

    cout << "Nome: ";
    getline(cin, guias[cont_guia].nome);

    cout << "Endereco: ";
    getline(cin, guias[cont_guia].endereco);

    cout << "Telefone: ";
    getline(cin, guias[cont_guia].telefone);

    int cod_temp_cidade;
    cout << "Codigo da Cidade: ";
    cin >> cod_temp_cidade;

    guias[cont_guia].seqcidade = cod_temp_cidade;

    bool cidade_existe = false;
    for (int i = 0; i < cont_cidade; i++)
    {
        if (cod_temp_cidade == idx_cidades[i].seqcidade)
        {
            cout << "Cidade: " << cidades[idx_cidades[i].endereco].nome << endl;
            cidade_existe = true;

            int cod_temp_pais = cidades[idx_cidades[i].endereco].seqpais;
            cout << "Codigo pais: " << cod_temp_pais << endl;

            bool pais_existe = false;
            for (int j = 0; j < cont_pais; j++)
            {
                if (cod_temp_pais == idx_paises[j].seqpais)
                {
                    cout << "Pais: " << paises[idx_paises[j].endereco].nome << endl;
                    pais_existe = true;
                    break;
                }
            }

            if (!pais_existe)
            {
                cout << "Pais nao encontrado!" << endl;
            }

            break;
        }
    }

    if (!cidade_existe)
    {
        cout << "Cidade nao existe!" << endl;
        return;
    }

    guias[cont_guia].status = 0;

    idx_guias[cont_guia].seqguia = cod_temp;
    idx_guias[cont_guia].endereco = cont_guia;

    cont_guia++;
}

/*3) Escreva uma fun��o para permitir a inclus�o de novos registros na tabela de Clientes.
3.1) O programa dever� garantir que o Codigo do cliente a ser inserido nao existe na tabela de clientes.
3.2) Quando o usu�rio digitar o Codigo da cidade, o programa dever� buscar este Codigo na tabela de Cidades e exibir o nome da cidade e UF e o nome do pais.*/

void ler_cliente(cliente clientes[], idx_cliente idx_clientes[], int &cont_cliente, guia guias[], idx_guia idx_guias[], int cont_guia, cidade cidades[], idx_cidade idx_cidades[], int cont_cidade, pais paises[], idx_pais idx_paises[], int cont_pais)
{
    if (cont_guia >= 10)
    {
        cout << "Limite de clientes atingido!" << endl;
        return;
    }

    int cod_temp = cont_cliente + 1;

    cout << "Cliente Numero " << cod_temp << ":" << endl;
    clientes[cont_cliente].seqcliente = cod_temp;
    cin.ignore();

    cout << "Nome: ";
    getline(cin, clientes[cont_cliente].nome);

    cout << "Endereco: ";
    getline(cin, clientes[cont_cliente].endereco);

    int cod_temp_cidade;
    cout << "Codigo da Cidade: ";
    cin >> cod_temp_cidade;

    clientes[cont_cliente].seqcidade = cod_temp_cidade;

    bool cidade_existe = false;
    for (int i = 0; i < cont_cidade; i++)
    {
        if (cod_temp_cidade == idx_cidades[i].seqcidade)
        {
            cout << "Cidade: " << cidades[idx_cidades[i].endereco].nome << endl;
            cidade_existe = true;

            int cod_temp_pais = cidades[idx_cidades[i].endereco].seqpais;
            cout << "Codigo pais: " << cod_temp_pais << endl;

            bool pais_existe = false;
            for (int j = 0; j < cont_pais; j++)
            {
                if (cod_temp_pais == idx_paises[j].seqpais)
                {
                    cout << "Pais: " << paises[idx_paises[j].endereco].nome << endl;
                    pais_existe = true;
                    break;
                }
            }

            if (!pais_existe)
            {
                cout << "Pais nao encontrado!" << endl;
            }

            break;
        }
    }

    if (!cidade_existe)
    {
        cout << "Cidade nao existe!" << endl;
        return;
    }

    clientes[cont_cliente].status = 0;

    idx_clientes[cont_cliente].seqcliente = cod_temp;
    idx_clientes[cont_cliente].endereco = cont_cliente;

    cont_cliente++;
}

/*4) Escreva uma fun��o para permitir a exclus�o de registros na tabela de Clientes.
4.1) O programa nao dever� permitir a exclus�o de clientes que possuam vendas cadastradas em seu nome.*/

void excluir_cliente(cliente clientes[], idx_cliente idx_clientes[], venda vendas[], idx_venda idx_vendas[], int &cont_cliente, int &cont_venda)
{
    cout << "Digite o Codigo do cliente a ser excluido: ";
    int cod_cliente;
    cin >> cod_cliente;

    int inicio = 0;
    int fim = cont_cliente - 1;
    int idx_cliente_encontrado = -1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (clientes[idx_clientes[meio].endereco].seqcliente == cod_cliente)
        {
            idx_cliente_encontrado = meio;
            break;
        }
        else if (clientes[idx_clientes[meio].endereco].seqcliente < cod_cliente)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    if (idx_cliente_encontrado == -1)
    {
        cout << "Cliente nao encontrado!" << endl;
        return;
    }

    bool possui_vendas = false;
    for (int i = 0; i < cont_venda; i++)
    {
        if (vendas[idx_vendas[i].endereco].seqcliente == clientes[idx_clientes[idx_cliente_encontrado].endereco].seqcliente)
        {
            possui_vendas = true;
            break;
        }
    }

    if (possui_vendas)
    {
        cout << "Nao e possivel excluir um cliente que possui vendas cadastradas!" << endl;
        return;
    }

    clientes[idx_clientes[idx_cliente_encontrado].endereco].status = 1;
    cout << "Cliente excluido com sucesso!" << endl;

    // Reorganiza��o:
    int j = 0;
    for (int i = 0; i < cont_cliente; i++)
    {
        if (clientes[i].status == 0)
        {
            idx_clientes[j].seqcliente = clientes[i].seqcliente;
            idx_clientes[j].endereco = i;
            j++;
        }
    }
    cont_cliente = j;
}

/*5) Escreva uma fun��o para permitir a exclus�o de registros na tabela de Guias.
5.1) O programa nao dever� permitir a exclus�o de guias que possuam pacotes cadastrados em seu nome.*/

void excluir_guia(guia guias[], idx_guia idx_guias[], pacote pacotes[], idx_pacote idx_pacotes[], int &cont_guia, int &cont_pacote)
{
    cout << "Digite o Codigo do guia a ser excluido: ";
    int cod_guia;
    cin >> cod_guia;

    int inicio = 0;
    int fim = cont_guia - 1;
    int idx_guia_encontrado = -1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (guias[idx_guias[meio].endereco].seqguia == cod_guia)
        {
            idx_guia_encontrado = meio;
            break;
        }
        else if (guias[idx_guias[meio].endereco].seqguia < cod_guia)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    if (idx_guia_encontrado == -1)
    {
        cout << "Guia nao encontrado!" << endl;
        return;
    }

    bool possui_pacotes = false;
    for (int i = 0; i < cont_pacote; i++)
    {
        if (pacotes[idx_pacotes[i].endereco].seqguia == guias[idx_guias[idx_guia_encontrado].endereco].seqguia)
        {
            possui_pacotes = true;
            break;
        }
    }

    if (possui_pacotes)
    {
        cout << "Nao e possivel excluir um guia que possui pacotes cadastrados!" << endl;
        return;
    }

    guias[idx_guias[idx_guia_encontrado].endereco].status = 1;
    cout << "Guia excluido com sucesso!" << endl;

    // Reorganiza��o:
    int j = 0;
    for (int i = 0; i < cont_guia; i++)
    {
        if (guias[i].status == 0)
        {
            idx_guias[j].seqguia = guias[i].seqguia;
            idx_guias[j].endereco = i;
            j++;
        }
    }
    cont_guia = j;
}

/*6) Escreva uma fun��o para permitir a inclus�o de novos registros na tabela de Pacotes.
6.1) Quando o usu�rio digitar o Codigo do guia, o programa dever� buscar este Codigo na tabela de Guias e exibir o nome do guia, o nome da cidade e o nome do pais.*/

void ler_pacote(pacote pacotes[], idx_pacote idx_pacotes[], int &cont_pacote,
                guia guias[], idx_guia idx_guias[], int cont_guia,
                cidade cidades[], idx_cidade idx_cidades[], int cont_cidade,
                pais paises[], idx_pais idx_paises[], int cont_pais)
{

    int cod_temp = cont_pacote + 1;
    if (cont_pacote < 10)
    {
        cout << "Pacote Numero " << cod_temp << ":" << endl;
        pacotes[cont_pacote].seqpacote = cod_temp;
        cin.ignore();
        cout << "Descricao: ";
        getline(cin, pacotes[cont_pacote].descricao);

        // Leitura do Codigo do guia
        cout << "Codigo do Guia: ";
        int cod_temp_guia;
        cin >> cod_temp_guia;
        pacotes[cont_pacote].seqguia = cod_temp_guia;

        bool guia_existe = false;
        for (int i = 0; i < cont_guia; i++)
        {
            if (cod_temp_guia == idx_guias[i].seqguia)
            {
                // Exibe o nome do guia
                guia_existe = true;
                int guia_endereco = idx_guias[i].endereco;
                cout << "Guia: " << guias[guia_endereco].nome << endl;

                int cod_cidade = guias[guia_endereco].seqcidade;
                bool cidade_existe = false;
                for (int j = 0; j < cont_cidade; j++)
                {
                    if (cod_cidade == idx_cidades[j].seqcidade)
                    {
                        cidade_existe = true;
                        int cidade_endereco = idx_cidades[j].endereco;
                        cout << "Cidade: " << cidades[cidade_endereco].nome << " (" << cidades[cidade_endereco].uf << ")" << endl;

                        int cod_pais = cidades[cidade_endereco].seqpais;
                        bool pais_existe = false;
                        for (int k = 0; k < cont_pais; k++)
                        {
                            if (cod_pais == idx_paises[k].seqpais)
                            {
                                pais_existe = true;
                                int pais_endereco = idx_paises[k].endereco;
                                cout << "Pais: " << paises[pais_endereco].nome << endl;
                                break;
                            }
                        }

                        if (!pais_existe)
                        {
                            cout << "Pais nao encontrado!" << endl;
                        }
                        break;
                    }
                }

                if (!cidade_existe)
                {
                    cout << "Cidade nao encontrada!" << endl;
                }

                break;
            }
        }

        if (!guia_existe)
        {
            cout << "Guia nao existe!" << endl;
            return;
        }

        cout << "Valor por pessoa: ";
        cin >> pacotes[cont_pacote].valor_por_pessoa;
        pacotes[cont_pacote].total_participantes = 0;
        cout << "Quantidade maxima de participantes: ";
        cin >> pacotes[cont_pacote].quant_max_participantes;

        idx_pacotes[cont_pacote].seqpacote = cod_temp;
        idx_pacotes[cont_pacote].seqguia = cod_temp_guia;
        idx_pacotes[cont_pacote].endereco = cont_pacote;

        cont_pacote++;
    }
    else
    {
        cout << "Limite de pacotes atingido!" << endl;
    }
}

/*7.1) Quando o usu�rio digitar o Codigo_cliente, o programa dever� buscar este Codigo na tabela de Clientes e exibir seu nome e o nome da sua cidade.
7.2) Quando o usu�rio digitar o Codigo_pacote, o programa dever� buscar este Codigo na tabela de Pacotes e exibir a Descricao, o nome do guia e o valor por pessoa.
7.3) Quando o usu�rio digitar quantidade_pessoas, o programa dever� adicionar esta informa��o ao total_participantes da tabela de Pacotes.
7.3.1) O programa nao dever� permitir que o total_participantes seja maior do que quant_max_participantes.
7.4) O programa dever� calcular e exibir o valor total a ser pago pelo cliente e gravar essa informa��o em valor_total na tabela Vendas.*/

void ler_venda(venda vendas[], idx_venda idx_vendas[], int &cont_venda,
               cliente clientes[], idx_cliente idx_clientes[], int cont_cliente,
               pacote pacotes[], idx_pacote idx_pacotes[], int cont_pacote,
               guia guias[], idx_guia idx_guias[], int cont_guia,
               cidade cidades[], idx_cidade idx_cidades[], int cont_cidade,
               pais paises[], idx_pais idx_paises[], int cont_pais)
{

    int cod_temp = cont_venda + 1;
    if (cont_venda < 10)
    {
        cout << "Venda Numero " << cod_temp << ":" << endl;
        vendas[cont_venda].seqvenda = cod_temp;

        cout << "Codigo do Cliente: ";
        int cod_temp_cliente;
        cin >> cod_temp_cliente;
        vendas[cont_venda].seqcliente = cod_temp_cliente;

        bool cliente_existe = false;
        string nome_cliente, nome_cidade;

        for (int i = 0; i < cont_cliente; i++)
        {
            if (cod_temp_cliente == idx_clientes[i].seqcliente)
            {
                nome_cliente = clientes[idx_clientes[i].endereco].nome;
                int cod_cidade_cliente = clientes[idx_clientes[i].endereco].seqcidade;

                for (int j = 0; j < cont_cidade; j++)
                {
                    if (cod_cidade_cliente == idx_cidades[j].seqcidade)
                    {
                        nome_cidade = cidades[idx_cidades[j].endereco].nome;
                        break;
                    }
                }

                cliente_existe = true;
                break;
            }
        }

        if (cliente_existe)
        {
            cout << "Cliente: " << nome_cliente << endl;
            cout << "Cidade: " << nome_cidade << endl;
        }
        else
        {
            cout << "Cliente nao existe!" << endl;
            return;
        }

        cout << "Codigo do Pacote: ";
        int cod_temp_pacote;
        cin >> cod_temp_pacote;
        vendas[cont_venda].seqpacote = cod_temp_pacote;

        bool pacote_existe = false;
        string descricao_pacote, nome_guia;
        float valor_por_pessoa = 0;
        int total_participantes_pacote = 0, max_participantes_pacote = 0;

        for (int i = 0; i < cont_pacote; i++)
        {
            if (cod_temp_pacote == idx_pacotes[i].seqpacote)
            {
                descricao_pacote = pacotes[idx_pacotes[i].endereco].descricao;
                valor_por_pessoa = pacotes[idx_pacotes[i].endereco].valor_por_pessoa;
                total_participantes_pacote = pacotes[idx_pacotes[i].endereco].total_participantes;
                max_participantes_pacote = pacotes[idx_pacotes[i].endereco].quant_max_participantes;

                int cod_guia_pacote = pacotes[idx_pacotes[i].endereco].seqguia;

                for (int j = 0; j < cont_guia; j++)
                {
                    if (cod_guia_pacote == idx_guias[j].seqguia)
                    {
                        nome_guia = guias[idx_guias[j].endereco].nome;
                        break;
                    }
                }

                pacote_existe = true;
                break;
            }
        }

        if (pacote_existe)
        {
            cout << "Descricao do Pacote: " << descricao_pacote << endl;
            cout << "Guia: " << nome_guia << endl;
            cout << "Valor por Pessoa: " << valor_por_pessoa << endl;

            cout << "Quantidade de pessoas para a venda: ";
            int quantidade_pessoas;
            cin >> quantidade_pessoas;

            if (total_participantes_pacote + quantidade_pessoas > max_participantes_pacote)
            {
                cout << "Numero total de participantes excede o limite maximo permitido!" << endl;
                return;
            }
            else
            {
                vendas[cont_venda].quantidade_pessoas = quantidade_pessoas;

                float valor_total = quantidade_pessoas * valor_por_pessoa;
                vendas[cont_venda].valor_total = valor_total;
                cout << "Valor total a ser pago: " << valor_total << endl;
                pacotes[idx_pacotes[cod_temp_pacote - 1].endereco].total_participantes += quantidade_pessoas;
            }
        }
        else
        {
            cout << "Pacote nao existe!" << endl;
            return;
        }

        idx_vendas[cont_venda].seqvenda = cod_temp;
        idx_vendas[cont_venda].seqcliente = cod_temp_cliente;
        idx_vendas[cont_venda].endereco = cont_venda;

        cont_venda++;
    }
    else
    {
        cout << "Limite de vendas atingido!" << endl;
    }
}

/*8) Escreva uma fun��o para permitir ao usu�rio consultar os dados de determinado pacote.
8.1) Para cada pacote consultado, exibir: todos os seus dados e o valor total arrecadado pelo pacote (valor_por_pessoa * total_participantes).*/

void busca_binaria_pacote(pacote pacotes[], idx_pacote idx_pacotes[], int cont_pacote)
{
    cout << "Digite o Codigo do pacote que deseja consultar: ";
    int cod_pacote;
    cin >> cod_pacote;

    int inicio = 0;
    int fim = cont_pacote - 1;
    bool pacote_encontrado = false;
    int endereco_pacote = -1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (idx_pacotes[meio].seqpacote == cod_pacote)
        {
            pacote_encontrado = true;
            endereco_pacote = idx_pacotes[meio].endereco;
            break;
        }
        else if (idx_pacotes[meio].seqpacote < cod_pacote)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    if (pacote_encontrado)
    {

        cout << "Pacote encontrado:" << endl;
        cout << "Codigo do Pacote: " << pacotes[endereco_pacote].seqpacote << endl;
        cout << "Descricao: " << pacotes[endereco_pacote].descricao << endl;
        cout << "Codigo do Guia: " << pacotes[endereco_pacote].seqguia << endl;
        cout << "Valor por Pessoa: " << pacotes[endereco_pacote].valor_por_pessoa << endl;
        cout << "Total de Participantes: " << pacotes[endereco_pacote].total_participantes << endl;
        cout << "Quantidade maxima de Participantes: " << pacotes[endereco_pacote].quant_max_participantes << endl;

        // valor total
        float valor_total_arrecadado = pacotes[endereco_pacote].valor_por_pessoa * pacotes[endereco_pacote].total_participantes;
        cout << "Valor total arrecadado: " << valor_total_arrecadado << endl;
    }
    else
    {
        cout << "Pacote nao encontrado." << endl;
    }
}

/*9) Escreva uma fun��o para exibir todos os registros da tabela Pacotes que tenham sido completamente vendidos (total_participantes = quant_max_participantes).
  9.1) As seguintes informa��es devem ser exibidas: Codigo, Descricao, nome do guia, valor total arrecadado pelo pacote (valor_por_pessoa * total_participantes).*/

void exibir_pacotes_completamente_vendidos(pacote pacotes[], idx_pacote idx_pacotes[], int cont_pacote, guia guias[], int cont_guia)
{
    cout << "Pacotes completamente vendidos:" << endl;
    bool algum_vendido = false;

    for (int i = 0; i < cont_pacote; i++)
    {
        if (pacotes[i].total_participantes == pacotes[i].quant_max_participantes)
        {
            algum_vendido = true;

            string nome_guia;
            for (int j = 0; j < cont_guia; j++)
            {
                if (guias[j].seqguia == pacotes[i].seqguia)
                {
                    nome_guia = guias[j].nome;
                    break;
                }
            }

            float valor_total_arrecadado = pacotes[i].valor_por_pessoa * pacotes[i].total_participantes;

            cout << "Codigo do Pacote: " << pacotes[i].seqpacote << endl;
            cout << "Descricao: " << pacotes[i].descricao << endl;
            cout << "Nome do Guia: " << nome_guia << endl;
            cout << "Valor Total Arrecadado: " << valor_total_arrecadado << endl;
            cout << "-----------------------------" << endl;
        }
    }

    if (!algum_vendido)
    {
        cout << "Nenhum pacote completamente vendido." << endl;
    }
}
/*10) Escreva uma fun��o para exibir todos os registros da tabela de vendas.
10.1) As seguintes informa��es devem ser exibidas: Codigo, nome do cliente, Descricao do pacote, quantidade_pessoas e valor_total da venda.
10.2) Ao final, a fun��o dever� exibir o valor total vendido.*/

void exibir_vendas(venda vendas[], cliente clientes[], pacote pacotes[], idx_venda idx_vendas[], int cont_venda, int cont_cliente, int cont_pacote)
{
    cout << "Registros de Vendas:" << endl;
    float valor_total_vendido = 0.0;

    for (int i = 0; i < cont_venda; i++)
    {
        string nome_cliente;
        for (int j = 0; j < cont_cliente; j++)
        {
            if (clientes[j].seqcliente == vendas[idx_vendas[i].endereco].seqcliente)
            {
                nome_cliente = clientes[j].nome;
                break;
            }
        }

        string descricao_pacote;
        for (int k = 0; k < cont_pacote; k++)
        {
            if (pacotes[k].seqpacote == vendas[idx_vendas[i].endereco].seqpacote)
            {
                descricao_pacote = pacotes[k].descricao;
                break;
            }
        }

        cout << "Codigo da Venda: " << vendas[idx_vendas[i].endereco].seqvenda << endl;
        cout << "Nome do Cliente: " << nome_cliente << endl;
        cout << "Descricao do Pacote: " << descricao_pacote << endl;
        cout << "Quantidade de Pessoas: " << vendas[idx_vendas[i].endereco].quantidade_pessoas << endl;
        cout << "Valor Total da Venda: " << vendas[idx_vendas[i].endereco].valor_total << endl;
        cout << "-----------------------------" << endl;

        valor_total_vendido += vendas[idx_vendas[i].endereco].valor_total;
    }

    cout << "Valor Total Vendido: " << valor_total_vendido << endl;
}

// PREDEFINIR VALORES
void predefinir_valores(pais paises[], idx_pais idx_paises[],
                        cidade cidades[], idx_cidade idx_cidades[],
                        guia guias[], idx_guia idx_guias[],
                        cliente clientes[], idx_cliente idx_clientes[],
                        pacote pacotes[], idx_pacote idx_pacotes[],
                        venda vendas[], idx_venda idx_vendas[])
{

    // Predefinir paises
    paises[0] = {1, "pais 1"};
    paises[1] = {2, "pais 2"};
    paises[2] = {3, "pais 3"};
    paises[3] = {4, "pais 4"};
    paises[4] = {5, "pais 5"};
    paises[5] = {6, "pais 6"};
    paises[6] = {7, "pais 7"};

    idx_paises[0] = {1, 0};
    idx_paises[1] = {2, 1};
    idx_paises[2] = {3, 2};
    idx_paises[3] = {4, 3};
    idx_paises[4] = {5, 4};
    idx_paises[5] = {6, 5};
    idx_paises[6] = {7, 6};

    // Predefinir cidades
    cidades[0] = {1, "Cidade 1", "C1", 1};
    cidades[1] = {2, "Cidade 2", "C2", 2};
    cidades[2] = {3, "Cidade 3", "C3", 3};
    cidades[3] = {4, "Cidade 4", "C4", 4};
    cidades[4] = {5, "Cidade 5", "C5", 5};
    cidades[5] = {6, "Cidade 6", "C6", 6};
    cidades[6] = {7, "Cidade 7", "C7", 7};

    idx_cidades[0] = {1, 0};
    idx_cidades[1] = {2, 1};
    idx_cidades[2] = {3, 2};
    idx_cidades[3] = {4, 3};
    idx_cidades[4] = {5, 4};
    idx_cidades[5] = {6, 5};
    idx_cidades[6] = {7, 6};

    // Predefinir guias
    guias[0] = {1, "Guia 1", "Endereco 1", "Telefone 1", 1, 0};
    guias[1] = {2, "Guia 2", "Endereco 2", "Telefone 2", 2, 0};
    guias[2] = {3, "Guia 3", "Endereco 3", "Telefone 3", 3, 0};
    guias[3] = {4, "Guia 4", "Endereco 4", "Telefone 4", 4, 0};
    guias[4] = {5, "Guia 5", "Endereco 5", "Telefone 5", 5, 0};
    guias[5] = {6, "Guia 6", "Endereco 6", "Telefone 6", 6, 0};
    guias[6] = {7, "Guia 7", "Endereco 7", "Telefone 7", 7, 0};

    idx_guias[0] = {1, 0};
    idx_guias[1] = {2, 1};
    idx_guias[2] = {3, 2};
    idx_guias[3] = {4, 3};
    idx_guias[4] = {5, 4};
    idx_guias[5] = {6, 5};
    idx_guias[6] = {7, 6};

    // Predefinir clientes
    clientes[0] = {1, "Cliente 1", "Endereco 1", 1, 0};
    clientes[1] = {2, "Cliente 2", "Endereco 2", 2, 0};
    clientes[2] = {3, "Cliente 3", "Endereco 3", 3, 0};
    clientes[3] = {4, "Cliente 4", "Endereco 4", 4, 0};
    clientes[4] = {5, "Cliente 5", "Endereco 5", 5, 0};
    clientes[5] = {6, "Cliente 6", "Endereco 6", 6, 0};
    clientes[6] = {7, "Cliente 7", "Endereco 7", 7, 0};

    idx_clientes[0] = {1, 0};
    idx_clientes[1] = {2, 1};
    idx_clientes[2] = {3, 2};
    idx_clientes[3] = {4, 3};
    idx_clientes[4] = {5, 4};
    idx_clientes[5] = {6, 5};
    idx_clientes[6] = {7, 6};

    // Predefinir pacotes
    pacotes[0] = {1, "Pacote 1", 1, 100, 3, 5};
    pacotes[1] = {2, "Pacote 2", 2, 200, 7, 10};
    pacotes[2] = {3, "Pacote 3", 3, 300, 10, 15};
    pacotes[3] = {4, "Pacote 4", 4, 400, 15, 20};
    pacotes[4] = {5, "Pacote 5", 5, 500, 20, 30};
    pacotes[5] = {6, "Pacote 6", 6, 600, 35, 40};
    pacotes[6] = {7, "Pacote 7", 7, 700, 40, 50};

    idx_pacotes[0] = {1, 1, 0};
    idx_pacotes[1] = {2, 2, 1};
    idx_pacotes[2] = {3, 3, 2};
    idx_pacotes[3] = {4, 4, 3};
    idx_pacotes[4] = {5, 5, 4};
    idx_pacotes[5] = {6, 6, 5};
    idx_pacotes[6] = {7, 7, 6};

    // Predefinir vendas
    vendas[0] = {1, 1, 1, 3, 300};
    vendas[1] = {2, 2, 2, 7, 1400};
    vendas[2] = {3, 3, 3, 10, 3000};
    vendas[3] = {4, 4, 4, 15, 6000};
    vendas[4] = {5, 5, 5, 20, 10000};
    vendas[5] = {6, 6, 6, 35, 21000};
    vendas[6] = {7, 7, 7, 40, 28000};

    idx_vendas[0] = {1, 1, 0};
    idx_vendas[1] = {2, 2, 1};
    idx_vendas[2] = {3, 3, 2};
    idx_vendas[3] = {4, 4, 3};
    idx_vendas[4] = {5, 5, 4};
    idx_vendas[5] = {6, 6, 5};
    idx_vendas[6] = {7, 7, 6};
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    pais paises[10];
    idx_pais idx_paises[10];
    cidade cidades[10];
    idx_cidade idx_cidades[10];
    guia guias[10];
    idx_guia idx_guias[10];
    cliente clientes[10];
    idx_cliente idx_clientes[10];
    pacote pacotes[10];
    idx_pacote idx_pacotes[10];
    venda vendas[10];
    idx_venda idx_vendas[10];
    int opcao, cont_pais = 7, cont_cidade = 7, cont_guia = 7, cont_cliente = 7, cont_pacote = 7, cont_venda = 7;

    predefinir_valores(paises, idx_paises,
                       cidades, idx_cidades,
                       guias, idx_guias,
                       clientes, idx_clientes,
                       pacotes, idx_pacotes,
                       vendas, idx_vendas);

    do
    {
        cout << "\n  1) - Adicionar Pais:\n";
        cout << "  2) - Adicionar Cidade:\n";
        cout << "  3) - Adicionar Guia:\n";
        cout << "  4) - Adicionar Cliente:\n";
        cout << "  5) - Adicionar Pacote:\n";
        cout << "  6) - Adicionar Venda:\n";
        cout << "  7) - Consultar Pacote:\n";
        cout << "  8) - Consultar Pacotes Totalmente Vendidos:\n";
        cout << "  9) - Imprimir todos os registros de Vendas:\n";
        cout << " 10) - Excluir cliente sem registros de Vendas:\n";
        cout << " 11) - Excluir guia sem registros de Pacotes:\n";
        cout << "  0) - Sair\n";
        cout << "\n Escolha uma Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            ler_pais(paises, idx_paises, cont_pais);
            break;
        case 2:
            ler_cidade(cidades, idx_cidades, cont_cidade,
                       paises, idx_paises, cont_pais);
            break;
        case 3:
            ler_guia(guias, idx_guias, cont_guia,
                     cidades, idx_cidades, cont_cidade,
                     paises, idx_paises, cont_pais);
            break;
        case 4:
            ler_cliente(clientes, idx_clientes, cont_cliente,
                        guias, idx_guias, cont_guia,
                        cidades, idx_cidades, cont_cidade,
                        paises, idx_paises, cont_pais);
            break;
        case 5:
            ler_pacote(pacotes, idx_pacotes, cont_pacote,
                       guias, idx_guias, cont_guia,
                       cidades, idx_cidades, cont_cidade,
                       paises, idx_paises, cont_pais);
            break;
        case 6:
            ler_venda(vendas, idx_vendas, cont_venda,
                      clientes, idx_clientes, cont_cliente,
                      pacotes, idx_pacotes, cont_pacote,
                      guias, idx_guias, cont_guia,
                      cidades, idx_cidades, cont_cidade,
                      paises, idx_paises, cont_pais);
            break;
        case 7:
            busca_binaria_pacote(pacotes, idx_pacotes, cont_pacote);
            break;
        case 8:
            exibir_pacotes_completamente_vendidos(pacotes, idx_pacotes, cont_pacote, guias, cont_guia);
            break;
        case 9:
            exibir_vendas(vendas, clientes, pacotes, idx_vendas, cont_venda, cont_cliente, cont_pacote);
            break;
        case 10:
            excluir_cliente(clientes, idx_clientes, vendas, idx_vendas, cont_cliente, cont_venda);
            break;
        case 11:
            excluir_guia(guias, idx_guias, pacotes, idx_pacotes, cont_guia, cont_pacote);
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);
}
