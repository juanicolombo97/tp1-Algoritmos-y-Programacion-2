#include <stdio.h>
#include <string.h>
/*
void bf_commands(char* archivo, char* puntero){
  switch(caracter){
    case '>':
    //Avanzo el puntero a la sig posicion del array
      puntero++;
      break;
    case '<':
    //Restrocedo el puntero a una posicion anterior en el array
      puntero--;
      break;
    case '+':
    // Aumento uno al valor del array al que apunta el puntero
      ++*puntero;
      break;
    case '-':
    // Le saco uno al valor del array que apunta el puntero
      --*puntero;
      break;
    case '.':
    // Imprimo el valor del puntero en ASCII
      putchar(*puntero);
      break;
    case ',':
      *puntero = ;

    case '[':
}

int brainfuck(char* script){
  FILE* archivo = fopen(script,"r");
  if(!archivo){
    // Si no puedo abrir el archivo
    fprintf(stderr,"Error: archivo fuente inaccesible\n");
    return NULL;
  }
  char array[30000]={0};
  char* puntero = array;

  do{
    int caracter =fgetc(archivo);
    if(caracter == EOF){  // archivo vacio
      return 0;
    }
    bf_commands(puntero,caracter);
  } while (caracter != EOF);


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
*/
