#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
struct Nodo {
  item dato;
  struct Nodo* siguiente;
};
typedef struct Nodo* Lista;


Lista crearLista(){
  Lista L = NULL;
  return L;
}

Lista insertar(Lista L, item X){
  Lista nuevo;
  nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
  nuevo->dato = X;
  nuevo->siguiente = L;
  L = nuevo;
  return L;
}

Lista borrar(Lista L){
  Lista aux;
  aux = L;
  L = L->siguiente;
  free(aux);
  return L;
}

bool esListaVacia(Lista L){
  return (L==NULL);
}

item primerElemento(Lista L){
  if (esListaVacia(L)) {
    return -9999;
  }else {
    return L->dato;
  }
}

void mostrar (Lista L){
  while (!esListaVacia(L)) {
    printf("\n");
    printf("%d",L->dato);
    L = L->siguiente;
  }
}

int longitud(Lista L){
  return 3;
}

int main(){
  Lista L = crearLista();
  L = insertar(L, 1);
  L = insertar(L,2);
  L = insertar(L, 3);
  mostrar(L);
  printf("Borrar el primero\n");
  L = borrar(L);
  mostrar(L);
  printf("Mostrar el elemento del primer nodo\n");
  printf("\n");
  printf("%d",primerElemento(L));

  return 0;
}
