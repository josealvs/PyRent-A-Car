#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
            case '2': 	tela_pesquisar_aluguel();
                break;
            case '3': 	tela_alterar_aluguel();
                break;
            case '4': 	tela_excluir_aluguel();
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
    printf("///            3. Atualizar o cadastro de um Aluguel                        ///\n");
    printf("///            4. Excluir um Aluguel do sistema                             ///\n");
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
    printf("///            CPF do Cliente:                                              ///\n");
    fgets(alg->cpf_c, sizeof(alg->cpf_c), stdin);
    if (validadorCPF(alg->cpf_c)){
        printf("\t\t\t>>>CPF válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            CPF do Funcionario:                                          ///\n");
    fgets(alg->cpf_f, sizeof(alg->cpf_f), stdin);
    if (validadorCPF(alg->cpf_f)){
        printf("\t\t\t>>>CPF válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>CPF inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Placa do Veículo:                                            ///\n");
    fgets(alg->placa, sizeof(alg->placa), stdin);
    if (validadorPlaca(alg->placa)){
        printf("\t\t\t>>>Placa válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Placa inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Data de Início do Aluguel:                                   ///\n");
    printf("///            Dia:                                                         ///\n");
    scanf("%d", &alg->dia_i);   
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &alg->mes_i);   
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &alg->ano_i);   

    
    if (validadorData(alg->dia_i, alg->mes_i, alg->ano_i)){
        printf("\t\t\t>>>Data de Início válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Data de Início inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Data de Fim do Aluguel:                                      ///\n");
    printf("///            Dia:                                                         ///\n");
    scanf("%d", &alg->dia_f);   
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &alg->mes_f);   
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &alg->ano_f);   

    
    if (validadorData(alg->dia_f,alg->mes_f, alg->ano_f)){
        printf("\t\t\t>>>Data Final válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Data Final inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    
    alg->status = 'a';

    FILE* file;
    Aluguel* aluguel;
    file = fopen("alg.dat","wb");
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

}

void tela_pesquisar_aluguel(void) {
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void tela_alterar_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Aluguel = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Código do Aluguel:                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void tela_excluir_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Aluguel = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Código do Aluguel:                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}