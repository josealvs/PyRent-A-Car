#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "aluguel.h"
#include "util.h"
 
//ALUGUÉIS  

void tela_menu_aluguel(void){
    char op;
    do{
        op = menu_aluguel();
        switch(op){
            case '1': 	cadastrar_aluguel();
                break;
            case '2': 	pesquisar_aluguel();
                break;
        }
    }while (op != '0');
}

char menu_aluguel(void) {
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
    printf("///            = = = = = = = = =  Menu Aluguel = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo Aluguel                                 ///\n");
    printf("///            2. Pesquisar os dados de um Aluguel                          ///\n");
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

Aluguel* cadastrar_aluguel(void) {
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Aluguel = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Codigo do Aluguel:                                          ///\n");
    fgets(alg->codigo, sizeof(alg->codigo), stdin);
    limpaBuffer();
    printf("///            CPF do Cliente:                                              ///\n");
    fgets(alg->cpf_c, sizeof(alg->cpf_c), stdin);
    limpaBuffer();
    if (validadorCPF(alg->cpf_c)){
        printf("\t\t\t>>>CPF válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("///            CPF do Funcionario:                                          ///\n");
    fgets(alg->cpf_f, sizeof(alg->cpf_f), stdin);
    limpaBuffer();
    if (validadorCPF(alg->cpf_f)){
        printf("\t\t\t>>>CPF válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("///            Placa do Veículo:                                            ///\n");
    fgets(alg->placa, sizeof(alg->placa), stdin);
    limpaBuffer();
    if (validadorPlaca(alg->placa)){
        printf("\t\t\t>>>Placa válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Placa inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("///            Data de Início do Aluguel:                                   ///\n");
    printf("///            Dia:                                                         ///\n");
    scanf("%d", &alg->dia_i);   
    limpaBuffer();
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &alg->mes_i); 
    limpaBuffer();
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &alg->ano_i);   
    limpaBuffer();

    
    if (validadorData(alg->dia_i, alg->mes_i, alg->ano_i)){
        printf("\t\t\t>>>Data de Início válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Data de Início inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("///            Data de Fim do Aluguel:                                      ///\n");
    printf("///            Dia:                                                         ///\n");
    scanf("%d", &alg->dia_f);
    limpaBuffer();
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &alg->mes_f); 
    limpaBuffer();
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &alg->ano_f); 
    limpaBuffer();

    
    if (validadorData(alg->dia_f,alg->mes_f, alg->ano_f)){
        printf("\t\t\t>>>Data Final válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Data Final inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    
    alg->status = 'a';

    FILE* file;
    Aluguel* aluguel;
    file = fopen("alg.dat","a+b");
    aluguel = alg;
    fwrite(aluguel, sizeof(Aluguel), 1, file);
    fclose(file);
    free(aluguel);

    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return 0;

}

Aluguel* pesquisar_aluguel(void) {
    FILE* fp;
    Aluguel* aluguel;
    char codigo_dig[11];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Aluguel = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Código do Aluguel:                                 ///\n");
    scanf("%11[^\n]", codigo_dig);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    fp = fopen("alg.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }else{
        while(!feof(fp)) {
            fread(aluguel, sizeof(Aluguel), 1, fp);
            if (strcmp(aluguel->codigo, codigo_dig)==0){
                exibe_aluguel(aluguel);
                printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(fp);
                return aluguel;
            }else{
                printf("Erro");
            }
        }
    }
    fclose(fp);
    return NULL;

}

void exibe_aluguel (Aluguel* aluguel) {

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
  if ((aluguel == NULL) || (aluguel->status == 'x')) {
      printf("\n Cliente não encontrado!\n");
      printf("\n");
      printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
      getchar();
  } else {
      printf("\n*** Cliente Cadastrado***\n");
      printf("\n");
      printf("*** Codigo: ");
      printf("%s" ,aluguel->codigo);
      printf("\n");
      printf("*** CPF do CLiente: ");
      printf("%s" ,aluguel->cpf_c);
      printf("\n");
      printf("*** CPF do Funcionario: ");
      printf("%s" ,aluguel->cpf_f);
      printf("\n");
      printf("*** Placa do Veiculo: ");
      printf("%s" ,aluguel->placa);
      printf("\n");
      printf("*** Data de Inicio: ");
      printf("\n");
      printf("%d/%d/%d", aluguel->dia_i, aluguel->mes_i, aluguel->ano_i);
      printf("*** Data de Fim: ");
      printf("\n");
      printf("%d/%d/%d", aluguel->dia_f, aluguel->mes_f, aluguel->ano_f);
      printf("\n");

    if (aluguel->status == 'a') {
      strcpy(situacao, "Cadastrado Ativo");
    } else {
      strcpy(situacao, "Cadastro Inativo");
    }
    printf("Status do Aluguel: %s\n", situacao);
    printf("\n");
  }   
}
