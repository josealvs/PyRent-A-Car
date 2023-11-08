#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "funcionarios.h"
#include "util.h"

// FUNCIONÁRIOS
void tela_menu_funcionario(void){
    char op;
    do{
        op = menu_funcionario();
        switch(op){
            case '1': 	cadastrar_funcionario();
                break;
            case '2': 	pesquisar_funcionario();
                break;
            case '3': 	tela_alterar_funcionario();
                break;
            case '4': 	tela_excluir_funcionario();
                break;
        }
    }while (op != '0');
}

char menu_funcionario(void) {
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
    printf("///            = = = = = = = = =  Menu Funcionário = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo Funcionário                             ///\n");
    printf("///            2. Pesquisar os dados de um Funcionário                      ///\n");
    printf("///            3. Atualizar o cadastro de um Funcionário                    ///\n");
    printf("///            4. Excluir um Funcionário do sistema                         ///\n");
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

Funcionarios* cadastrar_funcionario(void) {
    Funcionarios* fun;
    fun = (Funcionarios*) malloc(sizeof(Funcionarios));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Funcionario = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome:                                                        ///\n");
    fgets(fun->nome, sizeof(fun->nome), stdin);
    limpaBuffer();
    if (!(validadorNome(fun->nome))){
        printf("\t\t\t>>>Nome válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Nome inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("\n");
    printf("///            CPF:                                                         ///\n");
    fgets(fun->cpf, sizeof(fun->cpf), stdin);
    limpaBuffer();
    if (validadorCPF(fun->cpf)){
        printf("\t\t\t>>>CPF válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("\n");
    printf("///            Data de Nascimento:                                          ///\n");
    printf("///            Dia:                                                         ///\n");
    scanf("%d", &fun->dia);
    limpaBuffer();
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &fun->mes);
    limpaBuffer();
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &fun->ano);
    limpaBuffer();

    
    if (validadorData(fun->dia, fun->mes, fun->ano)){
        printf("\t\t\t>>>Data de Nascimento válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Data de Nascimento inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("///            Cidade:                                                      ///\n");
    fgets(fun->cidade, sizeof(fun->cidade), stdin);
    limpaBuffer();
    if (!(validadorCidade(fun->cidade))){
        printf("\t\t\t>>>Cidade válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Cidade inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("///            Endereço:                                                    ///\n");
    fgets(fun->endereco, sizeof(fun->endereco), stdin);
    limpaBuffer();
    printf("///            Telefone:                                                    ///\n");
    fgets(fun->telefone, sizeof(fun->telefone), stdin);
    limpaBuffer();
    if (!(validadorTelefone(fun->telefone))){
        printf("\t\t\t>>>Número válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Número inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    printf("\n");
    printf("///            Cargo na Empresa:                                            ///\n");
    fgets(fun->cargo, sizeof(fun->cargo), stdin);
    limpaBuffer();
    if (!(validadorCargo(fun->cargo))){
        printf("\t\t\t>>>Cargo válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Cargo inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        sleep(1);
        exit(1);
    }
    fun->status = 'a';

    FILE* file;
    Funcionarios* funcionarios;
    file = fopen("fun.dat","a+b");
    funcionarios = fun;
    fwrite(funcionarios, sizeof(Funcionarios), 1, file);
    fclose(file);
    free(funcionarios);

    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar();
    return 0;

}

Funcionarios* pesquisar_funcionario(void) {
    FILE* fp;
    Funcionarios* funcionarios;
    char cpf_dig[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Funcionário = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do Funcionário:                                ///\n");
    scanf("%s", cpf_dig);
    limpaBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    funcionarios = (Funcionarios*) malloc(sizeof(Funcionarios));
    fp = fopen("fun.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }else{
        while(!feof(fp)) {
            fread(funcionarios, sizeof(Funcionarios), 1, fp);
            if (strcmp(funcionarios->cpf, cpf_dig)==0){
                exibe_funcionario(funcionarios);
                printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(fp);
                return funcionarios;
            }else{

            }
        }
    }
    fclose(fp);
    free(funcionarios);
    return NULL;

    

} 

void tela_alterar_funcionario(void) {
    FILE* fp;
    Funcionarios* funcionarios = (Funcionarios*) malloc(sizeof(Funcionarios));
    char cpf_dig[12];
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
    printf("///            = = = = = = = = Alterar Funcionario = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do Funcionario:                                ///\n");
    scanf("%s", cpf_dig);
    limpaBuffer();
    getchar();
    fp = fopen("fun.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (!feof(fp)) {
        fread(funcionarios, sizeof(Funcionarios), 1, fp) == 1;
        if(strcmp(funcionarios->cpf, cpf_dig) == 0) {
            printf("\n");
            printf("\t\t\t*** Cliente Encontrado ***\n");
            printf("\t\t\t*** Refaça o Cadastro ***\n");
            printf("\n");

            printf("///            Nome:                                                        ///\n");
            fgets(funcionarios->nome, sizeof(funcionarios->nome), stdin);
            limpaBuffer();
            if (!(validadorNome(funcionarios->nome))){
                printf("\t\t\t>>>Nome válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Nome inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                sleep(1);
                break;
            }
            printf("\n");
            printf("///            CPF:                                                         ///\n");
            fgets(funcionarios->cpf, sizeof(funcionarios->cpf), stdin);
            limpaBuffer();
            if (validadorCPF(funcionarios->cpf)){
                printf("\t\t\t>>>CPF válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>CPF inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                sleep(1);
                break;
            }
            printf("\n");
            printf("///            Data de Nascimento:                                          ///\n");
            printf("///            Dia:                                                         ///\n");
            scanf("%d", &funcionarios->dia);
            limpaBuffer();
            printf("///            Mês(em número):                                              ///\n");
            scanf("%d", &funcionarios->mes);
            limpaBuffer();
            printf("///            Ano:                                                         ///\n");
            scanf("%d", &funcionarios->ano);
            limpaBuffer();

            
            if (validadorData(funcionarios->dia, funcionarios->mes, funcionarios->ano)){
                printf("\t\t\t>>>Data de Nascimento válida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Data de Nascimento inválida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                sleep(1);
                break;
            }
            printf("///            Cidade:                                                      ///\n");
            fgets(funcionarios->cidade, sizeof(funcionarios->cidade), stdin);
            limpaBuffer();
            if (!(validadorCidade(funcionarios->cidade))){
                printf("\t\t\t>>>Cidade válida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Cidade inválida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                sleep(1);
                break;
            }
            printf("///            Endereço:                                                    ///\n");
            fgets(funcionarios->endereco, sizeof(funcionarios->endereco), stdin);
            limpaBuffer();
            printf("///            Telefone:                                                    ///\n");
            fgets(funcionarios->telefone, sizeof(funcionarios->telefone), stdin);
            limpaBuffer();
            if (!(validadorTelefone(funcionarios->telefone))){
                printf("\t\t\t>>>Número válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Número inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                sleep(1);
                break;
            }
            printf("\n");
            printf("///            Cargo na Empresa:                                            ///\n");
            fgets(funcionarios->cargo, sizeof(funcionarios->cargo), stdin);
            limpaBuffer();
            if (!(validadorCargo(funcionarios->cargo))){
                printf("\t\t\t>>>Cargo válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Cargo inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                sleep(1);
                break;
            }
            funcionarios->status = 'a';

            fseek(fp, -sizeof(Funcionarios), SEEK_CUR);
            fwrite(funcionarios, sizeof(Funcionarios), 1, fp);
            find = 1;
            break;
        }
      }
    }

    if (!find) {
        printf("\n");
        printf("\t\t\t CPF não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\t Funcionario atualizado com sucesso!\n");
    }
    printf("\n");
    sleep(1);
    getchar();
    fclose(fp);
    free(funcionarios);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void tela_excluir_funcionario(void) {
    FILE* fp;
    Funcionarios* funcionarios = (Funcionarios*) malloc(sizeof(Funcionarios));
    char cpf_dig[12];
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
    printf("///            = = = = = = = = Excluir Funcionário = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do Funcionário:                                ///\n");
    scanf("%s", cpf_dig);
    getchar();
    fp = fopen("fun.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(funcionarios, sizeof(Funcionarios), 1, fp) == 1) {
        if(strcmp(funcionarios->cpf, cpf_dig) == 0) {
          printf("\n");
          printf("\t\t\t*** Funcionario Encontrado ***\n");
          printf("\n");
          funcionarios->status = 'x';
          fseek(fp, -sizeof(Funcionarios), SEEK_CUR);
          fwrite(funcionarios, sizeof(Funcionarios), 1, fp);
          find = 1;
          break;
        }
      }
    }
    if (!find) {
        printf("\n");
        printf("\t\t\tCPF não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tFuncionario excluído com sucesso!\n");
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

void exibe_funcionario (Funcionarios* funcionarios) {

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
  if ((funcionarios == NULL) || (funcionarios->status == 'x')) {
      printf("\n Funcionário não encontrado!\n");
      printf("\n");
      printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
      getchar();
  } else {
      printf("\n*** Funcionário Cadastrado***\n");
      printf("\n");
      printf("*** Nome do Funcionário: ");
      printf("%s" ,funcionarios->nome);
      printf("\n");
      printf("*** CPF: ");
      printf("%s" ,funcionarios->cpf);
      printf("\n");
      printf("*** Cargo: ");
      printf("%s" ,funcionarios->cargo);
      printf("\n");
      printf("*** Endereco: ");
      printf("%s" ,funcionarios->endereco);
      printf("\n");
      printf("*** Cidade: ");
      printf("%s" ,funcionarios->cidade);
      printf("\n");
      printf("*** Telefone: ");
      printf("\n");
      printf("%s" ,funcionarios->telefone);
      printf("\n");
      printf("*** Data de Nascimento: ");
      printf("\n");
      printf("%d/%d/%d", funcionarios->dia, funcionarios->mes, funcionarios->ano);
      printf("\n");

    if (funcionarios->status == 'a') {
      strcpy(situacao, "Cadastrado Ativo");
    } else {
      strcpy(situacao, "Cadastro Inativo");
    }
    printf("Status do Funcionário: %s\n", situacao);
    printf("\n");
  }   
}