#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "aluguel.h"
#include "clientes.h"
#include "veiculos.h"
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
            case '3':   tela_excluir_aluguel();
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
    printf("///            3. Inativar Aluguel                                          ///\n");
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
    char cpf_digc[13];
    char cpf_digf[13];
    char placa_dig[8];
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
    printf("///            Gerando Código do Aluguel...                                 ///\n");
    alg->codigo = geraCod();
    sleep(1);
    printf("///            Código do Aluguel: %i                                        ///\n", alg->codigo);
    printf("///            CPF do Cliente:                                              ///\n");
    scanf("%12[^\n]",cpf_digc);
    
    limpaBuffer();
    while(!(validadorCPF(cpf_digc)) ){
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Digite o CPF do Cliente novamente: \n");
        scanf("%12[^\n]", cpf_digc);

        while(!(cadastrar_cli(cpf_digc))){
        printf("\t\t\t>>>CPF Digitado não existe no banco de dados<<<\n");
        printf("\t\t\t>>> Digite o CPF do Cliente novamente: \n");
        scanf("%12[^\n]", cpf_digc);
        getchar();
        }


        getchar();
    }
    while(!(cadastrar_cli(cpf_digc))){
        printf("\t\t\t>>>CPF Digitado não existe no banco de dados<<<\n");
        printf("\t\t\t>>> Digite o CPF do Cliente novamente: \n");
        scanf("%12[^\n]", cpf_digc);
        
        while(!(validadorCPF(cpf_digc)) ){
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Digite o CPF do Cliente novamente: \n");
        scanf("%12[^\n]", cpf_digc);
        getchar();
        }


        getchar();
    }
    strcpy(alg->cpf_c, cpf_digc);  

    printf("///            CPF do Funcionario:                                          ///\n");
    scanf("%12[^\n]",cpf_digf);
    
    limpaBuffer();
   while(!(validadorCPF(cpf_digf))){
        printf("\t\t\t>>>CPF foi digitado incorretamente<<<\n");
        printf("\t\t\t>>> Digite o CPF novamente: \n");
        scanf("%12[^\n]",cpf_digf);
        while(!(cadastrar_fun(cpf_digf))){
            printf("\t\t\t>>>CPF Digitado não existe no banco de dados<<<\n");
            printf("\t\t\t>>> Digite o CPF novamente: \n");
            scanf("%12[^\n]",cpf_digf);
            getchar();
        }
        getchar();
    }

     while(!(cadastrar_fun(cpf_digf))){
        printf("\t\t\t>>>CPF Digitado não existe no banco de dados<<<\n");
        printf("\t\t\t>>> Digite o CPF novamente: \n");
        scanf("%12[^\n]",cpf_digf);
        getchar();
        while(!(validadorCPF(cpf_digf))){
            printf("\t\t\t>>>CPF foi digitado incorretamente<<<\n");
            printf("\t\t\t>>> Digite o CPF novamente: \n");
            scanf("%12[^\n]",cpf_digf);
            getchar();
        }
    }
    strcpy(alg->cpf_f, cpf_digf);  

    
    printf("///            Placa do Veículo:                                            ///\n");
    scanf("%7[^\n]", placa_dig);
    limpaBuffer();
    while(!(validadorPlaca(placa_dig))){
        printf("\t\t\t>>>Placa inválida<<<\n");
        printf("\t\t\t>>> Digite a Placa novamente:\n");
        scanf("%7[^\n]", placa_dig);
        getchar();
    }
    while(!(cadastrar_plac(placa_dig))){
        printf("\t\t\t>>>CPF não existe no banco de dados<<<\n");
        printf("\t\t\t>>> Digite o CPF do Cliente novamente: \n");
        scanf("%7[^\n]", placa_dig);
        getchar();
    }
    strcpy(alg->placa, placa_dig);

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
        printf("///            Dia:                                                     ///\n");
        scanf("%d", &alg->dia_i);   
        limpaBuffer();
        printf("///            Mês(em número):                                          ///\n");
        scanf("%d", &alg->mes_i); 
        limpaBuffer();
        printf("///            Ano:                                                     ///\n");
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
        printf("///            Dia:                                                     ///\n");
        scanf("%d", &alg->dia_f);
        limpaBuffer();
        printf("///            Mês(em número):                                          ///\n");
        scanf("%d", &alg->mes_f); 
        limpaBuffer();
        printf("///            Ano:                                                     ///\n");
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

void tela_excluir_aluguel(void) {
    int cod_dig;
    Aluguel* aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    FILE* fp;
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
    printf("///            = = = = = = = = Inativar Aluguel = = = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Código do Aluguel:                                 ///\n");
    scanf("%d", &cod_dig);
    getchar();
    fp = fopen("alg.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(aluguel, sizeof(Aluguel), 1, fp) == 1) {
        if(aluguel->codigo == cod_dig) {
          printf("\n");
          printf("\t\t\t*** Aluguel Encontrado ***\n");
          printf("\n");
          aluguel->status = 'x';
          fseek(fp, -sizeof(Aluguel), SEEK_CUR);
          fwrite(aluguel, sizeof(Aluguel), 1, fp);
          find = 1;
          break;
        }
      }
    }
    if (!find) {
        printf("\n");
        printf("\t\t\tCódigo não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tAluguel inativado com sucesso!\n");
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
      printf("%d/%d/%d", aluguel->dia_i, aluguel->mes_i, aluguel->ano_i);
      printf("\n");
      printf("*** Data de Fim: ");
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

//Código inspirado no Aluno Renan Messias
int geraCod (void) {
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
        Aluguel* aluguel;
        aluguel = (Aluguel*)malloc(sizeof(Aluguel));
        fread(aluguel, sizeof(Aluguel), 1, fp);
        int codigo = aluguel->codigo+1;
        fclose(fp);
        return codigo;
    }
}





