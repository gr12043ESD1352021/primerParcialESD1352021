
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct Pelicua{
     
    int TheGodfather, TokyoDrift, SpiritedAway, Tenet, TheGrandBudapestHotel, Frozen;
    
}Peliculas[5][58];

int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
    //Validamos ejecucion de lectura de archivo.
    if (Datos == NULL) {
        perror("Error al abrir archivo.");
        return 1;

    }
    int coma = 0, largo=0, ancho=0, aux;
    char caracter[59];
    char *token;
    while (fgets(caracter, sizeof (caracter), Datos)) {

        token = strtok(caracter, ",");
        
         if (coma > 1) {
            while (token != NULL) {
                   switch (ancho){
                       
                       case 1:
                        aux =  strtol(token, NULL, 10);
                        Peliculas[ancho][largo].TheGodfather = aux;
                        printf("guardo exitoso el valor %i", Peliculas[ancho][largo].TheGodfather);
                        break;
                    case 2:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho][largo].TokyoDrift = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho][largo].TokyoDrift);
                        break;
                    case 3:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho][largo].SpiritedAway = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho][largo].SpiritedAway);
                        break;
                    case 4:                        
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho][largo].Tenet = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho][largo].Tenet);
                        break;
                    case 5: 
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho][largo].TheGrandBudapestHotel = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho][largo].TheGrandBudapestHotel);
                        break;
                    case 6:
                        aux = (int) strtol(token, NULL, 10);
                        Peliculas[ancho][largo].Frozen = aux;
                        printf("guardo exitoso el valor %d", Peliculas[ancho][largo].TheGodfather);
                        break;
                    default:
                        break;                        
                }
                   printf("\n");
                    token = strtok(NULL, ",");
                
                    ancho++;
                
            }
            printf("\n");
        } 
        else {
            token = strtok(NULL, ",");
        }
        coma++;
        if(ancho>=5){
            largo++;
            ancho=0;
        }
        
    }
    fclose(Datos);

    printf("\n\nSe ha leido el archivo.");
    return 0;
}