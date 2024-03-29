#ifndef __LISTA_DUP_H__
#define __LISTA_DUP_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct est_no_dup
{
    int id;
    char titulo[50];
    char artista[50];
    char genre[50];
    struct est_no_dup *ant, *prox;
};

typedef struct est_no_dup tipo_noh_dup;

tipo_noh_dup *aloca_noh(int, char*, char *);
void insereInicioListDup (tipo_noh_dup**, int, char*, char*);
void insereFimListDup( tipo_noh_dup**, int, char*, char*);
void inserePosListDup(tipo_noh_dup **, int, char*, char* ,int);
int removeInicioListDup(tipo_noh_dup**);
int removeFimListDup(tipo_noh_dup**);
int RemovePosListDup(tipo_noh_dup **, int);
void imprimeListDup(tipo_noh_dup*);



#endif