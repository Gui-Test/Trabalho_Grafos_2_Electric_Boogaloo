//Trabalho de Grafos 2: Electric Boogaloo
//gcc main.c funcoes.h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//#include "funcoes.h"



int main(){
    
    int tam = tamanhotxt();
    int tamanhos[tam];
    int qtd_componentes = 0;
    int visitado[tam];

    zeraArray(tam, tamanhos);
    zeraArray(tam, visitado);

    int (*mat_adja)[tam] = malloc(tam * sizeof(*mat_adja));

    if (mat_adja == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    printf("3232");
    printf("tam:%i\n", tam);
    char *palavras[tam];

    for (int i = 0; i < tam; i++) {
        palavras[i] = malloc(sizeof(char)*5);
    }

    letxt(tam,palavras);
    printf("1");
    montarMatriz(tam,mat_adja, palavras);
    printf("2");
    criaArqGrafo(tam, mat_adja);
    printf("3");
    componentes(tam, mat_adja, visitado, tamanhos, &qtd_componentes);

    for (int i = 0; i < tam; i++)
        //printf("%d", mat_adja[0][i]);
        
    for (int i = 0; i < tam; i++) {
        free(palavras[i]);
    }
   free(mat_adja);
}

