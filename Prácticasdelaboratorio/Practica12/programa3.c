#include <stdio.h>
#define RED "\033[31m"
int main(int argc, char **argv){
    FILE *archivo;
    char linea[256];
    if(argc<2){
        printf(RED"Error fatal: hacen falta arguemntos\n");
        return 1;
    }    
    archivo=fopen (argv[1],"r");//arrgeo de cadenas va a venir el nombre del archivo
   
    if(archivo!=NULL){
        printf("El archivo se abrio correctamente:\n");
        while(feof(archivo)==0){
            //retrona un 0 mientras noi halla leido el fin de archivo
            fgets(linea, 256, archivo);
            /*en donde guardar loq ue se leio, 
            el numero maximo 
            de donde quiero leer
            puede dejar de leer cuando leai un maximo de caracteries o leer un salto de linea*/
            printf("%s", linea);
        }
        int res=fclose(archivo);
        printf("fclose=%d\n", res);
    }else{
        printf(RED"Error Fatal: %s no es un archivo o directorio\n", argv[1]);
    }
    return 0;
}