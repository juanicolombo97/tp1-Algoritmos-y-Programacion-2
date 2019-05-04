#include "strutil.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void pruebas_substr(){
  printf("\nPruebas SUBSTR\n");
  // Prueba ejemplo1
  char cadena[11] = "hola mundo";
  char* cadenanueva = substr(cadena,15);
  print_test("La cadena devuelve Hola m",strcmp(cadenanueva,"hola mundo")==0);
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
  //Caso 1
  char** cadena = split("abc,def,ghi", ',');
  for(int x = 0; x<4;x++){
    printf("Prueba %d: %s\n",x,cadena[x]);
  }
  free_strv(cadena);
  //Caso 2
  char** cadena2 = split("abc,def,", ',');
  for(int x = 0; x<4;x++){
    printf("Prueba %d: %s\n",x,cadena2[x]);
  }
  free_strv(cadena2);
  //Caso 3
  char** cadena3 = split(",abc,def", ',');
  for(int x = 0; x<4;x++){
    printf("Prueba %d: %s\n",x,cadena3[x]);
  }
  free_strv(cadena3);
  //Caso 4
  char** cadena4 = split("abc", '\0');
  for(int x = 0; x<1;x++){
    printf("Prueba %d: %s\n",x,cadena4[x]);
  }
  free_strv(cadena4);
  //Caso 5
  char** cadena5 = split(",", ',');
  for(int x = 0; x<3;x++){
    printf("Prueba %d: %s\n",x,cadena5[x]);
  }
  free_strv(cadena5);
  // Caso 6
  char** cadena6 = split("", ',');
  for(int x = 0; x<2;x++){
    printf("Prueba %d: %s\n",x,cadena6[x]);
  }
  free_strv(cadena6);
}

static void pruebas_join(){
  // Pruebo que funcione correctamente
  char *palabras[3] = {"hola","mundo",NULL};
  char *otro_resultado = join(palabras, ',');
  printf("%s\n",otro_resultado);
  free(otro_resultado);
  // Prueba 2
  char *palabras1[4] = {"abc","def","ghi",NULL};
  char *otro_resultado1 = join(palabras1, ';');
  printf("%s\n",otro_resultado1);
  free(otro_resultado1);
  //Pruebo casos borde
  //Caso 1

  char *palabras2[2] = {"",NULL};
  char *otro_resultado2 = join(palabras2, ';');
  printf("%s\n",otro_resultado2);
  // Caso 2

  char *palabras3[2] = {"abc",NULL};
  char *otro_resultado3 = join(palabras3, ',');
  printf("%s\n",otro_resultado3);
  free(otro_resultado3);
  //Caso 3

  char *palabras4[3] = {"","",NULL};
  char *otro_resultado4 = join(palabras4, ',');
  printf("%s\n",otro_resultado4);
  free(otro_resultado4);
  //Caso 4

  char *palabras5[1] = {NULL};
  char *otro_resultado5 = join(palabras5, ',');
  printf("%s\n",otro_resultado5);
  //Caso 5

  char *palabras6[4] = {"abc","def","ghi",NULL};
  char *otro_resultado6 = join(palabras6, '\0');
  printf("%s\n",otro_resultado6);
  free(otro_resultado6);


}


void pruebas_cadenas(){
  pruebas_substr();
  pruebas_split();
  pruebas_join();
}
