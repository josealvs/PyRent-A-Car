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
    printf("///            Codigo do Aluguel:                                           ///\n");
    scanf("%d", &alg->codigo);
    limpaBuffer();
    printf("///            CPF do Cliente:                                              ///\n");
    scanf("%12[^\n]", alg->cpf_c);
    limpaBuffer();
    while(!(validadorCPF(alg->cpf_c))){
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Digite o CPF do Cliente novamente: \n");
        scanf("%12[^\n]", alg->cpf_c);
        getchar();
    }

    printf("///            CPF do Funcionario:                                          ///\n");
    scanf("%12[^\n]", alg->cpf_f);
    limpaBuffer();
    while (!(validadorCPF(alg->cpf_f))){
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Digite o CPF do Funcionário novamente: \n");
        scanf("%12[^\n]", alg->cpf_f);
        getchar();
    }
    
    printf("///            Placa do Veículo:                                            ///\n");
    scanf("%8[^\n]", alg->placa);
    limpaBuffer();
    while(!(validadorPlaca(alg->placa))){
        printf("\t\t\t>>>Placa inválida<<<\n");
        printf("\t\t\t>>> Digite a Placa novamente:\n");
        scanf("%8[^\n]", alg->placa);
        getchar();
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

    
    while(!(validadorData(alg->dia_i, alg->mes_i, alg->ano_i))){
        printf("\t\t\t>>>Data de Início inválida<<<\n");
        printf("\t\t\t>>> Digite a Data novamente: \n");
        printf("///            Dia:                                                         ///\n");
        scanf("%d", &alg->dia_i);   
        limpaBuffer();
        printf("///            Mês(em número):                                              ///\n");
        scanf("%d", &alg->mes_i); 
        limpaBuffer();
        printf("///            Ano:                                                         ///\n");
        scanf("%d", &alg->ano_i);   
        limpaBuffer();
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

    
    while (!(validadorData(alg->dia_f,alg->mes_f, alg->ano_f))){
        printf("\t\t\t>>>Data Final inválida<<<\n");
        printf("\t\t\t>>> Digite a Data novamente: \n");
        printf("///            Dia:                                                         ///\n");
        scanf("%d", &alg->dia_f);
        limpaBuffer();
        printf("///            Mês(em número):                                              ///\n");
        scanf("%d", &alg->mes_f); 
        limpaBuffer();
        printf("///            Ano:                                                         ///\n");
        scanf("%d", &alg->ano_f); 
        limpaBuffer();
    }
    
    alg->status = 'a';

    FILE* file;
    Aluguel* aluguel;
    file = fopen("alg.dat","ab");
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
    int codigo_dig;
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
    scanf("%d", &codigo_dig);
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
            if (aluguel->codigo == codigo_dig){
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
      printf("%i" ,aluguel->codigo);
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

//Percorre o algoritmo para gerar um id de uma venda adequadamente
int generateID(void) {
    FILE *fp;
    fp = fopen("alg.dat", "rb");
    if (fp == NULL) {
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    if ((long)ftell(fp) == 0){
        fclose(fp);
        return 1;
    }
    else {
        fseek(fp, -((long)sizeof(Aluguel)), SEEK_END);
        Aluguel* alg;
        alg = (Aluguel*)malloc(sizeof(Aluguel));
        fread(alg, sizeof(Aluguel), 1, fp);
        int codigo = alg->codigo+1;
        fclose(fp);
        return codigo;
    }
}
