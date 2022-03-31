#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef int item;

struct Nodo {
    item dato;
    struct Nodo* siguiente;
}; 

typedef struct Nodo* Lista;

Lista crearLista();

bool esListaVacia(Lista L);

void mostrar(Lista L);

item primerElemento(Lista L); //PUEDO PONER SOLO LISTA?

Lista insertar(Lista L, item X);

Lista borrar(Lista L);

int longitud(Lista L);

bool pertenece(Lista L, item X);

Lista borrarK(Lista L, item K);

int main(){

}

Lista crearLista(){
    return NULL;
}

bool esListaVacia(Lista L){
    return L==NULL;
}

void mostrar(Lista L){ 
    while (!esListaVacia(L))
    {
        printf("%d\n",L->dato);
        L=L->siguiente;
    }
} //SIEMPRE TENGO QUE PONER LISTA L?

item primerElemento(Lista L){
    if (esListaVacia(L))
    {
        int indefinido = NULL;
        return indefinido;
    }else{
        return L->dato;
    }
    
}

Lista insertar(Lista L, item X){
    Lista nuevo;
    nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato=X;
    nuevo->siguiente=L;
    L=nuevo;
    return L;
}

Lista borrar(Lista L){
    if (esListaVacia(L))
    {
        printf("La lista esta vacia.\n");
    }else{
        Lista auxiliar;
        auxiliar=L;
        L=L->siguiente;
        free(auxiliar);
        printf("1 elemento borrado.\n");
    }
    return L;
}

int longitud(Lista L){
    Lista auxiliar;
    auxiliar=L;
    int count=0;
    while (auxiliar->siguiente)
    {
        auxiliar=auxiliar->siguiente;
        count++;
    }
    return count;
}

bool pertenece(Lista L, item X){
    Lista auxiliar;
    auxiliar=L;
    int count=0;
    while (auxiliar->siguiente)
    {
        if (auxiliar->dato==X)
        {
            count++;
        }
    }
    return count>0;
}

Lista borrarK(Lista L, item K){
    Lista auxiliar;
    auxiliar
}
