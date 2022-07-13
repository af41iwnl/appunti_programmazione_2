#include <iostream>
#include <cstring>
#include <fstream>
#include "tipo.h"
#include "liste.h"
#include "grafo.h"

using namespace std;

int carica(lista&  pi);
tipo_inf search_pi(lista pi,  int id);
graph mappa(int n);
void stampa_mappa(graph g, lista pi);
void trip(graph g, int node, lista pi);
void stampaLista(lista l);
lista genera(lista pi, char tipo);

int main(){

  lista l = NULL;
  int n = carica(l);
  int s;
  

  cout<<"inserire ID da cercare, 0 per terminare"<<endl;
  cin>>s;
  while(s>0){
    tipo_inf res = search_pi(l, s);
    print(res);
    cin>>s;
  } 

  graph g = mappa(n);
  stampa_mappa(g, l);
  

  lista l1 = genera(l, 'm');
  stampaLista(l1);

  return 0;
}


int carica(lista&  pi){
  ifstream f;
  f.open("PI.txt");
  int p = 0;
  tipo_inf inf;
  string s;

  while(getline(f, s)){
    inf.id = stoi(s);
    getline(f, s);
    strcpy(inf.nome, s.c_str());
    getline(f, s);
    inf.tipo = s[0];
    
    elem* e = new_elem(inf);
    pi = ord_insert_elem(pi, e);

    p++;
  }

  f.close();

  

  return p;
}

tipo_inf search_pi(lista pi,  int id){
  tipo_inf ret;
  while(pi != NULL){
    if(head(pi).id == id){
      ret = head(pi);
    }
    pi = tail(pi);
  }

  return ret;
}


graph mappa(int n){
  ifstream f;
  graph g = new_graph(n);

  f.open("G.txt");
  int u, v;
  while(f>>u){
    f>>v;
    add_edge(g, u, v, 0);
  }

  f.close();

  return g;
}


void stampa_mappa(graph g, lista pi){
  for(int i=0; i<get_dim(g); i++){
    adj_list l = get_adjlist(g, i+1);
    cout<<search_pi(pi, i+1).nome<<"\t\t\t"<<endl;
    cout<<"connesso a: "<<endl;
    cout<<endl;
    while(l != NULL){
      tipo_inf res = search_pi(pi, l->node+1);
      cout<<res.nome<<endl;
      l = l->next;
    }
    cout<<endl;
  }
}


void trip(graph g, int node, lista pi){

}

lista genera(lista pi, char tipo){
  lista l1 = NULL;
  while(pi != NULL){
    if(head(pi).tipo == tipo){
      elem* e = new_elem(head(pi));
      l1 = ord_insert_elem(l1, e);
    }

    pi = tail(pi);
  }

  return l1;
}


void stampaLista(lista l){
  while(l != NULL){
    print(head(l));
    l = tail(l);
  }
}