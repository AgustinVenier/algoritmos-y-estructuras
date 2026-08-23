#include <stdio.h>
#include <string.h>

#define TAM 50
#define ERROR 1;
#define OK 0;
typedef struct{
    char pila[TAM];
    unsigned tope;
}t_pila;

void crearPila(t_pila *pila);
int apilar(t_pila *pila, const void* elemento, unsigned tam);
int desapilar(t_pila* pila, void* elemento, unsigned tam);
int verTope(const t_pila* pila, void* elemento,  unsigned tam);
int pilaVacia(const t_pila* pila);
int pilaLlena(const t_pila* pila, unsigned tam); // verifica si esta llena para lo que yo quiero poner
void vaciarPila(t_pila* pila);
int main () {
    t_pila p1;
    return 0;
}

void crearPila(t_pila* pila){
    pila->tope = TAM;
}

void vaciarPila(t_pila* pila){
    pila->tope = TAM;
}

int pilaVacia(t_pila* pila){
    if(pila->tope == TAM)
        return OK;
    return ERROR;

}

int pila

int apilar(t_pila *pila, const void* elemento, unsigned tam){
    int *ppila;
    ppila = pila;
    if(pila->tope - sizeof(tam) - tam >= 0)//verificamos que la pila tenga suficiente tamañano para meter el elemento y su tamaño
        return ERROR;

    memcpy((ppila) + (tam), elemento, tam);
    memcpy((ppila) + (tam + sizeof(tam)), tam, sizeof(tam));

    if(pila->pila != NULL)
        return OK;
}
