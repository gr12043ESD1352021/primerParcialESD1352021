
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pelicua {
    int Matriz[5][58];
    int MatrizInversa[58][5];
    int MultiploDeMatrices[58][58];
} Peliculas;

int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
    //Validamos ejecucion de lectura de archivo.
    if (Datos == NULL) {
        perror("Error al abrir archivo.");
        return 1;

    }
    for (int largo = 0; largo <= 58; largo++) {
        for (int ancho = 0; ancho <= 5; ancho++) {
            Peliculas.MatrizInversa[largo][ancho] = 0;
            Peliculas.Matriz[ancho][largo] = 0;
        }
    }
    int coma = 0, largo = 0, ancho = 0, aux;
    char caracter[59];
    char *token;
    while (fgets(caracter, sizeof (caracter), Datos)) {

        token = strtok(caracter, ",");

        if (coma > 1) {
            while (token != NULL) {
                if (ancho == 0) {
                    token = strtok(NULL, ",");
                } else if (ancho > 0) {
                    aux = strtol(token, NULL, 10);
                    if (aux != 0) {
                        Peliculas.Matriz[ancho - 1][largo] = aux;
                    } else {
                        Peliculas.Matriz[ancho - 1][largo] = 0;
                        Peliculas.MatrizInversa[largo][ancho - 1] = 0;
                    }
                    token = strtok(NULL, ",");
                }
                ancho++;
            }

        } else if (coma <= 1) {
            token = strtok(NULL, ",");
        }

        coma++;

        if (coma > 1 && ancho >= 6) {
            largo++;
            ancho = 0;
        }
    }
    for (int a = 0; a <= 58; a++) {
        for (int b = 0; b <= 5; b++) {
            printf("%i\t", Peliculas.Matriz[b][a]);
        }
        printf("\n");
    }
    fclose(Datos);
    return 0;
}

void LlenandoInversa() {
    for (int a = 0; a <= 58; a++) {
        for (int b = 0; b <= 5; b++) {
            Peliculas.MatrizInversa[a][b]=Peliculas.Matriz[b][a];
        }
        printf("\n");
    }
}