#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int tamanhotxt();
void letxt(int tam, char *palavra[tam]);
void criaArqGrafo(int tam, int mat_adja[][tam]);
void montarMatriz(int tam, int mat_adja[][tam], char *palavra[tam]);
int comparaPalavra(char palavra1[], char palavra2[]);
void zeraMatriz(int tam, int mat[tam][tam]);
void zeraArray(int tam, int array[tam]);
int dfs(int v,int tam, int mat_adja[][tam], int visitado[tam]);
int componentes(int tam, int mat_adja[][tam], int visitado[tam], int tamanhos[tam], int *qtd_componentes);
int encontra_palavra(char pal[],int tam,char *palavras[tam]);
int compara_igual(char palavra1[], char palavra2[]);


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
        for (int i = 0; i < tam; i++) {
            if (fgets(linha, sizeof(linha), f) == NULL) {
                break;
            }

            linha[strcspn(linha, "\r\n")] = '\0';

            strcpy(palavra[i], linha);
        }
    }

    fclose(f);
}

void criaArqGrafo(int tam, int mat_adja[][tam]){
    FILE *f = fopen("grafo.csv", "w");

    if(f == NULL){
        printf("Csv de grafo não criado");
        return;
    }
    
    for(int i=1;i<=tam;i++){
        fprintf(f,"%i,", i); 
    }
    fprintf(f, "\n");

    for (int i = 0; i < tam; i++) {
        fprintf(f, "%d", i);

        for (int j = 0; j < tam; j++) {
           
            fprintf(f, ";%i", mat_adja[i][j]);
            //if(mat_adja[i][j] ==1) printf("linha: %i", j);
        }

        fprintf(f, "\n");
    }
    fclose(f);
}

int comparaPalavra(char palavra1[], char palavra2[]) {
    int diferentes = 0;

    for (int i = 0; i < 4; i++) {
        if (tolower((unsigned char)palavra1[i]) !=
            tolower((unsigned char)palavra2[i])) {
            diferentes++;
        }
    }

    return diferentes == 1;
}

void montarMatriz(int tam, int mat_adja[][tam], char *palavra[tam]){
    for(int i=0; i<tam ; i++){
        for(int j= i; j<tam ; j++){ 
            if(i != j){
                int result = comparaPalavra(palavra[i], palavra[j]);
                if(result != 0 && result != 1) printf("linha: %i", j);
                mat_adja[i][j] = result;
                mat_adja[j][i] = result;
                //fprintf(f,"%i %i\n",flor[i].numVert,flor[j].numVert);
            }else{
                mat_adja[i][j] = 0;
            } 
        }
    }
}

void zeraMatriz(int tam, int mat[tam][tam]){
    for(int i=0; i<tam ; i++){
        for(int j=0; j<tam ; j++){
            mat[i][j] = 0;
        }
    }
}

void zeraArray(int tam, int array[tam]){
    for(int i=0; i<tam ; i++){
       array[i] = 0;    
    }
}


int dfs(int v,int tam, int mat_adja[][tam], int visitado[tam]) {
    visitado[v] = 1;
    int tamanho = 1;

    for (int u = 0; u < tam; u++) {
        if (mat_adja[v][u] == 1 && !visitado[u]) {
            tamanho += dfs(u, tam, mat_adja, visitado);
        }
    }

    return tamanho;
}

int componentes(int tam, int mat_adja[][tam], int visitado[tam], int tamanhos[tam], int *qtd_componentes) {
    
    for (int i = 0; i < tam; i++) {
        printf("%i ",visitado[i]) ;
           
    }

    for (int i = 0; i < tam; i++) {
        if (!visitado[i]) {
            tamanhos[*qtd_componentes] = dfs(i, tam, mat_adja, visitado);
            (*qtd_componentes)++;
        }
    }

    printf("Quantidade de componentes: %d\n",
           *qtd_componentes);

    for (int i = 0; i < *qtd_componentes; i++) {
        printf("Componente %d: %d vertices\n",
               i + 1, tamanhos[i]);
    }

    return 0;
}

int encontra_palavra(char *pal,int tam,char *palavras[tam]){
    int i = 0;
    printf("%s\n", pal);
    for(int i = 0;i<tam;i++){
        if(compara_igual(pal,palavras[i])==1){
            return i;
        }
    }
    return -1;
}

int compara_igual(char *palavra1, char palavra2[]) {
    

    for (int i = 0; i < 4; i++) {
        
        if (tolower(palavra1[i]) != 
        tolower(palavra2[i])) {
            return 0;
        }
    }

    return 1;
}



