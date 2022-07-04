#include <stdio.h>
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
bool esListaVacia(lista);
lista insertarNuevoNodo(lista, item );
void mostrarLista(lista);
lista borrar(lista);
int longitud(lista);
bool pertenece(lista, item);
lista borrarK(lista, item);
item primerElemento(lista);

//OPERACIONES COMO USUARIO DE LA LISTA
bool estaContenida(lista, lista);

void main(){
    int cantidad, valor=3;

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

    printf("\n1.Creo una lista y la inicializo en lista vacia.\n");
    lista L = crearListaVacia();
    lista M=crearListaVacia();

    printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
    if(esListaVacia(L)){
        printf("Lista Vacia\n");
    }else{
        printf("Lista NO Vacia\n");
    }

    printf("\n3.Muestro la lista vacia por pantalla: ");
    mostrarLista(L);

    printf("\n4.Escribo la cantidad de elementos de una lista vacia: %d \n", longitud(L));

    printf("\n5.Escribo el valor del primer elemento de una lista vacia: %d \n", primerElemento(L));

    printf("\n6.Inserto un elemento en la lista\n");
    L=insertarNuevoNodo(L,1);

    printf("\n6.Pruebo la función esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
    if(esListaVacia(L)){
    printf("Lista Vacia\n");
    }else{
    printf("Lista NO Vacia\n");
    }

    printf("\n7.Borro un elemento de la lista\n");
    L = borrar(L);

    printf("\n8.Muestro la lista vacia por pantalla: ");
    mostrarLista(L);

    printf("\n9.Inserto 5 elementos en la lista\n");
    L=insertarNuevoNodo(L,1);   M=insertarNuevoNodo(M,7);
    L=insertarNuevoNodo(L,2);   M=insertarNuevoNodo(M,5);
    L=insertarNuevoNodo(L,3);
    L=insertarNuevoNodo(L,4);
    L=insertarNuevoNodo(L,5);

    printf("\n14.Busco si la lista 1 esta contenida en la lista 2. Mensaje esperado: 'NO Contenida': ");

    if(estaContenida(M,L)){
        printf("Contenida\n");
    }else{
        printf("NO Contenida\n");
    }

    printf("\n10.Escribo la cantidad de elementos de la lista: %d \n", longitud(L));

    printf("\n11.Escribo el valor del primer elemento de la lista: %d \n", primerElemento(L));

    printf("\n12.Muestro la lista de 5 elementos por pantalla: ");
    mostrarLista(L);

    printf("\n13.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(L, 100)){
    printf("Pertenece\n");
    }else{
    printf("NO Pertenece\n");}

    printf("\n14.Busco si pertenece el valor 3 en la lista. Mensaje esperado: 'Pertenece': ");

    if(pertenece(L, 3)){
        printf("Pertenece\n");
    }else{
        printf("NO Pertenece\n");
    }

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

lista  insertarNuevoNodo(lista head, item x){
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
    while (head->siguiente && x!=head->dato)
    {
        head=head->siguiente;
    }
    return x==head->dato;
}

item primerElemento(lista head){
    if (head!=NULL)
    {
        return head->dato;
    }else{
        return indefinido;
    }
}

// lista borrarK(lista head, item k){
//     nodo *aux, *eliminado;
//     aux=head;

//     if (aux)//ACA ENTRA SI LA LISTA NO ESTA VACIA
//     {
//         if (aux->siguiente)//ACA ENTRA SI LA LISTA TIENE MAS DE UN ELEMENTO
//         {
//             while (aux->siguiente)//MIENTRAS LA LISTA TENGA MAS DE UN ELEMENTO
//             {
//                 if (aux->dato==k)//SI EL PRIMER ELEMENTO ES EL DATO A BORRAR
//                 {
//                     eliminado=aux;
//                     head=head->siguiente;
//                     aux=aux->siguiente;
//                     free(eliminado);
//                 }else if (aux->siguiente->dato==k)//SI EL SEGUNDO ELEMENTO ES EL DATO A BORRAR
//                 {
//                     eliminado=aux->siguiente;
//                     aux->siguiente=aux->siguiente->siguiente;
//                     free(eliminado);
//                 }else{
//                     aux=aux->siguiente;
//                 }
//             }
//         }else{ //ACA ENTRA SI LA LISTA TIENE UN SOLO ELEMENTO
//             if (aux->dato==k)
//             {
//                 eliminado=aux;
//                 head=head->siguiente;
//                 return head;
//             }
//         }
//     }else{
//         return head;
//     }
// }

bool estaContenida(lista head1, lista head2){
    int control=0;
    while (head1)
    {
        if(pertenece(head2, primerElemento(head1)))
        {
            control=1;
        }else{
            control=0;
            return control==1;
        };
        head1=borrar(head1);
    }
    return control==1;
};

lista borrarK(lista head, item k){
    nodo *aux, *eliminado;
    aux=head;

    if (aux)//ACA ENTRA SI LA LISTA NO ESTA VACIA
    {
        if (aux->siguiente)//ACA ENTRA SI LA LISTA TIENE MAS DE UN ELEMENTO
        {
            while (aux->siguiente)//MIENTRAS LA LISTA TENGA MAS DE UN ELEMENTO
            {
                if (aux->dato==k)//SI EL PRIMER ELEMENTO ES EL DATO A BORRAR
                {
                    eliminado=aux;
                    head=head->siguiente;
                    aux=aux->siguiente;
                    free(eliminado);
                }else if (aux->siguiente->dato==k)//SI EL SEGUNDO ELEMENTO ES EL DATO A BORRAR
                {
                    eliminado=aux->siguiente;
                    aux->siguiente=aux->siguiente->siguiente;
                    free(eliminado);
                }else{
                    aux=aux->siguiente;
                }
            }
        }else{ //ACA ENTRA SI LA LISTA TIENE UN SOLO ELEMENTO
            if (aux->dato==k)
            {
                eliminado=aux;
                head=head->siguiente;
                free(eliminado);
                return head;
            }
        }
    }else{
        return head;
    }
}