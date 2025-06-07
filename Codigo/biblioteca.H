#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED



#endif // BIBLIOTECA_H_INCLUDED

#define RANDO rand() % 1000

typedef struct endereco
{
    char rua[20];
    int numero;
    char bairro[20];
    char cep[9];
}endereco;

typedef struct cliente
{
    int idCliente;
    char nome[50];
    char telefone[12];
    char cpf[12];
    char email[50];
    endereco end;
    struct cliente *proximo;
    struct cliente *anterior;
}cliente;

typedef struct produto
{
    int idProduto;
    char nome[50];
    char midia[10];
    char genero[10];
    float preco;
    int qtdeEstoque;
    struct produto *proximo;
    struct produto *anterior;
}produto;

typedef struct pedido
{
    int idPedido;
    char nomeCliente[50];
    char nomeProduto[50];
    int qtde;
    float vlrUni;
    float desconto;
    float vlrTotal;
    struct pedido *proximo;
    struct pedido *anterior;
}pedido;


void menu(cliente **listaCliente, produto **listaProduto, pedido **listaPedido);

cliente* cadastrarClienteInicio(cliente* inicio);
cliente* cadastrarClienteFim(cliente *inicio);
cliente* cadastrarClienteMeio(cliente *inicio, int posicao);
void listarClientes(cliente *lista);

produto* cadastrarProdutoInicio(produto* inicio);
produto* cadastrarProdutoFim(produto* inicio);
produto* cadastrarProdutoMeio(produto *inicio, int posicao);
void listarProduto(produto *listaProduto);

pedido* cadastrarPedidoInicio (pedido *inicio);
pedido* cadastrarPedidoFim (pedido *inicio);
pedido* cadastrarPedidoMeio (pedido *inicio, int posicao);
void listarPedido(pedido *listaPedido);


cliente* carregarClientes(char* nomeArquivo);
void salvarClientes(char* nomeArquivo, cliente* lista);

produto* carregarProdutos(char* nomeArquivo);
void salvarProdutos(char* nomeArquivo, produto* lista);

pedido* carregarPedidos(char* nomeArquivo);
void salvarPedidos(char* nomeArquivo, pedido* lista);

void liberarClientes(cliente* lista);
void liberarProdutos(produto* lista);
void liberarPedidos(pedido* lista);