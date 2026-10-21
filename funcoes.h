#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int tamanhotxt();
void letxt(int tam, char *palavra[tam]);



int tamanhotxt(){ 
    FILE *f; 
    int tam = 0;
    char c;
    f=fopen("palavras4l.txt","r");

    if(f == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return 0;
    }

    for (c = getc(f); c != EOF; c = getc(f))
        if (c == '\n') 
            tam++;

    fclose(f);
    return tam+1;
}

void letxt(int tam, char *palavra[tam]){
    FILE *f; 
    char linha[100];
    int i = 0;
    f=fopen("palavras4l.txt","r");

    if(f == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return;
    }

    for(int i=0;i<tam;i++){
        fgets(linha,100,f);
        printf("%s\n", linha);
        strcpy(palavra[i],linha);
        printf("%s\n", palavra[i]);
    }

    fclose(f);
}