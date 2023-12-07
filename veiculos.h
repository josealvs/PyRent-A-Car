struct veiculos{
    char modelo[51];
    char fabricante[51];
    char placa[9];
    char chassi[18];
    char estado_c[21];
    int diaria;
    int ano;
    char status;
    struct veiculos *next;
};
typedef struct veiculos Veiculos;

void tela_menu_veiculo(void);
char menu_veiculo(void);
Veiculos* cadastrar_veiculo(void);
Veiculos* pesquisar_veiculo(void);
void tela_alterar_veiculo(void);
void tela_excluir_veiculo(void);
void exibe_veiculos(Veiculos* veiculos);