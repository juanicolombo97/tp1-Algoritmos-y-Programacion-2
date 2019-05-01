#include "strutil.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void pruebas_substr(){
  printf("\nPruebas SUBSTR\n");
  // Prueba ejemplo1
  char cadena[11] = "hola mundo";
  char* cadenanueva = substr(cadena,6);
  print_test("La cadena devuelve Hola m",strcmp(cadenanueva,"hola m")==0);
  free(cadenanueva);
  //Prueba ejemplo 2
  const char* ejemplo = "Ejemplo";
  char* cadena2 = substr(ejemplo + 2, 2);
  print_test("La cadena devuelta es 'em'",strcmp(cadena2,"em")==0);
  free(cadena2);
  //Prueba ejemplo3
  char* cadena3 = substr("",2);
  print_test("La cadena es ''",strcmp(cadena3,"")==0);
  free(cadena3);
  // Prueba ejemplo4
  char* cadena4 = substr("Algoritmos",30);
  print_test("La cadena es Algoritmos",strcmp(cadena4,"Algoritmos")==0);
  free(cadena4);

}
static void pruebas_split(){
  const char* arreglo = "abc,def,ghi";
  char** cadena = split(arreglo, ',');
  for(int x = 0; x<4;x++){
    printf("Prueba 1: %s\n",cadena[x]);
  }
}






void pruebas_cadenas(){
  pruebas_substr();
  pruebas_split();
}
