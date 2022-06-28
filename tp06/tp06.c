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
    nodo *frente;
    nodo *final;
    int longitud;
}tipofila;

//OPERACIONES DEL ADT FILA
void filaVacia(tipofila *);
bool esFilaVacia(tipofila);
void inqueue(tipofila *,item);
void dequeue(tipofila *);
item frente(tipofila);

//FUNCIONES COMO USUARIO
void mezclar(tipofila *, tipofila *, tipofila *);
int productosPares(tipofila *);

void main(){
    tipofila filaNueva, filaNueva2, filaOrdenada;
    filaVacia(&filaNueva);
    inqueue(&filaNueva,1);
    inqueue(&filaNueva,3);
    filaVacia(&filaNueva2);
    inqueue(&filaNueva2,2);
    inqueue(&filaNueva2,4);
    filaVacia(&filaOrdenada);
    mezclar(&filaNueva,&filaNueva2,&filaOrdenada);
    getchar();
}

void filaVacia(tipofila *fila){
    fila->frente=NULL;
    fila->final=NULL;
    fila->longitud=0;
}

bool esFilaVacia(tipofila fila){
    return (fila.frente==NULL && fila.final==NULL);
}

void inqueue(tipofila *fila,item x){
    nodo *nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->dato=x;
    nuevo->siguiente=NULL;
    if (esFilaVacia(*fila))
    {
        fila->frente=nuevo;
    }else{
        fila->final->siguiente=nuevo;
    }
    fila->final=nuevo;
    fila->longitud++;
}

void dequeue(tipofila *fila){
    nodo *eliminado;
    eliminado=fila->frente;
    if (!esFilaVacia(*fila))
    {
        if (fila->final==fila->frente)
        {
            fila->final=NULL;
            fila->frente=NULL;
        }else{
            fila->frente=fila->frente->siguiente;
        }
        free(eliminado);
        fila->longitud--;
    }
}

item frente(tipofila fila){
    if (esFilaVacia(fila))
    {
        return indefinido;
    }else{
        return fila.frente->dato;
    }
}

void mezclar(tipofila *fila1,tipofila *fila2,tipofila *filaMezclada){
    if (esFilaVacia(*fila1) && esFilaVacia(*fila2))
    {
        return;
    }else{
        if (!esFilaVacia(*fila1) && !esFilaVacia(*fila2))
        {
            if (frente(*fila1)<frente(*fila2))
            {
                inqueue(filaMezclada,frente(*fila1));
                dequeue(fila1);
                mezclar(fila1,fila2,filaMezclada);
            }else{
                inqueue(filaMezclada,frente(*fila2));
                dequeue(fila2);
                mezclar(fila1,fila2,filaMezclada);
            }
        }else{
            if (!esFilaVacia(*fila1))
            {
                inqueue(filaMezclada,frente(*fila1));
                dequeue(fila1);
                mezclar(fila1,fila2,filaMezclada);
            }else{
                inqueue(filaMezclada,frente(*fila2));
                dequeue(fila2);
                mezclar(fila1,fila2,filaMezclada);
            }
        }
    }
}

int productosPares(tipofila *fila){
    int paridad;
    paridad=frente(*fila)%2;
    if (esFilaVacia(*fila))
    {
        return 1;
    }else{
        if (paridad==2)
        {
            dequeue(fila);
            return frente(*fila)*productosPares(fila);
        }
    }
}