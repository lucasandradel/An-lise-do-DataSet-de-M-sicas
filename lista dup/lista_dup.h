#ifndef __LISTA_DUP_H__
#define __LISTA_DUP_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct est_musica
{
    int id;
    char artist_name[50];
    char track_name[50];
    int release_date;
    char genre[50];
    char letra[2000];
    int len;
    char titulo[50];
    double danceability;
    double dating;
    double violence;
    double world_life;
    double night_time;
    double shake_the_audience;
    double family_gospel;
    double romantic;
    double communication;
    double obscene;
    double music;
    double movement_places;
    double light_visual_perceptions;
    double family_spiritual;
    double like_girls;
    double sadness;
    double feelings;
    double loudness;
    double acousticness;
    double instrumentalness;
    double valence;
    double energy;
    char topic[50];
    double age;

};
typedef struct est_musica Musica ;

struct no_letra
{
    Musica DadosMusic;
    struct no_letra * prox, *ant;
    
};

typedef struct no_letra tipo_no_letra;

//prototipação dasfunções

tipo_no_letra *aloca_noh(Musica);
void insereFimListDup(tipo_no_letra **, Musica);
void imprimeListDup(tipo_no_letra *);
void carregarCSV(const char *nomeArquivo, tipo_no_letra **lista);






#endif