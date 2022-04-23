/* APELLIDO Y NOMBRE: Gomez Rodrigo Sebastian
* Lista enlazada de n�meros enteros
*/

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
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


//IMPLEMENTACION

