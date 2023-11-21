#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50000
#define NUM_EXECUTIONS 100
#define MAX_TIME 1000000.0 // replace this with a large number

// Implementación de la búsqueda secuencial
int sequential_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Implementación de la búsqueda binaria
int binary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[SIZE];
    int search_num, result;
    clock_t start, end;
    double total_time_seq = 0, total_time_bin = 0;
    double min_time_seq = MAX_TIME, min_time_bin = MAX_TIME;
    double max_time_seq = 0, max_time_bin = 0;

    // Generar un arreglo ordenado de 50,000 elementos
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    srand(time(0));

    for (int i = 0; i < NUM_EXECUTIONS; i++) {
        // Generar un número aleatorio para buscar
        search_num = rand() % SIZE;

        // Búsqueda secuencial
        start = clock();
        result = sequential_search(arr, SIZE, search_num);
        end = clock();
        double time_taken_seq = ((double)end - start) / CLOCKS_PER_SEC * 1000; // en milisegundos
        total_time_seq += time_taken_seq;
        if (time_taken_seq < min_time_seq) min_time_seq = time_taken_seq;
        if (time_taken_seq > max_time_seq) max_time_seq = time_taken_seq;

        // Búsqueda binaria
        start = clock();
        result = binary_search(arr, 0, SIZE - 1, search_num);
        end = clock();
        double time_taken_bin = ((double)end - start) / CLOCKS_PER_SEC * 1000; // en milisegundos
        total_time_bin += time_taken_bin;
        if (time_taken_bin < min_time_bin) min_time_bin = time_taken_bin;
        if (time_taken_bin > max_time_bin) max_time_bin = time_taken_bin;
    }

    printf("Búsqueda secuencial - Tiempo promedio: %.2f ms, Tiempo mínimo: %.2f ms, Tiempo máximo: %.2f ms\n", total_time_seq / NUM_EXECUTIONS, min_time_seq, max_time_seq);
    printf("Búsqueda binaria - Tiempo promedio: %.2f ms, Tiempo mínimo: %.2f ms, Tiempo máximo: %.2f ms\n", total_time_bin / NUM_EXECUTIONS, min_time_bin, max_time_bin);

    return 0;
}


