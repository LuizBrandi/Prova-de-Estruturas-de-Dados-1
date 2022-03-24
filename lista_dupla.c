#include <stdio.h>
#include <stdlib.h>

struct lista{
    int informacao;
    struct lista * anterior;
    struct lista * proximo;
}; typedef struct lista Lista;

Lista * criaLista();
Lista * insereElemento(Lista * lst, int valor);
Lista * buscaElemento(Lista * lst, int valor);
Lista * removeElemento(Lista * lst, int valor);
void imprimeLista(Lista * lst);

int main(void){
    Lista * numeros;
    numeros = criaLista();
    numeros = insereElemento(numeros, 10);
    numeros = insereElemento(numeros, 8);
    numeros = insereElemento(numeros, 6);
    numeros = insereElemento(numeros, 4);
    numeros = insereElemento(numeros, 2);
    imprimeLista(numeros);
    numeros = removeElemento(numeros, 6);
    imprimeLista(numeros);
}

Lista * criaLista(){
    return NULL;
}

Lista * insereElemento(Lista * lst, int valor){
    Lista * novo = (Lista *) malloc(sizeof(Lista));
    novo->informacao = valor;
    novo->anterior = NULL;
    novo->proximo = lst;

    //verifica se a lista estava vazia
    if(lst != NULL){
        lst->anterior = novo;
    }
    return novo;
}

Lista * buscaElemento(Lista * lst, int valor){
    Lista * p;
    for(p = lst; p != NULL; p = p->proximo){
        if(p->informacao == valor) return p;
    }
    return NULL;
}

Lista * removeElemento(Lista * lst, int valor){
    Lista * p = buscaElemento(lst, valor);
    if(p == NULL) return lst;

    //remoção quando o elemento é o primeiro da lista
    if(p == lst){
        lst = p->proximo; 
    } else{
        //remoção quando o elemento não é o primeiro
        p->anterior->proximo = p->proximo;
    }

    //verifica se é o último elemento
    if(p->proximo != NULL){
        p->proximo->anterior = p->anterior;
    }

    free(p);
    return lst;
}

void imprimeLista(Lista * lst){
    Lista * p;
    printf("Lista: ");
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->informacao);
    }
    printf("\n");
}
