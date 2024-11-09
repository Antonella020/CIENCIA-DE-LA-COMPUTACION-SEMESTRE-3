#include <iostream>
using namespace std;

// Función para separar pares a la izquierda e impares a la derecha
void Split(int *ini, int *fin)
{
    int *p = ini;   // Puntero que avanza desde el inicio
    int *q = fin;   // Puntero que avanza desde el final

    // Recorremos el array
    while (p < q)
    {
        if (*p % 2 == 0) 
        {
            // Si el valor de p es par, simplemente avanzamos el puntero
            p++;
        } 
        else 
        {
            // Si es impar, lo movemos al final (q)
            int temp = *p;
            
            // Desplazamos los elementos a la izquierda
            for (int *r = p; r < q; r++) 
            {
                *r = *(r + 1);
            }
            
            // Colocamos el impar al final
            *q = temp;
            
            // Reducimos q porque ya hemos movido un número impar al final
            q--;
        }
    }
}

// Función para imprimir el array
void ImprimirArray(int A[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[10] = {12, 11, 13, 5, 6, 7, 1, 10, 2, 9};  // Array desordenado

    // Aplicamos el método Split
    Split(A, A + 9);

    // Mostramos el array después de aplicar Split
    cout << "Array con pares a la izquierda y impares a la derecha: ";
    ImprimirArray(A, 10);
    return 0;
}
