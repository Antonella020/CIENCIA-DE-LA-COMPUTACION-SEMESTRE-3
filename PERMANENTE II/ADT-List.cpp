#include <iostream>
using namespace std;

// Definición de la estructura del nodo de la lista enlazada
struct nodo {
    int valor;       // Valor del nodo
    nodo* next;      // Puntero al siguiente nodo

    // Constructor del nodo
    nodo(int v, nodo* n = nullptr) : valor(v), next(n) {}
};

// Función para insertar un nodo al principio de la lista
void insertAtBeginning(nodo*& head, int data) {
    nodo* newNode = new nodo(data);
    newNode->next = head;
    head = newNode;
}

// Función para fusionar dos listas enlazadas de manera ordenada
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

// Función para imprimir el contenido de la lista enlazada
void print(nodo* head) {
    while (head != nullptr) {
        cout << head->valor << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    nodo* LEA = nullptr;
    insertAtBeginning(LEA, 18); // 18
    insertAtBeginning(LEA, 7);  // 7 -> 18
    insertAtBeginning(LEA, 2);  // 2 -> 7 -> 18
    insertAtBeginning(LEA, 1);  // 1 -> 2 -> 7 -> 18

    nodo* LEB = nullptr;
    insertAtBeginning(LEB, 40); // 40
    insertAtBeginning(LEB, 30); // 30 -> 40
    insertAtBeginning(LEB, 10); // 10 -> 30 -> 40
    insertAtBeginning(LEB, 9);  // 9 -> 10 -> 30 -> 40
    insertAtBeginning(LEB, 8);  // 8 -> 9 -> 10 -> 30 -> 40
    insertAtBeginning(LEB, 1);  // 1 -> 8 -> 9 -> 10 -> 30 -> 40

    // Imprimir listas antes de la fusión
    cout << "Lista LEA original (ordenada): ";
    print(LEA);

    cout << "Lista LEB original (ordenada): ";
    print(LEB);

    // Fusionar LEA y LEB
    mergeLists(LEA, LEB);

    // Imprimir la lista fusionada
    cout << "Lista LEA fusionada y ordenada: ";
    print(LEA); // LEA contendrá la lista fusionada

    // LEB debe estar vacío
    cout << "Lista LEB (debe ser NULL): ";
    print(LEB);

    // Liberar memoria de la lista fusionada
    while (LEA != nullptr) {
        nodo* temp = LEA;
        LEA = LEA->next;
        delete temp;
    }

    return 0;
}
