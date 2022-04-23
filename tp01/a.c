#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
//Definicion del TIPO DE DATO de la Lista
typedef int item;
const item indefinido = 9999;

//Definicion del NODO de la Lista
struct nodo{
item dato;
struct nodo *siguiente;
};

//Definicion de la CABECERA de la Lista
typedef struct nodo* Lista;

//PROTOTIPO DE LAS OPERACIONES de la Lista Enlazada
Lista crearListaVacia();
int esListaVacia(Lista L);
Lista insertar(Lista L, item x);
void mostrar(Lista L);
Lista borrar(Lista L);
int longitud(Lista L);
int pertenece(Lista L, item X);
item primerElemento(Lista L);
int contarMenoresQue(Lista L, item X);

int main(){

int cantidad, valor=3;

printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

printf("\n1.Creo una lista y la inicializo en lista vacia.\n");
Lista L = crearListaVacia();

printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
if(esListaVacia(L))
printf("Lista Vacia\n");
else
printf("Lista NO Vacia\n");

printf("\n3.Muestro la lista vacia por pantalla: ");
mostrar(L);

printf("\n4.Escribo la cantidad de elementos de una lista vacia: %d \n", longitud(L));

printf("\n5.Escribo el valor del primer elemento de una lista vacia: %d \n", primerElemento(L));

printf("\n6.Inserto un elemento en la lista\n");
L=insertar(L,1);

printf("\n6.Pruebo la función esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
if(esListaVacia(L)){
printf("Lista Vacia\n");
}else{
printf("Lista NO Vacia\n");
}

printf("\n7.Borro un elemento de la lista\n");
L = borrar(L);

printf("\n8.Muestro la lista vacia por pantalla: ");
mostrar(L);

printf("\n9.Inserto 5 elementos en la lista\n");
L=insertar(L,1);
L=insertar(L,2);
L=insertar(L,3);
L=insertar(L,4);
L=insertar(L,5);

printf("\nx.Vamos a buscar valores menores a %d:\n", valor);
cantidad=contarMenoresQue(L,valor);
printf("\nx.La cantidad de numeros menores a %d es: %d\n", valor,cantidad);

printf("\n10.Escribo la cantidad de elementos de la lista: %d \n", longitud(L));

printf("\n11.Escribo el valor del primer elemento de la lista vacia: %d \n", primerElemento(L));

printf("\n12.Muestro la lista de 5 elementos por pantalla: ");
mostrar(L);

printf("\n13.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': ");
if(pertenece(L, 100))
printf("Pertenece\n");
else
printf("NO Pertenece\n");

printf("\n14.Busco si pertenece el valor 3 en la lista. Mensaje esperado: 'Pertenece': ");

if(pertenece(L, 3)){
printf("Pertenece\n");
}else{
printf("NO Pertenece\n");}

printf("\n15.Libero la memoria reservada en forma dinámica\n");
while(!esListaVacia(L))
L=borrar(L);
printf("\nFIN DEL PROGRAMA DE PRUEBA\n");

return 0;
}

Lista crearListaVacia(){
return NULL;
}

int esListaVacia(Lista L){
return L==NULL;
}

Lista insertar(Lista L, item x){
struct nodo* nuevo;
nuevo = (struct nodo*) malloc(sizeof( struct nodo));
nuevo->dato = x;
nuevo->siguiente = L;
L=nuevo;
return L;
}

void mostrar(Lista L){
printf("L --> ");
while(L!=NULL){
printf("%d -> ", L->dato);
L = L->siguiente;
}
printf("NULL\n");
}

Lista borrar(Lista L){
struct nodo *aux;
if(L!=NULL){
aux = L;
L = L->siguiente;
free(aux);
}
return L;
}

int longitud(Lista L){
int cont=0;
while(L!=NULL){
cont++;
L = L->siguiente;
}
return cont;
}

int pertenece(Lista L, item X){
    while(L!=NULL && L->dato!=X){
        L = L->siguiente;
    }   
    return L!=NULL;
}

item primerElemento(Lista L){
if(L==NULL){
return indefinido;
}
else
return L->dato;
}

int contarMenoresQue(Lista L, item X){
int cont=0;
while(L!=NULL){
if (L->dato<X){
cont++;
}
L=L->siguiente;
}
return cont;
}

