
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos  = fopen("peliculasFavoritasESD135_2021.csv", "rb");
    //Validamos ejecucion de lectura de archivo.
    if(Datos == NULL){
        perror("Error al abrir archivo."); 
        return 1;
                        
    }
    char caracter;
    while(feof(Datos)==0){
         caracter = fgetc(Datos);
         printf("%c", caracter);
         }
    fclose(Datos);
 
    printf("\n\nSe ha leido el archivo.");
    
    printf("largo %d anchod");
    
    
    
    return 0;
}
