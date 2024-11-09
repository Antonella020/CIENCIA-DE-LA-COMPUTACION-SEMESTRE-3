#include <iostream>
using namespace std;

// Verificar si la oración es palíndromo usando aritmética de punteros
bool esPalindromo(char *frase)
{
    char *inicio = frase; //Inicio
    char *final = frase;  //Final

    // Encontrar la longitud de la frase manualmente
    while (*final != '\0') {
        final++;
    }
    final--;// (antes de '\0')

    // Todos a minisculas 
    for (char *p = frase; p <= final; p++) {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p + 32;
        }
    }

    // Comparar caracteres desde el inicio al final
    while (inicio <= final) {

        // 1.- PRIMERAS CONDICIONES PARA AVANZAR:

        // INICIO(izquierda):Si no es letra ignora y avanza.
        if (!(*inicio >= 'a' && *inicio <= 'z')) {
            inicio++;
        }
        // FINAL(derecha):Si no es letra ignora y retrocede.
        else if (!(*final >= 'a' && *final <= 'z')) {
            final--;
        }
        // 2.- VERIFICAR SI ES PALÍNDROMO

        // Iguales = Avanza y achica el array de caracteres.
        else if (*inicio == *final) {
            inicio++;
            final--;
        }
        //Diferentes = Termina el programa.
        else {
            return false;
        }
    }

    return true; // Si todo es igual = Verdad
}

int main()
{
    // Cadena de caracteres
    char frase[] = "...AniTa   LaVA LA   TINA.";

    //VERDAD
    if (esPalindromo(frase)) {
        cout << "La frase SI es un palíndromo." << endl;
    }
    //FALSO
    else {
        cout << "La frase NO es un palíndromo." << endl;
    }

    return 0;
}
