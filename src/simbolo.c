#include "simbolo.h"

simbolo *crea_simbolo(char *id, int dir, int type, int var, Lista *args) {
  simbolo* nuevo_simbolo = malloc(sizeof(simbolo));
  nuevo_simbolo->id = id;
  nuevo_simbolo->dir = dir;
  nuevo_simbolo->tipo = type;
  nuevo_simbolo->var = var;
  nuevo_simbolo->args = malloc(sizeof(args));
  strcpy(nuevo_simbolo->args, args);
  return nuevo_simbolo;
}


