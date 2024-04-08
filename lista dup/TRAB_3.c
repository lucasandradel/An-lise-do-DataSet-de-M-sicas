#include "TRAB_3.h"

//*****************Funções para carregamento da base de dados *********************//

//**************** Função para alocar um novo nó em uma lista duplamente encadeada *********************//
tipo_no_letra *aloca_nohLD(Musica DadosMusic){
    tipo_no_letra * novo_no;
    novo_no = (tipo_no_letra *) malloc (sizeof(tipo_no_letra));

    // Verifica se a alocação de memória foi bem-sucedida
    if(novo_no == NULL){
        printf("Erro ao alocar memoria para novo no.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa os campos do novo nó
    novo_no -> DadosMusic = DadosMusic;
    novo_no -> prox = NULL;
    novo_no -> ant = NULL;
    return novo_no;
}

//**************** Função para inserir um novo nó no final de uma lista duplamente encadeada *****************//
void insereFimListDup (tipo_no_letra **lst, Musica DadosMusic){
    tipo_no_letra * novo_no, *aux;
    novo_no = aloca_nohLD(DadosMusic);

    // Verifica se a lista não está vazia
    if ((*lst) != NULL){
        aux = (*lst);
        // Percorre a lista até o último nó
        while (aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        // Insere o novo nó no final da lista
        novo_no -> ant = aux ;
        aux -> prox = novo_no ;
    } else {
        // Se a lista estiver vazia, o novo nó se torna o início da lista
        (*lst) = novo_no;
    }
}

// *************** Função para carregar os dados de um arquivo CSV para uma lista duplamente encadeada *****************//
void carregarCSV (const char *nomeArquivo, tipo_no_letra **lista) {
    FILE *arquivo;
    char linha[2000]; // Aumentei o tamanho para lidar com o campo "letra"
    Musica novaMusica;
    int contador = 0;

    // Abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Ler cada linha do arquivo CSV
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Extrair os dados da linha
        sscanf(linha, "%d, %49[^,],%49[^,],%d,%49[^,],%2000[^,],%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%49[^,],%lf",
       &novaMusica.id, 
       novaMusica.artist_name, 
       novaMusica.track_name, 
       &novaMusica.release_date,
       novaMusica.genre, 
       novaMusica.letra, 
       &novaMusica.len,
       &novaMusica.dating, 
       &novaMusica.violence,
       &novaMusica.world_life, 
       &novaMusica.night_time, 
       &novaMusica.shake_the_audience, 
       &novaMusica.family_gospel,
       &novaMusica.romantic, 
       &novaMusica.communication, 
       &novaMusica.obscene, 
       &novaMusica.music,
       &novaMusica.movement_places, 
       &novaMusica.light_visual_perceptions, 
       &novaMusica.family_spiritual,
       &novaMusica.like_girls, 
       &novaMusica.sadness, 
       &novaMusica.feelings, 
       &novaMusica.danceability,
       &novaMusica.loudness, 
       &novaMusica.acousticness, 
       &novaMusica.instrumentalness, 
       &novaMusica.valence,
       &novaMusica.energy, 
       novaMusica.topic, 
       &novaMusica.age);

        // Inserir a música na lista
        insereFimListDup(lista, novaMusica);
        contador++;
    }
    printf("\nQuantidade de musicas na lista = %d \n",contador);
    fclose(arquivo);
}

// **************** Função para imprimir os elementos da lista duplamente encadeada ****************//
void imprimeListDup (tipo_no_letra *arquivo) {
    printf("Lista de Musicas:\n");
    int contador;
    contador = 0;
    if (arquivo == NULL) {
        printf("Lista vazia\n\n");
    } else {
        while (arquivo != NULL) {
            Musica musica = arquivo->DadosMusic;
            printf("\n");
            printf("ID: %d\n", musica.id);
            printf("Artista: %s\n", musica.artist_name);
            printf("Titulo: %s\n", musica.track_name);
            printf("Data de Lancamento: %d\n", musica.release_date);
            printf("Genero: %s\n", musica.genre);
            /*printf("Letra: %s\n", musica.letra);
            printf("Len: %d\n", musica.len);
            printf("Dating: %lf\n", musica.dating);
            printf("Violence: %lf\n", musica.violence);
            printf("World/Life: %lf\n", musica.world_life);
            printf("Night/Time: %lf\n", musica.night_time);
            printf("Shake the Audience: %lf\n", musica.shake_the_audience);
            printf("Family/Gospel: %lf\n", musica.family_gospel);
            printf("Romantic: %lf\n", musica.romantic);
            printf("Communication: %lf\n", musica.communication);
            printf("Obscene: %lf\n", musica.obscene);
            printf("Music: %lf\n", musica.music);
            printf("Movement/Places: %lf\n", musica.movement_places);
            printf("Light/Visual Perceptions: %lf\n", musica.light_visual_perceptions);
            printf("Family/Spiritual: %lf\n", musica.family_spiritual);
            printf("Like/Girls: %lf\n", musica.like_girls);
            printf("Sadness: %lf\n", musica.sadness);
            printf("Feelings: %lf\n", musica.feelings);*/
            printf("Danceability: %lf\n", musica.danceability);
            /*printf("Loudness: %lf\n", musica.loudness);
            printf("Acousticness: %lf\n", musica.acousticness);
            printf("Instrumentalness: %lf\n", musica.instrumentalness);
            printf("Valence: %lf\n", musica.valence);
            printf("Energy: %lf\n", musica.energy);
            printf("Tópico: %s\n", musica.topic);
            printf("Idade: %lf\n\n", musica.age);*/
            contador++;
            arquivo = arquivo->prox;
        }
        printf("\nQuantidade de musicas na lista = %d \n\n",contador);
    }
}




//**************** Funções para segunda etapa do trabalho, primeira estrutura: lista encadeada *************/

//**************** Função para alocar um novo nó em uma lista encadeada simples ****************//
nova_lista *aloca_noh (Musica DadosMusic){
    nova_lista * novo_no;
    novo_no = (nova_lista *) malloc (sizeof(nova_lista));

    // Verifica se a alocação de memória foi bem-sucedida
    if(novo_no == NULL){
        printf("Erro ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa os campos do novo nó
    novo_no -> DadosMusica = DadosMusic;
    novo_no -> prox = NULL;
    return novo_no;
}

//**************** Função para inserir um novo nó no final de uma lista encadeada simples ****************//
void insereFimListEnc (nova_lista **lst, Musica DadosMusica){
    nova_lista * novo_no, *aux;
    novo_no = aloca_noh(DadosMusica);

    // Verifica se a lista não está vazia
    if ((*lst) != NULL){
        aux = (*lst);
        // Percorre a lista até o último nó
        while (aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        // Insere o novo nó no final da lista
        aux -> prox = novo_no ;
    } else {
        // Se a lista estiver vazia, o novo nó se torna o início da lista
        (*lst) = novo_no;
    }
}

//**************** Função para inserir na lista encadeada apenas as músicas com danceability maior ou igual a 0.5 ****************//
nova_lista *InsereNovaLista (nova_lista *nlst, tipo_no_letra *vlst){
    int contador = 0;
    tipo_no_letra *aux = vlst;
    
    while (aux != NULL){
        Musica musicaVelha;
        musicaVelha = aux->DadosMusic;

        if (musicaVelha.danceability >= 0.5){
            insereFimListEnc(&nlst, musicaVelha); // Insere a música na lista encadeada simples
            contador ++;
        }

        aux = aux->prox;
    }
    printf("\nQuantidade de musicas com danceability maior ou igual a 0.5 na Lista Encadeada eh = %d\n", contador);


    return nlst;
}

// **************** Função para imprimir os elementos de uma lista encadeada simples ****************//
void imprimeListEnc (nova_lista *lst) {
    printf("\nLista de Musicas:\n\n");
    int contador;
    contador = 0;
    if (lst == NULL) {
        printf("Lista vazia\n\n");
    } else {
        nova_lista * atual = lst;
        while (atual != NULL) {
            Musica musica = atual->DadosMusica;
            printf("\n");
            printf("ID: %d\n", musica.id);
            printf("Artista: %s\n", musica.artist_name);
            printf("Titulo: %s\n", musica.track_name);
            printf("Data de Lancamento: %d\n", musica.release_date);
            printf("Genero: %s\n", musica.genre);
            /*printf("Letra: %s\n", musica.letra);
            printf("Len: %d\n", musica.len);
            printf("Dating: %lf\n", musica.dating);
            printf("Violence: %lf\n", musica.violence);
            printf("World/Life: %lf\n", musica.world_life);
            printf("Night/Time: %lf\n", musica.night_time);
            printf("Shake the Audience: %lf\n", musica.shake_the_audience);
            printf("Family/Gospel: %lf\n", musica.family_gospel);
            printf("Romantic: %lf\n", musica.romantic);
            printf("Communication: %lf\n", musica.communication);
            printf("Obscene: %lf\n", musica.obscene);
            printf("Music: %lf\n", musica.music);
            printf("Movement/Places: %lf\n", musica.movement_places);
            printf("Light/Visual Perceptions: %lf\n", musica.light_visual_perceptions);
            printf("Family/Spiritual: %lf\n", musica.family_spiritual);
            printf("Like/Girls: %lf\n", musica.like_girls);
            printf("Sadness: %lf\n", musica.sadness);
            printf("Feelings: %lf\n", musica.feelings);*/
            printf("Danceability: %lf\n", musica.danceability);
            /*printf("Loudness: %lf\n", musica.loudness);
            printf("Acousticness: %lf\n", musica.acousticness);
            printf("Instrumentalness: %lf\n", musica.instrumentalness);
            printf("Valence: %lf\n", musica.valence);
            printf("Energy: %lf\n", musica.energy);
            printf("Tópico: %s\n", musica.topic);
            printf("Idade: %lf\n\n", musica.age);*/
            contador++;
            atual = atual->prox;
        }
        printf("\n\t Quantidade de musicas com danceability maior ou igual a 0.5 eh = %d\n", contador);
    }
}

//**************** Funcao que conta quantas musicas com genero pop tem na lista ****************//
int contaGeneroPOP (nova_lista* lst) {
    int contador;
    contador = 0;
    if (lst == NULL) {
        return 0;
    } else {
        while (lst != NULL) {
            if (lst->DadosMusica.genre[0] == 'p' && lst->DadosMusica.genre[1] == 'o' && lst->DadosMusica.genre[2] == 'p' )
                contador++;
            lst = lst->prox;
        }
        return contador;
    }
}


//*****************Funções para a segunda estrutura de dados esolhida pela dupla: PILHA encadeada ****************//

//**************** Função para alocar um novo nó em uma PILHA encadeada ****************//
tipo_no_pilha *aloca_no_PL( Musica DadosMusic ){
    tipo_no_pilha *novo_no;
    novo_no = (tipo_no_pilha*)malloc(sizeof(tipo_no_pilha));

    if(novo_no == NULL){
        printf("Erro ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novo_no -> DadosMusic = DadosMusic;
    novo_no -> prox = NULL;
    return novo_no;
    
}

//**************** Função para empilhar ****************//
void empilha(tipo_no_pilha** pl, Musica DadosMusic ){
    tipo_no_pilha * novo_no;
    
    novo_no = aloca_no_PL (DadosMusic);
    
    if ((*pl) == NULL){
        (*pl) = novo_no;

    }else{
        novo_no -> prox = (*pl);
        (*pl) = novo_no;
    }
}

//**************** Função para inserir na pilha apenas as músicas com danceability maior ou igual a 0.5 ****************//
tipo_no_pilha *EmpilhaNovaPilha(tipo_no_pilha *nPL, tipo_no_letra *vlst){
    int contador = 0;
    tipo_no_letra *aux = vlst;
    
    while (aux != NULL){
        Musica musicaVelha;
        musicaVelha = aux->DadosMusic;

        if (musicaVelha.danceability >= 0.5){
            //printf("Empilhando elemento com ID %d\n", musicaVelha.id); // Adiciona esta linha para depurar a função
            empilha(&nPL, musicaVelha);
            contador ++;
        }

        aux = aux->prox;
    }
    printf("\nQuantidade de musicas com danceability maior ou igual a 0.5 na Lista Encadeada eh = %d\n", contador);


    return nPL;
}

// **************** Função para imprimir os elementos de uma pilha encadeada ****************//
void imprimePilha(tipo_no_pilha *topo) {
    // Verifica se a pilha está vazia
    if (topo == NULL) {
        printf("Pilha vazia.\n");
    }else{
        int contador = 0;
        // Percorre a pilha a partir do topo
        tipo_no_pilha * atual = topo;
        while (atual != NULL) {
            Musica musica = atual->DadosMusic;
            printf("\n");
            printf("ID: %d\n", musica.id);
            printf("Artista: %s\n", musica.artist_name);
            printf("Titulo: %s\n", musica.track_name);
            printf("Data de Lancamento: %d\n", musica.release_date);
            printf("Genero: %s\n", musica.genre);
            /*printf("Letra: %s\n", musica.letra);
            printf("Len: %d\n", musica.len);
            printf("Dating: %lf\n", musica.dating);
            printf("Violence: %lf\n", musica.violence);
            printf("World/Life: %lf\n", musica.world_life);
            printf("Night/Time: %lf\n", musica.night_time);
            printf("Shake the Audience: %lf\n", musica.shake_the_audience);
            printf("Family/Gospel: %lf\n", musica.family_gospel);
            printf("Romantic: %lf\n", musica.romantic);
            printf("Communication: %lf\n", musica.communication);
            printf("Obscene: %lf\n", musica.obscene);
            printf("Music: %lf\n", musica.music);
            printf("Movement/Places: %lf\n", musica.movement_places);
            printf("Light/Visual Perceptions: %lf\n", musica.light_visual_perceptions);
            printf("Family/Spiritual: %lf\n", musica.family_spiritual);
            printf("Like/Girls: %lf\n", musica.like_girls);
            printf("Sadness: %lf\n", musica.sadness);
            printf("Feelings: %lf\n", musica.feelings);*/
            printf("Danceability: %lf\n", musica.danceability);
            /*printf("Loudness: %lf\n", musica.loudness);
            printf("Acousticness: %lf\n", musica.acousticness);
            printf("Instrumentalness: %lf\n", musica.instrumentalness);
            printf("Valence: %lf\n", musica.valence);
            printf("Energy: %lf\n", musica.energy);
            printf("Tópico: %s\n", musica.topic);
            printf("Idade: %lf\n\n", musica.age);*/
            contador ++;
            atual = atual->prox;
        }
        printf("\n\t Quantidade de musicas com danceability maior ou igual a 0.5 na pilha eh = %d\n", contador);
    } 
}

//**************** Função que conta quantas musicas com genero pop tem na PILHA ****************//
int contaGeneroPOPpilha (tipo_no_pilha* pl) {
    int contador;
    contador = 0;
    if (pl == NULL) {
        return 0;
    } else {
        while (pl != NULL) {
            if (pl->DadosMusic.genre[0] == 'p' && pl->DadosMusic.genre[1] == 'o' && pl->DadosMusic.genre[2] == 'p' )
                contador++;
            pl = pl->prox;
        }
        return contador;
    }
}