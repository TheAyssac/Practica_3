def max_cruce(A, izq, mid, der):
    # Suma hacia la izquierda desde el centro
    suma_total = 0
    max_izq = float('-inf')
    for i in range(mid, izq - 1, -1):
        suma_total += A[i]
        if suma_total > max_izq:
            max_izq = suma_total

    # Suma hacia la derecha desde el centro + 1
    suma_total = 0
    max_der = float('-inf')
    for i in range(mid + 1, der + 1):
        suma_total += A[i]
        if suma_total > max_der:
            max_der = suma_total

    return max_izq + max_der

def resolver_dac(A, izq, der):
    # Caso base
    if izq == der:
        return A[izq]

    mid = (izq + der) // 2

    # Llamadas recursivas
    max_izq = resolver_dac(A, izq, mid)
    max_der = resolver_dac(A, mid + 1, der)
    max_centro = max_cruce(A, izq, mid, der)

    return max(max_izq, max_der, max_centro)

# --- Pruebas de los casos de la imagen ---
casos = [
    [-2, 1, -3, 4, -1, 2, 1, -5, 4], # Esperado: 6
    [-1, -2, -3, -4], # Esperado: -1
    [5, 4, -1, 7, 8], # Esperado: 23
    [1], # Esperado: 1
    [2, -1, 2, 3, 4, -1] # Esperado: 10
]

print("--- RESULTADOS ---")
for i, A in enumerate(casos, 1):
    resultado = resolver_dac(A, 0, len(A) - 1)
    print(f"Caso {i}: {resultado}")
