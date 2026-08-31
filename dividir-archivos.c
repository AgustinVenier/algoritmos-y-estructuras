#include <stdio.h>

/*### Enunciado del ejercicio

Una empresa registra las ventas de productos en un archivo de movimientos "mov.dat". Cada registro del archivo contiene producto y cantidad vendida. El archivo se encuentra **ordenado por código de producto**.

Desarrollar un programa que:

Leyendo 1 única vez el **archivo de movimientos genere dos archivos de salida:

   * "minorista.dat": con los movimientos de los productos cuyo total **no supera** el límite.
   * "mayorista.dat": con los movimientos de los productos cuyo total **iguala o supera** el límite.

  * límite es establecido por el cliente (L)

Todos los registros de un mismo producto deben ir al mismo archivo. Además, los registros deben mantenerse en el mismo orden en que aparecen en el archivo original.

### Estructura del archivo de movimientos

Cada registro contiene:

* codigoProducto (entero))
* cantidad (entero)

Ejemplo

### Límite
L = 100

### Lote pequeño de prueba

Archivo **movimientos.dat**

codigo     cantidad
101        30
102        60
102        50
103        20
103        10
104        120

---

### Archivos esperados
**minorista.dat**
101 20240101 30
103 20240104 20
103 20240107 10


**mayorista.dat**
102 20240102 60
102 20240106 50
104 20240108 120 */

#define ARCH_MOVIMIENTOS "./mov.dat"
#define ARCH_MINORISTAS "./minorista.dat"
#define ARCH_MAYORISTAS "./mayorista.dat"
#define L 100

int main()
{

}
