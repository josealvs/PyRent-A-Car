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
int len = strlen(cpf);
    
    if (len != 11) {
        return 0; 
    }

    // Verificar se todos os caracteres são dígitos numéricos
    for (int i = 0; i < len; i++) {
        if (!isdigit(cpf[i])) {
            return 0; 
        }
    }

    //Converte os dígitos do CPF em números inteiros
    int numerosCPF[11];
    for (int i = 0; i < len; i++) {
        numerosCPF[i] = cpf[i] - '0';
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += numerosCPF[i] * (10 - i);
    }
    int primeiroDigito = 11 - (soma % 11);

    if (primeiroDigito == 10 || primeiroDigito == 11) {
        primeiroDigito = 0;
    }

    // Verifica o primeiro dígito verificador
    if (primeiroDigito != numerosCPF[9]) {
        return 0; 
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += numerosCPF[i] * (11 - i);
    }
    int segundoDigito = 11 - (soma % 11);

    if (segundoDigito == 10 || segundoDigito == 11) {
        segundoDigito = 0;
    }

    // Verifica o segundo dígito verificador
    if (segundoDigito != numerosCPF[10]) {
        return 0; 
    }

    return 1; // CPF válido
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

int validadorCargo(char* cargo) { 

    for (int i = 0; cargo[i] != '\0'; i++) {


        if (!isalpha(cargo[i]) && cargo[i] != ' ') {


            return 0;
        }
    }
    return 1;
}

int validadorCidade(char* cidade) { 

    for (int i = 0; cidade[i] != '\0'; i++) {


        if (!isalpha(cidade[i]) && cidade[i] != ' ') {


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

//Valida o ano do carro
int validadorAno(int ano){
    if (ano < 0 || !isdigit(ano)){
        return 0;
    }


    return 1;
}

void limpaBuffer(void){
    int entrada;
    do{
        entrada = fgetc(stdin);
    } while(entrada != EOF && entrada != '\n');
}
