
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos  = fopen("peliculasFavoritasESD135_2021.csv", "r");
    //Validamos ejecucion de lectura de archivo.
    if(Datos == NULL){
        perror("Error al abrir archivo."); 
        return 1;
        
    }
    char caracter[200];
    while(fgets(caracter, sizeof(caracter), Datos)){
        char *token;
        token = strtok(caracter, "\n");
        while(token!=NULL){
         printf("%s", token);
         token =strtok(NULL, "\n");
        }
        
        printf("\n");
    }
    fclose(Datos);
 
    printf("\n\nSe ha leido el archivo.");
    
    //hioa
    
    
    return 0;
}
