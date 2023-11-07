#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "clientes.h"
#include "util.h"

void tela_menu_cliente(void){
    char op;
    do{
        op = menu_cliente();
        switch(op){
            case '1': 	cadastrar_cliente();
                break;
            case '2': 	pesquisar_cliente();
                break;
            case '3': 	tela_alterar_cliente();
                break;
            case '4': 	tela_excluir_cliente();
                break;
        }
    }while (op != '0');
}

char menu_cliente(void) {
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
    printf("///            = = = = = = = = =  Menu Cliente = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo Cliente                                 ///\n");
    printf("///            2. Pesquisar os dados de um Cliente                          ///\n");
    printf("///            3. Atualizar o cadastro de um Cliente                        ///\n");
    printf("///            4. Excluir um Cliente do sistema                             ///\n");
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

Clientes* cadastrar_cliente(void) {
    Clientes* cli;
    cli = (Clientes*) malloc(sizeof(Clientes));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome:                                                        ///\n");
    fgets(cli->nome, sizeof(cli->nome), stdin);
    limpaBuffer();
    if (!(validadorNome(cli->nome))){
        printf("\t\t\t>>>Nome válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Nome inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("\n");
    printf("///            CPF(apenas números):                                                         ///\n");
    fgets(cli->cpf, sizeof(cli->cpf), stdin);
    limpaBuffer();
    if (validadorCPF(cli->cpf)){
        printf("\t\t\t>>>CPF válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("\n");
    printf("///            Cidade:                                                      ///\n");
    fgets(cli->cidade, sizeof(cli->cidade), stdin);
    limpaBuffer();
    if (validadorCidade(cli->cidade)){
        printf("\t\t\t>>>Cidade válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Cidade inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Endereço:                                                    ///\n");
    fgets(cli->endereco, sizeof(cli->endereco), stdin);
    limpaBuffer();
    printf("///            Telefone:                                                    ///\n");
    fgets(cli->telefone, sizeof(cli->telefone), stdin);
    limpaBuffer();
    if (validadorTelefone(cli->telefone)){
        printf("\t\t\t>>>Número válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Número inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("\n");
    printf("///            Data de Nascimento:                                          ///\n");
    printf("///            Dia:                                                         ///\n");
    scanf("%d", &cli->dia);
    limpaBuffer();
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &cli->mes);
    limpaBuffer();
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &cli->ano);
    limpaBuffer();
    cli->status = 'a';
    
    if (validadorData(cli->dia, cli->mes, cli->ano)){
        printf("\t\t\t>>>Data de Nascimento válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Data de Nascimento inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    FILE* file;
    Clientes* cliente;
    cliente = cli;
    file = fopen("cli.dat","wb");
    fwrite(cliente, sizeof(Clientes), 1, file);
    fclose(file);
    free(cliente);
    
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}

Clientes* pesquisar_cliente(void) {
    FILE* fp;
    Clientes* clientes;
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
    printf("///            = = = = = = = = Pesquisar Cliente = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do Cliente:                                    ///\n");
    scanf("%s", cpf_dig);
    limpaBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    clientes = (Clientes*) malloc(sizeof(Clientes));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }else{
        while(!feof(fp)) {
            fread(clientes, sizeof(Clientes), 1, fp);
            if (strcmp(clientes->cpf, cpf_dig)==0){
                exibe_cliente(clientes);
                printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(fp);
                return clientes;
            }else{

            }
        }
    }
    fclose(fp);
    return NULL;

}

void tela_alterar_cliente(void) {
    char cpf_dig[12];
    Clientes* clientes = (Clientes*) malloc(sizeof(Clientes));
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
    printf("///            = = = = = = = = Alterar Cliente = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do Cliente:                                    ///\n");
    scanf("%s", cpf_dig);
    limpaBuffer();
    getchar();
    fp = fopen("cli.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(clientes, sizeof(Clientes), 1, fp) == 1) {
        if(strcmp(clientes->cpf, cpf_dig) == 0) {
            printf("\n");
            printf("\t\t\t*** Cliente Encontrado ***\n");
            printf("\t\t\t*** Refaça o Cadastro ***\n");
            printf("\n");

            printf("///            Nome:                                                        ///\n");
            fgets(clientes->nome, sizeof(clientes->nome), stdin);
            limpaBuffer();
            if (!(validadorNome(clientes->nome))){
                printf("\t\t\t>>>Nome válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Nome inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                break;
            }
            printf("\n");
            printf("///            CPF(apenas números):                                                         ///\n");
            fgets(clientes->cpf, sizeof(clientes->cpf), stdin);
            limpaBuffer();
            if (validadorCPF(clientes->cpf)){
                printf("\t\t\t>>>CPF válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>CPF inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                break;
            }
            printf("\n");
            printf("///            Cidade:                                                      ///\n");
            fgets(clientes->cidade, sizeof(clientes->cidade), stdin);
            limpaBuffer();
            if (!validadorCidade(clientes->cidade)){
                printf("\t\t\t>>>Cidade válida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Cidade inválida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                break;
            }
            printf("///            Endereço:                                                    ///\n");
            fgets(clientes->endereco, sizeof(clientes->endereco), stdin);
            limpaBuffer();
            printf("///            Telefone:                                                    ///\n");
            fgets(clientes->telefone, sizeof(clientes->telefone), stdin);
            limpaBuffer();
            if (validadorTelefone(clientes->telefone)){
                printf("\t\t\t>>>Número válido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Número inválido<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                break;
            }
            printf("\n");
            printf("///            Data de Nascimento:                                          ///\n");
            printf("///            Dia:                                                         ///\n");
            scanf("%d", &clientes->dia);
            limpaBuffer();
            printf("///            Mês(em número):                                              ///\n");
            scanf("%d", &clientes->mes);
            limpaBuffer();
            printf("///            Ano:                                                         ///\n");
            scanf("%d", &clientes->ano);
            limpaBuffer();
            clientes->status = 'a';
            
            if (validadorData(clientes->dia, clientes->mes, clientes->ano)){
                printf("\t\t\t>>>Data de Nascimento válida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            }else{
                printf("\t\t\t>>>Data de Nascimento inválida<<<\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                break;
            }

            fseek(fp, -sizeof(Clientes), SEEK_CUR);
            fwrite(clientes, sizeof(Clientes), 1, fp);
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
        printf("\t\t\t Cliente atualizado com sucesso!\n");
    }

    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");

}

void tela_excluir_cliente(void) {
    char cpf_dig[12];
    Clientes* clientes = (Clientes*) malloc(sizeof(Clientes));
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
    printf("///            = = = = = = = = Excluir Cliente = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do Cliente:                                    ///\n");
    scanf("%s", cpf_dig);
    getchar();
    fp = fopen("cli.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Ops! Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Não é possível continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(clientes, sizeof(Clientes), 1, fp) == 1) {
        if(strcmp(clientes->cpf, cpf_dig) == 0) {
          printf("\n");
          printf("\t\t\t*** Cliente Encontrado ***\n");
          printf("\n");
          clientes->status = 'x';
          fseek(fp, -sizeof(Clientes), SEEK_CUR);
          fwrite(clientes, sizeof(Clientes), 1, fp);
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
        printf("\t\t\tCliente excluído com sucesso!\n");
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


void exibe_cliente (Clientes* clientes) {

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
  if ((clientes == NULL) || (clientes->status == 'x')) {
      printf("\n Cliente não encontrado!\n");
      printf("\n");
      printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
      getchar();
  } else {
      printf("\n*** Cliente Cadastrado***\n");
      printf("\n");
      printf("*** Nome do Cliente: ");
      printf("%s" ,clientes->nome);
      printf("\n");
      printf("*** CPF: ");
      printf("%s" ,clientes->cpf);
      printf("\n");
      printf("*** Endereco: ");
      printf("%s" ,clientes->endereco);
      printf("\n");
      printf("*** Cidade: ");
      printf("%s" ,clientes->cidade);
      printf("\n");
      printf("*** Telefone: ");
      printf("\n");
      printf("%s" ,clientes->telefone);
      printf("\n");
      printf("*** Data de Nascimento: ");
      printf("\n");
      printf("%d/%d/%d", clientes->dia, clientes->mes, clientes->ano);
    if (clientes->status == 'a') {
      strcpy(situacao, "Cadastrado Ativo");
    } else {
      strcpy(situacao, "Cadastro Inativo");
    }
    printf("Status do cliente: %s\n", situacao);
    printf("\n");
  }   
}