#include "lista_dup.h"

tipo_noh_dup *aloca_noh(int id,  char * titulo, char * artista){
    tipo_noh_dup * novo_no;
    novo_no = (tipo_noh_dup *) malloc (sizeof(tipo_noh_dup));
    novo_no -> id = id;
    strcpy(novo_no->titulo, titulo);
    strcpy(novo_no->artista, artista);
    novo_no -> prox = NULL;
    novo_no -> ant = NULL;
    return novo_no;
}

void insereInicioListDup (tipo_noh_dup** list, int id, char *titulo , char *artista){
    tipo_noh_dup *novo_no;
    novo_no = aloca_noh (id, titulo, artista );

    if ((*list)!= NULL){
        novo_no -> prox = (*list);
        (*list) -> ant = novo_no;
        (*list) = novo_no;

    }else{
        (*list) = novo_no;
    }
}

void insereFimListDup( tipo_noh_dup**lst,int id, char *titulo , char *artista ){
    tipo_noh_dup * novo_no, *aux;
    novo_no = aloca_noh(id, titulo, artista);

    if ((*lst) != NULL){
        aux = (*lst);
        while (aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        novo_no -> ant = aux ;
        aux -> prox = novo_no ;
        
        
    }else{
        insereInicioListDup(lst, id, titulo, artista);
    }
}

void inserePosListDup(tipo_noh_dup **lst, int id, char *titulo, char *artista, int pos){
    tipo_noh_dup *aux, * novo_no;
    int contador = 0;
    novo_no = aloca_noh(id, titulo, artista);

    if ( pos != 0){
       aux = (*lst);

       while ((aux != NULL) && (contador < pos))
       {
        aux = aux -> prox;
        contador ++;
       }
       if ( pos > contador){
        printf ("[ERRO] POSIÇÃO INVÁLIDA\n\n");

       }else{
            if((aux != NULL) && ( contador == pos)){
                novo_no -> ant = aux -> ant;
                novo_no -> prox = aux;
                novo_no -> ant -> prox = novo_no;
                novo_no -> prox ->ant = novo_no;
            
            }else if ((aux == NULL) && (contador == pos)){
                insereFimListDup(lst, id, titulo, artista);
            }
        }

    }else{
        insereInicioListDup(lst, id, titulo, artista);
    }
}

int removeInicioListDup(tipo_noh_dup**lst){
    tipo_noh_dup *aux;
    int id;

    if ((*lst) != NULL){

        id = (*lst) -> id;
        aux =  (*lst);
        (*lst) = (*lst) -> prox;
        if((*lst) -> prox != NULL){
            (*lst) -> ant = NULL;
        }
        free (aux);
        return id;
        
    }else{
        printf("\n\nLista vazia\n\n");
        return -1;
    }
}   

int removeFimListDup(tipo_noh_dup**lst){
    tipo_noh_dup *aux;
    int id;

    if ((*lst) != NULL){
        aux = (*lst);

        while ( aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        id = aux -> id;

        if(aux -> ant != NULL){ //verifica se não é o último no
            aux -> ant -> prox = NULL;
            aux -> ant = NULL;
        }

        //verifica se é o ultimo no
        if (((*lst) -> ant == NULL) && ((*lst)-> prox == NULL)){
            (*lst) = NULL;
        }
        free (aux);
        return id;
        
    }else{
        printf ("Lista vazia, erro na remoção\n");
        return -1;
    }
}

int RemovePosListDup(tipo_noh_dup ** lst, int pos){
    tipo_noh_dup *aux;
    int contador = 0;
    int id;


    if ((*lst) != NULL){
        aux = (*lst);

        if (pos != 0){
            while (aux != NULL && contador < pos)
            {
                aux = aux -> prox;
                contador ++;
            }

            if (pos > contador){

                printf ("[ERRO NA REMOÇÃO POSIÇÃO INVÁLIDA] \n\n");
                return -1;
            
            }else{
                if (aux != NULL && contador == pos){
                    id = aux -> id;
                    aux -> ant -> prox = aux -> prox;
                    aux -> prox-> ant = aux -> ant;
                    free ( aux);
                    return id;

                }else if ( aux == NULL && contador == pos){
                    removeFimListDup(lst);
                }
            }    
        }

        else{
            removeInicioListDup(lst);
        }

    }else{
        printf (" [ERRO] LISTA VAZIA\n\n");
        return -1;
    }
}

void imprimeListDup(tipo_noh_dup*arquivo){
    printf("Lista dup: ");
    if (arquivo == NULL){
        printf ("lista vazia\n\n");
    }
    else{
        while (arquivo !=NULL){
            printf("[%d - %s, %s] ", arquivo->id, arquivo->titulo, arquivo->artista);
            arquivo = arquivo -> prox;
        }
        printf(" \n\n");
    }
    
    
}
