#ifndef __LISTA_DUP_H__ 
#define __LISTA_DUP_H__

#include <stdio.h> // Inclusão da biblioteca padrão de entrada e saída
#include <string.h> // Inclusão da biblioteca para manipulação de strings
#include <stdlib.h> // Inclusão da biblioteca padrão de alocação de memória

// Definição da estrutura para armazenar os dados de cada música
struct est_musica
{
    int id; // ID da música
    char artist_name[50]; // Nome do artista
    char track_name[50]; // Nome da faixa
    int release_date; // Ano de lançamento
    char genre[50]; // Gênero musical
    char letra[2000]; // Letra da música
    int len; // Comprimento da letra
    char titulo[50]; // Título da música
    double danceability; // Índice de dançabilidade
    double dating; // ...
    double violence; // ...
    double world_life; // ...
    double night_time; // ...
    double shake_the_audience; // ...
    double family_gospel; // ...
    double romantic; // ...
    double communication; // ...
    double obscene; // ...
    double music; // ...
    double movement_places; // ...
    double light_visual_perceptions; // ...
    double family_spiritual; // ...
    double like_girls; // ...
    double sadness; // ...
    double feelings; // ...
    double loudness; // ...
    double acousticness; // ...
    double instrumentalness; // ...
    double valence; // ...
    double energy; // ...
    char topic[50]; // Tópico da música
    double age; // Idade
};
typedef struct est_musica Musica;

// Definição da estrutura de um nó da lista duplamente encadeada
struct no_letra
{
    Musica DadosMusic; // Dados da música armazenados neste nó
    struct no_letra * prox; // Ponteiro para o próximo nó
    struct no_letra * ant; // Ponteiro para o nó anterior
};
typedef struct no_letra tipo_no_letra; 

// Definição da estrutura de um nó da lista encadeada
struct est_lista_encadeada
{
    Musica DadosMusica; // Dados da música armazenados neste nó
    struct est_lista_encadeada * prox; // Ponteiro para o próximo nó
};
typedef struct est_lista_encadeada nova_lista; 

// Protótipos das funções
tipo_no_letra *aloca_nohLD(Musica); // Aloca memória para um novo nó da lista duplamente encadeada
void insereFimListDup(tipo_no_letra **, Musica); // Insere um novo nó no final da lista duplamente encadeada
void insereFimListEnc(nova_lista **, Musica ); // Insere um novo nó no final da lista encadeada
void imprimeListDup(tipo_no_letra *); // Imprime todos os elementos da lista duplamente encadeada
void imprimeListEnc(nova_lista *); // Imprime todos os elementos da lista encadeada
void carregarCSV(const char *, tipo_no_letra **); // Carrega os dados do arquivo CSV para a lista duplamente encadeada
nova_lista *InsereNovaLista(nova_lista *, tipo_no_letra *); // Insere elementos na lista encadeada com base nos critérios especificados
int contaGeneroPOP(nova_lista*);

#endif // Fim do arquivo de inclusão de cabeçalho "__LISTA_DUP_H__"
