#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED



#endif // BIBLIOTECA_H_INCLUDED

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
void alterarCliente (cliente *listaCliente);
cliente *excluirClienteInicio(cliente *inicio);
cliente *excluirClienteFim(cliente *inicio);
cliente *excluirClienteMeio(cliente *inicio, int id);
void buscarClienteNomeCPF(cliente *listaClientes, char *nomeCPF);
void buscarClienteID(cliente *listaClientes, int id);
void listarClientes(cliente *lista);

produto* cadastrarProdutoInicio(produto* inicio);
produto* cadastrarProdutoFim(produto* inicio);
produto* cadastrarProdutoMeio(produto *inicio, int posicao);
void alterarProduto(produto *listaProduto);
produto *excluirProdutoInicio(produto *inicio);
produto *excluirProdutoFim(produto *inicio);
produto *excluirProdutoMeio(produto *inicio, int id);
void buscarProdutoNome(produto *listaProduto, char *nome);
void buscarProdutoID(produto *listaProduto, int id);
void listarProduto(produto *listaProduto);

pedido *cadastrarPedidoInicio (pedido *inicio, cliente *listaClientes, produto *listaProdutos);
pedido *cadastrarPedidoFim(pedido *inicio, cliente *listaClientes, produto *listaProdutos);
pedido *cadastrarPedidoMeio(pedido *inicio, cliente *listaClientes, produto *listaProdutos, int posicao);
void alterarPedido (pedido *listaPedido);
pedido *excluirPedidoInicio(pedido *inicio);
pedido *excluirPedidoFim(pedido *inicio);
pedido *excluirPedidoMeio(pedido *inicio, int id);
void buscarPedidoNome(pedido *listaPedido, char *nome);
void buscarPedidoID(pedido *listaPedido, int id);
void listarPedido(pedido *listaPedido);

void relatorio (cliente *listaCliente, produto *listaProduto, pedido *listaPedido);

cliente* carregarClientes(char* nomeArquivo);
void salvarClientes(char* nomeArquivo, cliente* lista);

produto* carregarProdutos(char* nomeArquivo);
void salvarProdutos(char* nomeArquivo, produto* lista);

pedido* carregarPedidos(char* nomeArquivo);
void salvarPedidos(char* nomeArquivo, pedido* lista);

void liberarClientes(cliente* lista);
void liberarProdutos(produto* lista);
void liberarPedidos(pedido* lista);

int validarNome(char *nome);
int validarTelefone(char *telefone);
int validarCPF(char *cpf);
int validarEmail(char *email);
int validarCEP(char *cep);
int validarMidia(char *midia);
int validarPreco(float *preco);
