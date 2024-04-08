#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TRAB_3.h" 
#include <unistd.h> // Para usar a função sleep


int main(int argc, char *argv[]) {
    tipo_no_letra *inicioListaDUp = NULL;
    nova_lista *inicioEnc = NULL;
    tipo_no_pilha *inicioPL = NULL;

    clock_t inicio_tempo, fim_tempo, inicio_tempo_lst_enc, fim_tempo_lst_enc, inicio_tempo_pilha, fim_tempo_pilha;//váriaveis que irão contabilizar o inicio e fim de cada estrutura de dados
    double tempo_decorrido, tempo_lista_enc, tempo_pilha;//váriaveis que irão definir o tempo gasto

    printf("\n----- Armazenando Banco de dados na lista duplamente encadeada ----- \n");

    inicio_tempo = clock(); // Marca o início do tempo do carregamento do banco de dados na lista duplamente encadeada
    
    carregarCSV("tcc_ceds_music.csv", &inicioListaDUp);//função que carrega o arquio csv numa lista duplamente encadeada

    fim_tempo = clock(); // Marca o fim do tempo do carregamento do banco de dados na lista duplamente encadeada

    imprimeListDup(inicioListaDUp);//impressão após armazenamento da lista duplamente encadeada
    sleep(3);

    tempo_decorrido = ((double) (fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;//cálculo para contabilizar o tempo de armazenamento na lista duplamente encadeada
    printf("\n\nTempo de execucao para armazenamento do arquivo na lista duplamente encadeada: %.6f segundos\n\n", tempo_decorrido);

//************************************* Armazenamento dos registros com danceability >= 0.5 numa lista encadeada ***************************************//

    printf("\n\n----- Armazenando musicas com danceability maior ou igual a 0.5 na Lista Encadeada -----\n\n");

    inicio_tempo_lst_enc = clock();//inicio da contabilização do tempo da inserção na lista encadeada

    inicioEnc = InsereNovaLista(inicioEnc, inicioListaDUp);//chamada da função que insere na lista encadeada apenas registros com danceability >= 0.5

    fim_tempo_lst_enc = clock();//fim da contabilização do tempo da lista encadeada

    imprimeListEnc(inicioEnc);//impressão após inserção de registors com danceability maiou ou igual a 0.5 na lista encadeada

    int poplst;//váriavel para armazenar a quantidade de musicas com danceability >= 0.5 do gênero POP
    poplst = contaGeneroPOP(inicioEnc);//chamada da função que contabiliza a quantidade de registros que contém o gênro pop na lista encadeada
    printf("\nQuantidade de musica com genero pop na lista encadeada = %d\n", poplst);


    tempo_lista_enc = ((double) (fim_tempo_lst_enc - inicio_tempo_lst_enc)) / CLOCKS_PER_SEC;//cálculo para contabilizar o tempo de armazenamento na lista encadeada
    printf("\nTempo de execucao para armazenamento dos registros que tem danceability maior ou igual a 0.5 na lista encadeada: %.6f segundos\n\n", tempo_lista_enc);
    sleep(3);

//************************************* Armazenamento dos registros com danceability >= 0.5 numa pilha encadeada ***************************************//

    printf("\n\n----- Armazenando musicas com danceability maior ou igual a 0.5 na Pilha -----\n\n");

    inicio_tempo_pilha = clock();//inicio da contabilização do tempo da inserção na pilha encadeada

    inicioPL = EmpilhaNovaPilha(inicioPL, inicioListaDUp);//chamada da função que insere registros com danceability >= 0.5 na pilha encadeada

    fim_tempo_pilha = clock();//fim da contabilização do tempo na armazenação na pilha encadeada

    imprimePilha(inicioPL);//impressão após inserção de registors com danceability maiou ou igual a 0.5 na pilha encadeada
    

    int popPL;//váriavel para armazenar a quantidade de musicas com danceability >= 0.5 do gênero POP
    popPL= contaGeneroPOPpilha(inicioPL);//chamada da função que contabiliza a quantidade de registros que contém o gênro pop na pilha encadeada
    printf("\nQuantidade de musica com genero pop na PILHA = %d\n", popPL);

    tempo_pilha = ((double) (fim_tempo_pilha - inicio_tempo_pilha)) / CLOCKS_PER_SEC;//cálculo para contabilizar o tempo de armazenamento na lista encadeada
    printf("\nTempo de execucao para armazenamento dos registros que tem danceability maior ou igual a 0.5 na Pilha: %.6f segundos\n\n", tempo_pilha);
    sleep(3);


    return 0;
}
