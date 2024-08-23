/*
* ------------------------------------------------------------
* parte3_lab5.c
* Laboratorio 5A - Parte 3
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* Programación de Microprocesadores
*
* Descripción: Este programa usa OpenMP para ejecutar tres funciones
*              en paralelo: cálculo de factorial, serie de Fibonacci,
*              y búsqueda del máximo en un arreglo.
* Autor:       P.D.L
* Fecha:       Agosto 21, 2024.
* ------------------------------------------------------------
*/

#include <stdio.h>
#include <omp.h>

// Función para calcular el factorial de un número.
void calculate_factorial(int n) 
{
    long long factorial = 1;
    for (int i = 1; i <= n; i++) 
    {
        factorial *= i;
    }
    printf("Factorial de %d: %lld\n", n, factorial);
}

// Función para generar la serie de Fibonacci hasta n términos.
void generate_fibonacci(int n) 
{
    long long a = 0, b = 1, temp;
    printf("Serie de Fibonacci hasta %d terminos:\n", n);
    for (int i = 1; i <= n; i++) 
    {
        printf("%lld ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

// Función para encontrar el máximo en un arreglo.
void find_maximum(int arr[], int size) 
{
    int max = arr[0];
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    printf("Maximo en el arreglo: %d\n", max);
}

int main() 
{
    int n = 20;  // Número de términos para Fibonacci y factorial.
    int arr[] = {3, 1, 7, 4, 9, 2, 34, 22, 34};  // Arreglo para buscar el máximo.

    // Sección paralela para ejecutar tres funciones en paralelo.
    #pragma omp parallel sections
    {
        // Primera sección: Cálculo del factorial.
        #pragma omp section
        calculate_factorial(n);

        // Segunda sección: Generar la serie de Fibonacci.
        #pragma omp section
        generate_fibonacci(n);

        // Tercera sección: Búsca el máximo en el arreglo.
        #pragma omp section
        find_maximum(arr, sizeof(arr) / sizeof(arr[0]));
    }

    return 0;
}
