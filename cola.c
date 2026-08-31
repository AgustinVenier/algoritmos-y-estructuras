#include <stdio.h>
#include <string.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

#define OK 0
#define COLA_VACIA -2
#define COLA_LLENA -1
#define TAM 300

typedef struct{
    unsigned pri, ult, tam_disp;
    char cola[TAM];
}t_cola;

int acolar(t_cola* c, const void* elem, unsigned tam_elem);
int desacolar(t_cola* c, void* elem, unsigned tam_elem);
int colaLlena(const t_cola* c, unsigned tam_elem);
int colaVacia(const t_cola* c);
int verPrimero(const t_cola* c, void* elem, unsigned tam_elem);
void crearCola(t_cola* c);
void vaciarCola(t_cola* c);

int main(){
    t_cola c1;
    return OK;
}

int acolar(t_cola* c, const void* elem, unsigned tam_elem){
    unsigned ini, fin;

    if(c->tam_disp < tam_elem + sizeof(unsigned))
        return COLA_LLENA;

    c->tam_disp -= (tam_elem + sizeof(unsigned));

    if((ini = MIN(TAM - c->ult, sizeof(tam_elem))) != 0)
        memcpy(c->cola + c->ult, &tam_elem, ini);

    if((fin = sizeof(tam_elem) - ini) != 0)
        memcpy(c->cola, ((char *)&tam_elem) + ini, fin);

    c->ult = fin ? fin: c->ult + ini;

    if((ini = MIN(TAM - c->ult, tam_elem)) != 0)
        memcpy(c->cola + c->ult, elem, ini);

    if((fin = tam_elem - ini) != 0)
        memcpy(c->cola, ((char *)elem) + ini, fin);

    c->ult = fin ? fin: c->ult + ini;

    return OK;
}

int desacolar(t_cola* c, void* elem, unsigned tam_elem){
    unsigned tam_info, ini, fin;

    if(c->tam_disp == TAM)
        return COLA_VACIA;

    if((ini = MIN(sizeof(unsigned), TAM - c->pri)) != 0)
        memcpy(&tam_info, c->cola + c->pri, ini);

    if((fin = (sizeof(unsigned) - ini)) != 0)
        memcpy(((char*)&tam_info)) + ini, c->cola, fin);

    c->pri = fin ? fin : c->pri + ini;

    c->tam_disp += sizeof(unsigned) + tam_info;

    tam_info = MIN(tam_info, tam_elem);

    if((ini = MIN(tam_info, TAM - c->pri)) != 0)
        memcpy(elem, c->cola + c->pri, ini);

    if((fin = tam_info - ini)) != 0)
        memcpy(((char*)elem)) + ini, c->cola, fin);

    c->pri = fin ? fin : c->pri + ini;

    return OK;
}

int verPrimero(const t_cola* c, void* elem, unsigned tam_elem){

}

void crearCola(t_cola *c){
    c->tam_disp = TAM;
    c->pri = TAM - 50;
    c->ult = TAM - 50;
}

void vaciarCola(t_cola *c){
    c->tam_disp = TAM;
    c->ult = c->pri;
}

int colaLlena(const t_cola* c, unsigned tam_elem){
    if(c->tam_disp < tam_elem + sizeof(unsigned))
        return COLA_LLENA;
}

int colaVacia(const t_cola* c){
    if(c->tam_disp == TAM)
        return COLA_VACIA;
}
