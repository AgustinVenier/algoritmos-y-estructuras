#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(X,Y) ((X<Y)?(X):(Y))

#define TAM 50
#define PILA_LLENA -1
#define PILA_VACIA -2
#define OK 1

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
    int elem = 15;
    int elem_user;

    crearPila(&p1);

    apilar(&p1, &elem, sizeof(elem));
    if(verTope(&p1, &elem_user, sizeof(elem_user))== PILA_VACIA)
    {
        printf("La pila esta vacia. No hay nada para ver...");
        exit(1);
    }
    printf("%d\n", elem_user);

    return 0;
}

void crearPila(t_pila* pila){
    pila->tope = TAM;
}

void vaciarPila(t_pila* pila){
    pila->tope = TAM;
}

int pilaVacia(const t_pila* pila){
    if(pila->tope == TAM)
        return OK;
    return PILA_VACIA;

}

int pilaLlena(const t_pila* pila, unsigned tam){
    if(pila->tope < sizeof(tam) + tam)
        return PILA_LLENA;
    return OK;
}

int apilar(t_pila *pila, const void* elemento, unsigned tam){

    if(pila->tope < sizeof(tam) + tam)//verificamos que la pila tenga suficiente tamañano para meter el elemento y su tamaño
        return PILA_LLENA;
    pila->tope -= tam;
    memcpy(pila->pila + pila->tope, elemento, tam);

    pila->tope -= sizeof(tam);
    memcpy(pila->pila + pila->tope, &tam, sizeof(tam));

    return OK;
}

int verTope(const t_pila *pila, void* elemento, unsigned tam)
{
    unsigned tam_local;
    if(pila->tope == TAM)
        return PILA_VACIA;
    memcpy(&tam_local, pila->pila + pila->tope, sizeof(unsigned));
    memcpy(elemento, pila->pila + pila->tope + sizeof(unsigned), MIN(tam_local, tam));
    return OK;
}
