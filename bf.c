#include <stdio.h>
#include <string.h>
#include "cola.h"
int brainfuck(char* script);

void bf_commands(int** ptr, int caracter, FILE* archivo){
  int contador_abierto;
  int contador_cerrado;
  int contador;
  int array[1000];
  switch(caracter){
    case '>':
    //Avanzo el puntero a la sig posicion del array
      ++*ptr;
      break;
    case '<':
    //Restrocedo el puntero a una posicion anterior en el array
      --*ptr;
      break;
    case '+':
    // Aumento uno al valor del array al que apunta el puntero
      ++**ptr;
      break;
    case '-':
    // Le saco uno al valor del array que apunta el puntero
      --**ptr;
      break;
    case '.':
    // Imprimo el valor del puntero en ASCII
      putchar(**ptr);
      break;
    case ',':
      **ptr = getchar();
      break;
    case '[':
      contador_abierto =1;
      contador_cerrado=0;
      contador = 0;
      while(**ptr != 0 && contador_abierto != contador_cerrado){
        if(caracter == ']'){
          contador_cerrado++;
          continue;
        }
        if(contador_abierto != contador_cerrado){
        caracter = fgetc(archivo);
        }
        if(caracter == EOF) break;
        array[contador] = caracter;
        contador++;
      }
      while(**ptr!=0){
        for(int x = 0;x<contador;x++){
          bf_commands(ptr,array[x],archivo);
        }
      }
      break;

    default:
      break;
    }
}

int brainfuck(char* script){
  FILE* archivo = fopen(script,"r");
  if(!archivo){
    // Si no puedo abrir el archivo
    fprintf(stderr,"Error: archivo fuente inaccesible\n");
    return 0;
  }
  int array[30000]={0};
  int* puntero = &array[0];
  int** ptr = &puntero;
  int caracter;
  caracter =fgetc(archivo);
  while(caracter != EOF){
    bf_commands(ptr,caracter,archivo);
    caracter =fgetc(archivo);
  }
  fclose(archivo);
  return 0;
}

int main(int argc,char* arcv[]){
  if(argc != 2){
    // Si no se le pasan los comandos deseados
    fprintf(stderr,"Error: Cantidad erronea de parametros");
  }
  // Llamo a brainfuck pasandole el nombre del archivo a ejecutar
  brainfuck(arcv[1]);
  return 0;
}
