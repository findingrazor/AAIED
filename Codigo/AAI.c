#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"

int main()
{
    menu();
    return 0;
}

void menu()
{
    produto *listaProduto = NULL;
    cliente *lista = NULL;
    char opcao;
    int alt;

    do
    {
        printf("\n--------Bem-Vindo ao ED ERP!--------");
        printf("\nEste e o Modulo de Vendas!");
        printf("\nQual acao voce deseja realizar hoje? ");
        printf("\nA) Gerenciamento de Clientes");
        printf("\nB) Gerenciamento de Pordutos");
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
                    lista = cadastrarClienteInicio(lista);
                }
                else if (alt == 2)
                {
                }
                else if (alt == 3)
                {
                }
                else
                {
                    listarClientes(lista);
                }
            }
            else if (alt == 2)
            {
            }
            else
            {
            }
            break;

        case 'B':
            printf("\nVoce esta no Gerenciamento de Produto, o que deseja fazer?");
            printf("\n1) Cadastrar Produto");
            printf("\n2) Alterar Produto");
            printf("\n3) Excluir Produto");
            printf("\n4) Listar Produto");

            do {
                printf("\nDigite a opcao desejada: ");
                scanf("%d", &alt);
                if (alt > 4 || alt < 1) {
                    printf("\nOpcao invalida, por favor, digite um numero de 1 a 4 para escolher um modulo!");
                }
            } while (alt > 4 || alt < 1);

            if (alt == 1) {

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

                if (alt == 1) {
                    listaProduto = cadastrarProdutoInicio(listaProduto);
                } else if  (alt == 2){
                    printf("\nEm que posicao da lista deseja colocar o novo produto? ");
                    scanf("%d", &posicao);
                    listaProduto = cadastrarProdutoMeio(listaProduto, posicao);
                } else {
                    listaProduto = cadastrarProdutoFim(listaProduto);
                }

            } else if (alt == 2) {

            } else if (alt == 3) {
            } else {
                listarProduto(listaProduto);
            }
            break;

        case 'C':
            break;

        case 'D':
            break;

        case 'E':
            break;

        case 'F':
            printf("\nObrigado por utilizar o ED ERP, volte sempre!");
            break;
        }
        fclose(f);
    } while (opcao != 'F');
}

cliente *cadastrarClienteInicio(cliente *inicio)
{
    cliente *novo = (cliente *)malloc(sizeof(cliente));

    novo->idCliente = RANDO;
    novo->proximo = inicio;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um Cliente pelo inicio!");
    printf("\nDigite o nome do Cliente: ");
    scanf(" %[^\n]", novo->nome);
    printf("\nDigite o telefone do Cliente: ");
    scanf(" %s", novo->telefone);
    printf("\nDigite o CPF do Cliente: ");
    scanf(" %s", novo->cpf);
    printf("\nDigite o email do Cliente: ");
    scanf(" %s", novo->email);
    printf("\nVamos preencher o endereço!");
    printf("\nDigite a rua: ");
    scanf(" %[^\n]", novo->end.rua);
    printf("\nDigite o numero: ");
    scanf(" %d", &novo->end.numero);
    printf("\nDigite o bairro: ");
    scanf(" %[^\n]", novo->end.bairro);
    printf("\nDigite o CEP: ");
    scanf(" %s", novo->end.cep);
    printf("Cadastro realizado com sucesso!");

    printf("\n--------------------------");
    printf("\nDados Pessoais");
    printf("\nId: %d", novo->idCliente);
    printf("\nNome: %s", novo->nome);
    printf("\nTelefone: %s", novo->telefone);
    printf("\nCPF: %s", novo->cpf);
    printf("\nEmail: %s", novo->email);
    printf("\nEndereco");
    printf("\nRua: %s", novo->end.rua);
    printf("\nNumero: %d", novo->end.numero);
    printf("\nBairro: %s", novo->end.bairro);
    printf("\nCEP: %s", novo->end.cep);

    FILE *f = fopen("dados.txt", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para gravar!\n");
        return inicio;
    }

    fprintf(f, "%d;%s;%s;%s;%s;%s;%d;%s;%s\n",
            novo->idCliente, novo->nome, novo->telefone, novo->cpf, novo->email,
            novo->end.rua, novo->end.numero, novo->end.bairro, novo->end.cep);

    fclose(f);
    return novo;
}

void listarClientes(cliente *lista)
{
    if (lista == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }
    cliente *atual = lista;
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
}

produto *cadastrarProdutoInicio (produto *inicio) {
    produto *novo = (produto *)malloc(sizeof(produto));

    novo->idProduto = RANDO;
    novo->proximo = inicio;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Produto pelo inicio da lista!");
    printf("\nDigite o nome do Produto: ");
    scanf("%s", novo->nome);
    printf("Digite a midia do Produto: ");
    scanf("%s", novo->midia);
    printf("Digite o genero do Produto: ");
    scanf("%s", novo->genero);
    printf("Digite o preco do Produto: ");
    scanf("%f", &novo->preco);
    printf("Digite a quantidade do Produto no estoque: ");
    scanf("%d", &novo->qtdeEstoque);
    printf("Cadastro realizado com sucesso");
    return novo;
}

produto *cadastrarProdutoFim(produto *inicio) {
    produto *novo = (produto *)malloc(sizeof(produto));

    novo->idProduto = RANDO;
    novo->proximo = NULL;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Produto no fim da lista!");
    printf("\nDigite o nome do Produto: ");
    scanf("%s", novo->nome);
    printf("Digite a midia do Produto: ");
    scanf("%s", novo->midia);
    printf("Digite o genero do Produto: ");
    scanf("%s", novo->genero);
    printf("Digite o preco do Produto: ");
    scanf("%f", &novo->preco);
    printf("Digite a quantidade do Produto no estoque: ");
    scanf("%d", &novo->qtdeEstoque);

    if (inicio == NULL) {
        return novo;
    }

    produto *atual = inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;
    return inicio;
}

produto *cadastrarProdutoMeio(produto *inicio, int posicao) {
    produto *novo = (produto *)malloc(sizeof(produto));

    novo->idProduto = RANDO;
    novo->proximo = NULL;
    novo->anterior = NULL;

    printf("\nVoce esta cadastrando um novo Produto no meio da lista!");
    printf("\nDigite o nome do Produto: ");
    scanf("%s", novo->nome);
    printf("Digite a midia do Produto: ");
    scanf("%s", novo->midia);
    printf("Digite o genero do Produto: ");
    scanf("%s", novo->genero);
    printf("Digite o preco do Produto: ");
    scanf("%f", &novo->preco);
    printf("Digite a quantidade do Produto no estoque: ");
    scanf("%d", &novo->qtdeEstoque);

    produto *atual = inicio;
    int contador = 1;

    while (contador < posicao-1 && atual->proximo != NULL) {
        atual = atual->proximo;
        contador++;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;

    if (atual->proximo != NULL) {
        atual->proximo->anterior = novo;
    }
    atual->proximo = novo;
    return inicio;
}


void listarProduto(produto *listaProduto) {
    if (listaProduto == NULL) {
        printf("\nLista vazia");
        return;
    }

    produto *atual = listaProduto;
    while (atual != NULL) {
        printf("\n--------------------------");
        printf("\nId: %d", atual->idProduto);
        printf("\nNome: %s", atual->nome);
        printf("\nMidia: %s", atual->midia);
        printf("\nGenero: %s", atual->genero);
        printf("\nPreco: %.2f", atual->preco);
        printf("\nQuantidade em Estoque: %d", atual->qtdeEstoque);
        atual = atual->proximo;
    }
}
