
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pelicula {
    int TheGodfather, TokyoDrift, SpiritedAway, Tenet, TheGrandBudapestHotel, Frozen;

} Peliculas[5][58], InversionDePeliculas[58][5];

struct Multiplicando{
    int multiplicador;
}MultiplicandoPeliculasEInversion[58][58];

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

                switch (ancho) {

                    case 1:
                        aux = strtol(token, NULL, 10);
                        Peliculas[ancho - 1][largo].TheGodfather = aux;
                        printf("guardo exitoso el valor %i", Peliculas[ancho - 1][largo].TheGodfather);
                        break;
                    case 2:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho - 1][largo].TokyoDrift = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho - 1][largo].TokyoDrift);
                        break;
                    case 3:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho - 1][largo].SpiritedAway = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho - 1][largo].SpiritedAway);
                        break;
                    case 4:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho - 1][largo].Tenet = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho - 1][largo].Tenet);
                        break;
                    case 5:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho - 1][largo].TheGrandBudapestHotel = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho - 1][largo].TheGrandBudapestHotel);
                        break;
                    case 6:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho - 1][largo].Frozen = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho - 1][largo].TheGodfather);
                        break;
                    default:
                        break;
                }
                ancho++;
                printf("\n");
                token = strtok(NULL, ",");

            }
            printf("\n");
        }
        else {
            token = strtok(NULL, ",");
        }
        coma++;
        if (ancho >= 5) {
            largo++;
            ancho = 0;
        }

    }
    fclose(Datos);

    printf("\n\nSe ha leido el archivo.\n");
    LlenarInversionDePeliculas();
    LlenandoMultiplicacionDeMatrices();
    return 0;
}

void LlenarInversionDePeliculas() {
    printf("valor de 1 %d \n", Peliculas[0][0].TheGodfather);
    printf("valor de 1 %d", Peliculas[1][0].TheGodfather);
    printf("valor de 1 %d\n", Peliculas[3][0].TheGodfather);
    for (int largo = 0; largo <= 58; largo++) {
        for (int ancho = 0; ancho <= 5; ancho++) {
            switch (ancho) {
                case 0:
                    InversionDePeliculas[largo][ancho].TheGodfather = Peliculas[ancho][largo].TheGodfather;
                    printf("%d", InversionDePeliculas[largo][ancho].TheGodfather);
                    break;
                case 1:
                    InversionDePeliculas[largo][ancho].TokyoDrift = Peliculas[ancho][largo].TokyoDrift;
                    printf("%d", InversionDePeliculas[largo][ancho].TokyoDrift);
                    break;
                case 2:
                    InversionDePeliculas[largo][ancho].SpiritedAway = Peliculas[ancho][largo].SpiritedAway;
                    printf("%d", InversionDePeliculas[largo][ancho].SpiritedAway);
                    break;
                case 3:
                    InversionDePeliculas[largo][ancho].Tenet = Peliculas[ancho][largo].Tenet;
                    printf("%d", InversionDePeliculas[largo][ancho].Tenet);
                    break;
                case 4:
                    InversionDePeliculas[largo][ancho].TheGrandBudapestHotel = Peliculas[ancho][largo].TheGrandBudapestHotel;
                    printf("%d", InversionDePeliculas[largo][ancho].TheGrandBudapestHotel);
                    break;
                case 5:
                    InversionDePeliculas[largo][ancho].Frozen = Peliculas[ancho][largo].Frozen;
                    printf("%d", Peliculas[largo][ancho].Frozen);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}


void LlenandoMultiplicacionDeMatrices(){
    int aux=0;
    for(int largo=0;largo<=58;largo++){
        for(int ancho=58;ancho<=58;ancho++){
            MultiplicandoPeliculasEInversion[ancho][largo].multiplicador=0;
        }
    }
    for (int largoMult=0; largoMult<=58; largoMult++){
        for (int largo=0; largo<=58; largo++){
            for (int ancho=0; ancho<=5; ancho++){
                aux = aux+(Peliculas[ancho][largo].TheGodfather);
            }
        }
    }
    
}
