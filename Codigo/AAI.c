#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"

int main()
{
    produto *listaProduto = carregarProdutos("produto.txt");
    cliente *listaCliente = carregarClientes("cliente.txt");
    pedido *listaPedido = carregarPedidos("pedido.txt");

    menu(&listaCliente, &listaProduto, &listaPedido);

    salvarClientes("cliente.txt", listaCliente);
    salvarProdutos("produto.txt", listaProduto);
    salvarPedidos("pedido.txt", listaPedido);

    liberarClientes(listaCliente);
    liberarProdutos(listaProduto);
    liberarPedidos(listaPedido);
    return 0;
}

void menu(cliente **listaCliente, produto **listaProduto, pedido **listaPedido)
{
    char opcao;
    int alt;
    int posicao;
    int id;
    char nomeCPF[50];

    do
    {
        printf("\n--------Bem-Vindo ao ED ERP!--------");
        printf("\nEste e o Modulo de Vendas!");
        printf("\nQual acao voce deseja realizar hoje? ");
        printf("\nA) Gerenciamento de Clientes");
        printf("\nB) Gerenciamento de Produtos");
        printf("\nC) Gerenciamento de Vendas");
        printf("\nD) Buscar");
        printf("\nE) Relatorios");
        printf("\nF) Sair");

        do
        {
            printf("\nDigite a opcao desejada: ");
            scanf(" %c", &opcao);
            opcao = toupper(opcao);

            if (opcao < 'A' || opcao > 'F')
            {
                printf("\nOpcao invalida, por favor, digite uma letra de A a F para escolher uma acao do modulo!");
            }
        } while (opcao < 'A' || opcao > 'F');

        switch (opcao)
        {
        case 'A':
            printf("\nVoce esta no Gerenciamento de Clientes, o que deseja fazer?");
            printf("\n1) Cadastrar Cliente");
            printf("\n2) Alterar Cliente");
            printf("\n3) Excluir Cliente");
            printf("\n4) Listar Clientes");
            do
            {
                printf("\nDigite a opcao desejada: ");
                scanf(" %d", &alt);

                if (alt < 1 || alt > 4)
                {
                    printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                }
            } while (alt < 1 || alt > 4);

            if (alt == 1)
            {
                printf("\nVoce quer cadastrar um Cliente pelo inicio, meio ou fim da lista?");
                printf("\n1) Inicio");
                printf("\n2) Meio");
                printf("\n3) Fim");

                do
                {
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 3)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                    }
                } while (alt < 1 || alt > 3);

                if (alt == 1)
                {
                    *listaCliente = cadastrarClienteInicio(*listaCliente);
                }
                else if (alt == 2)
                {
                    printf("\nEm que posicao da lista deseja colocar o novo Cliente? ");
                    scanf("%d", &posicao);
                    *listaCliente = cadastrarClienteMeio(*listaCliente, posicao);
                }
                else
                {
                    *listaCliente = cadastrarClienteFim(*listaCliente);
                }
            }
            else if (alt == 2)
            {
                alterarCliente(*listaCliente);
            }
            else if (alt == 3)
            {
                printf("\nVoce quer excluir um Cliente pelo inicio, meio ou fim da lista?");
                printf("\n1) Inicio");
                printf("\n2) Meio");
                printf("\n3) Fim");

                do
                {
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 3)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                    }
                } while (alt < 1 || alt > 3);

                if (alt == 1)
                {
                    *listaCliente = excluirClienteInicio(*listaCliente);
                }
                else if (alt == 2)
                {
                    printf("\nQual Cliente da lista deseja excluir? (Digite seu ID): ");
                    scanf("%d", &id);
                    *listaCliente = excluirClienteMeio(*listaCliente, id);
                }
                else
                {
                    *listaCliente = excluirClienteFim(*listaCliente);
                }
            }
            else
            {
                listarClientes(*listaCliente);
            }
            break;

        case 'B':
            printf("\nVoce esta no Gerenciamento de Produto, o que deseja fazer?");
            printf("\n1) Cadastrar Produto");
            printf("\n2) Alterar Produto");
            printf("\n3) Excluir Produto");
            printf("\n4) Listar Produto");

            do
            {
                printf("\nDigite a opcao desejada: ");
                scanf("%d", &alt);
                if (alt > 4 || alt < 1)
                {
                    printf("\nOpcao invalida, por favor, digite um numero de 1 a 4 para escolher um modulo!");
                }
            } while (alt > 4 || alt < 1);

            if (alt == 1)
            {

                printf("\nVoce quer cadastrar um Produto pelo inicio, meio ou fim da lista?");
                printf("\n1) Inicio");
                printf("\n2) Meio");
                printf("\n3) Fim");

                do
                {
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 3)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                    }
                } while (alt < 1 || alt > 3);

                if (alt == 1)
                {
                    *listaProduto = cadastrarProdutoInicio(*listaProduto);
                }
                else if (alt == 2)
                {
                    printf("\nEm que posicao da lista deseja colocar o novo Produto? ");
                    scanf("%d", &posicao);
                    *listaProduto = cadastrarProdutoMeio(*listaProduto, posicao);
                }
                else
                {
                    *listaProduto = cadastrarProdutoFim(*listaProduto);
                }
            }
            else if (alt == 2)
            {
                alterarProduto(*listaProduto);
            }
            else if (alt == 3)
            {
                printf("\nVoce quer excluir um Produto pelo inicio, meio ou fim da lista?");
                printf("\n1) Inicio");
                printf("\n2) Meio");
                printf("\n3) Fim");

                do
                {
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 3)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                    }
                } while (alt < 1 || alt > 3);

                if (alt == 1)
                {
                    *listaProduto = excluirProdutoInicio(*listaProduto);
                }
                else if (alt == 2)
                {
                    printf("\nQual Produto da lista deseja excluir? (Digite seu ID): ");
                    scanf("%d", &id);
                    *listaProduto = excluirProdutoMeio(*listaProduto, id);
                }
                else
                {
                    *listaProduto = excluirProdutoFim(*listaProduto);
                }
            }
            else
            {
                listarProduto(*listaProduto);
            }
            break;

        case 'C':
            printf("\nVoce esta no Gerenciamento de Vendas, o que deseja fazer?");
            printf("\n1) Cadastrar Venda");
            printf("\n2) Alterar Venda");
            printf("\n3) Excluir Venda");
            printf("\n4) Listar Vendas");
            do
            {
                printf("\nDigite a opcao desejada: ");
                scanf("%d", &alt);
                if (alt > 4 || alt < 1)
                {
                    printf("\nOpcao invalida, por favor, digite um numero de 1 a 4 para escolher um modulo!");
                }
            } while (alt > 4 || alt < 1);

            if (alt == 1)
            {

                printf("\nVoce quer cadastrar uma Venda pelo inicio, meio ou fim da lista?");
                printf("\n1) Inicio");
                printf("\n2) Meio");
                printf("\n3) Fim");

                do
                {
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 3)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                    }
                } while (alt < 1 || alt > 3);

                if (alt == 1)
                {
                    *listaPedido = cadastrarPedidoInicio(*listaPedido, *listaCliente, *listaProduto);
                }
                else if (alt == 2)
                {
                    printf("\nEm que posicao da lista deseja colocar a nova Venda? ");
                    scanf("%d", &posicao);
                    *listaPedido = cadastrarPedidoMeio(*listaPedido, *listaCliente, *listaProduto, posicao);
                }
                else
                {
                    *listaPedido = cadastrarPedidoFim(*listaPedido, *listaCliente, *listaProduto);
                }
            }
            else if (alt == 2)
            {
                alterarPedido(*listaPedido);
            }
            else if (alt == 3)
            {
                printf("\nVoce quer excluir um Pedido pelo inicio, meio ou fim da lista?");
                printf("\n1) Inicio");
                printf("\n2) Meio");
                printf("\n3) Fim");

                do
                {
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 3)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                    }
                } while (alt < 1 || alt > 3);

                if (alt == 1)
                {
                    *listaPedido = excluirPedidoInicio(*listaPedido);
                }
                else if (alt == 2)
                {
                    printf("\nQual Pedido da lista deseja excluir? (Digite seu ID):");
                    scanf("%d", &id);
                    *listaPedido = excluirPedidoMeio(*listaPedido, id);
                }
                else
                {
                    *listaPedido = excluirPedidoFim(*listaPedido);
                }
            }
            else
            {
                listarPedido(*listaPedido);
            }
            break;

        case 'D':
            printf("\nVoce esta na Busca, o que deseja buscar?");
            printf("\n1) Cliente");
            printf("\n2) Produto");
            printf("\n3) Vendas");
            do{
                printf("\nDigite a opcao desejada: ");
                scanf(" %d", &alt);

                if (alt < 1 || alt > 3)
                {
                    printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
                }
            }while (alt < 1 || alt > 3);

            if (alt == 1){
                printf("\nVoce deseja buscar o Cliente pelo Nome/CPF ou ID? ");
                printf("\n1) Nome ou CPF");
                printf("\n2) ID");
                do{
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 2)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 2 para escolher uma acao do modulo!");
                    }
                }while (alt < 1 || alt > 2);

                if (alt==1)
                {
                    printf("\nDigite o Nome ou CPF do Cliente: ");
                    scanf(" %[^\n]", nomeCPF);
                    buscarClienteNomeCPF(*listaCliente, nomeCPF);
                }
                else 
                {
                    printf("\nDigite o ID do Cliente: ");
                    scanf(" %d", &id);
                    buscarClienteID(*listaCliente, id);
                }
            }
            else if (alt == 2)
            {
                printf("\nVoce deseja buscar o Produto pelo nome ou ID? ");
                printf("\n1) Nome");
                printf("\n2) ID");
                do{
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 2)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 2 para escolher uma acao do modulo!");
                    }
                }while (alt < 1 || alt > 2);

                if (alt==1)
                {
                    printf("\nDigite o Nome do Produto: ");
                    scanf(" %[^\n]", nomeCPF);
                    buscarProdutoNome(*listaProduto, nomeCPF);
                }
                else 
                {
                    printf("\nDigite o ID do Produto: ");
                    scanf(" %d", &id);
                    buscarProdutoID(*listaProduto, id);
                }
            }
            else 
            {
                printf("\nVoce deseja buscar o Pedido pelo nome do Cliente/nome do Produto ou ID? ");
                printf("\n1) Nome do Cliente ou do Produto");
                printf("\n2) ID");
                do{
                    printf("\nDigite a opcao desejada: ");
                    scanf(" %d", &alt);

                    if (alt < 1 || alt > 2)
                    {
                        printf("\nOpcao invalida, por favor, digite um numero de 1 a 2 para escolher uma acao do modulo!");
                    }
                }while (alt < 1 || alt > 2);

                if (alt==1)
                {
                    printf("\nDigite o Nome do Cliente ou do Produto: ");
                    scanf(" %[^\n]", nomeCPF);
                    buscarPedidoNome(*listaPedido, nomeCPF);
                }
                else 
                {
                    printf("\nDigite o ID do Pedido: ");
                    scanf(" %d", &id);
                    buscarPedidoID(*listaPedido, id);
                }
            }
            break;

        case 'E':
            relatorio(*listaCliente, *listaProduto, *listaPedido);
            break;

        case 'F':
            printf("\nObrigado por utilizar o ED ERP, volte sempre!");
            break;
        }
    } while (opcao != 'F');
}

cliente *cadastrarClienteInicio(cliente *inicio)
{
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = inicio;
    novo->anterior = NULL;

    if (inicio != NULL)
    {
        inicio->anterior = novo;
    }

    printf("\nVoce esta cadastrando um novo Cliente pelo inicio!");
    do {
        printf("\nDigite o nome do Cliente: ");
        scanf(" %[^\n]", novo->nome);
    } while (validarNome(novo->nome) == 0);

    do {
        printf("\nDigite o telefone do Cliente: ");
        scanf(" %s", novo->telefone);
    } while (validarTelefone(novo->telefone) == 0);

    do {
        printf("\nDigite o CPF do Cliente: ");
        scanf(" %s", novo->cpf);
    } while (validarCPF(novo->cpf) == 0);

    do {
        printf("\nDigite o email do Cliente: ");
        scanf(" %s", novo->email);
    } while (validarEmail(novo->email) == 0);

    printf("\nVamos preencher o endereço!");
    printf("\nDigite a rua: ");
    scanf(" %[^\n]", novo->end.rua);
    printf("\nDigite o numero: ");
    scanf(" %d", &novo->end.numero);
    printf("\nDigite o bairro: ");
    scanf(" %[^\n]", novo->end.bairro);
    do {
        printf("\nDigite o CEP: ");
        scanf(" %s", novo->end.cep);
    } while (validarCEP(novo->end.cep) == 0);

    printf("\nCliente cadastrado com sucesso!");

    cliente *atual = novo;
    int id = 1;
    while (atual != NULL) {
        atual->idCliente = id++;
        atual = atual->proximo;
    }
    return novo;
}

cliente *cadastrarClienteFim(cliente *inicio)
{
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = NULL;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Cliente no fim da lista!");
    do {
        printf("\nDigite o nome do Cliente: ");
        scanf(" %[^\n]", novo->nome);
    } while (validarNome(novo->nome) == 0);

    do {
        printf("\nDigite o telefone do Cliente: ");
        scanf(" %s", novo->telefone);
    } while (validarTelefone(novo->telefone) == 0);

    do {
        printf("\nDigite o CPF do Cliente: ");
        scanf(" %s", novo->cpf);
    } while (validarCPF(novo->cpf) == 0);

    do {
        printf("\nDigite o email do Cliente: ");
        scanf(" %s", novo->email);
    } while (validarEmail(novo->email) == 0);

    printf("\nVamos preencher o endereço!");
    printf("\nDigite a rua: ");
    scanf(" %[^\n]", novo->end.rua);
    printf("\nDigite o numero: ");
    scanf(" %d", &novo->end.numero);
    printf("\nDigite o bairro: ");
    scanf(" %[^\n]", novo->end.bairro);
    do {
        printf("\nDigite o CEP: ");
        scanf(" %s", novo->end.cep);
    } while (validarCEP(novo->end.cep) == 0);


    if (inicio == NULL)
    {
        return novo;
    }

    cliente *atual = inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idCliente = id++;
        atual = atual->proximo;
    }
    printf("\nCliente cadastrado com sucesso!");
    return inicio;
}

cliente *cadastrarClienteMeio(cliente *inicio, int posicao)
{
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = NULL;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Cliente no meio da lista!");
    do {
        printf("\nDigite o nome do Cliente: ");
        scanf(" %[^\n]", novo->nome);
    } while (validarNome(novo->nome) == 0);

    do {
        printf("\nDigite o telefone do Cliente: ");
        scanf(" %s", novo->telefone);
    } while (validarTelefone(novo->telefone) == 0);

    do {
        printf("\nDigite o CPF do Cliente: ");
        scanf(" %s", novo->cpf);
    } while (validarCPF(novo->cpf) == 0);

    do {
        printf("\nDigite o email do Cliente: ");
        scanf(" %s", novo->email);
    } while (validarEmail(novo->email) == 0);

    printf("\nVamos preencher o endereço!");
    printf("\nDigite a rua: ");
    scanf(" %[^\n]", novo->end.rua);
    printf("\nDigite o numero: ");
    scanf(" %d", &novo->end.numero);
    printf("\nDigite o bairro: ");
    scanf(" %[^\n]", novo->end.bairro);
    do {
        printf("\nDigite o CEP: ");
        scanf(" %s", novo->end.cep);
    } while (validarCEP(novo->end.cep) == 0);


    cliente *atual = inicio;
    int contador = 1;

    while (contador < posicao - 1 && atual->proximo != NULL)
    {
        atual = atual->proximo;
        contador++;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;

    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = novo;
    }
    atual->proximo = novo;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idCliente = id++;
        atual = atual->proximo;
    }
    printf("\nCliente cadastrado com sucesso!");
    return inicio;
}

void alterarCliente (cliente *listaCliente) {
    if (listaCliente == NULL) {
        printf("\nLista de cliente vazia");
        return;
    }

    int id;
    printf("\nDigite o ID do cliente que deseja alterar: ");
    scanf("%d", &id);

    cliente *atual = listaCliente;
    while (atual != NULL && atual->idCliente != id) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nCliente com ID %d nao encontrado.\n", id);
        return;
    }

    printf("\nCliente encontrado: \n");
    printf("Nome: %s\n", atual->nome);
    printf("Telefone: %s\n", atual->telefone);
    printf("CPF: %s\n", atual->cpf);
    printf("Email: %s\n", atual->email);
    printf("Rua: %s\n", atual->end.rua);
    printf("Numero: %d\n", atual->end.numero);
    printf("Bairro: %s\n", atual->end.bairro);
    printf("CEP: %s\n", atual->end.cep);

    printf("\nInforme os novos dados:\n");
    printf("Digite o novo nome: ");
    scanf(" %[^\n]", atual->nome);
    printf("Digite o novo telefone: ");
    scanf("%s", atual->telefone);
    printf("Digite o novo CPF: ");
    scanf("%s", atual->cpf);
    printf("Digite o novo email: ");
    scanf("%s", atual->email);
    printf("Digite a nova rua: ");
    scanf(" %[^\n]", atual->end.rua);
    printf("Digite o novo numero: ");
    scanf("%d", &atual->end.numero);
    printf("Digite o novo bairro: ");
    scanf(" %[^\n]", atual->end.bairro);
    printf("Digite o novo CEP: ");
    scanf(" %[^\n]", atual->end.cep);

    printf("\nCliente alterado com sucesso!\n");

}

cliente *excluirClienteInicio(cliente *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    cliente *atual = inicio;
    inicio = inicio->proximo;
    atual->proximo = NULL;
    atual->anterior = NULL;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idCliente = id++;
        atual = atual->proximo;
    }

    printf("\nCliente excluido com sucesso!");
    return inicio;
}

cliente *excluirClienteFim(cliente *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    cliente *atual = inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->anterior->proximo = NULL;
    atual->anterior = NULL;
    atual->proximo = NULL;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idCliente = id++;
        atual = atual->proximo;
    }

    printf("\nCliente excluido com sucesso!");
    return inicio;
}

cliente *excluirClienteMeio(cliente *inicio, int id)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    cliente *atual = inicio;
    int contador = 1;

    while (contador < id && atual->proximo != NULL)
    {
        atual = atual->proximo;
        contador++;
    }

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    if (atual->proximo == NULL)
    {
        atual->anterior->proximo = NULL;
    }

    atual->proximo = NULL;
    atual->anterior = NULL;

    atual = inicio;
    id = 1;
    while (atual != NULL) {
        atual->idCliente = id++;
        atual = atual->proximo;
    }
    printf("\nCliente excluido com sucesso!");
    return inicio;
}

void buscarClienteNomeCPF(cliente *listaClientes, char *nomeCPF)
{
    if (listaClientes == NULL)
    {
        printf("\nLista Vazia");
        return;
    }

    cliente *atual = listaClientes;
    int contador = 0;
    while (atual != NULL)
    {
        if(stricmp(atual->nome, nomeCPF) == 0 || stricmp(atual->cpf, nomeCPF) == 0)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idCliente);
            printf("\nNome: %s", atual->nome);
            printf("\nTelefone: %s", atual->telefone);
            printf("\nCPF: %s", atual->cpf);
            printf("\nEmail: %s", atual->email);
            printf("\nEndereco");
            printf("\nRua: %s", atual->end.rua);
            printf("\nNumero: %d", atual->end.numero);
            printf("\nBairro: %s", atual->end.bairro);
            printf("\nCEP: %s", atual->end.cep);

            atual = atual->proximo;
            contador++;
        }
        else
        {
            atual = atual->proximo;
        }
    }
    if (contador == 0){
        printf("\nNão foi encontrado nenhum Cliente com estes dados");
    }

    printf("\nBusca feita com sucesso");
}

void buscarClienteID(cliente *listaClientes, int id)
{
    if (listaClientes == NULL)
    {
        printf("\nLista Vazia");
        return;
    }

    cliente *atual = listaClientes;
    int contador = 0;
    while (atual != NULL)
    {
        if(atual->idCliente == id)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idCliente);
            printf("\nNome: %s", atual->nome);
            printf("\nTelefone: %s", atual->telefone);
            printf("\nCPF: %s", atual->cpf);
            printf("\nEmail: %s", atual->email);
            printf("\nEndereco");
            printf("\nRua: %s", atual->end.rua);
            printf("\nNumero: %d", atual->end.numero);
            printf("\nBairro: %s", atual->end.bairro);
            printf("\nCEP: %s", atual->end.cep);

            atual = atual->proximo;
            contador++;
        }
        else
        {
            atual = atual->proximo;
        }
    }

    if (contador == 0){
        printf("\nNão foi encontrado nenhum Cliente com estes dados");
    }
    printf("\nBusca feita com sucesso");
}

void listarClientes(cliente *listaClientes)

{
    if (listaClientes == NULL)
    {
        printf("\nLista Vazia");
        return;
    }
    cliente *atual = listaClientes;
    int alt;

    printf("\nVoce deseja listar os clientes por ID em ordem Crescente, Decrescente ou por Nome em ordem alfabética de A a Z, de Z a A?");
    printf("\n1) ID Crescente");
    printf("\n2) ID Decrescente");
    printf("\n3) Nome (A-Z)");
    printf("\n4) Nome (Z-A)");
    do{
        printf("\nDigite a opcao desejada: ");
        scanf(" %d", &alt);

        if (alt < 1 || alt > 4)
        {
            printf("\nOpcao invalida, por favor, digite um numero de 1 a 4 para escolher uma acao do modulo!");
        }
    }while (alt < 1 || alt > 4);

    if(alt == 1){
        while (atual != NULL)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idCliente);
            printf("\nNome: %s", atual->nome);
            printf("\nTelefone: %s", atual->telefone);
            printf("\nCPF: %s", atual->cpf);
            printf("\nEmail: %s", atual->email);
            printf("\nEndereco");
            printf("\nRua: %s", atual->end.rua);
            printf("\nNumero: %d", atual->end.numero);
            printf("\nBairro: %s", atual->end.bairro);
            printf("\nCEP: %s", atual->end.cep);

            atual = atual->proximo;
        }
        printf("\nListagem feita com sucesso!");
    } else if(alt == 2){
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        while (atual != NULL)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idCliente);
            printf("\nNome: %s", atual->nome);
            printf("\nTelefone: %s", atual->telefone);
            printf("\nCPF: %s", atual->cpf);
            printf("\nEmail: %s", atual->email);
            printf("\nEndereco");
            printf("\nRua: %s", atual->end.rua);
            printf("\nNumero: %d", atual->end.numero);
            printf("\nBairro: %s", atual->end.bairro);
            printf("\nCEP: %s", atual->end.cep);

            atual = atual->anterior;
        }
        printf("\nListagem feita com sucesso!");
    } else if (alt == 3){
            for (char letra = 'A'; letra <= 'Z'; letra++) {
            atual = listaClientes;
            while (atual != NULL) {
                
                if (toupper(atual->nome[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idCliente);
                    printf("\nNome: %s", atual->nome);
                    printf("\nTelefone: %s", atual->telefone);
                    printf("\nCPF: %s", atual->cpf);
                    printf("\nEmail: %s", atual->email);
                    printf("\nEndereco");
                    printf("\nRua: %s", atual->end.rua);
                    printf("\nNumero: %d", atual->end.numero);
                    printf("\nBairro: %s", atual->end.bairro);
                    printf("\nCEP: %s", atual->end.cep);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    } else {
        for (char letra = 'Z'; letra >= 'A'; letra--) {
            atual = listaClientes;
            while (atual != NULL) {
                
                if (toupper(atual->nome[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idCliente);
                    printf("\nNome: %s", atual->nome);
                    printf("\nTelefone: %s", atual->telefone);
                    printf("\nCPF: %s", atual->cpf);
                    printf("\nEmail: %s", atual->email);
                    printf("\nEndereco");
                    printf("\nRua: %s", atual->end.rua);
                    printf("\nNumero: %d", atual->end.numero);
                    printf("\nBairro: %s", atual->end.bairro);
                    printf("\nCEP: %s", atual->end.cep);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    }
}


produto *cadastrarProdutoInicio(produto *inicio)
{
    produto *novo = (produto *)malloc(sizeof(produto));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }
    novo->proximo = inicio;
    novo->anterior = NULL;
    printf("\nVoce esta cadastrando um novo Produto pelo inicio da lista!");
    printf("\nDigite o nome do Produto: ");
    scanf(" %[^\n]", novo->nome);
    do {
        printf("Digite a midia do Produto: ");
        scanf(" %s", novo->midia);
    } while (validarMidia(novo->midia) == 0);
    printf("Digite o genero do Produto: ");
    scanf(" %s", novo->genero);
    do {
        printf("Digite o preco do Produto: ");
        scanf(" %f", &novo->preco);
    } while (validarPreco(&novo->preco) == 0);
    printf("Digite a quantidade do Produto no estoque: ");
    scanf(" %d", &novo->qtdeEstoque);
    printf("\nProduto cadastrado com sucesso!");
 
    produto *atual = novo;
    int id = 1;
    while (atual != NULL) {
        atual->idProduto = id++;
        atual = atual->proximo;
    }

    return novo;
}
 
produto *cadastrarProdutoFim(produto *inicio)
{
    produto *novo = (produto *)malloc(sizeof(produto));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = NULL;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Produto no fim da lista!");
    printf("\nDigite o nome do Produto: ");
    scanf(" %[^\n]", novo->nome);
    printf("Digite a midia do Produto: ");
    scanf(" %s", novo->midia);
    printf("Digite o genero do Produto: ");
    scanf(" %s", novo->genero);
    printf("Digite o preco do Produto: ");
    scanf(" %f", &novo->preco);
    printf("Digite a quantidade do Produto no estoque: ");
    scanf(" %d", &novo->qtdeEstoque);

    if (inicio == NULL)
    {
        return novo;
    }

    produto *atual = inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idProduto = id++;
        atual = atual->proximo;
    }
    printf("\nProduto cadastrado com sucesso!");
    return inicio;
}

produto *cadastrarProdutoMeio(produto *inicio, int posicao)
{
    produto *novo = (produto *)malloc(sizeof(produto));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = NULL;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Produto no meio da lista!");
    printf("\nDigite o nome do Produto: ");
    scanf(" %[^\n]", novo->nome);
    printf("Digite a midia do Produto: ");
    scanf(" %s", novo->midia);
    printf("Digite o genero do Produto: ");
    scanf(" %s", novo->genero);
    printf("Digite o preco do Produto: ");
    scanf(" %f", &novo->preco);
    printf("Digite a quantidade do Produto no estoque: ");
    scanf(" %d", &novo->qtdeEstoque);

    produto *atual = inicio;
    int contador = 1;

    while (contador < posicao - 1 && atual->proximo != NULL)
    {
        atual = atual->proximo;
        contador++;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;

    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = novo;
    }
    atual->proximo = novo;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idProduto = id++;
        atual = atual->proximo;
    }
    printf("\nProduto cadastrado com sucesso!");
    return inicio;
}

void alterarProduto (produto *listaProduto) {
    if (listaProduto == NULL) {
        printf("\nLista de produtos vazia");
        return;
    }

    int id;
    printf("\nDigite o ID do produto que deseja alterar: ");
    scanf("%d", &id);

    produto *atual = listaProduto;
    while (atual != NULL && atual->idProduto != id) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nProduto com ID %d nao encontrado.\n", id);
        return;
    }

    printf("\nProduto encontrado: \n");
    printf("Nome: %s\n", atual->nome);
    printf("Midia: %s\n", atual->midia);
    printf("Genero: %s\n", atual->genero);
    printf("Preco: %.2f\n", atual->preco);
    printf("Quantidade em estoque: %d\n", atual->qtdeEstoque);

    printf("\nInforme os novos dados:\n");
    printf("Digite o novo nome: ");
    scanf(" %[^\n]", atual->nome);
    printf("Digite a nova midia: ");
    scanf("%s", atual->midia);
    printf("Digite o novo genero: ");
    scanf("%s", atual->genero);
    printf("Digite o novo preco: ");
    scanf("%f", &atual->preco);
    printf("Digite a nova quantidade em estoque: ");
    scanf("%d", &atual->qtdeEstoque);

    printf("\nProduto alterado com sucesso!\n");

}

produto *excluirProdutoInicio(produto *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    produto *atual = inicio;
    inicio = inicio->proximo;
    atual->proximo = NULL;
    atual->anterior = NULL;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idProduto = id++;
        atual = atual->proximo;
    }

    printf("\nProduto excluido com sucesso!");
    return inicio;
}

produto *excluirProdutoFim(produto *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    produto *atual = inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->anterior->proximo = NULL;
    atual->anterior = NULL;
    atual->proximo = NULL;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idProduto = id++;
        atual = atual->proximo;
    }
    printf("\nCliente excluido com sucesso!");
    return inicio;
}

produto *excluirProdutoMeio(produto *inicio, int id)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    produto *atual = inicio;
    int contador = 1;

    while (contador < id && atual->proximo != NULL)
    {
        atual = atual->proximo;
        contador++;
    }

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    if (atual->proximo == NULL)
    {
        atual->anterior->proximo = NULL;
    }

    atual->proximo = NULL;
    atual->anterior = NULL;

    atual = inicio;
    id = 1;
    while (atual != NULL) {
        atual->idProduto = id++;
        atual = atual->proximo;
    }
    printf("\nCliente excluido com sucesso!");
    return inicio;
}

void buscarProdutoNome(produto *listaProduto, char *nome)
{
    if (listaProduto == NULL)
    {
        printf("\nLista Vazia");
        return;
    }

    produto *atual = listaProduto;
    int contador = 0;
    while (atual != NULL)
    {
        if(stricmp(atual->nome, nome) == 0)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idProduto);
            printf("\nNome: %s", atual->nome);
            printf("\nMidia: %s", atual->midia);
            printf("\nGenero: %s", atual->genero);
            printf("\nPreco: %.2f", atual->preco);
            printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);

            contador ++;
            atual = atual->proximo;
        }
        else
        {
            atual = atual->proximo;
        }
    }

    if(contador == 0){
        printf("\nNão foi encontrado nenhum Produto com estes dados");
    }

    printf("\nBusca feita com sucesso");
}

void buscarProdutoID(produto *listaProduto, int id)
{
    if (listaProduto == NULL)
    {
        printf("\nLista Vazia");
        return;
    }

    produto *atual = listaProduto;
    int contador = 0;
    while (atual != NULL)
    {
        if(atual->idProduto == id)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idProduto);
            printf("\nNome: %s", atual->nome);
            printf("\nMidia: %s", atual->midia);
            printf("\nGenero: %s", atual->genero);
            printf("\nPreco: %.2f", atual->preco);
            printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);

            contador ++;
            atual = atual->proximo;
        }
        else
        {
            atual = atual->proximo;
        }
    }

    if(contador == 0){
        printf("\nNão foi encontrado nenhum Produto com estes dados");
    }

    printf("\nBusca feita com sucesso");
}

void listarProduto(produto *listaProduto)
{
    if (listaProduto == NULL)
    {
        printf("\nLista vazia");
        return;
    }

    produto *atual = listaProduto;
    int alt;

    printf("\nVoce deseja listar os produtos por ID em ordem Crescente, Decrescente ou por Nome em ordem alfabética de A a Z, de Z a A?");
    printf("\n1) ID Crescente");
    printf("\n2) ID Decrescente");
    printf("\n3) Nome (A-Z)");
    printf("\n4) Nome (Z-A)");
    do{
        printf("\nDigite a opcao desejada: ");
        scanf(" %d", &alt);

        if (alt < 1 || alt > 4)
        {
            printf("\nOpcao invalida, por favor, digite um numero de 1 a 3 para escolher uma acao do modulo!");
        }
        }while (alt < 1 || alt > 4);

    if(alt == 1){
        while (atual != NULL)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idProduto);
            printf("\nNome: %s", atual->nome);
            printf("\nMidia: %s", atual->midia);
            printf("\nGenero: %s", atual->genero);
            printf("\nPreco: %.2f", atual->preco);
            printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);
            atual = atual->proximo;
        }
        printf("\nListagem feita com sucesso!");
    } else if(alt == 2){
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        while (atual != NULL)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idProduto);
            printf("\nNome: %s", atual->nome);
            printf("\nMidia: %s", atual->midia);
            printf("\nGenero: %s", atual->genero);
            printf("\nPreco: %.2f", atual->preco);
            printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);

            atual = atual->anterior;
        }
        printf("\nListagem feita com sucesso!");
    } else if(alt == 3){
        for (char letra = 'A'; letra <= 'Z'; letra++) {
            atual = listaProduto;
            while (atual != NULL) {
                
                if (toupper(atual->nome[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idProduto);
                    printf("\nNome: %s", atual->nome);
                    printf("\nMidia: %s", atual->midia);
                    printf("\nGenero: %s", atual->genero);
                    printf("\nPreco: %.2f", atual->preco);
                    printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    }else{
        for (char letra = 'Z'; letra >= 'A'; letra--) {
            atual = listaProduto;
            while (atual != NULL) {
                
                if (toupper(atual->nome[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idProduto);
                    printf("\nNome: %s", atual->nome);
                    printf("\nMidia: %s", atual->midia);
                    printf("\nGenero: %s", atual->genero);
                    printf("\nPreco: %.2f", atual->preco);
                    printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    }
}


pedido *cadastrarPedidoInicio(pedido *inicio, cliente *listaClientes, produto *listaProdutos)
{
    pedido *novo = (pedido *)malloc(sizeof(pedido));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = inicio;
    novo->anterior = NULL;

    cliente *atualC = listaClientes;
    produto *atualP = listaProdutos;

    printf("\nVoce esta cadastrando um novo Pedido pelo inicio da lista!");
    do{
        printf("\nDigite o nome do Cliente: ");
        scanf(" %[^\n]", novo->nomeCliente);

        atualC = listaClientes;

        while(atualC != NULL && stricmp(atualC->nome, novo->nomeCliente) != 0){
            atualC = atualC->proximo;
        }
        if(atualC == NULL){
            printf("\nCliente nao encontrado, por favor digite um cliente cadastrado!");
        }
    }while(atualC == NULL);

    do{
        printf("\nDigite o nome do Produto: ");
        scanf(" %[^\n]", novo->nomeProduto);

        atualP = listaProdutos;

        while(atualP != NULL && stricmp(atualP->nome,novo->nomeProduto) != 0){
            atualP = atualP->proximo;
        }
        if(atualP == NULL){
            printf("\nProduto nao encontrado, por favor digite um cliente cadastrado!");
        }
    }while(atualP == NULL);

    printf("\nDigite a quantidade do Produto: ");
    scanf(" %d", &novo->qtde);
    atualP->qtdeEstoque -= novo->qtde;
    printf("\nPreco unitário do Produto: %.2f", atualP->preco);
    novo->vlrUni = atualP->preco;
    printf("\nDigite o desconto (0.0 se não houver): ");
    scanf(" %f", &novo->desconto);
    printf("Valor Total: %f", novo->vlrTotal = novo->qtde * novo->vlrUni * (1 - (novo->desconto / 100)));
    printf("\nPedido cadastrado com sucesso!");

    pedido *atual = novo;
    int id = 1;
    while (atual != NULL) {
        atual->idPedido = id++;
        atual = atual->proximo;
    }
    return novo;
}

pedido *cadastrarPedidoFim(pedido *inicio, cliente *listaClientes, produto *listaProdutos)
{
    pedido *novo = (pedido *)malloc(sizeof(pedido));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = NULL;
    novo->anterior = NULL;

    cliente *atualC = listaClientes;
    produto *atualP = listaProdutos;

    printf("\nVoce esta cadastrando um novo Pedido no fim da lista!");
    do{
        printf("\nDigite o nome do Cliente: ");
        scanf(" %[^\n]", novo->nomeCliente);

        atualC = listaClientes;

        while(atualC != NULL && stricmp(atualC->nome, novo->nomeCliente) != 0){
            atualC = atualC->proximo;
        }
        if(atualC == NULL){
            printf("\nCliente nao encontrado, por favor digite um cliente cadastrado!");
        }
    }while(atualC == NULL);

    do{
        printf("\nDigite o nome do Produto: ");
        scanf(" %[^\n]", novo->nomeProduto);

        atualP = listaProdutos;

        while(atualP != NULL && stricmp(atualP->nome,novo->nomeProduto) != 0){
            atualP = atualP->proximo;
        }
        if(atualP == NULL){
            printf("\nProduto nao encontrado, por favor digite um cliente cadastrado!");
        }
    }while(atualP == NULL);

    printf("\nDigite a quantidade do Produto: ");
    scanf(" %d", &novo->qtde);
    atualP->qtdeEstoque -= novo->qtde;
    printf("\nPreco unitário do Produto: %.2f", atualP->preco);
    novo->vlrUni = atualP->preco;
    printf("\nDigite o desconto (0.0 se não houver): ");
    scanf(" %f", &novo->desconto);
    printf("Valor Total: %f", novo->vlrTotal = novo->qtde * novo->vlrUni * (1 - (novo->desconto / 100)));
    printf("\nPedido cadastrado com sucesso!");

    if (inicio == NULL)
    {
        return novo;
    }

    pedido *atual = inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idPedido = id++;
        atual = atual->proximo;
    }
    printf("\nPedidoo cadastrado com sucesso!");
    return inicio;
}

pedido *cadastrarPedidoMeio(pedido *inicio, cliente *listaClientes, produto *listaProdutos, int posicao)
{
    pedido *novo = (pedido *)malloc(sizeof(pedido));
    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria!");
        return inicio;
    }

    novo->proximo = NULL;
    novo->anterior = NULL;

    cliente *atualC = listaClientes;
    produto *atualP = listaProdutos;

    do{
        printf("\nDigite o nome do Cliente: ");
        scanf(" %[^\n]", novo->nomeCliente);

        atualC = listaClientes;

        while(atualC != NULL && stricmp(atualC->nome, novo->nomeCliente) != 0){
            atualC = atualC->proximo;
        }
        if(atualC == NULL){
            printf("\nCliente nao encontrado, por favor digite um cliente cadastrado!");
        }
    }while(atualC == NULL);

    do{
        printf("\nDigite o nome do Produto: ");
        scanf(" %[^\n]", novo->nomeProduto);

        atualP = listaProdutos;

        while(atualP != NULL && stricmp(atualP->nome,novo->nomeProduto) != 0){
            atualP = atualP->proximo;
        }
        if(atualP == NULL){
            printf("\nProduto nao encontrado, por favor digite um cliente cadastrado!");
        }
    }while(atualP == NULL);

    printf("\nDigite a quantidade do Produto: ");
    scanf(" %d", &novo->qtde);
    atualP->qtdeEstoque -= novo->qtde;
    printf("\nPreco unitário do Produto: %.2f", atualP->preco);
    novo->vlrUni = atualP->preco;
    printf("\nDigite o desconto (0.0 se não houver): ");
    scanf(" %f", &novo->desconto);
    printf("Valor Total: %f", novo->vlrTotal = novo->qtde * novo->vlrUni * (1 - (novo->desconto / 100)));

    pedido *atual = inicio;
    int contador = 1;

    while (contador < posicao - 1 && atual->proximo != NULL)
    {
        atual = atual->proximo;
        contador++;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;

    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = novo;
    }
    atual->proximo = novo;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idPedido = id++;
        atual = atual->proximo;
    }
    printf("\nPedido cadastrado com sucesso!");
    return inicio;
}

void alterarPedido (pedido *listaPedido) {
    if (listaPedido == NULL) {
        printf("\nLista de pedidos vazia");
        return;
    }

    int id;
    printf("\nDigite o ID do pedido que deseja alterar: ");
    scanf("%d", &id);

    pedido *atual = listaPedido;
    while (atual != NULL && atual->idPedido != id) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nPedido com ID %d nao encontrado.\n", id);
        return;
    }

    printf("\nPedido encontrado: \n");
    printf("Nome do Cliente: %s\n", atual->nomeCliente);
    printf("Nome do Produto: %s\n", atual->nomeProduto);
    printf("Quantidade do produto: %d\n", atual->qtde);
    printf("Valor unitario: %.2f\n", atual->vlrUni);
    printf("Desconto: %.2f\n", atual->desconto);
    printf("Valor Total: %.2f", atual->vlrTotal);


    printf("\nInforme os novos dados:\n");
    printf("Digite o novo nome do Cliente: ");
    scanf(" %[^\n]", atual->nomeCliente);
    printf("Digite o novo nome do Produto: ");
    scanf(" %[^\n]", atual->nomeProduto);
    printf("Digite a novo quantidade do produto: ");
    scanf("%d", &atual->qtde);
    printf("Digite o novo valor unitario do produto: ");
    scanf("%f", &atual->vlrUni);
    printf("Digite o novo desconto: ");
    scanf("%f", &atual->desconto);
    printf("Valor Total: %f", atual->desconto);
    atual->vlrTotal = atual->qtde * atual->vlrUni * (1 - (atual->desconto / 100));
    printf("Valor Total: %.2f\n", atual->vlrTotal);

    printf("\nPedido alterado com sucesso!\n");

}

pedido *excluirPedidoInicio(pedido *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    pedido *atual = inicio;
    inicio = inicio->proximo;
    atual->proximo = NULL;
    atual->anterior = NULL;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idPedido = id++;
        atual = atual->proximo;
    }
    printf("\nPedido excluido com sucesso!");
    return inicio;
}

pedido *excluirPedidoFim(pedido *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    pedido *atual = inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->anterior->proximo = NULL;
    atual->anterior = NULL;
    atual->proximo = NULL;

    atual = inicio;
    int id = 1;
    while (atual != NULL) {
        atual->idPedido = id++;
        atual = atual->proximo;
    }
    printf("\nCliente excluido com sucesso!");
    return inicio;
}

pedido *excluirPedidoMeio(pedido *inicio, int id)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia");
        return inicio;
    }

    pedido *atual = inicio;
    int contador = 1;

    while (contador < id && atual->proximo != NULL)
    {
        atual = atual->proximo;
        contador++;
    }

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    if (atual->proximo == NULL)
    {
        atual->anterior->proximo = NULL;
    }

    atual->proximo = NULL;
    atual->anterior = NULL;

    atual = inicio;
    id = 1;
    while (atual != NULL) {
        atual->idPedido = id++;
        atual = atual->proximo;
    }
    printf("\nCliente excluido com sucesso!");
    return inicio;
}

void buscarPedidoNome(pedido *listaPedido, char *nome)
{
    if (listaPedido == NULL)
    {
        printf("\nLista Vazia");
        return;
    }

    pedido *atual = listaPedido;
    while (atual != NULL)
    {
        if(stricmp(atual->nomeCliente, nome) == 0 || stricmp(atual->nomeProduto, nome) == 0)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idPedido);
            printf("\nNome Cliente: %s", atual->nomeCliente);
            printf("\nNome Produto: %s", atual->nomeProduto);
            printf("\nQuantidade: %d", atual->qtde);
            printf("\nValor Unitario: %.2f", atual->vlrUni);
            printf("\nDesconto: %.2f", atual->desconto);
            printf("\nPreco: %.2f", atual->vlrTotal);

            atual = atual->proximo;
        }
        else
        {
            atual = atual->proximo;
        }
    }

    printf("\nBusca feita com sucesso");
}

void buscarPedidoID(pedido *listaPedido, int id)
{
    if (listaPedido == NULL)
    {
        printf("\nLista Vazia");
        return;
    }

    pedido *atual = listaPedido;
    while (atual != NULL)
    {
        if(atual->idPedido == id)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idPedido);
            printf("\nNome Cliente: %s", atual->nomeCliente);
            printf("\nNome Produto: %s", atual->nomeProduto);
            printf("\nQuantidade: %d", atual->qtde);
            printf("\nValor Unitario: %.2f", atual->vlrUni);
            printf("\nDesconto: %.2f", atual->desconto);
            printf("\nPreco: %.2f", atual->vlrTotal);

            atual = atual->proximo;
        }
        else
        {
            atual = atual->proximo;
        }
    }
}

void listarPedido(pedido *listaPedido)
{
    if (listaPedido == NULL)
    {
        printf("\nLista vazia");
        return;
    }

    pedido *atual = listaPedido;
    int alt;

    printf("\nVoce deseja listar os Pedidos por ID em ordem Crescente, Decrescente, por Nome em Ordem Alfabetica de Clientes,\n"
    " de A a Z, de Z a A ou Produtos, de A a Z, de Z a A?");
    printf("\n1) ID Crescente");
    printf("\n2) ID Decrescente");
    printf("\n3) Cliente (A-Z)");
    printf("\n4) Cliente (Z-A)");
    printf("\n5) Produto (A-Z)");
    printf("\n6) Produto (Z-A)");
    do{
        printf("\nDigite a opcao desejada: ");
        scanf(" %d", &alt);

        if (alt < 1 || alt > 6)
        {
            printf("\nOpcao invalida, por favor, digite um numero de 1 a 6 para escolher uma acao do modulo!");
        }
        }while (alt < 1 || alt > 6);

    if(alt == 1){
        while (atual != NULL)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idPedido);
            printf("\nNome Cliente: %s", atual->nomeCliente);
            printf("\nNome Produto: %s", atual->nomeProduto);
            printf("\nQuantidade: %d", atual->qtde);
            printf("\nValor Unitario: %.2f", atual->vlrUni);
            printf("\nDesconto: %.2f", atual->desconto);
            printf("\nPreco: %.2f", atual->vlrTotal);
            atual = atual->proximo;
        }
        printf("\nListagem feita com sucesso!");
    } else if(alt == 2){
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        while (atual != NULL)
        {
            printf("\n--------------------------");
            printf("\nId: %d", atual->idPedido);
            printf("\nNome Cliente: %s", atual->nomeCliente);
            printf("\nNome Produto: %s", atual->nomeProduto);
            printf("\nQuantidade: %d", atual->qtde);
            printf("\nValor Unitario: %.2f", atual->vlrUni);
            printf("\nDesconto: %.2f", atual->desconto);
            printf("\nPreco: %.2f", atual->vlrTotal);

            atual = atual->anterior;
        }
        printf("\nListagem feita com sucesso!");
    } else if(alt == 3){
        for (char letra = 'A'; letra <= 'Z'; letra++) {
            atual = listaPedido;
            while (atual != NULL) {

                if (toupper(atual->nomeCliente[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idPedido);
                    printf("\nNome Cliente: %s", atual->nomeCliente);
                    printf("\nNome Produto: %s", atual->nomeProduto);
                    printf("\nQuantidade: %d", atual->qtde);
                    printf("\nValor Unitario: %.2f", atual->vlrUni);
                    printf("\nDesconto: %.2f", atual->desconto);
                    printf("\nPreco: %.2f", atual->vlrTotal);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    } else if(alt == 4){
        for (char letra = 'Z'; letra >= 'A'; letra--) {
            atual = listaPedido;
            while (atual != NULL) {

                if (toupper(atual->nomeCliente[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idPedido);
                    printf("\nNome Cliente: %s", atual->nomeCliente);
                    printf("\nNome Produto: %s", atual->nomeProduto);
                    printf("\nQuantidade: %d", atual->qtde);
                    printf("\nValor Unitario: %.2f", atual->vlrUni);
                    printf("\nDesconto: %.2f", atual->desconto);
                    printf("\nPreco: %.2f", atual->vlrTotal);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    }else if (alt == 5){
        for (char letra = 'A'; letra <= 'Z'; letra++) {
            atual = listaPedido;
            while (atual != NULL) {

                if (toupper(atual->nomeProduto[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idPedido);
                    printf("\nNome Cliente: %s", atual->nomeCliente);
                    printf("\nNome Produto: %s", atual->nomeProduto);
                    printf("\nQuantidade: %d", atual->qtde);
                    printf("\nValor Unitario: %.2f", atual->vlrUni);
                    printf("\nDesconto: %.2f", atual->desconto);
                    printf("\nPreco: %.2f", atual->vlrTotal);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    }else{
        for (char letra = 'Z'; letra >= 'A'; letra--) {
            atual = listaPedido;
            while (atual != NULL) {

                if (toupper(atual->nomeProduto[0]) == letra) {
                    printf("\n--------------------------");
                    printf("\nId: %d", atual->idPedido);
                    printf("\nNome Cliente: %s", atual->nomeCliente);
                    printf("\nNome Produto: %s", atual->nomeProduto);
                    printf("\nQuantidade: %d", atual->qtde);
                    printf("\nValor Unitario: %.2f", atual->vlrUni);
                    printf("\nDesconto: %.2f", atual->desconto);
                    printf("\nPreco: %.2f", atual->vlrTotal);
                }
                atual = atual->proximo;
            }
        }
        printf("\nListagem feita com sucesso!");
    }
}

void relatorio(cliente *listaCliente, produto *listaProduto, pedido *listaPedido) {
    int totalClientes = 0;
    int totalProdutos = 0;
    int totalPedidos = 0;
    float total = 0;
    float maiorValor = 0;
    char melhorCliente[50] = "SemNome";

    cliente *clienteAtual = listaCliente;
    while (clienteAtual != NULL) {
        totalClientes++;
        clienteAtual = clienteAtual->proximo;
    }

    produto *produtoAtual = listaProduto;
    while (produtoAtual != NULL) {
        totalProdutos++;
        produtoAtual = produtoAtual->proximo;
    }

    pedido *pedidoAtual = listaPedido;
    while (pedidoAtual != NULL) {
        totalPedidos++;
        total += pedidoAtual->vlrTotal;
        pedidoAtual = pedidoAtual->proximo;
    }

    clienteAtual = listaCliente;
    while (clienteAtual != NULL) {
        float soma = 0;
        pedido *pedidoTemp = listaPedido;

        while (pedidoTemp != NULL) {
            if (strcmp(pedidoTemp->nomeCliente, clienteAtual->nome) == 0) {
                soma += pedidoTemp->vlrTotal;
            }
            pedidoTemp = pedidoTemp->proximo;
        }

        if (soma > maiorValor) {
            maiorValor = soma;
            strcpy(melhorCliente, clienteAtual->nome);
        }
        clienteAtual = clienteAtual->proximo;
    }


    printf("\n------ RELATORIOS DO SISTEMA ------\n");
    printf("Total de clientes cadastrados: %d\n", totalClientes);
    printf("Total de produtos cadastrados: %d\n", totalProdutos);
    printf("Total de pedidos realizados: %d\n", totalPedidos);

    if (strcmp(melhorCliente, "SemNome") != 0) {
        printf("Cliente que mais gastou: %s (R$ %.2f)\n", melhorCliente, maiorValor);
    } else {
        printf("Nenhum cliente realizou compras ainda\n");
    }

    printf("\nProdutos vendidos:\n");
    pedidoAtual = listaPedido;
    while (pedidoAtual != NULL) {
        printf("- Produto: %s | Quantidade: %d | Total: R$ %.2f\n",
               pedidoAtual->nomeProduto, pedidoAtual->qtde, pedidoAtual->vlrTotal);
        pedidoAtual = pedidoAtual->proximo;
    }

    printf("Total faturado: R$ %.2f\n", total);
}


cliente *carregarClientes(char *nomeArquivo)
{
    FILE *f = fopen(nomeArquivo, "r");
    if (!f)
    {
        printf("Arquivo %s nao encontrado. Iniciando com lista vazia.\n", nomeArquivo);
        return NULL;
    }

    cliente *inicio = NULL, *fim = NULL, *novo;
    char linha[300];

    while (fgets(linha, sizeof(linha), f))
    {
        linha[strcspn(linha, "\n")] = 0;
        novo = (cliente *)malloc(sizeof(cliente));
        sscanf(linha, "%d;%49[^;];%11[^;];%11[^;];%49[^;];%19[^;];%d;%19[^;];%8s",
               &novo->idCliente, novo->nome, novo->telefone, novo->cpf, novo->email,
               novo->end.rua, &novo->end.numero, novo->end.bairro, novo->end.cep);

        novo->proximo = NULL;
        novo->anterior = fim;

        if (fim != NULL)
        {
            fim->proximo = novo;
        }
        else
        {
            inicio = novo;
        }

        fim = novo;
    }

    fclose(f);
    return inicio;
}

void salvarClientes(char *nomeArquivo, cliente *lista)
{
    FILE *f = fopen(nomeArquivo, "w");
    if (!f)
        return;

    cliente *atual = lista;
    while (atual != NULL)
    {
        fprintf(f, "%d;%s;%s;%s;%s;%s;%d;%s;%s\n",
                atual->idCliente, atual->nome, atual->telefone, atual->cpf,
                atual->email, atual->end.rua, atual->end.numero,
                atual->end.bairro, atual->end.cep);
        atual = atual->proximo;
    }

    fclose(f);
}

produto *carregarProdutos(char *nomeArquivo)
{
    FILE *f = fopen(nomeArquivo, "r");
    if (!f)
    {
        printf("Arquivo %s nao encontrado. Iniciando com lista vazia.\n", nomeArquivo);
        return NULL;
    }

    produto *inicio = NULL, *fim = NULL, *novo;
    char linha[300];

    while (fgets(linha, sizeof(linha), f))
    {
        linha[strcspn(linha, "\n")] = 0;
        novo = (produto *)malloc(sizeof(produto));
        sscanf(linha, "%d;%49[^;];%9[^;];%9[^;];%f;%d",
               &novo->idProduto, novo->nome, novo->midia, novo->genero, &novo->preco,
               &novo->qtdeEstoque);

        novo->proximo = NULL;
        novo->anterior = fim;

        if (fim != NULL)
        {
            fim->proximo = novo;
        }
        else
        {
            inicio = novo;
        }

        fim = novo;
    }

    fclose(f);
    return inicio;
}

void salvarProdutos(char *nomeArquivo, produto *lista)
{
    FILE *f = fopen(nomeArquivo, "w");
    if (!f)
        return;

    produto *atual = lista;
    while (atual != NULL)
    {
        fprintf(f, "%d;%s;%s;%s;%f;%d\n",
                atual->idProduto, atual->nome, atual->midia, atual->genero,
                atual->preco, atual->qtdeEstoque);
        atual = atual->proximo;
    }

    fclose(f);
}

pedido *carregarPedidos(char *nomeArquivo)
{
    FILE *f = fopen(nomeArquivo, "r");
    if (!f)
    {
        printf("Arquivo %s nao encontrado. Iniciando com lista vazia.\n", nomeArquivo);
        return NULL;
    }

    pedido *inicio = NULL, *fim = NULL, *novo;
    char linha[300];

    while (fgets(linha, sizeof(linha), f))
    {
        linha[strcspn(linha, "\n")] = 0;
        novo = (pedido *)malloc(sizeof(pedido));
        sscanf(linha, "%d;%49[^;];%49[^;];%d;%f;%f;%f",
               &novo->idPedido, novo->nomeCliente, novo->nomeProduto, &novo->qtde, &novo->vlrUni,
               &novo->desconto, &novo->vlrTotal);

        novo->proximo = NULL;
        novo->anterior = fim;

        if (fim != NULL)
        {
            fim->proximo = novo;
        }
        else
        {
            inicio = novo;
        }

        fim = novo;
    }

    fclose(f);
    return inicio;
}

void salvarPedidos(char *nomeArquivo, pedido *lista)
{
    FILE *f = fopen(nomeArquivo, "w");
    if (!f)
        return;

    pedido *atual = lista;
    while (atual != NULL)
    {
        fprintf(f, "%d;%s;%s;%d;%f;%f;%f\n",
                atual->idPedido, atual->nomeCliente, atual->nomeProduto, atual->qtde, atual->vlrUni,
                atual->desconto, atual->vlrTotal);
        atual = atual->proximo;
    }

    fclose(f);
}

void liberarClientes(cliente *lista)
{
    cliente *atual = lista;
    while (atual != NULL)
    {
        cliente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void liberarProdutos(produto *lista)
{
    produto *atual = lista;
    while (atual != NULL)
    {
        produto *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void liberarPedidos(pedido *lista)
{
    pedido *atual = lista;
    while (atual != NULL)
    {
        pedido *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}


int validarNome(char *nome) {
    if (strlen(nome) == 0 || strlen(nome) > 99) {
        printf("\nNome invalido! Digite apenas letras.");
        return 0;
    }

    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            printf("\nNome invalido! Digite apenas letras.");
            return 0;
        }
    }
    return 1;
}

int validarTelefone(char *telefone) {
    if (strlen(telefone) != 11) {
        printf("\nTelefone invalido!");
        return 0;
    }

    for (int i = 0; telefone[i] != '\0'; i++) {
        if (!isdigit(telefone[i])) {
            printf("\nTelefone invalido! Digite apenas numeros");
            return 0;
        }
    }
    return 1;
}

int validarCPF(char *cpf) {
    if (strlen(cpf) != 11) {
        printf("\nO cpf deve ter 11 caracteres.");
        return 0;
    }

    for (int i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit(cpf[i])) {
            printf("\nDigite apenas numeros.");
            return 0;
        }
    }
    return 1;
}

int validarEmail(char *email) {
    if (strlen(email) < 5 || strlen(email) > 99) {
        printf("Email invalido!\n");
        return 0;
    }

    char *arroba = strchr(email, '@');
    if (arroba == NULL || arroba == email) {
        printf("Email invalido! Deve conter @ (arroba)\n");
        return 0;
    }

    char *ponto = strchr(arroba, '.');
    if (ponto == NULL || ponto == arroba + 1) {
        printf("Email invalido! Deve conter ponto\n");
        return 0;
    }

    return 1;
}

int validarCEP(char *cep) {
    if (strlen(cep) != 8) {
        printf("\nO CEP deve ter 8 caracteres.");
        return 0;
    }

    for (int i = 0; cep[i] != '\0'; i++) {
        if (!isdigit(cep[i])) {
            printf("\nDigite apenas numeros.");
            return 0;
        }
    }
     return 1;
}

int validarMidia(char *midia) {
    if (strcmp(midia, "CD") != 0 && strcmp(midia, "LP") != 0 && strcmp(midia, "DVD") != 0) {
        printf("Midia invalida! Escolha CD, DVD ou LP\n");
        return 0;
    }
    return 1;
}
 
int validarPreco(float *preco) {
    if (preco <= 0) {
        printf("O preço não pode ser negativo ou igual a zero\n");
        return 0;
    }
    return 1;
}
