#include <iostream>
using namespace std;

// Definición de la estructura del nodo de la lista enlazada
struct nodo {
    int valor;       // Valor del nodo
    nodo* next;      // Puntero al siguiente nodo

    // Constructor del nodo
    nodo(int v, nodo* n = nullptr) : valor(v), next(n) {}
};

// Función para convertir un array en una lista enlazada
void ARRAYTOLE(int* Begin, int* End, nodo*& head) {
    head = nullptr; // Inicializa la cabeza de la lista como nula
    for (int* p = End; p >= Begin; p--) { // Recorre de derecha a izquierda
        head = new nodo(*p, head); // Crea un nuevo nodo y lo coloca como cabeza
    }
}

// Función para imprimir el contenido de la lista enlazada
void print(nodo* head) {
    cout << "HEAD -> ";
    for (nodo* p = head; p != nullptr; p = p->next) {
        cout << p->valor << " -> "; // Imprime el valor del nodo actual
    }
    cout << "NULL" << endl; // Indica el final de la lista
}

// Función para fusionar dos listas enlazadas en orden creciente
void mergeLists(nodo*& LEA, nodo*& LEB) {
    nodo* mergedHead = nullptr;
    nodo** lastPtrRef = &mergedHead;

    // Fusiona las listas ordenadamente
    while (LEA != nullptr && LEB != nullptr) {
        if (LEA->valor < LEB->valor) {
            *lastPtrRef = LEA;
            LEA = LEA->next;
        } else {
            *lastPtrRef = LEB;
            LEB = LEB->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    // Si queda algún nodo en LEA o LEB, se añade al final de la lista fusionada
    *lastPtrRef = (LEA != nullptr) ? LEA : LEB;

    // Apunta LEA a la lista fusionada y LEB a nullptr
    LEA = mergedHead;
    LEB = nullptr;
}

int main() {
    // Arrays de ejemplo
    int A[] = {12, 17, 20, 25, 30, 38};
    int B[] = {1, 8, 13, 20, 23, 31, 38, 40, 53};

    // Definir los inicios y finales de los arrays
    int* BeginA = A;
    int* EndA = A + (sizeof(A) / sizeof(A[0])) - 1;
    int* BeginB = B;
    int* EndB = B + (sizeof(B) / sizeof(B[0])) - 1;

    // Crear las listas enlazadas LEA y LEB
    nodo* LEA = nullptr;
    nodo* LEB = nullptr;

    // Convertir los arrays en listas enlazadas
    ARRAYTOLE(BeginA, EndA, LEA);
    ARRAYTOLE(BeginB, EndB, LEB);

    // Fusionar LEA y LEB en LEA en orden creciente
    mergeLists(LEA, LEB);

    // Imprimir ambas listas
    cout << "Lista LEA (fusionada y ordenada):" << endl;
    print(LEA);

    cout << "Lista LEB (debe ser NULL):" << endl;
    print(LEB);

    // Liberar la memoria de la lista enlazada LEA
    while (LEA != nullptr) {
        nodo* temp = LEA;
        LEA = LEA->next;
        delete temp;
    }

    return 0;
}
