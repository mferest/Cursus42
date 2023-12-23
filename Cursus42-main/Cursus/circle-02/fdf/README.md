# `get_next_line` 📜

## Descripción del Proyecto 🚀

`get_next_line` es una función en C diseñada para extraer líneas completas desde un descriptor de archivo. Este proyecto, parte del plan de estudios de la escuela 42, tiene como objetivo perfeccionar las habilidades de manipulación de archivos y cadenas en el lenguaje de programación C.

## Instalación 🛠️

La instalación de `get_next_line` es sencilla. Simplemente agrega los archivos fuente a tu proyecto y compílalos junto con tu programa principal.

## Uso 🖥️

Para incorporar `get_next_line` en tu código, incluye el archivo de cabecera `get_next_line.h`. Asegúrate de compilar junto con los archivos fuente.

```c
#include "get_next_line.h"

int main(void) {
    int fd;
    char *line;

    fd = open("archivo.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);

    return 0;
}


