#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "relatorios.h"
#include "clientes.h"
#include "veiculos.h"
#include "funcionarios.h"
#include "aluguel.h"
#include "util.h"
//RELATORIOS

void tela_relatorios(void){
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
    //Baseado no código da colega Sayonara Rayanne
    FILE* fp;
    Clientes* cli;
    printf("///           Relatório de Clientes:                                        ///\n");
    printf("///                                                                         ///\n");
    cli = (Clientes*) malloc(sizeof(Clientes));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
        printf("erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(fread(cli, sizeof(Clientes), 1, fp)) {
        if (cli->status != 'x') {
        printf("--------------------- \n");
        printf("CLIENTES CADASTRADOS: \n");
        printf("---------------------\n");
        printf("CPF: %s\n", cli->cpf);
        printf("Nome do cliente: %s\n", cli->nome);
        printf("Cidade: %s\n", cli->cidade);
        printf("Telefone: %s\n", cli->telefone);
        printf("Endereco: %s\n", cli->endereco);
        printf("Data de Nascimento: %d/%d/%d\n", cli->dia, cli-> mes, cli->ano);
        
        }
    }
    fclose(fp);
    free(cli);

    FILE* ap;
    Funcionarios* fun;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           Relatório de Funcionários:                                    ///\n");
    printf("///                                                                         ///\n");
    fun = (Funcionarios*) malloc(sizeof(Funcionarios));
    ap = fopen("fun.dat", "rb");
    if (ap == NULL) {
        printf("erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(fread(fun, sizeof(Funcionarios), 1, ap)) {
        if (fun->status != 'x') {
        printf("--------------------- \n");
        printf("Funcionarios Cadastrados: \n");
        printf("---------------------\n");
        printf("CPF: %s\n", fun->cpf);
        printf("Nome do cliente: %s\n", fun->nome);
        printf("Cidade: %s\n", fun->cidade);
        printf("Telefone: %s\n", fun->telefone);
        printf("Endereco: %s\n", fun->endereco);
        printf("Cargo: %s\n", fun->cargo);
        printf("Data de Nascimento: %d/%d/%d\n", fun->dia, fun-> mes, fun->ano);
        }
    }
    fclose(ap);
    free(fun);

    FILE* bp;
    Veiculos* vei;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           Relatório de Veículos:                                        ///\n");
    printf("///                                                                         ///\n");
    vei = (Veiculos*) malloc(sizeof(Veiculos));
    bp = fopen("vei.dat", "rb");
    if (bp == NULL) {
        printf("erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(fread(vei, sizeof(Veiculos), 1, bp)) {
        if (vei->status != 'x') {
        printf("--------------------- \n");
        printf("Veiculos Cadastrados: \n");
        printf("---------------------\n");
        printf("Modelo: %s\n", vei->modelo);
        printf("Fabricante: %s\n", vei->fabricante);
        printf("Placa: %s\n", vei->placa);
        printf("Chassi: %s\n", vei->chassi);
        printf("Estado: %s\n", vei->estado_c);
        printf("Data: %d\n", vei->ano);
        printf("Valor da Diária: %d\n", vei->diaria);
        }
    }
    fclose(bp);
    free(vei);

    FILE* cp;
    Aluguel* alg;

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           Relatório de Aluguéis:                                        ///\n");
    printf("///                                                                         ///\n");
    alg = (Aluguel*) malloc(sizeof(Aluguel));
    cp = fopen("alg.dat", "rb");
    if (cp == NULL) {
        printf("erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(fread(alg, sizeof(Aluguel), 1, cp)) {
        if (alg->status != 'x') {
        printf("--------------------- \n");
        printf("Alugueis Cadastrados: \n");
        printf("--------------------- \n");
        printf("CPF do Funcionário: %s\n", alg->cpf_f);
        printf("CPF do Cliente: %s\n", alg->cpf_c);
        printf("Placa: %s\n", alg->placa);
        printf("Data de Início do Aluguel: %d/%d/%d\n", alg->dia_i, alg-> mes_i, alg->ano_i);
        printf("Data de Fim do Aluguel: %d/%d/%d\n", alg->dia_f, alg-> mes_f, alg->ano_f);
        }
    }
    fclose(cp);
    free(alg);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}