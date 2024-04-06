#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_dup.h" 

int main(int argc, char *argv[]) {
    tipo_no_letra *inicio = NULL;
    nova_lista *inicioEnc = NULL;

    clock_t inicio_tempo, fim_tempo, inicio_tempo_lst_enc, fim_tempo_lst_enc;
    double tempo_decorrido, tempo_lista_enc;

    printf("\n\t----- Armazenando Banco de dados na lista duplamente encadeada ----- \n");

    inicio_tempo = clock(); // Marca o início do tempo

    carregarCSV("tcc_ceds_music.csv", &inicio);

    fim_tempo = clock(); // Marca o fim do tempo

    //imprimeListDup(inicio);

    tempo_decorrido = ((double) (fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execução para armazenamento do arquivo na lista duplamente encadeada: %.6f segundos\n\n", tempo_decorrido);

    //imprimir a lista de músicas carregadas

    printf("\n\n\t----- Armazenando musicas com danceability maior ou igual a 0.5 na Lista Encadeada -----\n\n");

    inicio_tempo_lst_enc = clock();
    inicioEnc = InsereNovaLista(inicioEnc, inicio);

    //imprimeListEnc(inicioEnc);

    fim_tempo_lst_enc = clock();

    tempo_lista_enc = ((double) (fim_tempo_lst_enc - inicio_tempo_lst_enc)) / CLOCKS_PER_SEC;
    printf("\nTempo de execução para armazenamento dos registros que têm danceability maior ou igual a 0.5 na lista encadeada: %.6f segundos\n\n", tempo_lista_enc);

    return 0;
}
