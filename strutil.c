#include "strutil.h"
#include <string.h>
#include <stdlib.h>

// Funciones auxiliares

char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);
    if (d == NULL) return NULL;
    strcpy (d,s);
    return d;
}

size_t cant_sep(const char* str, char sep){
  size_t contador = 0;
  for(int x = 0; x< strlen(str);x++){
    if(str[x] == sep){
      contador++;
    }
  }
  return contador;
}

//Funciones

char *substr(const char *str, size_t n){
  char* nueva_cadena = calloc(sizeof(char),n+1);
  if(!nueva_cadena) return NULL;
  strncpy(nueva_cadena,str,n);
  return nueva_cadena;
}

char **split(const char *str, char sep){
  size_t separaciones = cant_sep(str,sep)+2;
  char** arreglo = malloc(sizeof(char*) * (separaciones));
  char* cadena[100] = NULL;
  int lugar_arreglo = 0;
  for(int x = 0;str[x]!='\0';x++){
    if(str[x] != sep){
      if(cadena == NULL){
        strcpy(cadena,&str[x]);
      }
      else{
        strcat(cadena,&str[x]);
      }
    }
    if(str[x] == sep){
      arreglo[lugar_arreglo] = cadena;
      lugar_arreglo++;
      strcpy(cadena,"");
    }
  }
  arreglo[separaciones] = NULL;
  return arreglo;
}
