#include <stdio.h>
int main (){
    FILE *archivo;
    archivo=fopen("datos.txt", "a");
    if (archivo ==NULL){
        printf("Eror Fatal: datos.txt No es archivo o carpeta \n");
        return 1;
    }
    fprintf(archivo, "Alfosnso \t20\t0\n");
    fpruntf(archivo, "Nepamuceno \t42\t0\n");
    fclose(archivo);
    return 0;
}