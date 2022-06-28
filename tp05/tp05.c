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
void pilaVacia(tipopila *);
bool esPilaVacia(tipopila);
void push(tipopila *,item);
void pop(tipopila *);
item top(tipopila);

//
item fondo(tipopila);
void pushf(tipopila *,item);
bool incluida(tipopila,tipopila);

//OPERACIONES COMO USUARIO DE LA LISTA
bool esCreciente(tipopila);

void main(){

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");
    printf("\n1)Creo una pila y la inicializo.\n");
    tipopila P;
    pilaVacia(&P);
    printf("\n2)Prueba de la funcion esPilaVacia. Esperamos un 'Pila vacia': ");
    if (esPilaVacia(P))
    {
        printf("Pila Vacia\n");
    }else{
        printf("Pila NO Vacia\n");
    }
    printf("\n3)Altura de la pila vacia: %d\n",P.altura);
    printf("\n4)Primer elemento de una pila vacia: %d\n",top(P));
    printf("\n5)Inserto un elemento en la pila.\n");
    push(&P,1);
    printf("\n6)Prueba de la funcion esPilaVacia. Esperamos un 'Pila NO vacia': ");
    if (esPilaVacia(P))
    {
        printf("Pila vacia\n");
    }else{
        printf("Pila NO vacia\n");
    }
    printf("\n7)Primer elemento de la pila: %d\n",top(P));
    printf("\n8)Elimino un elemento en la pila.\n");
    pop(&P);
    printf("\n9)Prueba de la funcion esPilaVacia. Esperamos un 'Pila vacia': ");
    if (esPilaVacia(P))
    {
        printf("Pila Vacia\n");
    }else{
        printf("Pila NO Vacia\n");
    }
    printf("\n10)Inserto varios elementos en la pila.\n");
    push(&P,1);
    push(&P,2);
    push(&P,3);
    push(&P,4);
    push(&P,5);
    printf("\n11)Ultimo elemento de la pila: %d\n",fondo(P));
    printf("\n12)Inserto un elemento en el fondo de la pila.\n");
    pushf(&P,0);
    printf("\n13)Ultimo elemento de la pila: %d\n",fondo(P));
    printf("\n14)Creo una segunda pila y la inicializo.\n");
    tipopila Q;
    pilaVacia(&Q);
    printf("\n15)Inserto varios elementos en la segunda pila.\n");
    push(&Q,1);
    push(&Q,3);
    push(&Q,4);
    printf("\n16)Prueba de la funcion incluida. Esperamos un 'Pila incluida': ");
    if (incluida(Q,P))
    {
        printf("Pila incluida\n");
    }else{
        printf("Pila NO incluida\n");
    }
    printf("\n16)Prueba de la funcion esCreciente. Esperamos un 'Pila creciente': ");
    if (esCreciente(P))
    {
        printf("Pila creciente\n");
    }else{
        printf("Pila NO creciente\n");
    }
    fflush(stdin);
    getchar();
}

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
    pila->altura--;
    free(aux);
}

item top(tipopila pila){
    if (!esPilaVacia(pila))
    {
        return pila.head->dato;
    }else{
        return indefinido;
    }
}

item fondo(tipopila pila){
    if (!esPilaVacia(pila))
    {
        while (pila.head->siguiente!=NULL)
        {
            pila.head=pila.head->siguiente;
        }
        return pila.head->dato;
    }else{
        return indefinido;
    }
}

void pushf(tipopila *pila,item x){
    nodo *new=(nodo *)malloc(sizeof(nodo));
    new->dato=x;
    new->siguiente=NULL;
    if (esPilaVacia(*pila))
    {
        push(pila,x);
    }else{
        nodo *aux=pila->head;
        while (aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=new;
    }
}

bool incluida (tipopila pila1,tipopila pila2){
    if (esPilaVacia(pila1))
    {
        return true;
    }else{
        if (!esPilaVacia(pila2))
        {
            if (top(pila1)==top(pila2))
            {
                pila1.head=pila1.head->siguiente;
                pila2.head=pila2.head->siguiente;
                incluida(pila1,pila2);
            }else{
                pila2.head=pila2.head->siguiente;
                incluida(pila1,pila2);//hace falta poner return?
            }
        }else{
            return false;
        }
    }
}

bool esCreciente(tipopila pila){
    if (pila.altura==0 || pila.altura==1)
    {
        return true;
    }else{
        int aux=top(pila);
        pop(&pila);
        if (aux >= top(pila))
        {
            esCreciente(pila);
        }else{
            return false;
        }
    }    
}