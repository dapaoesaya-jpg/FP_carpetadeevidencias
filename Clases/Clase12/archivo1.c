#include <stdio.h>
int main (){
    FILE *archivo;
    archivo=fopen("datos.txt", "r");
    if (archivo ==NULL){
        printf("Eror Fatal: datos.txt No es archivo o carpeta \n");
        return 1;
    }
    char c;
    c=getc(archivo);
    while(c!=EOF){
        printf("%c", c);
        c=getc(archivo);
    }
    printf("\n");
    fclose(archivo);
    return 0;
}