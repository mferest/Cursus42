#include <stdio.h>
#include <string.h>

int main() {
    char str[20]; // Un arreglo de caracteres para demostrar el uso de memset

    // Llamamos a memset para llenar 'str' con el valor 'A' (65 en ASCII)
    memset(str, 'A', sizeof(str));

    // Imprimimos el contenido de 'str' sin un bucle
    printf("%.*s\n", sizeof(str), str);

    return 0;
}
