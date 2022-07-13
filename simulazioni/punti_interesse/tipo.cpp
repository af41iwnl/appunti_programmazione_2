#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;

int compare(tipo_inf x, tipo_inf y){
  if(strcmp(x.nome, y.nome)==0 && x.id==y.id && x.tipo==y.tipo){
    return 0;
  }

  return strcmp(x.nome, y.nome);
}

void copy(tipo_inf &dst, tipo_inf src){
  dst.id = src.id;
  strcpy(dst.nome, src.nome);
  dst.tipo = src.tipo;
}

void print(tipo_inf x){
  cout << x.id << " " << x.tipo << " " << x.nome << endl;
}


