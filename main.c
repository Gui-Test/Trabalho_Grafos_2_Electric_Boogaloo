//Trabalho de Grafos 2: Electric Boogaloo
//gcc main.c funcoes.h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"

int main(){
    int tam = tamanhotxt();
    printf("tam:%i\n", tam);
    char *palavra[tam];
    for (int i = 0; i < tam; i++) {
        palavra[i] = malloc(sizeof(char)*4);
    }   
    letxt(tam,palavra);

    printf("\nteste: %s", palavra[0]);
}

