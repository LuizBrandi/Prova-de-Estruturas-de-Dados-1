#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int info;
    struct elemento * proximo;
}; typedef struct elemento Elemento;

struct pilha{
    Elemento * topo;
}; typedef struct pilha Pilha;

Pilha * criaPilha();
void empilha(Pilha * pl, int valor);
int desempilha(Pilha * pl);
void simulaLista(Pilha * P1, Pilha * P2);
void imprimePilha(Pilha * pl);


int main(void){
    Pilha * PA = criaPilha();
    Pilha * PB = criaPilha();
    empilha(PA, 2);
    empilha(PA, 4);
    empilha(PA, 6);
    imprimePilha(PA);
    simulaLista(PA, PB);
    imprimePilha(PB);
}

Pilha * criaPilha(){
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}   

void empilha(Pilha * pl, int valor){
    Elemento * novoTopo = (Elemento *) malloc(sizeof(Elemento));
    novoTopo->info = valor;
    novoTopo->proximo = pl->topo;
    pl->topo = novoTopo;
}

int desempilha(Pilha * pl){
    Elemento * temp;
    int valor;
    temp = pl->topo;
    valor = temp->info;
    pl->topo = temp->proximo;

    free(temp);
    return valor;
}

void simulaLista(Pilha * P1, Pilha * P2){
    //Pilha * p;
    while(P1->topo != NULL){
        int temp;
        temp = desempilha(P1);
        empilha(P2, temp);
    }
}

void imprimePilha(Pilha * pl){
    Elemento * p;

    printf("Topo da pilha\n");
    for(p = pl->topo; p != NULL; p = p->proximo){
        printf("%d\n", p->info);
    }
    printf("Fim da pilha\n");
}