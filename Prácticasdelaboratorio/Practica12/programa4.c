#include <stdio.h>
#define RED "\033[31m"
int main(int argc, char **argv){
    FILE *archivo;
    char linea[]="Estalinea se agure mediante la función fputs\nDPEA\n";
    if(argc<2){
        printf(RED"Error fatal: hacen falta arguemntos\n");
        return 1;
    }    
    archivo=fopen (argv[1],"a+");//arrgeo de cadenas va a venir el nombre del archivo
   
    if(archivo!=NULL){
        printf("El archivo se abrio correctamente:\n");
        while(feof(archivo)==0){
            //retrona un 0 mientras noi halla leido el fin de archivo
            fputs(linea, archivo);
        }
        int res=fclose(archivo);
        printf("fclose=%d\n", res);
    }else{
        printf(RED"Error Fatal: %s no es un archivo o directorio\n", argv[1]);
    }
    return 0;
}