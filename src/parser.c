#include "parser.h"
#include "simbolo.c"
#include <stdio.h>
extern token *yylex();
extern int yylineno;

void eat(int clase) {
  if(equals(tokenActual, clase)) {
    tokenActual = yylex();
  } else {
    error("Error de sintaxis");
  }
}

void parse() {
  //inicializar TS y TT
  D();
  //imprimir TS y TT
}

void D() {
  if(equals(tokenActual, FIN)) {
    puts("Fin de análisis sintáctico.");
    return;
  }
  //implementa
}
// Aldo
int T() {
  //implementa
  return 0; //cambiar
}

int B() {
  if(equals(tokenActual, INT)){
    eat(INT);
    return 0;
  }else if(equals(tokenActual, FLOAT)){
    eat(FLOAT);
    return 1;
  }else{
    return FIN;
  }
}

int C (int base) { 
  //implementa
  return 0; 
}

/*
* Aqui eliminamos la recursividad izquierda en L. Creamos las reglas:
* L-> id L'
* L'-> ,id L' | epsilon  
*/
void L(int tipo) {
  if(equals(tokenActual, ID)){
    if(!buscar(tokenActual->valor)){
      simbolo* sim = crea_simbolo(tokenActual->valor, dir, tipo, 0, null); 
      lista_agrega_final(tablaSimbolos, sim); 
      dir += getTam(tipo);
    }else{
      error("Ya existe la variable");
    }
    eat(ID);
    LP(tipo);
  }else{
    error("Error de sintaxis");
  }
}

//Esta es L'
void LP(int tipo) {
  if(equals(tokenActual, COMA)){
    eat(COMA);
    if(buscar(tokenActual->valor) == -1){
      simbolo* simb = crea_simbolo(tokenActual->valor, dir, tipo, 0, null); 
      lista_agrega_final(tablaSimbolos, simb); 
      dir += getTam(tipo);
    }else{
      error("Ya existe la variable");
    }
    eat(ID);
    LP(tipo);
  }
}

//para buscar los simbolos
int buscar(char *simbolo){
  while(tablaSimbolos != NULL){
    if(equals(tablaSimbolos->simbolo->id, simbolo)){
      return 1;
    }else{
      return -1;
    }
    tablaSimbolos->NodoLista->siguiente;
  }
}

int getTam(int id){
 while(tablaTipos != NULL){
    if(equals(tablaTipos->tipo->id, id)){
      return tablaTipos->tipo->tam;
    }else{
      return -1;
    }
    tablaTipos->NodoLista->siguiente;
  } 
}

void error(char *msg) {
  printf(msg);
  printf(": línea %i\n", yylineno);
  exit(1);
}
