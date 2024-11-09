#include <iostream>
#define MAXSIZE 10 

int A[MAXSIZE];     
int end = -1;       

//Insertar un elemento al final del array
void insert(int value) {
    if (end < MAXSIZE - 1) {   // Verifica SI HAY ESPACIO en el array
        A[++end] = value;      // Inserta en la siguente posicion de `end`
    } else {
        std::cout << "Error: El array está lleno." << std::endl;
    }
}

//Insertar un elemento
void insert(int value, int position) {
    if (end >= MAXSIZE - 1) {
        std::cout << "Error: El array está lleno." << std::endl;
        return;
    }
    if (position < 0 || position > end + 1) {
        std::cout << "Error: Posición inválida." << std::endl;
        return;
    }
    // Mueve los elementos a la derecha para abrir espacio en `position`
    for (int i = end; i >= position; i--) {
        A[i + 1] = A[i];
    }
    A[position] = value;  // Inserta el nuevo valor en la posición deseada
    end++;                // Aumenta el tamaño del array
}

// Función para eliminar un elemento en una posición específica
void remove(int position) {
    if (position < 0 || position > end) {
        std::cout << "Error: Posición inválida." << std::endl;
        return;
    }
    // Mueve los elementos a la izquierda para cubrir la posición eliminada
    for (int i = position; i < end; i++) {
        A[i] = A[i + 1];
    }
    end--;  // Disminuye el tamaño del array
}

// Función para mostrar el contenido del array
void display() {
    std::cout << "Array: ";
    for (int i = 0; i <= end; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Insertamos 5 elementos: 2, 4, 6, 7, 9
    insert(2);
    insert(4);
    insert(6);
    insert(7);
    insert(9);
    display();

    // Intercambiamos elementos insertando 5 en la posición 2
    insert(5, 2);
    display();

    // Eliminamos el elemento en la posición 0
    remove(0);
    display();

    return 0;
}
