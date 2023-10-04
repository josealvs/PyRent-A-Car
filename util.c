#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////Referências: Função baseada em @flgorgonio e IA Chat gpt
int validadorNome(char* nome) { 

    for (int i = 0; nome[i] != '\0'; i++) {


        if (!isalpha(nome[i]) && nome[i] != ' ') {


            return 0;
        }
    }
    return 1;
}

////Referências: Função baseada em @flgorgonio e IA Chat gpt
int validadorTelefone(char* telefone) {

    for (int i = 0; telefone[i] != '\0'; i++) {


        if (!isdigit(telefone[i])) {

            return 0;
        }
    }
    int tam = strlen(telefone);


    if (tam != 11) {


        return 0;
    }
    return 1;
}

////Referências: Função baseada em @flgorgonio e IA Chat gpt
int validadorCPF(char* cpf) {

    int i, j;

    int digito1 = 0, digito2 = 0;

    for (int i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit(cpf[i])) {
            return 0;


        }
    }
    int tam = strlen(cpf); 
    if (tam != 11) {
        return 0;

    }

    //Referências: Função feita com ajuda do colega Gabriel Araújo. 


    for (i = 0, j = 10; i < 9; i++, j--) { 

        digito1 += (cpf[i] - '0') * j;

    }
        digito1 = 11 - (digito1 % 11);

        if (digito1 > 9) {


            digito1 = 0;
    }


    for (i = 0, j = 11; i < 10; i++, j--) {

        digito2 += (cpf[i] - '0') * j;



    }

    digito2 = 11 - (digito2 % 11);



    if (digito2 > 9) {

        digito2 = 0;
    }

    if (digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0')) {
        return 0;


    } else {

        return 1;

    }
}


////Referências: Função baseada em @flgorgonio e IA Chat gpt

int ano_bissexto(int ano) {
  if ((ano % 4 == 0) && (ano % 100 != 0)) {
    return 1;
  } else if (ano % 400 == 0) {
    return 1;
  } else {
    return 0;
  } 
}


////Referências: Função baseada em @flgorgonio e IA Chat gpt

int validadorData(int dia, int mes, int ano) {


  int ultimo_dia;
  if (ano < 0 || mes < 1 || mes > 12)

    return 0;

  if (mes == 2) {

    if (ano_bissexto(ano)) 


      ultimo_dia = 29;
    else
      ultimo_dia = 28;
  } else if (mes == 4 || mes == 6 || 
             mes == 9 || mes == 11) {

               ultimo_dia = 30;
  } else
    ultimo_dia = 31;

  if (dia < 1 || dia > ultimo_dia)

    return 0;
  return 1;
}
//Inspirado no validador Nome
int validadorModelo(char* modelo) { 

    for (int i = 0; modelo[i] != '\0'; i++) {


        if (!isalpha(modelo[i]) && modelo[i] != ' ') {


            return 0;
        }
    }
    return 1;
}
//Validador Fabricante, inspirado em nome e modelo
int validadorFabricante(char* fabricante) { 

    for (int i = 0; fabricante[i] != '\0'; i++) {


        if (!isalpha(fabricante[i]) && fabricante[i] != ' ') {


            return 0;
        }
    }
    return 1;
}
//validador da Placa no formato da Placa Mercosul "AAA1B23"
//feito com auxílio do chatgpt
int validadorPlaca(char* placa) {
    // Verificar o comprimento da placa
    int len = strlen(placa);
    if (len != 7) {
        return 0;
    }
https://github.com/josealvs/PyRent-A-Car.git
    // Verificar o formato da placa
    for (int i = 0; i < len; i++) {
        if (i < 3 || i == 4) {
            if (!isupper(placa[i])) {
                return 0;
            }
        } else if (i == 3) {
            if (!isdigit(placa[i])) {
                return 0;
            }
        } else {
            if (!isdigit(placa[i])) {
                return 0;
            }
        }
    }

    return 1;
}

//Validador de Chassi genérico, dentro doa padrões Brasileiros de Chassi
//os padroes e regras variam entre fabricante e montadora, por isso o "genérico"
//Criado com base no validadorPlaca
int validadorChassi(char* chassi) {
    // Verificar o comprimento do chassi (deve ter 17 caracteres)
    int len = strlen(chassi);
    if (len != 17) {
        return 0;
    }

    // Verificar se os caracteres são alfanuméricos
    for (int i = 0; i < len; i++) {
        if (!isalnum(chassi[i])) {
            return 0;
        }
    }

    return 1;
}

//valida se o valor digitado é menor que zero
int validadorDiaria(int diaria){
    if (diaria < 0){
        return 0;
    }

    return 1;
}

// valida se possui número na digitação
int validadorConservacao(char* estado_c){
    int i;
    for(i=0; i < strlen(estado_c); i++){
        if(isdigit(estado_c[i])){
            return 0;
        }

        
    }
    return 1;
}