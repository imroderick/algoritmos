#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int item; //tipo de dato que contiene la pila

#define indefinido -9999;

typedef struct nodo{
    item dato;
    struct nodo *siguiente;
}nodo;

typedef struct pila{
    nodo *head;
    int altura;
}tipopila;


//OPERACIONES DEL ADT PILA
// nodo * crearNodo(item);
void pilaVacia(tipopila *);
bool esPilaVacia(tipopila);
void push(tipopila *, item);
void pop(tipopila *);
item top(tipopila);

void main(){

}

// nodo * crearNodo(item x){
//     nodo *new=(nodo *)malloc(sizeof(nodo));
//     new->dato=x;
//     new->siguiente=NULL;
//     return new;
// }

void pilaVacia(tipopila *nuevaPila){
    nuevaPila->head=NULL;
    nuevaPila->altura=0;
}

bool esPilaVacia(tipopila pilaTest){
    return pilaTest.head==NULL;
}

void push(tipopila *pila, item x){
    nodo *new=(nodo *)malloc(sizeof(nodo));
    new->dato=x;
    new->siguiente=pila->head;
    pila->head=new;
    pila->altura++;
}

void pop(tipopila *pila){
    nodo *aux;
    aux=pila->head;
    pila->head=pila->head->siguiente;
    free(aux);
}

item top(tipopila pila){
    return pila.head->dato;
}