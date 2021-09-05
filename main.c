
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
    int coma = 0, largo = 0, ancho = 0, aux;
    char caracter[59];
    char *token;
    while (fgets(caracter, sizeof (caracter), Datos)) {

        token = strtok(caracter, ",");

        if (coma > 1) {
            while (token != NULL) {
                if (coma == 2 && ancho == 2) {
                    token = strtok(NULL, ",");
                }
                if (ancho >=1) {
                    if(ancho==1){ancho=0;}
                    aux = strtol(token, NULL, 10);
                    Peliculas.Matriz[ancho][largo] = aux;
                    Peliculas.MatrizInversa[largo][ancho] = aux;
                    
                    printf("%d %d", Peliculas.Matriz[ancho][largo],(ancho));

                    printf("\t");
                } 
                ancho++;
                token = strtok(NULL, ",");
            }
            printf("\n");
        } else {
            token = strtok(NULL, ",");
            ancho++;
        }
        coma++;
        if (ancho > 5) {
            largo++;
            ancho = 0;
        }

    }
    fclose(Datos);

    printf("\n\nSe ha leido el archivo.\n");
    LlenandoMultiplicacionDeMatrices();
    return 0;
    
}


void LlenandoMultiplicacionDeMatrices(){
    
    for(int largo=0;largo<=58;largo++){
        for(int ancho=58;ancho<=58;ancho++){
            Peliculas.MultiploDeMatrices[ancho][largo]=0;
        }
    }
    for (int largoMult=0; largoMult<=58; largoMult++){
        for (int largo=0; largo<=58; largo++){
            for (int ancho=0; ancho<=5; ancho++){
                Peliculas.MultiploDeMatrices[largoMult][largo] +=Peliculas.Matriz[ancho][largoMult]*Peliculas.MatrizInversa[largo][ancho];
            }
            printf("%d ", Peliculas.MultiploDeMatrices[largoMult][largo]);
        }
        printf("\n");
    }
    
}
