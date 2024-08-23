/*
* ------------------------------------------------------------
* parte2_lab5.c
* Laboratorio 5A - Parte 2
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* Programación de Microprocesadores
*
* Descripción: Este programa utiliza OpenMP para paralelizar
*              la suma de los primeros N números naturales.
* Autor:       P.D.L
* Fecha:       Agosto 21, 2024.
* ------------------------------------------------------------
*/

#include <stdio.h>
#include <omp.h>

#define N 1000000  // Define N.

int main() {
    int sum = 0;  // Variable para acumular la suma.
    double start_time, end_time;  // Variables para medir el tiempo de ejecución.

    // Captura el tiempo antes de iniciar el cálculo.
    start_time = omp_get_wtime();

    // Sección paralela del ciclo for para calcular la suma.
    // La cláusula 'reduction' asegura que la suma sea hecha correctamente.
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) 
    {
        sum += i;
    }

    // Captura el tiempo después de completar el cálculo.
    end_time = omp_get_wtime();

    // Imprime el resultado de la suma y el tiempo de ejecución.
    printf("Suma de los primeros %d numeros naturales: %d\n", N, sum);
    printf("Tiempo de ejecucion: %f segundos\n", end_time - start_time);

    return 0;
}
