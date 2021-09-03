
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos  = fopen("PeliculasFavoritasGR12043ESD135.txt", "rb");
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
    
    printf("largo %d anchod", Datos->_lbfsize);
    
    
    
    return 0;
}
