
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct Pelicula{
     
    int TheGodfather, TokyoDrift, SpiritedAway, Tenet, TheGrandBudapestHotel, Frozen;
    
 }Peliculas[5][58], InversionDePeliculas[58][5], MultiplicandoPeliculaPorInversion[58][58];

int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
    //Validamos ejecucion de lectura de archivo.
    if (Datos == NULL) {
        perror("Error al abrir archivo.");
        return 1;
        
        
        
        
        
        
        printf("");

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

    printf("\n\nSe ha leido el archivo.\n");
    LlenarInversionDePeliculas();
    return 0;
}

void LlenarInversionDePeliculas(){
    for(int largo=0;largo<=58;largo++){
        for(int ancho=0;ancho<=5;ancho++){
            switch (ancho){                       
                       case 0:
                        InversionDePeliculas[largo][ancho].TheGodfather=Peliculas[ancho][largo].TheGodfather;
                        printf("p1r %d", InversionDePeliculas[ancho][largo].TheGodfather);
                        break;
                    case 1:
                        InversionDePeliculas[largo][ancho].TokyoDrift=Peliculas[ancho][largo].TokyoDrift;
                        printf("p2 %d", InversionDePeliculas[ancho][largo].TokyoDrift);
                        break;
                    case 2:
                        InversionDePeliculas[largo][ancho].SpiritedAway=Peliculas[ancho][largo].SpiritedAway;
                        printf("p3 %d", InversionDePeliculas[ancho][largo].SpiritedAway);
                        break;
                    case 3:                        
                        InversionDePeliculas[largo][ancho].Tenet=Peliculas[ancho][largo].Tenet;
                        printf("p4 %d", InversionDePeliculas[ancho][largo].Tenet);
                        break;
                    case 4: 
                        InversionDePeliculas[largo][ancho].TheGrandBudapestHotel=Peliculas[ancho][largo].TheGrandBudapestHotel;
                        printf("p5 %d", InversionDePeliculas[ancho][largo].TheGrandBudapestHotel);
                        break;
                    case 5:
                       InversionDePeliculas[largo][ancho].Frozen=Peliculas[ancho][largo].Frozen;
                        printf("p6 %d", InversionDePeliculas[ancho][largo].Frozen);
                        break;
                    default:
                        break;                        
                }
            printf("\t");
        }    
        printf("\n \n");
    }
}