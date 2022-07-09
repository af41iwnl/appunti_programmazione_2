#include <iostream>
#include <fstream>
#include <cstring>

#include "tipo.h"
#include "liste.h"


using namespace std;

void agenda(lista&  agenda, appuntamento  a);
void stampa(lista agenda);
void quanti(lista agenda, appuntamento a);

int main(){
  ifstream f;
  f.open("agenda.txt");

  
  lista l = NULL;

  while(!f.eof()){
    appuntamento a;
    string s;
    f>>a.data>>a.ora_i>>a.ora_f;
    getline(f>>ws, s);
    strcpy(a.descr, s.c_str());

    
    agenda(l, a);
  }

  f.close();

  stampa(l);

  appuntamento c;
  cout<<"inserire data, ora inizio, ora fine, descrizione, dell'appuntamento da controllare"<<endl;
  cin>>c.data>>c.ora_i>>c.ora_f>>c.descr;
  quanti(l, c);

  return 0;
}


void agenda(lista&  agenda, appuntamento  a){
    lista tmp = agenda;
    bool trovato = false;

    while(tmp != NULL && !trovato){
      if(compare(head(tmp), a) == true){
        trovato = true;
      }
      tmp = tail(tmp);
    }

    if(!trovato){
      elem* app = new_elem(a);
      agenda = insert_elem(agenda,app);
    }else{
      cout<<"Errore,l'appuntamento ";
      print(a);
      cout<<" è già stato prenotato"<<endl;
    }
    
}

void stampa(lista agenda){
  cout<<"AGENDA:"<<endl;
  while(agenda != NULL){
    print(head(agenda));
    agenda = tail(agenda);
  }
}

void quanti(lista agenda, appuntamento a){
  int contPrima = 0;
  int contDopo = 0;
  bool arrivato = false;

  while(agenda != NULL){
    if(prev(agenda) != NULL){
      agenda = prev(agenda);
    }else{
      arrivato = true;
    }

    if(arrivato == true){
      if((head(agenda).data == a.data) && compare(head(agenda), a) == false){
        if(head(agenda).ora_i < a.ora_i){
          contPrima++;
        }else if(head(agenda).ora_i > a.ora_i){
          contDopo++;
        }
      }
      agenda = tail(agenda);
    }
  }

  cout<<contPrima<<" appuntamenti prima e "<<contDopo<<" appuntamenti dopo"<<endl;
}