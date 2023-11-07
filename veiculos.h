struct veiculos{
    char modelo[50];
    char fabricante[50];
    char placa[8];
    char chassi[17];
    char estado_c[20];
    int diaria;
    int ano;
    char status;
};
typedef struct veiculos Veiculos;

void tela_menu_veiculo(void);
char menu_veiculo(void);
Veiculos* cadastrar_veiculo(void);
Veiculos* pesquisar_veiculo(void);
void tela_alterar_veiculo(void);
void tela_excluir_veiculo(void);
void exibe_veiculos(Veiculos* veiculos);