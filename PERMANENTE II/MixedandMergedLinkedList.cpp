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
void insertarInicio(nodo*& head, int data) {
    nodo* newNode = new nodo(data);
    newNode->next = head;
    head = newNode;
}

// Función para fusionar dos listas enlazadas de manera ordenada
void mergeLists(nodo*& LEA, nodo*& LEB) {
    nodo* mergedHead = nullptr;
    nodo** lastPtrRef = &mergedHead;


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

    *lastPtrRef = (LEA != nullptr) ? LEA : LEB;


    LEA = mergedHead;
    LEB = nullptr;
}

void print(nodo* head) {
    while (head != nullptr) {
        cout << head->valor << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    nodo* LEA = nullptr;
    insertarInicio(LEA, 18); // 18
    insertarInicio(LEA, 7);  // 7 -> 18
    insertarInicio(LEA, 2);  // 2 -> 7 -> 18
    insertarInicio(LEA, 1);  // 1 -> 2 -> 7 -> 18

    nodo* LEB = nullptr;
    insertarInicio(LEB, 40); // 40
    insertarInicio(LEB, 30); // 30 -> 40
    insertarInicio(LEB, 10); // 10 -> 30 -> 40
    insertarInicio(LEB, 9);  // 9 -> 10 -> 30 -> 40
    insertarInicio(LEB, 8);  // 8 -> 9 -> 10 -> 30 -> 40
    insertarInicio(LEB, 1);  // 1 -> 8 -> 9 -> 10 -> 30 -> 40

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
