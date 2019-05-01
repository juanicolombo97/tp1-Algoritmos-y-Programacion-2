#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int fixcol(char* archivo_recibido,size_t n){
  FILE* archivo = fopen(archivo_recibido,"r");
  if(!archivo){
    return 0;  // Si el archivo no se abrio correctamente
  }
  int contador = 1;
  int caracter = fgetc(archivo);
  while(caracter != EOF){ // mientras el caracter sea distinto de NULL, no termino
    if(caracter == '\n' && contador != n){
      caracter = fgetc(archivo);
      continue;
    }
    if(contador == n || caracter == '.'){
      printf("%c\n",caracter); //Si imprimio n elementos termino la linea
      contador = 0;
    }
    else{
    printf("%c",caracter);
    }
    caracter = fgetc(archivo);
    contador++;
  }
  fclose(archivo);
  return 0;
}


int main(int argc,char* argv[]){
  // Verifico que la cantidad de comandos sea correcta
  if(argc != 3){
    printf("La funcion necesita dos parametros\n");
    return 0;
  }
  int n = atol(argv[2]);
  fixcol(argv[1],n);
  return 0;
}
