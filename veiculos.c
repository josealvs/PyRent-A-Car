#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "veiculos.h"
#include "util.h"

//VEÍCULOS
 
void tela_menu_veiculo(void){
    
    char op;
    do{
        op = menu_veiculo();
        switch(op){
            case '1': 	cadastrar_veiculo();
                break;
            case '2': 	tela_pesquisar_veiculo();
                break;
            case '3': 	tela_alterar_veiculo();
                break;
            case '4': 	tela_excluir_veiculo();
                break;
        }
    }while (op != '0');
}
char menu_veiculo(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu Veículo = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo Veículo                                 ///\n");
    printf("///            2. Pesquisar os dados de um Veículo                          ///\n");
    printf("///            3. Atualizar o cadastro de um Veículo                        ///\n");
    printf("///            4. Excluir um Veículo do sistema                             ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}


Veiculos* cadastrar_veiculo(void) {
    Veiculos* vei;
    vei = (Veiculos*) malloc(sizeof(Veiculos));
    system("clear||cls"); 
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Veículo = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Modelo:                                                      ///\n");
    fgets(vei->modelo, sizeof(vei->modelo), stdin);
    limpaBuffer();
    if (!(validadorModelo(vei->modelo))){
        printf("\t\t\t>>>Modelo válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Modelo inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("\n");

    printf("///            Fabricante:                                                  ///\n");
    fgets(vei->fabricante, sizeof(vei->fabricante), stdin);
    limpaBuffer();
    if (!(validadorFabricante(vei->fabricante))){
        printf("\t\t\t>>>Nome válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Nome inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &vei->ano);
    limpaBuffer();
    if (!(validadorAno(vei->ano))){
        printf("\t\t\t>>>Ano válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Ano inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("\n");
    printf("///            Placa:                                                       ///\n");
    fgets(vei->placa, sizeof(vei->placa), stdin);
    limpaBuffer();
    if (!(validadorPlaca(vei->placa))){
        printf("\t\t\t>>>Placa válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Placa inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("\n");
    printf("///            Chassi:                                                      ///\n");
    fgets(vei->chassi, sizeof(vei->chassi), stdin);
    limpaBuffer();
    if (!(validadorChassi(vei->chassi))){
        printf("\t\t\t>>>Chassi válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Chassi inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Estado de Conservação:                                       ///\n");
    fgets(vei->estado_c, sizeof(vei->estado_c), stdin);
    limpaBuffer();
    if (validadorConservacao(vei->estado_c)){
        printf("\t\t\t>>>Estado de Conservacao Valido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Estado de Conservacao Invalido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Valor da Diária do Veículo:                                  ///\n");
    scanf("%d", &vei->diaria);
    limpaBuffer();
    if (validadorDiaria(vei->diaria)){
        printf("\t\t\t>>>Valor válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Chassi inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    vei->status = 'a';

    FILE* file;
    Veiculos* veiculos;
    file = fopen("vei.dat","wb");
    veiculos = vei;
    fwrite(veiculos, sizeof(Veiculos), 1, file);
    fclose(file);
    free(veiculos);

    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return 0;
    
}


void tela_pesquisar_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Veículo = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a Placa do Veículo:                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_alterar_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Veículo = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a Placa do Veículo:                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_excluir_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Veículo = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a Placa do Veículo:                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
