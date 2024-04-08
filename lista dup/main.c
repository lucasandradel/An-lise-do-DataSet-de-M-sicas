#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_dup.h" 

int main(int argc, char *argv[]) {
    tipo_no_letra *inicio = NULL;
    nova_lista *inicioEnc = NULL;

    clock_t inicio_tempo, fim_tempo, inicio_tempo_lst_enc, fim_tempo_lst_enc;//váriaveis que irão contabilizar o inicio e fim de cada estrutura de dados
    double tempo_decorrido, tempo_lista_enc;//váriaveis que irão definir o tempo gasto

    printf("\n\t----- Armazenando Banco de dados na lista duplamente encadeada ----- \n");

    inicio_tempo = clock(); // Marca o início do tempo do carregamento do banco de dados na lista duplamente encadeada
    
    carregarCSV("tcc_ceds_music.csv", &inicio);

    fim_tempo = clock(); // Marca o fim do tempo do carregamento do banco de dados na lista duplamente encadeada

    //imprimeListDup(inicio);//impressão após armazenamento da lista duplamente encadeada

    tempo_decorrido = ((double) (fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao para armazenamento do arquivo na lista duplamente encadeada: %.6f segundos\n\n", tempo_decorrido);

    //imprimir a lista de músicas carregadas

    printf("\n\n\t----- Armazenando musicas com danceability maior ou igual a 0.5 na Lista Encadeada -----\n\n");

    inicio_tempo_lst_enc = clock();//inicio da contabilização do tempo da inserção na lista encadeada

    inicioEnc = InsereNovaLista(inicioEnc, inicio);

    fim_tempo_lst_enc = clock();//fim da contabilização do tempo da lista encadeada

    //imprimeListEnc(inicioEnc);//impressão após inserção de registors com danceability maiou ou igual a 0.5 na lista encadeada

    int pop;
    pop = contaGeneroPOP(inicioEnc);//chamada da função que contabiliza a quantidade de registros que contém o gênro pop na lista enaceada
    printf("\n\tQuantidade de musica com genero pop na lista encadeada = %d\n", pop);


    tempo_lista_enc = ((double) (fim_tempo_lst_enc - inicio_tempo_lst_enc)) / CLOCKS_PER_SEC;
    printf("\n\tTempo de execucao para armazenamento dos registros que tem danceability maior ou igual a 0.5 na lista encadeada: %.6f segundos\n\n", tempo_lista_enc);

    return 0;
}
