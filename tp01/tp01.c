#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int item; //defino el tipo de dato del item
#define indefinido -9999; //declaro un indefinido

typedef struct nodo{ 
    item dato;
    struct nodo *siguiente;
}nodo; //defino el elemento de tipo nodo con un item y un puntero al siguiente nodo

typedef nodo *lista; //defino la cabecera de la lista que es un puntero a un nodo 

//OPERACIONES DE LA LISTA SIMPLEMENTE ENLAZADA
lista crearListaVacia();
bool esListaVacia(lista head);
lista insertarNuevoNodo(lista head, item x);
void mostrarLista(lista head);
lista borrar(lista head);
int longitud(lista head);
bool pertenece(lista head, item x);
lista borrarK(lista head, item k);
item primerElemento(lista head);

void main(){
    int cantidad, valor=3;

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

    printf("\n1.Creo una lista y la inicializo en lista vacia.\n");
    lista L = crearListaVacia();

    // printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
    // if(esListaVacia(L))
    // printf("Lista Vacia\n");
    // else
    // printf("Lista NO Vacia\n");

    // printf("\n3.Muestro la lista vacia por pantalla: ");
    // mostrarLista(L);

    // printf("\n4.Escribo la cantidad de elementos de una lista vacia: %d \n", longitud(L));

    // printf("\n5.Escribo el valor del primer elemento de una lista vacia: %d \n", primerElemento(L));

    // printf("\n6.Inserto un elemento en la lista\n");
    // L=insertarNuevoNodo(L,1);

    // printf("\n6.Pruebo la función esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
    // if(esListaVacia(L)){
    // printf("Lista Vacia\n");
    // }else{
    // printf("Lista NO Vacia\n");
    // }

    // printf("\n7.Borro un elemento de la lista\n");
    // L = borrar(L);

    // printf("\n8.Muestro la lista vacia por pantalla: ");
    // mostrarLista(L);

    printf("\n9.Inserto 5 elementos en la lista\n");
    L=insertarNuevoNodo(L,1);
    L=insertarNuevoNodo(L,2);
    L=insertarNuevoNodo(L,3);
    L=insertarNuevoNodo(L,4);
    L=insertarNuevoNodo(L,5);

    // printf("\nx.Vamos a buscar valores menores a %d:\n", valor);
    // cantidad=contarMenoresQue(L,valor);
    // printf("\nx.La cantidad de numeros menores a %d es: %d\n", valor,cantidad);

    printf("\n10.Escribo la cantidad de elementos de la lista: %d \n", longitud(L));

    printf("\n11.Escribo el valor del primer elemento de la lista vacia: %d \n", primerElemento(L));

    printf("\n12.Muestro la lista de 5 elementos por pantalla: ");
    mostrarLista(L);

    printf("\n13.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(L, 3)){
    printf("Pertenece\n");
    }else{
    printf("NO Pertenece\n");}

    printf("\n14.Busco si pertenece el valor 3 en la lista. Mensaje esperado: 'Pertenece': ");

    if(pertenece(L, 3)){
        printf("Pertenece\n");
    }else{
        printf("NO Pertenece\n");
    }

    printf("\n12.Muestro la lista de 5 elementos por pantalla: ");
    mostrarLista(L);


    printf("\nx.Vamos a borrar los nodos que valgan %d:\n", valor);
    L=borrarK(L,valor);
    printf("\nx.La lista sin los K:\n");
    mostrarLista(L);

    printf("\n15.Libero la memoria reservada en forma dinámica\n");
    while(!esListaVacia(L)){
        L=borrar(L);
    }

    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");
}

lista crearListaVacia(){
    return NULL;
}

bool esListaVacia(lista head){
    return head==NULL;
}

lista insertarNuevoNodo(lista head, item x){
    nodo *nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->dato=x;
    nuevo->siguiente=head;
    head=nuevo;

    return head;
}

void mostrarLista(lista head){
    printf("Lista --> ");
    while (head)
    {
        printf("%d -> ", head->dato);//%d porque item es tipo int
        head=head->siguiente;
    }
    printf("NULL\n");
}

lista borrar(lista head){
    nodo *aux;

    if (head != NULL)
    {
        aux=head;
        head=head->siguiente;
        free(aux);
    }
    return head;
}

int longitud(lista head){
    int cont=0;

    while (head)
    {
        cont++;
        head=head->siguiente;
    }
    return cont;
}

bool pertenece(lista head, item x){
    while (head && x!=head->dato)
    {
        head=head->siguiente;
    }
    return x==head->dato;
}

lista borrarK(lista head, item k){
    nodo *aux;
    printf("valor de head %p\n",head);
    while (head!=NULL)
    {
        if (head->dato==k)
        {
            printf("%d -> ", head->dato);//%d porque item es tipo int
            printf("estoy dentro del si. ");
            printf("valor de head %p\n",head);
            aux=head;
            head=head->siguiente;
            free(aux);
        }else{
            printf("%d -> ", head->dato);//%d porque item es tipo int
            printf("estoy dentro del sino. ");
            printf("valor de head %p\n",head);
            head=head->siguiente;
        }
    }
    printf("valor de head %p\n",head);
    return head;
}

item primerElemento(lista head){
    if (head!=NULL)
    {
        return head->dato;
    }else{
        return indefinido;
    }
}