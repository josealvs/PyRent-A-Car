struct aluguel{
    char cpf_f[12];
    char cpf_c[12];
    char placa[7];
    int dia_i;
    int mes_i;
    int ano_i;
    int dia_f;
    int mes_f;
    int ano_f;
    struct aluguel *next;
};
typedef struct aluguel Aluguel;

void tela_menu_aluguel(void);
char menu_aluguel(void);
Aluguel cadastrar_aluguel(void);
void tela_cadastrar_aluguel(void);
void tela_pesquisar_aluguel(void);
void tela_alterar_aluguel(void); 
void tela_excluir_aluguel(void);
