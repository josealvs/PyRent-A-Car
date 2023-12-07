struct funcionarios{
    char cpf[13];
    char nome[101];
    char cargo[21];
    int dia;
    int mes;
    int ano;
    char telefone[16];
    char cidade[51];
    char endereco[201];
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