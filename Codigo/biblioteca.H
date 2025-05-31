#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED



#endif // BIBLIOTECA_H_INCLUDED

#define RANDO rand() % 1000

typedef struct endereco
{
    char rua[20];
    int numero;
    char bairro[20];
    char cep[8];
}endereco;

typedef struct cliente
{
    int idCliente;
    char nome[50];
    char telefone[11];
    char cpf[11];
    char email[50];
    endereco end;
    struct cliente *proximo;
    struct cliente *anterior;
}cliente;

typedef struct produto
{
    int idProduto;
    char nome[50];
    char midia[5];
    char genero[5];
    float preco;
    int qtdeEstoque;
    struct produto *proximo;
    struct produto *anterior;
}produto;

typedef struct pedido
{
    int idPedido;
    cliente cli;
    produto prod;
    int qtde;
    float vlrUni;
    float desconto;
    float vlrTotal;
    struct pedido *proximo;
    struct pedido *anterior;
}pedido;


void menu();
cliente* cadastrarClienteInicio(cliente* inicio);
void listarClientes(cliente *lista);
