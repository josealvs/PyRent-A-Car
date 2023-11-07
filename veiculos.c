#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
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
            case '2': 	pesquisar_veiculo();
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


Veiculos* pesquisar_veiculo(void) {
    FILE* fp;
    Veiculos* veiculos;
    char placa_dig[8];
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
    scanf("%s", placa_dig);
    limpaBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    veiculos = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("vei.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }else{
        while(!feof(fp)) {
            fread(veiculos, sizeof(Veiculos), 1, fp);
            if (strcmp(veiculos->placa, placa_dig)==0){
                exibe_veiculos(veiculos);
                printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(fp);
                return veiculos;
            }else{

            }
        }
    }
    fclose(fp);
    return NULL;

    
}


void tela_alterar_veiculo(void) {
    FILE* fp;
    Veiculos* veiculos = (Veiculos*) malloc(sizeof(Veiculos));
    char placa_dig[8];
    int find = 0;
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
    scanf("%s", placa_dig);
    limpaBuffer();
    getchar();
    fp = fopen("vei.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(veiculos, sizeof(Veiculos), 1, fp) == 1) {
        if(strcmp(veiculos->placa, placa_dig) == 0) {
            printf("\n");
            printf("\t\t\t*** Veiculo Encontrado ***\n");
            printf("\t\t\t*** Refaça o Cadastro ***\n");
            printf("\n");

            printf("///            Modelo:                                                      ///\n");
            fgets(veiculos->modelo, sizeof(veiculos->modelo), stdin);
            limpaBuffer();
            if (!(validadorModelo(veiculos->modelo))){
                printf("\t\t\t>>>Modelo válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Modelo inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            printf("\n");

            printf("///            Fabricante:                                                  ///\n");
            fgets(veiculos->fabricante, sizeof(veiculos->fabricante), stdin);
            limpaBuffer();
            if (!(validadorFabricante(veiculos->fabricante))){
                printf("\t\t\t>>>Nome válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Nome inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            printf("///            Ano:                                                         ///\n");
            scanf("%d", &veiculos->ano);
            limpaBuffer();
            if (!(validadorAno(veiculos->ano))){
                printf("\t\t\t>>>Ano válida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Ano inválida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            printf("\n");
            printf("///            Placa:                                                       ///\n");
            fgets(veiculos->placa, sizeof(veiculos->placa), stdin);
            limpaBuffer();
            if (!(validadorPlaca(veiculos->placa))){
                printf("\t\t\t>>>Placa válida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Placa inválida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            printf("\n");
            printf("///            Chassi:                                                      ///\n");
            fgets(veiculos->chassi, sizeof(veiculos->chassi), stdin);
            limpaBuffer();
            if (!(validadorChassi(veiculos->chassi))){
                printf("\t\t\t>>>Chassi válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Chassi inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            printf("///            Estado de Conservação:                                       ///\n");
            fgets(veiculos->estado_c, sizeof(veiculos->estado_c), stdin);
            limpaBuffer();
            if (validadorConservacao(veiculos->estado_c)){
                printf("\t\t\t>>>Estado de Conservacao Valido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Estado de Conservacao Invalido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            printf("///            Valor da Diária do Veículo:                                  ///\n");
            scanf("%d", &veiculos->diaria);
            limpaBuffer();
            if (validadorDiaria(veiculos->diaria)){
                printf("\t\t\t>>>Valor válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Chassi inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }
            veiculos->status = 'a';


            fseek(fp, -sizeof(Veiculos), SEEK_CUR);
            fwrite(veiculos, sizeof(Veiculos), 1, fp);
            find = 1;
            break;
        }
      }
    }

    if (!find) {
        printf("\n");
        printf("\t\t\t Placa não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\t Veiculo atualizado com sucesso!\n");
    }
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}


void tela_excluir_veiculo(void) {
    FILE* fp;
    Veiculos* veiculos = (Veiculos*) malloc(sizeof(Veiculos));
    char placa_dig[8];
    int find = 0;
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
    scanf("%s", placa_dig);
    getchar();
    fp = fopen("vei.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(veiculos, sizeof(Veiculos), 1, fp) == 1) {
        if(strcmp(veiculos->placa, placa_dig) == 0) {
          printf("\n");
          printf("\t\t\t*** Veiculo Encontrado ***\n");
          printf("\n");
          veiculos->status = 'x';
          fseek(fp, -sizeof(Veiculos), SEEK_CUR);
          fwrite(veiculos, sizeof(veiculos), 1, fp);
          find = 1;
          break;
        }
      }
    }
    if (!find) {
        printf("\n");
        printf("\t\t\tPlaca não encontrada!\n");
    } else {
        printf("\n");
        printf("\t\t\tVeiculo excluído com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fclose(fp);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}


void exibe_veiculos(Veiculos* veiculos) {

    char situacao[20];
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Rent A Car = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
  if ((veiculos == NULL) || (veiculos->status == 'x')) {
      printf("\n Veículo não encontrado!\n");
      printf("\n");
      printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
      getchar();
  } else {
      printf("\n*** Veículo Cadastrado***\n");
      printf("\n");
      printf("*** Modelo: ");
      printf("%s" ,veiculos->modelo);
      printf("\n");
      printf("*** Fabricante: ");
      printf("%s" ,veiculos->fabricante);
      printf("\n");
      printf("*** Placa: ");
      printf("%s" ,veiculos->placa);
      printf("\n");
      printf("*** Chassi: ");
      printf("%s" ,veiculos->chassi);
      printf("\n");
      printf("*** Estado de COnservação: ");
      printf("%s" ,veiculos->estado_c);
      printf("\n");
      printf("*** Valor da Diaria: ");
      printf("\n");
      printf("%d" ,veiculos->diaria);
      printf("\n");
      printf("*** Ano: ");
      printf("\n");
      printf("%d",veiculos->ano);
    if (veiculos->status == 'a') {
      strcpy(situacao, "Cadastrado Ativo");
    } else {
      strcpy(situacao, "Cadastro Inativo");
    }
    printf("Status do Veiculo: %s\n", situacao);
    printf("\n");
  }   
}