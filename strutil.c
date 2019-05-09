#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Funciones auxiliares

size_t cant_sep(const char* str, char sep){
  size_t contador = 0;
  for(int x = 0; x< strlen(str);x++){
    if(str[x] == sep){
      contador++;
    }
  }
  return contador;
}

size_t cant_caracteres(char **str){
  size_t contador = 0,x = 0;
  while(str[x]!= NULL){
    contador+=strlen(str[x]);
    contador++;
    x++;
  }
  return contador;
}
//Funciones

char *substr(const char *str, size_t n){
  char* nueva_cadena = malloc(sizeof(char)*(n+1));
  size_t largo = strlen(str);
  if(!nueva_cadena) return NULL;
  if(largo < n){
    strncpy(nueva_cadena,str,largo);
    nueva_cadena[largo] = '\0';
    return nueva_cadena;
  }
  strncpy(nueva_cadena,str,n);
  nueva_cadena[n]= '\0';
  return nueva_cadena;
}

char *join(char **strv, char sep){
  size_t largo_palabra = cant_caracteres(strv);
  if(largo_palabra <= 1){
    return "";
  }
  if(!strv) return NULL;
  char* cadena = calloc(largo_palabra,sizeof(char));
  int contador = 0;
  size_t largo_sep = 0;
  while(strv[contador]!= NULL){
    if(contador == 0){
      strcpy(cadena,strv[contador]);
      largo_sep+=(strlen(strv[contador]));
    }
    else{
      strcat(cadena,strv[contador]);
      largo_sep+=(strlen(strv[contador])+1);
    }
    if(strv[contador+1] != NULL){
    cadena[largo_sep] = sep;
    }
    contador++;
  }
  cadena[largo_palabra-1] = '\0';
  return cadena;
}

char **split(const char *str, char sep){
  size_t separaciones = cant_sep(str,sep)+2;
  char** arreglo = malloc(sizeof(char*) * (separaciones));
  if(!arreglo) return NULL;
  int y=0;
  int inicio = 0;
  if(sep == '\0'){
    arreglo[y] = substr(&str[0],strlen(str));
    return arreglo;
  }
  for(int x = 0;x<= strlen(str);x++){
    if(str[x] == sep){
      arreglo[y] = substr(&str[inicio],x-inicio);
      inicio = x+1;
      y++;
    }
  }
  arreglo[separaciones-2]= substr(&str[inicio],inicio);
  arreglo[separaciones-1] = NULL;
  return arreglo;
}

void free_strv(char *strv[]){
  if(!strv) return;
  size_t pos = 0;
  while(!strv[pos]){
    free(strv[pos]);
    pos++;
  }
  free(strv);
}
