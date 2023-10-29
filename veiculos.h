struct veiculos{
    char modelo[50];
    char fabricante[50];
    char placa[7];
    char chassi[17];
    char estado_c[20];
    int diaria;
    int ano;
    struct veiculos *next;
};
typedef struct veiculos Veiculos;

void tela_menu_veiculo(void);
char menu_veiculo(void);
Veiculos cadastrar_veiculo(void);
void tela_pesquisar_veiculo(void);
void tela_alterar_veiculo(void);
void tela_excluir_veiculo(void); 