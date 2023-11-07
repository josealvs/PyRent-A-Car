#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "veiculos.h" 
#include "funcionarios.h"
#include "aluguel.h"
#include "clientes.h"
#include "relatorios.h"
#include "sobre.h"
#include "equipe.h"

//Código feito com base em: https://github.com/FlaviusGorgonio/LinguaSolta
// Assinatura das funções
void tela_menu_principal(void);
char menu_principal(void);


// Programa principal
int main(void) {
    char op;
 
    do{
        op = menu_principal();
        switch(op) {
            case '1': tela_menu_veiculo();
                break;
            case '2': tela_menu_cliente();
                break;
            case '3': tela_menu_funcionario();
                break;
            case '4': tela_menu_aluguel();
                break;
            case '5': tela_relatorios();
                break;
            case '6': tela_sobre();
                break;
            case '7':tela_equipe();
        }
    } while (op != '0');

    return 0;
}

// Funções 

char menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Developed by @josealvs -- since Ago, 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     = = = = = PyRent-A-Car = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Veículo                                                   ///\n");
    printf("///            2. Clientes                                                  ///\n");
    printf("///            3. Funcionários                                              ///\n");
    printf("///            4. Aluguéis                                                  ///\n");
    printf("///            5. Relatórios                                                ///\n");
    printf("///            6. Sobre                                                     ///\n");
    printf("///            7. Equipe                                                    ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;

}


//VEÍCULOS


//CLIENTES


//Funcionários



//ALUGUÉIS 
