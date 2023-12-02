struct funcionarios{
    char cpf[12];
    char nome[100];
    char cargo[20];
    int dia;
    int mes;
    int ano;
    char telefone[15];
    char cidade[50];
    char endereco[200];
    char status;
    struct funcionarios *next;
};
typedef struct funcionarios Funcionarios;

void tela_menu_funcionario(void);
char menu_funcionario(void);
Funcionarios* cadastrar_funcionario(void);
Funcionarios* pesquisar_funcionario(void);
void tela_alterar_funcionario(void);
void tela_excluir_funcionario(void); 
void exibe_funcionario(Funcionarios* funcionarios);