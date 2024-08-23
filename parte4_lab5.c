/*
* ------------------------------------------------------------
* parte4_lab5.c
* Laboratorio 5A - Parte 4
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* Programación de Microprocesadores
*
* Descripción: Este programa usa OpenMP para modificar dos
*              variables en paralelo dentro de un ciclo for,
*              usando las cláusulas 'shared' y 'private'.
* Autor:       P.D.L
* Fecha:       Agosto 21, 2024.
* ------------------------------------------------------------
*/

#include <stdio.h>
#include <omp.h>

int main() {
    int variable1 = 0;  // Variable compartida entre los hilos.
    int variable2 = 0;  // Variable privada para cada hilo.

    // Imprime el resultado inicial de las variables.
    printf("Resultado inicial - variable1: %d, variable2: %d\n", variable1, variable2);

    // Sección paralela para la modificación de las variables en un ciclo for.
    // 'variable1' es shared y 'variable2' es private.
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < 10; i++) 
    {
        variable1 = i * 2;  // Modificación de la variable compartida.
        variable2 = i * 2;  // Modificación de la variable privada.

        printf("Hilo %d - variable1: %d, variable2: %d\n", omp_get_thread_num(), variable1, variable2);
        printf("Resultado - variable1: %d, variable2: %d\n", variable1, variable2);
    }

    // Imprime el resultado final de las variables.
    printf("Resultado final - variable1: %d, variable2: %d\n", variable1, variable2);

    return 0;
}