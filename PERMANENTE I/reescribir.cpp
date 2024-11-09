#include <iostream>
using namespace std;

void Merge(int *ini, int *mitad, int *fin)
//OBJETIVO IF(P<Q){NO PASA NADA}, ELSE(P>Q){SE INTERCAMBIA EL MENOR Y SE EMPUJA}
{
    int *p = ini;         // Puntero que apunta al inicio del subarray izquierdo
    int *q = mitad + 1;   // Puntero que apunta al inicio del subarray derecho

    // Recorremos el array comparando p y q
    while (p <= mitad && q <= fin)
    {
        // Si el valor en p es menor que en q, solo avanzamos q
        if (*p <= *q)
        {
            p++; // p está en orden, avanzamos
        }
        else
        {
            // (P>Q)SE HACE EL INTERCAMBIO
            int valorQ = *q; // GUARDAR EL VALOR DE Q, ASI AL MOMENTO DE HACER LOS DEZPLASAMIENTOS, NO SE PIERDA
            //EL VALOR DE ESTE MENOR.

            int *k = q; //k HACE EL EMPUJE
            // DEZPLASAR CON UN WHILE, los elementos a la derecha
            while (k != p)
            {
                *k = *(k - 1);//Crea ESPACIOS ,asi poder insertar Q
                k--; // AVANZA atraz <-,<-,<- hasta quedar en la posicion correcta.
            }
            //P>Q
            // Insertar el valor de q, en la posicion de p, ya se hizo el previo empuje de valores a la derecha (While)
            *p = valorQ;

            // Seguimos comparando el siguente elemento

            p++;
            mitad++; //Como se hizo el empuje, la mitad se actualiza.
            q++;
        }
    }
}

//funcion MergeSort, y divide el array y llama a la función Merge
void MergeSort(int *ini, int *fin)
{
    if (ini < fin)
    {
        int *mitad = ini + (fin - ini) / 2; //Punto medio

        // Primera mitad
        MergeSort(ini, mitad);

        // Segunda mitad
        MergeSort(mitad + 1, fin);

        // Mezcla las dos mitades
        Merge(ini, mitad, fin);
    }
}

//Imprime el array
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
    int A[8] = {12, 11, 13, 5, 6, 7, 1, 10};

    MergeSort(A, A + 7);
    cout << "Array ordenado: ";
    ImprimirArray(A, 8);
    return 0;
}
