struct aluguel{
    char cpf_f[12];
    char cpf_c[12];
    char placa[8];
    int dia_i;
    int mes_i;
    int ano_i;
    int dia_f;
    int mes_f;
    int ano_f;
    int codigo;
    char status;
};
typedef struct aluguel Aluguel;

void tela_menu_aluguel(void);
char menu_aluguel(void);
Aluguel* cadastrar_aluguel(void);
Aluguel* pesquisar_aluguel(void);
void exibe_aluguel(Aluguel* aluguel);
int generateID(void);