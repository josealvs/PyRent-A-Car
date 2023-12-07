
struct clientes{
    char cpf[13];
    char nome[102];
    int dia;
    int mes;
    int ano;
    char telefone[16];
    char cidade[51];
    char endereco[201];
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