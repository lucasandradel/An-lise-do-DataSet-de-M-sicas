#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_dup.h" 

int main() {
    FILE *arquivo;
    char linha[256]; 
    int id;
    clock_t start, fim;
    double ResultTime;
    tipo_noh_dup *inicio = NULL;

    arquivo = fopen("tcc_ceds_music.csv", "r"); // Substitua "dados.csv" pelo nome do seu arquivo CSV

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    start = clock();

    printf("\t----- Inserindo -----\n\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id;
        char titulo[50], artista[50], genre[50];
        float danceability;

        // Parse da linha para obter os dados
        sscanf(linha, "%d,%[^,],%[^,],%[^,]\n\n, %f", &id, titulo, artista, genre, &danceability);

        insereFimListDup(&inicio, id, titulo, artista);
    }

    imprimeListDup(inicio);

    printf("\n\ncheguei aqui\n\n");
    fim = clock();


    /* Contagem de letras musicais com genre igual a "pop"
    int total_letras = 0;
    tipo_noh_dup *aux = inicio;
    while (aux != NULL) {
        if (strcmp(aux->genre, "pop") == 0) {
            total_letras += strlen(aux->titulo);
        }
        aux = aux->prox;
    }

    printf("Total de letras musicais com genre igual a 'pop': %d\n", total_letras);

    */

    ResultTime = ((double) (fim - start)) / CLOCKS_PER_SEC;
    printf("Tempo de processamento: %f segundos\n", ResultTime);

    fclose(arquivo);

    return 0;
}
