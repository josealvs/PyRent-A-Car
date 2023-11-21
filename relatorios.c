#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>
#include "relatorios.h"
#include "clientes.h"
#include "veiculos.h"
#include "funcionarios.h"
#include "aluguel.h"
#include "util.h"
//RELATORIOS


void menuRelatorio(void){
    char op;

    do {
        op = tela_relatorios();
        switch(op) {
            case '1':   relatorioFuncionario();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   relatorioCliente();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   ;
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '4':   ;
                        break;
          } 		
    } while (op != '0');
}
char tela_relatorios(void){
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
    printf("///            = = = = = = = =  = = Relatórios = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///              1- Relatório Funcionários                                  ///\n");
    printf("///              2- Relatório Clientes                                      ///\n");
    printf("///              3- Relatório Veículos                                      ///\n");
    printf("///              4- Relatório Vendas                                        ///\n");
    printf("///              0- Retornar ao Menu Principal                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Digite a opção escolhida:                                   ///\n");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

char relatorioCliente(void){
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
    printf("///            = = = = = = = Relatórios de Clientes = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///              1- Relatório por Nome, CPF e Telefone                      ///\n");
    printf("///              2- Relatório por Endereço e Cidade                         ///\n");
    printf("///              3- Relatório por Status de Inativo                         ///\n");
    printf("///              0- Retornar ao Menu Principal                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Digite a opção escolhida:                                   ///\n");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void tela_op_cliente(void){
    char op;
    do {
        op = relatorioCliente();
        switch(op) {
            case '1':   listaCliente();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   listaClienteBairro();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   listaClienteStatus('i');
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
          } 		
    } while (op != '0');
}

void listaCliente(void){

    FILE* fp;
    Clientes* clientes;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Clientes = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    clientes = (Clientes*) malloc(sizeof(Clientes));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-12s", "CPF");
    printf("|");
    printf("%-51s", "Nome");
    printf("|");
    printf("%-12s", "Telefone");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(clientes, sizeof(clientes), 1, fp)) { 
        if (clientes->status != 'i') {
            printf("%-12s", clientes->cpf);
            printf("|");
            printf("%-50s", clientes->nome);
            printf("|");
            printf("%-12s", clientes->telefone);
            printf("\n");
        }
    }
    fclose(fp);
    free(clientes);
    getchar();
 }
void listaClienteBairro(void){

    FILE* fp;
    Clientes* clientes;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Clientes = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    clientes = (Clientes*) malloc(sizeof(Clientes));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-12s", "Cidade");
    printf("|");
    printf("%-51s", "Endereco");
    printf("|");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(clientes, sizeof(clientes), 1, fp)) { 
        if (clientes->status != 'i') {
            printf("%-12s", clientes->cidade);
            printf("|");
            printf("%-50s", clientes->endereco);
            printf("\n");
            
        }
    }
    fclose(fp);
    free(clientes);
    getchar();
}

void listaClienteStatus(char status){
    FILE* fp;
    Clientes* clientes;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Clientes = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    getchar();
    clientes = (Clientes*) malloc(sizeof(Clientes));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-12s", "CPF");
    printf("|");
    printf("%-51s", "Nome");
    printf("|");
    printf("%-12s", "Status");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(clientes, sizeof(clientes), 1, fp)) { 
        if (clientes->status == 'i') {
            printf("%-12s", clientes->cpf);
            printf("|");
            printf("%-50s", clientes->nome);
            printf("|");
            printf("%-12s", clientes->status);
            printf("\n");
        }
    }
    fclose(fp);
    free(clientes);
    getchar();

}

void tela_op_funcionario(void){
    char op;

    do {
        op = relatorioFuncionario();
        switch(op) {
            case '1':   listaFuncionario();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   listaFuncionarioBairro();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   listaFuncionarioStatus('i');
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
          } 		
    } while (op != '0');
}

char relatorioFuncionario(void){
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
    printf("///            = = = = = = = Relatórios de Funcionarios = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///              1- Relatório por Nome, CPF e Telefone                      ///\n");
    printf("///              2- Relatório por Endereço e Cidade                         ///\n");
    printf("///              3- Relatório por Status de Inativo                         ///\n");
    printf("///              0- Retornar ao Menu Principal                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Digite a opção escolhida:                                   ///\n");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void listaFuncionario(void){
    
    FILE* fp;
    Funcionarios* funcionarios;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Funcionarios = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    funcionarios = (Funcionarios*) malloc(sizeof(Funcionarios));
    fp = fopen("fun.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-12s", "CPF");
    printf("|");
    printf("%-51s", "Nome");
    printf("|");
    printf("%-12s", "Telefone");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(funcionarios, sizeof(funcionarios), 1, fp)) { 
        if (funcionarios->status != 'i') {
            printf("%-12s", funcionarios->cpf);
            printf("|");
            printf("%-50s", funcionarios->nome);
            printf("|");
            printf("%-12s", funcionarios->telefone);
            printf("\n");
        }
    }
    fclose(fp);
    free(funcionarios);
    getchar();
}

void listaFuncionarioBairro(void){

    FILE* fp;
    Funcionarios* funcionarios;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Funcionarios = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    funcionarios = (Funcionarios*) malloc(sizeof(Funcionarios));
    fp = fopen("fun.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-12s", "Cidade");
    printf("|");
    printf("%-51s", "Endereco");
    printf("|");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(funcionarios, sizeof(funcionarios), 1, fp)) { 
        if (funcionarios->status != 'i') {
            printf("%-12s", funcionarios->cidade);
            printf("|");
            printf("%-50s", funcionarios->endereco);
            printf("\n");
            
        }
    }
    fclose(fp);
    free(funcionarios);
    getchar();
}

void listaFuncionarioStatus(char status){
    FILE* fp;
    Funcionarios* funcionarios;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Funcionarios = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    getchar();
    funcionarios = (Funcionarios*) malloc(sizeof(Funcionarios));
    fp = fopen("fun.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-12s", "CPF");
    printf("|");
    printf("%-51s", "Nome");
    printf("|");
    printf("%-12s", "Status");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(funcionarios, sizeof(funcionarios), 1, fp)) { 
        if (funcionarios->status == 'i') {
            printf("%-12s", funcionarios->cpf);
            printf("|");
            printf("%-50s", funcionarios->nome);
            printf("|");
            printf("%-12s", funcionarios->status);
            printf("\n");
        }
    }
    fclose(fp);
    free(funcionarios);
    getchar();

}