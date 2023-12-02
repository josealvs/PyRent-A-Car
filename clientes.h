
struct clientes{
    char cpf[12];
    char nome[101];
    int dia;
    int mes;
    int ano;
    char telefone[15];
    char cidade[50];
    char endereco[200];
    char status;
    struct clientes *next;
    
};
typedef struct clientes Clientes;

void tela_menu_cliente(void);
char menu_cliente(void);
Clientes* cadastrar_cliente(void);
Clientes* pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);
void exibe_cliente(Clientes* clientes);  