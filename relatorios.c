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
    char opcao;

    do {
        opcao = tela_relatorios();
        switch(opcao) {
            case '1':   tela_op_funcionario();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   tela_op_cliente();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   tela_op_veiculo();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '4':   tela_op_aluguel();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
          } 		
    } while (opcao != '0');
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
    printf("///              4- Relatório Aluguéis                                      ///\n");
    printf("///              0- Retornar ao Menu Principal                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Digite a opção escolhida:                                   ///\n");
    scanf("%c", &op);
    printf("\n");
    getchar();
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
    printf("///              1- Relatório por Completo                                  ///\n");
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
    char opcao;
    do {
        opcao = relatorioCliente();
        switch(opcao) {
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
    } while (opcao != '0');
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
    printf("%-12s","CPF");
        printf("|");
    printf("%-20s","Nome");
        printf("|");
    printf("%-12s","Telefone");
        printf("|");
    printf("%-30s","Endereco");
        printf("|");
    printf("%-20s","Cidade");
        printf("|");
    printf("%-11s","Data de Nascimento");
        printf("\n");
    while (fread(clientes, sizeof(Clientes), 1, fp)) { 
        if (clientes->status != 'i') {
                            printf("%-12s",clientes->cpf);
                            printf("|");
                            printf("%-20s",clientes->nome);
                            printf("|");
                            printf("%-12s",clientes->telefone);
                            printf("|");
                            printf("%-30s",clientes->endereco);
                            printf("|");
                            printf("%-20s",clientes->cidade);
                            printf("|");
                            printf("%d/%d/%d",clientes->dia,clientes->mes,clientes->ano);
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
    printf("%-20s", "Cidade");
    printf("|");
    printf("%-30s", "Endereco");
    printf("\n");
    while (fread(clientes, sizeof(Clientes), 1, fp)) { 
        if (clientes->status != 'i') {
            printf("%-20s", clientes->cidade);
            printf("|");
            printf("%-30s", clientes->endereco);
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
    while (fread(clientes, sizeof(Clientes), 1, fp)) { 
        if (clientes->status == 'i') {
            printf("%-12s", clientes->cpf);
            printf("|");
            printf("%-50s", clientes->nome);
            printf("|");
            printf("%-12i", clientes->status);
            printf("\n");
        }
    }
    fclose(fp);
    free(clientes);
    getchar();

}

void tela_op_funcionario(void){
    char opcao;

    do {
        opcao = relatorioFuncionario();
        switch(opcao) {
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
    } while (opcao != '0');
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
    printf("///              1- Relatório Completo                                      ///\n");
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
    printf("|");
    printf("%-12s", "Endereco");
    printf("|");
    printf("%-12s", "Cidade");
    printf("|");
    printf("%-11s", "Data de Nascimento");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(funcionarios, sizeof(Funcionarios), 1, fp)) { 
        if (funcionarios->status != 'i') {
            printf("%-12s", funcionarios->cpf);
            printf("|");
            printf("%-50s", funcionarios->nome);
            printf("|");
            printf("%-12s", funcionarios->telefone);
            printf("|");
            printf("%-12s", funcionarios->endereco);
            printf("|");
            printf("%-12s", funcionarios->cidade);
            printf("|");
            printf("%d/%d/%d", funcionarios->dia, funcionarios->mes, funcionarios->ano);
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
    while (fread(funcionarios, sizeof(Funcionarios), 1, fp)) { 
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
    while (fread(funcionarios, sizeof(Funcionarios), 1, fp)) { 
        if (funcionarios->status == 'i') {
            printf("%-12s", funcionarios->cpf);
            printf("|");
            printf("%-50s", funcionarios->nome);
            printf("|");
            printf("%-12i", funcionarios->status);
            printf("\n");
        }
    }
    fclose(fp);
    free(funcionarios);
    getchar();

}

char relatorioVeiculo(void){
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
    printf("///            = = = = = = = Relatórios de Veiculos = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///              1- Relatório Completo                                      ///\n");
    printf("///              2- Relatório por Valor da diária e Placa                   ///\n");
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

void tela_op_veiculo(void){
    char opcao;

    do {
        opcao = relatorioVeiculo();
        switch(opcao) {
            case '1':   listaVeiculo();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        
            case '2':   listaVeiculoDiaria();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        
            case '3':   listaVeiculoStatus('i');
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
          } 		
    } while (opcao != '0');
}


void listaVeiculoStatus(char status){
    FILE* fp;
    Veiculos* veiculos;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Veiculos = = = =  =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    getchar();
    veiculos = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("vei.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-50s", "Modelo");
    printf("|");
    printf("%-8s", "Placa");
    printf("|");
    printf("%-5s", "Ano");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(veiculos, sizeof(Veiculos), 1, fp)) { 
        if (veiculos->status == 'i') {
            printf("%-50s", veiculos->modelo);
            printf("|");
            printf("%-8s", veiculos->placa);
            printf("|");
            printf("%-12i", veiculos->ano);
            printf("\n");
        }
    }
    fclose(fp);
    free(veiculos);
    getchar();

}

void listaVeiculoDiaria(void){

    FILE* fp;
    Veiculos* veiculos;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Veiculos = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    veiculos = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("vei.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-8s", "Valor da diaria");
    printf("|");
    printf("%-9s", "Placa");
    printf("|");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(veiculos, sizeof(Veiculos), 1, fp)) { 
        if (veiculos->status != 'i') {
            printf("%-8i", veiculos->diaria);
            printf("|");
            printf("%-9s", veiculos->placa);
            printf("\n");
            
        }
    }
    fclose(fp);
    free(veiculos);
    getchar();
}

void listaVeiculo(void){
    
    FILE* fp;
    Veiculos* veiculos;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Veiculos = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    veiculos = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("vei.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-50s", "Modelo");
    printf("|");
    printf("%-50s", "Marca");
    printf("|");
    printf("%-8s", "Placa");
    printf("|");
    printf("%-17s", "Chassi");
    printf("|");
    printf("%-12s", "Estado de Conservação");
    printf("|");
    printf("%-12s", "Diária");
    printf("|");
    printf("%-4s", "Ano");
    printf("\n");
    while (fread(veiculos, sizeof(Veiculos), 1, fp)) { 
        if (veiculos->status != 'i') {
            printf("%-50s", veiculos->modelo);
            printf("|");
            printf("%-50s", veiculos->fabricante);
            printf("|");
            printf("%-8s", veiculos->placa);
            printf("|");
            printf("%-17s", veiculos->chassi);
            printf("|");
            printf("%-21s", veiculos->estado_c);
            printf("|");
            printf("%-11i", veiculos->diaria);
            printf("|");
            printf("%-5i", veiculos->ano);
            printf("\n");
        }
    }
    fclose(fp);
    free(veiculos);
    getchar();
}

void tela_op_aluguel(void)
{
    char opcao;

    do
    {
        opcao = relatorioAluguel();
        switch (opcao)
        {
        case '1':
            listaAluguel();
            printf("\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        case '2':
            listaAluguelData();
            printf("\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }
    } while (opcao != '0');
}

char relatorioAluguel(void)
{
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
    printf("///            = = = = = = = Relatórios de Aluguéis = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///              1- Relatório Completo                                      ///\n");
    printf("///              2- Relatório por Data de Início, Fim e Placa               ///\n");
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

void listaAluguel(void)
{

    FILE *fp;
    Aluguel *aluguel;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Aluguéis = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    aluguel = (Aluguel *)malloc(sizeof(Aluguel));
    fp = fopen("alg.dat", "rb");
    if (fp == NULL)
    {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-50s", "CPF do Cliente");
    printf("|");
    printf("%-51s", "CPF do Funcionario");
    printf("|");
    printf("%-12s", "Placa");
    printf("|");
    printf("%-8s", "Data de Início: ");
    printf("|");
    printf("%-8s", "Data de Fim: ");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(aluguel, sizeof(Aluguel), 1, fp))
    {
        if (aluguel->status != 'i')
        {
            printf("%-50s", aluguel->cpf_c);
            printf("|");
            printf("%-50s", aluguel->cpf_f);
            printf("|");
            printf("%-8s", aluguel->placa);
            printf("|");
            printf("%d/%d/%d", aluguel->dia_i, aluguel->mes_i, aluguel->ano_i);
            printf("|");
            printf("%d/%d/%d", aluguel->dia_f, aluguel->mes_f, aluguel->ano_f);
            printf("\n");
        }
    }
    fclose(fp);
    free(aluguel);
    getchar();
}

void listaAluguelData(void){

    FILE* fp;
    Aluguel* aluguel;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Aluguéis = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    fp = fopen("alg.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-8s", "Data de Início");
    printf("|");
    printf("%-9s", "Data de Fim");
    printf("|");
    printf("%-9s", "Placa");
    printf("|");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(aluguel, sizeof(Aluguel), 1, fp)) { 
        if (aluguel->status != 'i') {
            printf("%d/%d/%d", aluguel->dia_i, aluguel->mes_i, aluguel->ano_i);
            printf("|");
            printf("%d/%d/%d", aluguel->dia_f, aluguel->mes_f, aluguel->ano_f);
            printf("|");
            printf("%-8s", aluguel->placa);
            printf("\n");
            
        }
    }
    fclose(fp);
    free(aluguel);
    getchar();
}

void listaAluguelStatus(char status){
    FILE* fp;
    Aluguel* aluguel;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Relatórios de Aluguéis = = = =  =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("\n");
    getchar();
    aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    fp = fopen("alg.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    printf("%-50s", "CPF do Cliente");
    printf("|");
    printf("%-8s", "Placa");
    printf("\n");
    printf("%13s", "|");
    printf("%51s", "|");
    printf("\n");
    while (fread(aluguel, sizeof(Aluguel), 1, fp)) { 
        if (aluguel->status == 'i') {
            printf("%-50s", aluguel->cpf_c);
            printf("|");
            printf("%-8s", aluguel->placa);
            printf("\n");
        }
    }
    fclose(fp);
    free(aluguel);
    getchar();

}