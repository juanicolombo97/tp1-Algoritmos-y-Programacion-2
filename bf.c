#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Creo un arreglo llamado script para almacenar datos archivo
char script[30000];
char *p_script = script; // Puntero para usar en bf
char *p_aux = script; // Puntero para guardar datos archivo

// Aca es donde realizo los cambios segun el caracter recibido
char datos[30000];
char *p_datos = datos;

//Commandos validos en bf
char commandos[] = {',','.','+','-','<','>','[',']'};

int contador;
bool seguir_ciclo;

// Funcion para ver si el caracter recibido, es valido en bf
bool caracter_valido(char caracter){
  return strchr(commandos,caracter);
}

// Funcion que recibe un archivo lo abre, para recorrerlo
// y almacenar sus datos en el arreglo script, mediante p_aux.
void lectura_archivo(char* script){
  FILE* archivo = fopen(script,"r");
  if(!archivo){
    // Si no puedo abrir el archivo
    fprintf(stderr,"Error: archivo fuente inaccesible\n");
    return;
  }
  char caracter = (char)fgetc(archivo);
  while(caracter != EOF){
    if(caracter_valido(caracter)){
      *p_aux = caracter;
      p_aux++;
    }
    caracter = (char)fgetc(archivo);
  }
  fclose(archivo);
}

void bf_commands(char* caracter){
  switch(*caracter){
    case '>':
    //Avanzo el puntero a la sig posicion del array
      ++p_datos;
      break;
    case '<':
    //Restrocedo el puntero a una posicion anterior en el array
      --p_datos;
      break;
    case '+':
    // Aumento uno al valor del array al que apunta el puntero
      ++*p_datos;
      break;
    case '-':
    // Le saco uno al valor del array que apunta el puntero
      --*p_datos;
      break;
    case '.':
    // Imprimo el valor del puntero en ASCII
      putchar(*p_datos);
      break;
    case ',':
      *p_datos = (char)getchar();
      break;
    case '[':
      // Si p_datos es 0 entonces avanza hasta que sea igual la cantidad
      // de corchetes, que indicaria que termino el loop.
        seguir_ciclo = true;
        contador = 0;
        if(!*p_datos){
          p_script++;
          while(seguir_ciclo || contador){
            if(*p_script == '['){
              if(!seguir_ciclo){
                seguir_ciclo = true;
              }
              else{
                contador++;
              }
            }
            if(*p_script == ']'){
              if(seguir_ciclo){
                seguir_ciclo = false;
              }
              else{
                contador--;
              }
            }
            p_script++;
          }
        }
      break;
    case ']':
      // Si el puntero es 0 sigue como si nada
      // si es distinto de 0 vuelve a iniciar el loop
      seguir_ciclo = true;
      contador = 0;
      if(*p_datos){
        p_script--;
        while(seguir_ciclo || contador){
          if(*p_script == ']'){
            if(!seguir_ciclo){
              seguir_ciclo = true;
            }
            else{
              contador++;
            }
          }
          if(*p_script == '['){
            if(seguir_ciclo){
              seguir_ciclo = false;
            }
            else{
              contador--;
            }
          }
          p_script--;
        }
      }
      break;

    default:
      break;
    }
}

// Funcion que recorre el script hasta que termine
// y llama a la funcion bf_commands.
void brainfuck(){
  while(*p_script){
    bf_commands(p_script);
    p_script++;
  }
}

int main(int argc,char* arcv[]){
  if(argc != 2){
    // Si no se le pasan los comandos deseados
    fprintf(stderr,"Error: Cantidad erronea de parametros");
  }
  // Llamo a brainfuck pasandole el nombre del archivo a ejecutar
  lectura_archivo(arcv[1]);
  brainfuck();
  return 0;
}
