#include <stdio.h>
#define RED "\033[31m"
int main(){
    FILE *archivo;
    archivo=fopen ("dato.txt","r");
    if(archivo!=NULL){
        printf("El archivo se abrio correctamente:\n");
        int res=fclose(archivo);
        printf("fclose=%d\n", res);
    }else{
        printf(RED"Eror Fatal: .txt no es un archivo o directori");
    }
    return 0;
}