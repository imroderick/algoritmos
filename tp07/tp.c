#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int item; //tipo de dato que contiene la pila
#define indefinido -9999;
typedef struct nodo{
    item dato;
    struct nodo *siguiente;
}nodo;
typedef struct fila{
    nodo *head;
    int longitud;
}LC;

//OPERACIONES DEL ADT LC
void LCvacia(LC *);
bool esLCVacia(LC);
void LCinsertar(LC *,item);
void LCborrar(LC *);
item LCvalor(LC);

void main(){

}

void LCinsertar(LC *lista,item x){
    nodo *nuevo;
    nuevo=(nodo *)malloc(sizeof(nodo));

    nuevo->dato=x;
    nuevo->siguiente=lista->head->siguiente;
    lista->head=nuevo;
}