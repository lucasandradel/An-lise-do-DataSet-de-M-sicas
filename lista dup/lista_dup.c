#include "lista_dup.h"

tipo_no_letra *aloca_noh(Musica DadosMusic){
    tipo_no_letra * novo_no;
    novo_no = (tipo_no_letra *) malloc (sizeof(tipo_no_letra));

    if(novo_no == NULL){
        printf("Erro ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novo_no -> DadosMusic = DadosMusic;
    novo_no -> prox = NULL;
    novo_no -> ant = NULL;
    return novo_no;
}

void insereFimListDup(tipo_no_letra **lst, Musica DadosMusic){
    tipo_no_letra * novo_no, *aux;
    novo_no = aloca_noh(DadosMusic);

    if ((*lst) != NULL){
        aux = (*lst);
        while (aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        novo_no -> ant = aux ;
        aux -> prox = novo_no ;
        
        
    }else{
        (*lst) = novo_no;
    }
}

void carregarCSV(const char *nomeArquivo, tipo_no_letra **lista) {
    FILE *arquivo;
    char linha[2000]; // Aumentei o tamanho para lidar com o campo "letra"
    Musica novaMusica;

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Ler cada linha do arquivo CSV
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Extrair os dados da linha
        sscanf(linha, "%d,%49[^,],%49[^,],%d,%49[^,],%[^,],%*d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%hhd,%le",
               &novaMusica.id, novaMusica.artist_name, novaMusica.track_name, &novaMusica.release_date,
               novaMusica.genre, novaMusica.letra, &novaMusica.danceability, &novaMusica.dating, &novaMusica.violence,
               &novaMusica.world_life, &novaMusica.night_time, &novaMusica.shake_the_audience, &novaMusica.family_gospel,
               &novaMusica.romantic, &novaMusica.communication, &novaMusica.obscene, &novaMusica.music,
               &novaMusica.movement_places, &novaMusica.light_visual_perceptions, &novaMusica.family_spiritual,
               &novaMusica.like_girls, &novaMusica.sadness, &novaMusica.feelings, &novaMusica.danceability,
               &novaMusica.loudness, &novaMusica.acousticness, &novaMusica.instrumentalness, &novaMusica.valence,
               &novaMusica.energy, novaMusica.topic, &novaMusica.age);

        // Inserir a música na lista
        insereFimListDup(lista, novaMusica);
    }

    fclose(arquivo);
}

void imprimeListDup(tipo_no_letra *arquivo) {
    printf("Lista de Músicas:\n");

    if (arquivo == NULL) {
        printf("Lista vazia\n\n");
    } else {
        while (arquivo != NULL) {
            Musica musica = arquivo->DadosMusic;
            printf("ID: %d\n", musica.id);
            printf("Artista: %s\n", musica.artist_name);
            printf("Título: %s\n", musica.track_name);
            printf("Gênero: %s\n", musica.genre);
            printf("Danceability: %.2f\n\n", musica.danceability);

            arquivo = arquivo->prox;
        }
    }
}



/*
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

*/