#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"
#include "util.h"

void tela_menu_cliente(void){
    Clientes* cli;
    char op;
    do{
        op = menu_cliente();
        switch(op){
            case '1': 	cli = cadastrar_cliente();
                break;
            case '2': 	tela_pesquisar_cliente();
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
    if (validadorCidade(cli->cidade)){
        printf("\t\t\t>>>Cidade válida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }else{
        printf("\t\t\t>>>Cidade inválida<<<\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
    printf("///            Endereço:                                                    ///\n");
    fgets(cli->endereco, sizeof(cli->endereco), stdin);
    printf("///            Telefone:                                                    ///\n");
    fgets(cli->telefone, sizeof(cli->telefone), stdin);
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
    printf("///            Mês(em número):                                              ///\n");
    scanf("%d", &cli->mes);
    printf("///            Ano:                                                         ///\n");
    scanf("%d", &cli->ano);
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

void tela_pesquisar_cliente(void) {
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_alterar_cliente(void) {
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_excluir_cliente(void) {
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
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}