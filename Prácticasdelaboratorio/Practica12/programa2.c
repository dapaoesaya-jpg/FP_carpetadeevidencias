#include <stdio.h>
#define RED "\033[31m"
int main(int argc, char **argv){
    FILE *archivo;
    if(argc<2){
        printf(RED"Error fatal: hacen falta arguemntos\n");
        return 1;
    }    
    archivo=fopen (argv[1],"r");//arrgeo de cadenas va a venir el nombre del archivo
   
    if(archivo!=NULL){
        printf("El archivo se abrio correctamente:\n");
        int res=fclose(archivo);
        printf("fclose=%d\n", res);
    }else{
        printf(RED"Error Fatal: %s no es un archivo o directorio\n", argv[1]);
    }
    return 0;
}