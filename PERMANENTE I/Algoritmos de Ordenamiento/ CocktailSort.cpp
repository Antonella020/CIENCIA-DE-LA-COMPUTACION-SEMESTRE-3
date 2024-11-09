#include <iostream>
using namespace std;

// Función Cocktail Sort usando punteros
void CocktailSort(int *ini, int *fin)
{
    bool sigue = true;  // Variable para verificar si hay intercambios
    int *p, *q;         // Punteros para los extremos del array

    while (sigue) {
        sigue = false;  // Suponer que no habrá intercambios

        // P: de izquierda a derecha
        p = ini;
        while (p < fin) {
            if (*p > *(p + 1)) {
                swap(*p, *(p + 1));  // Intercambia si no hay orden (P)
                sigue = true;
            }
            p++;  //Puntero p hacia la derecha
        }
        fin--;  // Se reduce el array, porque el elemento final, esta ordenado.

        // Q : De derecha a izquierda
        q = fin;
        while (q > ini) {
            if (*q < *(q - 1)) {
                swap(*q, *(q - 1));  // Intercambia si no hay orden (Q)
                sigue = true; 
            }
            q--;  // Puntero q a la izquierda
        }
        ini++;
    }
}

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
    int A[11] = {15, 2, 16, 3, 8, 9, 11, 17, 26, 13, 24}; 

    CocktailSort(A, A + 10);

    cout << "Array ordenado: ";
    ImprimirArray(A, 11);

    return 0;
}
