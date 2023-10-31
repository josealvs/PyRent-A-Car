struct clientes{
    char cpf[12];
    char nome[200];
    int dia;
    int mes;
    int ano;
    char telefone[15];
    char cidade[50];
    char endereco[300];
    char status;
    
};
typedef struct clientes Clientes;


void tela_menu_cliente(void);
char menu_cliente(void);
Clientes* cadastrar_cliente(void);
void tela_pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);
  