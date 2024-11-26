#include <iostream>
using namespace std;

// Estructura para comparar en orden ascendente
struct asc {
    bool operator()(int a, int b) { return a < b; }
};

// Estructura para comparar en orden descendente
struct desc {
    bool operator()(int a, int b) { return a > b; }
};

// Nodo de la lista enlazada
struct nodo {
    int valor;
    nodo* next;
    nodo(int v, nodo* n = nullptr) { valor = v; next = n; }
};

// Crear lista enlazada a partir de un array
void crear(int* inicio, nodo*& lista) {
    lista = new nodo(*inicio);
    inicio++;
    for (nodo* n = lista; *inicio > 0; inicio++, n = n->next)
        n->next = new nodo(*inicio);
}

// Imprimir lista enlazada
void print(nodo* lista) {
    cout << "Lista -> ";
    for (; lista; lista = lista->next)
        cout << lista->valor << " -> ";
    cout << "NULL" << endl;
}

// Función para ordenar la lista enlazada basada en un pivote
template <typename Comparador>
void ordenarPorPivote(nodo*& lista, int pivote, Comparador comp) {
    nodo *izquierda = nullptr, *derecha = nullptr;

    // Dividir en dos listas (menores y mayores al pivote)
    while (lista) {
        if (comp(lista->valor, pivote)) {
            nodo* temp = lista->next;
            lista->next = izquierda;
            izquierda = lista;
            lista = temp;
        } else {
            nodo* temp = lista->next;
            lista->next = derecha;
            derecha = lista;
            lista = temp;
        }
    }

    // Reconstruir la lista enlazada
    nodo* resultado = nullptr;
    nodo* actual = nullptr;

    // Insertar los nodos de la izquierda primero
    for (nodo* temp = izquierda; temp; temp = temp->next) {
        if (!resultado) {
            resultado = actual = temp;
        } else {
            actual->next = temp;
            actual = temp;
        }
    }

    // Insertar los nodos de la derecha después
    for (nodo* temp = derecha; temp; temp = temp->next) {
        if (!resultado) {
            resultado = actual = temp;
        } else {
            actual->next = temp;
            actual = temp;
        }
    }

    lista = resultado;
}

int main() {
    // Array inicial y creación de lista enlazada
    int A[] = {7, 7, 27, 7, 12, 9, 18, 9, 8, 7, -1};
    nodo* miLista;

    crear(A, miLista);
    cout << "Lista original:" << endl;
    print(miLista);

    // Ordenar por pivote en orden ascendente
    int pivote = 15;
    cout << "\nOrdenar por pivote (" << pivote << ") en orden ascendente:" << endl;
    ordenarPorPivote(miLista, pivote, asc());
    print(miLista);

    // Ordenar por pivote en orden descendente
    pivote = 15;
    cout << "\nOrdenar por pivote (" << pivote << ") en orden descendente:" << endl;
    ordenarPorPivote(miLista, pivote, desc());
    print(miLista);

    return 0;
}
