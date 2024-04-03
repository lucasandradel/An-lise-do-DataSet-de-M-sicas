#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_dup.h" 

int main(int argc, char *argv[]) {
    tipo_no_letra *inicio = NULL;

    clock_t inicio_tempo, fim_tempo;
    double tempo_decorrido;

    printf("----- Inserindo ----- ");

    inicio_tempo = clock(); // Marca o início do tempo

    carregarCSV("tcc_ceds_music.csv", &inicio);

    fim_tempo = clock(); // Marca o fim do tempo

    tempo_decorrido = ((double) (fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido: %.6f segundos\n", tempo_decorrido);

    //imprimir a lista de músicas carregadas
    imprimeListDup(inicio);

    return 0;
}
