#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
            case '2': 	tela_pesquisar_funcionario();
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
    }
    printf("///            Cidade:                                                      ///\n");
    fgets(fun->cidade, sizeof(fun->cidade), stdin);
    limpaBuffer();
    if (validadorCidade(fun->cidade)){
        printf("\t\t\t>>>Cidade válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Cidade inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Endereço:                                                    ///\n");
    fgets(fun->endereco, sizeof(fun->endereco), stdin);
    limpaBuffer();
    printf("///            Telefone:                                                    ///\n");
    fgets(fun->telefone, sizeof(fun->telefone), stdin);
    limpaBuffer();
    if (validadorTelefone(fun->telefone)){
        printf("\t\t\t>>>Número válido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Número inválido<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
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
    }
    fun->status = 'a';

    FILE* file;
    Funcionarios* funcionarios;
    file = fopen("fun.dat","wb");
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

void tela_pesquisar_funcionario(void) {
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void tela_alterar_funcionario(void) {
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
    printf("///            Informe o CPF do Cliente:                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void tela_excluir_funcionario(void) {
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}