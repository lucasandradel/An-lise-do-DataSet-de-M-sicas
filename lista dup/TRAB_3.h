#ifndef __TRAB_3_H__
#define __TRAB_3_H__

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

struct est_no_pilha
{
    Musica DadosMusic;
    struct est_no_pilha *prox;

};
typedef struct est_no_pilha tipo_no_pilha;



//------------------ Protótipos das funções da primeira etapa -------------------//

// ------- Funções que foram usadada para o ARMAZENAMENTO do arquivo CSV, estrutura de dados (LISTA DUPLAMENTE ENCADEADA) ----------------//
tipo_no_letra *aloca_nohLD(Musica); // Aloca memória para um novo nó da lista duplamente encadeada
void insereFimListDup(tipo_no_letra **, Musica); // Insere um novo nó no final da lista duplamente encadeada
void imprimeListDup(tipo_no_letra *); // Imprime todos os elementos da lista duplamente encadeada
void carregarCSV(const char *, tipo_no_letra **); // Carrega os dados do arquivo CSV para a lista duplamente encadeada

//----------------- prototipo das funções usadas na segunda etapa ----------------//

// ------- Funções que foram usadada para a PRIMEIRA estrutura de dados (LISTA ENCADEADA) ----------------//

nova_lista *aloca_noh(Musica );//Função que aloca um noh na memória para uma lista encadeada
void insereFimListEnc(nova_lista **, Musica ); // Insere um novo nó no final da lista encadeada
void imprimeListEnc(nova_lista *); // Imprime todos os elementos da lista encadeada
nova_lista *InsereNovaLista(nova_lista *, tipo_no_letra *); // Insere elementos na lista encadeada com base nos critérios especificados
int contaGeneroPOP(nova_lista*);//função que conta quantas músicas do H~enero POP contém na lista enacadeada

// ------- Funções que foram usadada para a SEGUNDA estrutura de dados (PILHA ENCADEADA) ----------------

tipo_no_pilha *aloca_no_PL( Musica );//Função para alocar um novo nó em uma PILHA encadeada
void empilha(tipo_no_pilha** , Musica );//Função que empilha em uma pilha encadeada
tipo_no_pilha *EmpilhaNovaPilha(tipo_no_pilha *, tipo_no_letra *);//insere elementos na pilha encadeada com base nos crtérios especificados 
void imprimePilha(tipo_no_pilha *);//imprime os elementos da pilha Encadada
int contaGeneroPOPpilha (tipo_no_pilha* );//função que conta quantos elementos do gênero POP na pilha encadeada






#endif 
