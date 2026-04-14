#include <stdio.h>

// Función para obtener el máximo de dos números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función para obtener el máximo de tres números
int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

// Función auxiliar: Calcula la suma máxima que cruza el punto medio
int max_cruce(int A[], int izq, int mid, int der) {
    int suma = 0;
    
    // Suma hacia la izquierda
    int suma_izq = -1000000;
    for (int i = mid; i >= izq; i--) {
        suma += A[i];
        if (suma > suma_izq) suma_izq = suma;
    }

    // Suma hacia la derecha
    suma = 0;
    int suma_der = -1000000;
    for (int i = mid + 1; i <= der; i++) {
        suma += A[i];
        if (suma > suma_der) suma_der = suma;
    }

    return suma_izq + suma_der;
}

// Función principal: Divide y Vencerás (Recursiva)
int resolver(int A[], int izq, int der) {
    if (izq == der) return A[izq]; // Caso base

    int mid = (izq + der) / 2;

    int max_izq = resolver(A, izq, mid);
    int max_der = resolver(A, mid + 1, der);
    int max_centro = max_cruce(A, izq, mid, der);

    return max3(max_izq, max_der, max_centro);
}

int main() {
    // Definimos los arreglos de los casos de prueba
    int c1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int c2[] = {-1, -2, -3, -4};
    int c3[] = {5, 4, -1, 7, 8};
    int c4[] = {1};
    int c5[] = {2, -1, 2, 3, 4, -1};

    // Tamaños de los arreglos
    int n[] = {9, 4, 5, 1, 6};
    
    // Punteros a los arreglos para imprimirlos en un bucle
    int *casos[] = {c1, c2, c3, c4, c5};
    int esperados[] = {6, -1, 23, 1, 10};

    printf("--- PRUEBAS DE SUBARREGLO DE SUMA MAXIMA ---\n\n");

    for (int i = 0; i < 5; i++) {
        int resultado = resolver(casos[i], 0, n[i] - 1);
        printf("[Caso %d] Resultado: %d | Esperado: %d -> %s\n", 
               i + 1, resultado, esperados[i], 
               (resultado == esperados[i] ? "PASO" : "FALLO"));
    }

    return 0;
}
