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
void LCrotar(LC *);

//FUNCIONES COMO USUARIO DEL ADT
int LCcontarK(LC*,item,int);

void main(){

}

void LCvacia(LC *lista){
    lista->head=NULL;
    lista->longitud=0;
}

bool esLCVacia(LC lista){
    return lista.head==NULL;
}

void LCinsertar(LC *lista,item x){
    nodo *nuevo;
    nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->dato=x;
    if (esLCVacia(*lista))
    {
        nuevo->siguiente=nuevo;
        lista->head=nuevo;
    }else{
        nuevo->siguiente=lista->head->siguiente;
        lista->head->siguiente=nuevo;
    }
    lista->longitud++;
}

item LCvalor(LC lista){
    item x;
    if (!esLCVacia(lista))
    {
        x=lista.head->siguiente->dato;
    }else{
        x=indefinido;
    }
    return x;
}

void LCborrar (LC *lista){
    nodo *eliminado;
    eliminado = lista->head->siguiente;
    if (!esLCVacia(*lista))
    {
        if (lista->head == lista->head->siguiente)
        {
            lista->head=NULL;
        }else{
            lista->head->siguiente=lista->head->siguiente->siguiente;
        }
        free(eliminado);
        lista->longitud--;
    }
}

void LCrotar (LC *lista){
    lista->head=lista->head->siguiente;
}

int LCcontarK(LC *lista, item K, int longitud){
    if (longitud == 0)
    {
        return 0;
    }else{
        if (LCvalor(*lista) == K)
        {
            LCrotar(lista);
            return 1 + LCcontarK(lista,K,longitud-1);
        }
    }
}