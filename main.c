//Trabalho de Grafos 2: Electric Boogaloo
//gcc main.c funcoes.h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcoes.h"



int main(){
    
    int tam = tamanhotxt();
    int tamanhos[tam];
    int qtd_componentes = 0;
    int visitado[tam];
    MaiorGrau *listaMaiorGrau = NULL;
    MenorGrau *listaMenorGrau = NULL;
    zeraArray(tam, tamanhos);
    zeraArray(tam, visitado);

    int (*mat_adja)[tam] = malloc(tam * sizeof(*mat_adja));

    if (mat_adja == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    
    printf("tam:%i\n", tam);
    char *palavras[tam];

    for (int i = 0; i < tam; i++) {
        palavras[i] = malloc(sizeof(char)*4);
    }

    letxt(tam,palavras);
    
    montarMatriz(tam,mat_adja, palavras);
    
    criaArqGrafo(tam, mat_adja);
    
    componentes(tam, mat_adja, visitado, tamanhos, &qtd_componentes, listaMaiorGrau, listaMenorGrau, palavras);

    char *pal1 = malloc(sizeof(char)*4);
    char *pal2 = malloc(sizeof(char)*4);

    printf("\nDigite uma palavra de 4 caracteres:\n");
    scanf("%s", pal1);
    printf("\nDigite outra palavra de 4 caracteres:\n");
    scanf("%s", pal2);

    int ind_pal1 = encontra_palavra(pal1 ,tam, palavras);
    int ind_pal2 = encontra_palavra(pal2 ,tam, palavras);

    printf("\n\nrelacao direta matriz: %i", mat_adja[ind_pal1][ind_pal2]);

    dijkstra(tam,mat_adja,ind_pal1,ind_pal2);
    

    //for (int i = 0; i < tam; i++)
        //printf("%d", mat_adja[0][i]);
         
    for (int i = 0; i < tam; i++) {
        free(palavras[i]);
    }
   //free(mat_adja);
}

