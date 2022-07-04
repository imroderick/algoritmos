#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef char itemAB;
#define INDEFINIDO '!';
typedef struct nodoAB{
    struct nodoAB *izq;
    itemAB raiz;
    struct nodoAB *der;
}nodoAB;
typedef nodoAB *AB;

//OPERACIONES DEL ADT ARBOL BINARIO
AB ABvacio();
bool esABvacio(AB);
AB armarAB(AB,itemAB,AB);
bool pertenece(AB,itemAB);
AB izquierdo(AB);
itemAB raiz(AB);
AB derecho(AB);
void preorden(AB);

AB huffman();

int frecuencia[] = {0.110845,0.010895,0.048778,0.049769,0.133336,0.007965,0.011638,0.006108,0.077790,0.002889,0.000083,0.053524 
,0.026494,0.073580,0.093925,0.026700,0.008625,0.061571,0.079605,0.051378,0.041887,0.009698,0.000041,0.001940,0.008336,0.002600};

void main(){
    AB arbolPrueba;
    ABvacio(&arbolPrueba);
    if (esABvacio(arbolPrueba))
    {
        printf("vacio\n");
    }else{
        printf("no vacio\n");
    }
    arbolPrueba=armarAB(NULL,'x',NULL);
    if (esABvacio(arbolPrueba))
    {
        printf("vacio\n");
    }else{
        printf("no vacio\n");
    }
    arbolPrueba->der=armarAB(NULL,'y',NULL);
    arbolPrueba->izq=armarAB(NULL,'z',NULL);
    if (pertenece(arbolPrueba,'a'))
    {
        printf("si\n");
    }else{
        printf("no\n");
    }
}

AB ABvacio(){
    return NULL;
}

bool esABvacio(AB arbol){
    return arbol==NULL;
}

AB armarAB(AB izq,itemAB x,AB der){
    AB nuevoArbol = (AB)malloc(sizeof(nodoAB));
    nuevoArbol->izq=izq;
    nuevoArbol->raiz=x;
    nuevoArbol->der=der;

    return nuevoArbol;
}

bool pertenece(AB arbol, itemAB x){
    if (esABvacio(arbol))
    {
        return false;
    }else{
        return (arbol->raiz==x || pertenece(arbol->der,x) || pertenece(arbol->izq,x));
    }
}

AB izquierdo(AB arbol){
    if (!esABvacio(arbol))
    {
        return arbol->izq;
    }else{
        return NULL;
    }
}
itemAB raiz(AB arbol){
    if (!esABvacio(arbol))
    {
        return arbol->raiz;
    }else{
        return INDEFINIDO;
    }
}
AB der(AB arbol){
    if (!esABvacio(arbol))
    {
        return arbol->der;
    }else{
        return NULL;
    }
}

AB huffman(){
    AB arbolHuffman;
    AB *array;
    array=malloc(27*(sizeof(nodoAB)));
    return arbolHuffman;
}

void preorden(AB arbol){
    
}